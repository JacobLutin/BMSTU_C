#ifndef __FUNCTIONS_H__
#define __FUNCTIONS_H__

#include <stdio.h>

/**************************************************************************
	Коды ошибок
**************************************************************************/

#define FILE_DOESNT_EXIST -1  // Файл не существует
#define NO_FILE_NAME -2       // Отсутсвует имя файла
#define EMPTY_FILE -3		  // Пустой файл
#define BAD_DATA -4		  // Ошибка при считывании данных
#define NOT_ENOUGH_DATA -5    // Данных не достаточно для работы программы
#define ARRAY_OVERFLOW -6	  // Переполнение массива
#define DATA_OVERFLOW -7	  // Переполнение переменной

/**************************************************************************
	Максимальная вместимость массива
**************************************************************************/

#define N_MAX 100 

/**************************************************************************
	Объявление функций
**************************************************************************/

void log_error(int error_code);
int read_array_from_file(FILE *, float [], int *);
int count_above_average(const float [], int, float);
float array_average(const float [], int);
void create_array(const float [], float [], int, float);
int print_array_to_file(FILE *, const float [], int);

#endif
