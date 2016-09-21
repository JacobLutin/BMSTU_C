#include <stdio.h>
#include <math.h>
#include "functions.h"

#define EPS 0.01

void read_array_from_file_test			(int *);
void array_average_test					(int *);
void create_above_average_array_test	(int *);
void print_array_to_file_test			(int *);
int  float_cmp							(float, float, float);
int  array_cmp 							(float [], float [], int, float);

int main(void)
{
	int error_count = 0;

	read_array_from_file_test(&error_count);
	array_average_test(&error_count);
	create_above_average_array_test(&error_count);
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

void write_to_file(FILE **file, char *file_name, char *text)
{
	fclose(*file);
	*file = fopen(file_name, "w");
	fprintf(*file, "%s", text);
	fclose(*file);
	*file = fopen(file_name, "r");
}


int float_cmp(float a, float b, float epsilon)
{
	return (fabs(a - b) < epsilon) ? 1 : 0;
}

int array_cmp(float arr1[], float arr2[], int n, float epsilon)
{
	int equal = 1;

	for (int i = 0; i < n; i++)
	{
		if (float_cmp(arr1[i], arr2[i], epsilon) != 1)
		{
			equal = 0;
			break;
		}
	}

	return equal;
}

void read_array_from_file_test(int *error_count)
{
	FILE *file;
	char *file_name;
	float array[N_MAX];
	float result[N_MAX];
	int n;
	int warning;

	file = fopen("wrong_file.txt", "r");

	if (read_array_from_file(file, array, &n, &warning) != FILE_DOESNT_EXIST) 
		*error_count += 1;

	file_name = "test.txt";

	write_to_file(&file, file_name, "");

	if (read_array_from_file(file, array, &n, &warning) != EMPTY_FILE)
		*error_count += 1;

	write_to_file(&file, file_name, "AAA");

	if (read_array_from_file(file, array, &n, &warning) != BAD_DATA)
		*error_count += 1;

	write_to_file(&file, file_name, "1 2 3 AAA");

	if (read_array_from_file(file, array, &n, &warning) != BAD_DATA)
		*error_count += 1;

	write_to_file(&file, file_name, "1.5 3");

	result[0] = 1.5; result[1] = 3;

	if (read_array_from_file(file, array, &n, &warning) == 0)
	{
		if (array_cmp(array, result, n, EPS) != 1)
			*error_count += 1;
	}
	else
		*error_count += 1;

	write_to_file(&file, file_name, "14.2 5.86 9.0 88");

	result[0] = 14.2; result[1] = 5.86; result[2] = 9; result[3] = 88;

	if (read_array_from_file(file, array, &n, &warning) == 0)
	{
		if (array_cmp(array, result, n, EPS) != 1)
			*error_count += 1;
	}
	else
		*error_count += 1;
}

void array_average_test(int *error_count)
{
	float array[N_MAX];
	int n;
	float result;

	array[0] = 1; array[1] = 2; array[2] = 3; n = 3;

	if (array_average(array, n, &result) != 0)
		*error_count += 1;
	
	if (float_cmp(result, 2, EPS) != 1)
		*error_count += 1;

	array[0] = 1; array[1] = 1; array[2] = 1; n = 3;

	if (array_average(array, n, &result) != 0)
		*error_count += 1;

	if (float_cmp(result, 1, EPS) != 1)
		*error_count += 1;

	array[0] = 1; array[1] = 1; array[2] = 2; n = 3;

	if (array_average(array, n, &result) != 0)
		*error_count += 1;

	if (float_cmp(result, 1.33, EPS) != 1)
		*error_count += 1;

	array[0] = 9; array[1] = 10; n = 2;

	if (array_average(array, n, &result) != 0)
		*error_count += 1;

	if (float_cmp(result, 9.5, EPS) != 1)
		*error_count += 1;

	n = 0;

	if (array_average(array, n, &result) != BAD_AVERAGE)
		*error_count += 1;
}

void create_above_average_array_test(int *error_count)
{
	float array[N_MAX];
	float new_array[N_MAX];
	float result[N_MAX];
	float average;
	int n;
	int count;
	int result_count;

	array[0] = 1; array[1] = 2; array[2] = 3; average = 2; n = 3;
	result[0] = 3; result_count = 1;

	if (create_above_average_array(array, new_array, n, average, &count) != 1)
		error_count += 1;
	
	if (array_cmp(new_array, result, count, EPS) && (count != result_count))
		*error_count += 1;

	array[0] = 2; array[1] = 3; array[2] = 3; average = 2.66; n = 3;
	result[0] = 3; result[1] = 3; result_count = 2;
	new_array[0] = 0; new_array[1] = 0; new_array[2] = 0; count = 0;

	if (create_above_average_array(array, new_array, n, average, &count) != 1)
		error_count += 1;
	
	if (array_cmp(new_array, result, count, EPS) && (count != result_count))
		*error_count += 1;

	n = 0;

	if (create_above_average_array(array, new_array, n, average, &count) != BAD_ARRAY)
		*error_count += 1;
}

void print_array_to_file_test(int *error_count)
{
	FILE *file;
	char *file_name;

	float array[N_MAX];
	float result[N_MAX];
	int n;
	int warning;

	n = 0;

	file = fopen("wrong_file.txt", "r");
	if (print_array_to_file(file, array, n) != FILE_DOESNT_EXIST)
		*error_count += 1;

	file_name = "test.txt";

	file = fopen(file_name, "w");

	array[0] = 1; array[1] = 2; array[2] = 3; n = 3;

	if (print_array_to_file(file, array, n) != 0)
		*error_count += 1;

	fclose(file);

	file = fopen(file_name, "r");

	array[0] = 0; array[1] = 0; array[2] = 0; n = 0;
	result[0] = 1; result[1] = 2; result[2] = 3;

	if (read_array_from_file(file, array, &n, &warning) == 0)
	{
		if (array_cmp(array, result, n, EPS) != 1)
			*error_count += 1;
	}
	else
		*error_count += 1;

	fclose(file);

	remove(file_name);
}


