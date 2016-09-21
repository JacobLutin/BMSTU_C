#include <stdio.h>
#include "functions.h"

int main(int argc, char *argv[])
{
	float new_array[N_MAX];    // Новый массив с результатом
	float array[N_MAX];		  // Исходный массив

	FILE *input_file;       // Указатель на входной обрабатываемый файл
	FILE *output_file;     // Указатель на выходной обрабатываемый файл
	
	int warning;		 // Переменная для хранения состояния предупреждения
	float average;      // Переменная для хранения среднего арифметического
	int n; 	           // Количество элементов массива из исходного файл
	int count;        // Количество элементов, превышающих среднее арифметическое
	int error_code;  // Переменная для хранения кода ошибки, возвращаемой функцией

	error_code = 0;

	// Проверка на вводимость аргументов коммандной строки
	if (argc < 3)
	{
		printf("USAGE: ./main <input_file> <output_file>\n");
		error_code = NO_FILE_NAME;
	}
	else
	{
		input_file = fopen(argv[1], "r");	

		// Проверка существования исходного файла
		if (input_file == NULL)
		{
			error_code = FILE_DOESNT_EXIST;
		}
		else
		{
			warning = 0;

			if ((error_code = read_array_from_file(input_file, array, &n, &warning)) == 0)
			{
				if (warning == 1)
					fprintf(stdout, "warning: array storage is not enough\n");

				// Проверка на достаточность входных данных
				if (n > 1)
				{
					// Вычисление среднего арифметического
					if ((error_code = array_average(array, n, &average)) == 0)
					{
						// Создание нового массива
						if ((error_code = create_above_average_array(array, new_array, n, average, &count)) == 1)
						{
							output_file = fopen(argv[2], "w");

							// Проверка существования выходного файла
							if (output_file == NULL)
							{
								error_code = FILE_DOESNT_EXIST;
							}
							else
							{
								// Запись нового массива в выходной файл
								if ((error_code = print_array_to_file(output_file, new_array, count)) == 0)
									fprintf(stdout, "Output file was successfuly created!\n");			

								fclose(output_file);
							}
						}
					}
					fprintf(stdout, "Average number is %.5f\n", average);
				}
				else
				{
					error_code = NOT_ENOUGH_DATA;
				}
			}
			fclose(input_file);
		}
	}

	if (error_code != 0)
		log_error(error_code);

	return error_code;
}
