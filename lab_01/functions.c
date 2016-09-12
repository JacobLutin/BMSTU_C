#include <stdio.h>
#include <float.h>
#include "functions.h"

/**************************************************************************
	Считывание значений из файл
**************************************************************************/

int read_array_from_file(FILE *file, float array[], int *n)
{
	int error_code;
	int i;

	// Проверка существования самого файла
	if (file == NULL)
	{
		return FILE_DOESNT_EXIST;
	}

	i = 0;

	// Считывание значений и проверка на переполнение
	while (((error_code = fscanf(file, "%f", &array[i])) == 1))
	{
		if (array[i] > FLT_MAX || array[i] < FLT_MIN)
		{
			return DATA_OVERFLOW;
		}

		i++;	
	}

	// Проверка на переполнение массива
	if (i > N_MAX)
		return ARRAY_OVERFLOW;

	// Проверка отсутствия данных в файле
	if ((error_code == EOF) && (i == 0))
		return EMPTY_FILE;

	// Проверка наличия хотя бы двух значений
	if ((error_code == EOF) && (i < 2))
		return NOT_ENOUGH_DATA;

	// Проверка корректности типа данных
	if ((error_code != EOF) && (error_code != 1))
		return BAD_DATA;

	*n = i;

	fclose(file);

	return 0;
}

/**************************************************************************
	Нахождение среднего арифметического значения в массиве
**************************************************************************/

float array_average(const float array[], int n)
{
	if (n < 1)
	{
		return 0;	
	}

	float sum = 0;

	for (int i = 0; i < n; i++)
		sum += array[i]; 
	
	return sum / n;
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

int print_array_to_file(FILE *file, const float array[], int n)
{
	// Проверка существования самого файла
	if (file == NULL)
	{
		return FILE_DOESNT_EXIST;
	}

	for (int i = 0; i < n; i++)
		fprintf(file, "%.5f ", array[i]);

	fclose(file);

	return 0;
}

/**************************************************************************
	Вывод ошибок
**************************************************************************/

void log_error(int error_code)
{
	switch(error_code)
	{
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
		case DATA_OVERFLOW:
			fprintf(stderr, "I/O error. Value is overflowed.\n");
			break;
		default:
			fprintf(stderr, "Undefined error.");
	}
}







