#include "errors.h"

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