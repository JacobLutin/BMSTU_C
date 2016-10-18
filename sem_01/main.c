#include <stdio.h>

int count_elements(FILE *file)
{
	char c;
	int i = 0;

	while (fscanf(file, "%f", &c) == 1)
		i++;

	return i;
}

int read_array_from_file(FILE *file, float array[], int count)
{
	float c;
	int i = 0;

	while (fscanf(file, "%f", &c) == 1)
	{
		*(array + i++) = c;
	}

	return 0;
}