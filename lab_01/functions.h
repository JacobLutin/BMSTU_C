#ifndef __FUNCTIONS_H__
#define __FUNCTIONS_H__

#include <stdio.h>

/**************************************************************************
	Коды ошибок
**************************************************************************/

#define FILE_DOESNT_EXIST  -1   // Файл не существует
#define NO_FILE_NAME       -2   // Отсутсвует имя файла
#define EMPTY_FILE         -3	// Пустой файл
#define BAD_DATA 		   -4	// Ошибка при считывании данных
#define NOT_ENOUGH_DATA    -5   // Данных не достаточно для работы программы
#define ARRAY_OVERFLOW     -6	// Переполнение массива
#define BAD_AVERAGE        -7	// Ошибка в вычислении среднего значения
#define BAD_ARRAY	       -8	// Ошибка при создании нового массива

/**************************************************************************
	Максимальная вместимость массива
**************************************************************************/

#define N_MAX 100 

/**************************************************************************
	Объявление функций
**************************************************************************/

void   log_error	 			   (int error_code);
int    read_array_from_file		   (FILE *, float [], int *, int *);
int    count_above_average		   (const float [], int, float);
int    array_average			   (const float [], int, float *);
void   create_array				   (const float [], float [], int, float);
int    create_above_average_array  (const float [], float [], int, float, int *);
int    print_array_to_file		   (FILE *, const float [], int);

#endif
