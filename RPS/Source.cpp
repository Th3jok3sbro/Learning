#include <iostream>
#include <cstdlib>
#include <time.h>

enum choice{
	rock,
	paper,
	scissors
};


int main()
{
	srand(time(0));

	int num[10];

	for (int i = 0; i < 10; i++)
	{
		int temp = rand() % 10;
		for (int j = 0; j < 10; j++)
		{
			if (i == 0)
			{
				num[i] = temp;
				break;
			}
			if (num[i] == num[j])
			{
				break;
			}
		}
	}
	return 0;
}