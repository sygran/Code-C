#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>
#include <math.h>

#define BUFFER_SIZE 4096
// Буффер обмена между производителями и потребителями
struct buf_str
{
	int count;
	double values[BUFFER_SIZE];
} buffer;

void init_buffer()
{
	buffer.count = 0;
}

void put_buffer_item(double v)
{
	buffer.values[buffer.count] = v;
	buffer.count++;
}

double get_buffer_item()
{
	buffer.count--;
	return buffer.values[buffer.count];
}

// Семафоры и мьютекс ждя организации работы с буфером
sem_t buf_empty;
sem_t buf_full;
pthread_mutex_t buf_mutex = PTHREAD_MUTEX_INITIALIZER;

// переменные для суммирования и мьютекс для их защиты
double grand_total = 0;
long grand_count = 0;
pthread_mutex_t grand_mutex = PTHREAD_MUTEX_INITIALIZER;

// семафор для подсчета оставшихся "производителей"
sem_t producers_count;

// поток для чтения данных "производитель"
void *producer_thread(void *v)
{
	double val;
	FILE *f = fopen((char *)v, "r");
	if (!f)
	{
		perror((char *)v);
		sem_wait(&producers_count);
		return NULL;
	}
	while (!feof(f))
	{
		if (1 != sfcanf(f, "%lf", &val))
		{
			continue;
		}
		sem_wait(&buf_empty);
		pthread_mutex_lock(&buf_mutex);
		put_buffer_item(val);
		pthread_mutex_unlock(&buf_mutex);
		sem_post(&buf_full);
	}
	sem_wait(&producers_count);
	return NULL;
}
// Поток-Потребитель, получаемое входное значение игнорирует
void *consumer_thread(void *ignored)
{
	double local_total = 0;
	long local_count = 0;
	for (;;)
	{
		double val;
		sem_wait(&buf_full); // Алгоритм потребителя
		pthread_mutex_lock(&buf_mutex);
		val = get_buffer_item();
		pthread_mutex_unlock(&buf_mutex);
		sem_post(&buf_empty);
		// Вычисления
		local_total += log(val);
		local_count++;
		// При возможности сбрасываем данные
		if (0 == pthread_mutex_trylock(&grand_mutex))
		{
			grand_total += local_total;
			grand_count += local_count;
			local_total = 0;
			local_count = 0;
			pthread_mutex_unlock(&grand_mutex);
		}
	}
}
int main(int argc, char **argv)
{
	pthread_t thr;
	int i;
	init_buffer();
	sem_init(&buf_empty, 0, BUFFER_SIZE);
	sem_init(&buf_full, 0, 0);
	sem_init(&producers_count, 0, 0);
	// Производители
	for (i = 1; i < argc; i++)
	{
		sem_post(&producers_count);
		pthread_create(&thr, NULL, producer_thread, argv[i]);
	}
	// Потербители
	for (i = 0; i < 10; i++)
	{
		pthread_create(&thr, NULL, consumer_thread, NULL);
	}
	for (;;)
	{
		int p_c;
		sleep(5);
		pthread_mutex_lock(&grand_mutex);
		// проверка деления на 0
		if (grand_count > 0)
		{
			printf("total average: %f (sum = %f; count = %ld)\n",
				   grand_total / ((double)grand_count),
				   grand_total, grand_count);
		}
		else
		{
			printf("NO data yet...\n");
		}
		grand_total = 0;
		grand_count = 0;
		pthread_mutex_unlock(&grand_mutex);
		sem_getvalue(&producers_count, &p_c);
		if (p_c == 0)
		{
			printf("No more producers\n");
			break;
		}
	}
	return 0;
}