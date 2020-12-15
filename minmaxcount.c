#include <stdio.h>
#include <stdlib.h>

struct minmaxcount
{
	int count, min, max;
};

void int_callback_minmaxcount(int data, void *userdata)
{
	struct minmaxcount *mmc = userdata;
	if (mmc->count == 0)
	{
		mmc->min = mmc->max = data;
	}
	else
	{
		if (mmc->min > data)
		{
			mmc->min = data;
		}
		if (mmc->max < data)
		{
			mmc->max = data;
		}
	}
	mmc->count++;
}

int main()
{
	struct minmaxcount mmc;
	mmc.count = 0;
}