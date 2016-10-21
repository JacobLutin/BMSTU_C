#include <stdio.h>
#include <stdlib.h>
#include "errors.h"
#include "functions.h"

int main(int argc, char *argv[])
{
	FILE *file;
	int *array_p;
	int *array_p_end;
	int error_code;
	int count;
	int max_value;

	error_code = 0;

	if (argc < REQUIRED_ARGC)
	{
		printf("USAGE: ./main <input_file>\n");
		error_code = NO_FILE_NAME;
	}
	else
	{
		file = fopen(argv[1], "r");

		if (file == NULL)
		{
			error_code = FILE_DOESNT_EXIST;
		}
		else
		{
			if ((error_code = count_array_elements(file, &count)) == 0)
			{
				array_p = malloc(sizeof(int) * count);

				rewind(file);

				if ((error_code = read_array_from_file(file, array_p, count)) == 0)
				{
					array_p_end = (array_p + count);

					if ((error_code = calculate_value(array_p, array_p_end, &max_value)) == 0)
					{
						fprintf(stdout, "Success!\n");
					}
				}

				free(array_p);
			}

			fclose(file);
		}	
	}

	if (error_code != 0)
	{
		log_error(error_code);
	}
	else
	{
		fprintf(stdout, "Maximum value = %d\n", max_value);
	}

	return error_code;
}
