#include <stdio.h>
#include <stdlib.h>
#include "errors.h"
#include "functions.h"

void log_error(int error_code)
{
	switch(error_code)
	{
		case 0:
			break;
		case NO_FILE_NAME:
			break;
		case FILE_DOESNT_EXIST:
			fprintf(stderr, "I/O error. File doesn't exist.\n");
			break;
		case EMPTY_FILE:
			fprintf(stderr, "I/O error. Empty file.\n");
			break;
		case BAD_DATA:
			fprintf(stderr, "I/O error. Wrong data.\n");
			break;
		case NOT_ENOUGH_DATA:
			fprintf(stderr, "I/O error. Not enough data.\n");
			break;
		case ARRAY_OVERFLOW:
			fprintf(stderr, "I/O error. Too many values.\n");
			break;
		case BAD_AVERAGE:
			fprintf(stderr, "I/O error. Average value in undefined.\n");
			break;
		default:
			fprintf(stderr, "Undefined error.");
	}
}

int count_array_elements(FILE *file, int *count, int *warning)
{
	int c_buf;
	int scanf_code;
	int error_code;
	int i;

	error_code = 0;

	if (file != NULL)
	{
		i  = 0;
		while ((scanf_code = fscanf(file, "%d", &c_buf)) == 1 && i < N_MAX)
			i++;
			
		// Проверка на переполнение массива
		if ((scanf_code != EOF) && (i == N_MAX-1))
			*warning = 1;

		// Проверка отсутствия данных в файле и корректности типа данных
		if ((scanf_code == EOF) && (i == 0))
			error_code = EMPTY_FILE;
		else if ((scanf_code != EOF) && (scanf_code != 1))
			error_code = BAD_DATA;
		else
			*count = i;
	}
	else
		error_code = FILE_DOESNT_EXIST;

	return error_code;
}

int read_array_from_file(FILE *file, int *array_p, int n, int *warning)
{
	int error_code;
	int i;
	int scanf_code;
	float c_buf;

	error_code = 0;

	// Проверка существования самого файла
	if (file == NULL)
	{
		error_code = FILE_DOESNT_EXIST;
	}
	else
	{
		i = 0;

		// Считывание значений и проверка на переполнение
		while ((scanf_code = fscanf(file, "%f", &c_buf)) == 1 && i < n)
			*(array_p + i++) = c_buf;

		for (i = 0; i < n; i++)
			fprintf(stdout, "%d ", *(array_p + i));

		printf("\n");
			
		// Проверка на переполнение массива
		if ((scanf_code != EOF) && (i == n-1))
			*warning = 1;

		// Проверка отсутствия данных в файле и корректности типа данных
		if ((scanf_code == EOF) && (i == 0))
			error_code = EMPTY_FILE;
		else if ((scanf_code != EOF) && (scanf_code != 1))
			error_code = BAD_DATA;
	}

	return error_code;
}

int calculate_value(int *array_p, int *array_p_last, int *max)
{
	int error_code;
	int i;
	int sum;

	error_code = 0;
	i = 0;

	*max = 0;

	// 

	// while (atoi(&array_p) < ((atoi(&array_p) + atoi(&array_p_last)) / 2))
	// {
	// 	fprintf(stdout, "%d %d\n", *array_p, *array_p_last);
	// 	sum = *(array_p++) + *(array_p_last--);
	// 	fprintf(sum, "%s\n", );
	// 	if (sum > max)
	// 		*max = sum;
		
	// }

	return error_code;
}
