#ifndef __FUNCTIONS_H__
#define __FUNCTIONS_H__

#include <stdio.h>

#define N_MAX 100

#define REQUIRED_ARGC 2

/**************************************************************************
	Обьявления функций
**************************************************************************/

void 	log_error				(int);
int 	count_array_elements	(FILE *, int *);
int 	read_array_from_file	(FILE *, int *, int);
int 	calculate_value			(int *, int *, int *);

#endif
