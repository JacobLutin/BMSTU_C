#include <stdio.h>
#include <stdlib.h>
#include "errors.h"
#include "functions.h"

int main(int argc, char *argv[])
{
	int *array_p;
	int *array_p_end;

	int error_code;
	FILE *file;

	int i;
	int count;
	int warning;

	error_code = 0;

	if (argc < 2)
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
			warning = 0;

			if ((error_code = count_array_elements(file, &count, &warning)) == 0)
			{
				fprintf(stdout, "%d\n", count);

				array_p = malloc(sizeof(int) * count);

				rewind(file);

				if ((error_code = read_array_from_file(file, array_p, count, &warning)) == 0)
				{
					fprintf(stdout, "Success!\n");
					// for (i = 0; i < count; i++)
					// {
						
					// 	fprintf(stdout, "%d ", *(array_p));
					// 	fprintf(stdout, "%d ", (array_p));
					// 	array_p++;
					// }

					array_p_end = (array_p + count);

				}

				free(array_p);
			}

			fclose(file);
		}
		
	}

	log_error(error_code);

	return error_code;
}
