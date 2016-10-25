#ifndef __LIST_H__
#define __LIST_H__

/**************************************************************************
	Обьявления структуры списка
**************************************************************************/

typedef struct Node
{
	int val;
	struct Node *next;
} Node_t;

/**************************************************************************
	Обьявления функций
**************************************************************************/

int 		Node_print				(Node_t *);
Node_t 		*Node_init				(int);
int 		Node_push				(Node_t **, int);
int 		Node_pop				(Node_t **, int *);
int 		Node_remove_last		(Node_t **, int *);
int 		Node_insert_by_order	(Node_t **, int);

#endif
