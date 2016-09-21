#include <stdio.h>
#include <float.h>
#include "functions.h"

/**************************************************************************
	Считывание значений из файла
**************************************************************************/

int read_array_from_file(FILE *file, float array[], int *n, int *warning)
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
		while (((scanf_code = fscanf(file, "%f", &c_buf)) == 1) && (i < N_MAX))
			array[i++] = c_buf;
			
		// Проверка на переполнение массива
		if ((scanf_code != EOF) && (i == N_MAX-1))
			*warning = 1;

		// Проверка отсутствия данных в файле и корректности типа данных
		if ((scanf_code == EOF) && (i == 0))
			error_code = EMPTY_FILE;
		else if ((scanf_code != EOF) && (scanf_code != 1))
			error_code = BAD_DATA;
		else
			*n = i;
	}

	return error_code;
}

/**************************************************************************
	Нахождение среднего арифметического значения в массиве
**************************************************************************/

int array_average(const float array[], int n, float *result)
{
	if (n < 1)
	{
		return BAD_AVERAGE;
	}

	float sum = 0;

	for (int i = 0; i < n; i++)
		sum += array[i];

	*result = sum / n;
	
	return 0;
}

/**************************************************************************
	Подсчет количества значений в массиве, превышающих среднее
**************************************************************************/

int count_above_average(const float array[], int n, float average)
{
	int count = 0;

	for (int i = 0; i < n; i++)
		if (array[i] > average)
			count++;

	return count;
}

/**************************************************************************
	Создание нового массива из значений превышающих среднее арифметическое
**************************************************************************/

void create_array(const float array[], float new_array[], int n, float average)
{
	int k = 0;
	for (int i = 0; i < n; i++)
		if (array[i] > average)
			new_array[k++] = array[i];
}

/**************************************************************************
	Создание нового массива из значений превышающих среднее арифметическое
**************************************************************************/

int create_above_average_array(const float array[], float new_array[], int n, float average, int *count)
{
	int error_code;
	int k;

	error_code = 1;

	if (n < 1)
	{
		error_code = BAD_ARRAY;
	}
	else
	{
		k = 0;
		for (int i = 0; i < n; i++)
			if (array[i] > average)
				new_array[k++] = array[i];

		if (k < 1)
			error_code = 0;
		else
			*count = k;
	}

	return error_code;
}

/**************************************************************************
	Вывод массива в файл
**************************************************************************/

int print_array_to_file(FILE *file, const float array[], int n)
{
	// Проверка существования самого файла
	if (file == NULL)
	{
		return FILE_DOESNT_EXIST;
	}

	for (int i = 0; i < n; i++)
		fprintf(file, "%.5f ", array[i]);

	return 0;
}

/**************************************************************************
	Вывод ошибок
**************************************************************************/

void log_error(int error_code)
{
	switch(error_code)
	{
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







