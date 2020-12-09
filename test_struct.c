#include <stdio.h>

int main()
{
	enum
	{
		max_name_len = 64,
		max_group_len = 8
	};

	struct student
	{
		char name[max_name_len];
		char sex; // 'm' of 'f'
		int year_of_birth;
		int major_code;
		int year;
		char group[max_group_len];
		float average;
	};
}