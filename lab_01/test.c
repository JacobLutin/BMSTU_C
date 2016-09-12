#include <stdio.h>
#include <float.h>
#include "functions.h"

void read_array_from_file_test(int *error_count);
void count_above_average_test(int *error_count);
void array_average_test(int *error_count);
void create_array_test(int *error_count);
void print_array_to_file_test(int *error_count);

int main(void)
{
	int error_count = 0;

	read_array_from_file_test(&error_count);
	array_average_test(&error_count);
	count_above_average_test(&error_count);
	create_array_test(&error_count);
	print_array_to_file_test(&error_count);

	if (error_count > 0)
	{
		printf("%d tests are not passed.\n", error_count);
	}
	else
	{
		printf("All tests are successfully passed.\n");
	}

	return 0;
}

void write_to_file(FILE **file, char* file_name, char *text)
{
	fclose(*file);
	*file = fopen(file_name, "w");
	fprintf(*file, "%s", text);
	fclose(*file);
	*file = fopen(file_name, "r");
}


void read_array_from_file_test(int *error_count)
{
	FILE *file;
	char *file_name;
	float array[N_MAX];
	int n;

	file = fopen("wrong_file.txt", "r");

	if (read_array_from_file(file, array, &n) != FILE_DOESNT_EXIST)
		*error_count += 1;

	file_name = "test.txt";

	write_to_file(&file, file_name, "");

	if (read_array_from_file(file, array, &n) != EMPTY_FILE)
		*error_count += 1;

	write_to_file(&file, file_name, "AAA");

	if (read_array_from_file(file, array, &n) != BAD_DATA)
		*error_count += 1;

	write_to_file(&file, file_name, "1 2 3 AAA");

	if (read_array_from_file(file, array, &n) != BAD_DATA)
		*error_count += 1;

	write_to_file(&file, file_name, "256");

	if (read_array_from_file(file, array, &n) != NOT_ENOUGH_DATA)
		*error_count += 1;

	write_to_file(&file, file_name, "1.5 3");

	if (read_array_from_file(file, array, &n) == 0)
	{
		if ((array[0] != 1.5) || 
			(array[1] != 3) ||			
			(n != 2))
			*error_count += 1;
	}
	else
		*error_count += 1;

	write_to_file(&file, file_name, "14 5 9 88");

	if (read_array_from_file(file, array, &n) == 0)
	{
		if ((array[0] != 14) || 
			(array[1] != 5) || 
			(array[2] != 9) || 
			(array[3] != 88) ||
			(n != 4))
			*error_count += 1;
	}
	else
		*error_count += 1;

	file = fopen(file_name, "w");
	fprintf(file, "%f\n", FLT_MAX*2);
	fclose(file);
	file = fopen(file_name, "r");
	if (read_array_from_file(file, array, &n) != DATA_OVERFLOW)
		*error_count += 1;

	file = fopen(file_name, "w");
	for (int i = 0; i < N_MAX+1; i++)
		fprintf(file, "%d\n", i+1);

	fclose(file);

	file = fopen(file_name, "r");

	if (read_array_from_file(file, array, &n) != ARRAY_OVERFLOW)
		*error_count += 1;
}

void array_average_test(int *error_count)
{
	float array[N_MAX];
	int n;

	array[0] = 1; array[1] = 2; array[2] = 3; n = 3;

	if (array_average(array, n) != 2)
		*error_count += 1;

	array[0] = 1; array[1] = 1; array[2] = 1; n = 3;

	if (array_average(array, n) != 1)
		*error_count += 1;

	array[0] = 9; array[1] = 10; n = 2;

	if (array_average(array, n) != 9.5)
		*error_count += 1;

	n = 0;
	if (array_average(array, n) != 0)
		*error_count += 1;
}

void count_above_average_test(int *error_count)
{
	float array[N_MAX];
	int n;
	float average;

	array[0] = 2; array[1] = 5; n = 2; average = 3.5;

	if (count_above_average(array, n, average) != 1)
		*error_count += 1;

	array[0] = 0; array[1] = 0; n = 2; average = 1;

	if (count_above_average(array, n, average) != 0)
		*error_count += 1;
}

void create_array_test(int *error_count)
{
	float array[N_MAX];
	float new_array[N_MAX];
	float average;
	int n;

	array[0] = 1; array[1] = 2; array[2] = 3; average = 2; n = 3;

	create_array(array, new_array, n, average);
	if (new_array[0] != 3)
		*error_count += 1;

	array[0] = 2; array[1] = 0.676; array[2] = 4; average = 1.5; n = 3;

	create_array(array, new_array, n, average);
	if (new_array[0] != 2 || new_array[1] != 4)
		*error_count += 1;
}

void print_array_to_file_test(int *error_count)
{
	FILE *file;
	char *file_name;

	float array[N_MAX];
	int n;

	n = 0;

	file = fopen("wrong_file.txt", "r");
	if (print_array_to_file(file, array, n) != FILE_DOESNT_EXIST)
		*error_count += 1;

	file_name = "test.txt";

	file = fopen(file_name, "w");
	array[0] = 1; array[1] = 2; array[2] = 3; n = 3;
	print_array_to_file(file, array, n);

	file = fopen(file_name, "r");

	array[0] = 0; array[1] = 0; array[2] = 0; n = 0;

	if (read_array_from_file(file, array, &n) == 0)
	{
		if (array[0] != 1 || array[1] != 2 || array[2] != 3 || n != 3)
			*error_count += 1;
	}
	else
		*error_count += 1;
}
