#ifndef __ERRORS_H__
#define __ERRORS_H__

#define FILE_DOESNT_EXIST  -1   // Файл не существует
#define NO_FILE_NAME       -2   // Отсутсвует имя файла
#define EMPTY_FILE         -3	// Пустой файл
#define BAD_DATA 		   -4	// Ошибка при считывании данных
#define NOT_ENOUGH_DATA    -5   // Данных не достаточно для работы программы
#define ARRAY_OVERFLOW     -6	// Переполнение массива
#define BAD_AVERAGE        -7	// Ошибка в вычислении среднего значения
#define BAD_ARRAY	       -8	// Ошибка при создании нового массива

int abc(int);

#endif 
