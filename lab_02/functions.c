#include <stdio.h>
#include <stdlib.h>
#include "errors.h"
#include "functions.h"

/**************************************************************************
	Вывод ошибки
**************************************************************************/

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
			fprintf(stderr, "I/O error. Bad data.\n");
			break;
		case ARRAY_OVERFLOW:
			fprintf(stderr, "I/O error. Too many values.\n");
			break;
		case EMPTY_ARRAY:
			fprintf(stderr, "I/O error. Array is empty.\n");
			break;
		case NOT_ENOUGH_DATA:
			fprintf(stderr, "I/O error. NOT_ENOUGH_DATA.\n");
			break;
		default:
			fprintf(stderr, "Undefined error.");
	}
}

/**************************************************************************
	Считывание количества элементов массива из файла
**************************************************************************/

int count_array_elements(FILE *file, int *count)
{
	int c_buf;
	int scanf_code;
	int error_code;
	int i;

	error_code = 0;

	if (file != NULL)
	{
		i  = 0;
		while ((scanf_code = fscanf(file, "%d", &c_buf)) == 1)
			i++;

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

/**************************************************************************
	Считывание значений из файла
**************************************************************************/

int read_array_from_file(FILE *file, int *array_p, int n)
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

		// for (i = 0; i < n; i++)
		// 	fprintf(stdout, "%d ", *(array_p + i));
		// printf("\n");
			
		// Проверка на переполнение массива
		if ((scanf_code != EOF) && (i == n-1))
			error_code = ARRAY_OVERFLOW;
		// Проверка отсутствия данных в файле
		else if ((scanf_code == EOF) && (i == 0))
			error_code = EMPTY_FILE;
		// Проверка корректности типа данных
		else if ((scanf_code != EOF) && (scanf_code != 1))
			error_code = BAD_DATA;
	}

	return error_code;
}

/**************************************************************************
	Вычисление значения требуемого задачей
**************************************************************************/

int calculate_value(int *array_p, int *array_p_last, int *max)
{
	int error_code;
	int i;

	error_code = 0;
	*max = 0;

	i = 0;

	while (1)
	{
		array_p_last--;

		if (array_p >= array_p_last)
		{
			break;
		}

		if (*array_p + *array_p_last > *max)
		{
			*max = *array_p + *array_p_last;
		}
		else if (*array_p + *array_p > *max)

		array_p++;

		i++;
	}

	if (i == 0)
	{
		error_code = EMPTY_ARRAY;

		if (array_p_last == array_p)
		{
			error_code = NOT_ENOUGH_DATA;
		}
	}

	return error_code;
}
