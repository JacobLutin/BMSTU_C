#include <stdio.h>
#include "functions.h"

int main(int argc, char *argv[])
{
	FILE *file; 		  // Указатель на обрабатываемый файл
	float array[N_MAX];  // Исходный массив
	float average;      // Переменная для хранения среднего арифметического
	int n; 	           // Количество элементов массива из исходного файл
	int count;        // Количество элементов, превышающих среднее арифметическое
	int error_code;  // Переменная для хранения кода ошибки, возвращаемой функцией

	// Проверка на вводимость аргументов коммандной строки
	if (argc < 3)
	{
		printf("USAGE: ./main <input_file> <output_file>\n");
		return NO_FILE_NAME;
	}

	file = fopen(argv[1], "r");

	// Проверка существования исходного файла
	if (file == NULL)
	{
		fprintf(stderr, "I/O error. File doesn't exist.\n");
		return 1;
	}

	if ((error_code = read_array_from_file(file, array, &n)) != 0)
	{
		log_error(error_code);
		return 1;
	}

	// Вычисление среднего арифметического
	average = array_average(array, n);

	// Вычисление количества чисел, превышающих среднее арифметическое
	count = count_above_average(array, n, average);
	
	// Обьявление нового массве, на основе данных двух последних вычислений
	float new_array[count];

	create_array(array, new_array, n, average);

	file = fopen(argv[2], "w");

	// Проверка существования выходного файла
	if (file == NULL)
		fprintf(stderr, "I/O error. File doesn't exist.\n");

	if ((error_code = print_array_to_file(file, new_array, count)) != 0)
	{
		log_error(error_code);
		return 1;
	}

	fprintf(stdout, "Average number is %.5f\n", average);

	return 0;
}
