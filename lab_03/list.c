#include <stdio.h>
#include <stdlib.h>
#include "list.h"

/**************************************************************************
	print_list function
**************************************************************************/

int Node_print(Node_t *head)
{
	Node_t *current = head;

	while (current != NULL)
	{
		printf("%d ", current->val);
		current = current->next;
	}

	printf("\n");

	return 0;
}

/**************************************************************************
	Node_init function
**************************************************************************/

Node_t *Node_init(int num)
{
	Node_t *head = malloc(sizeof(Node_t));

	head->val = num;
	head->next = NULL;

	return head;
}

/**************************************************************************
	Node_push function
**************************************************************************/

void Node_push(Node_t **head, int num)
{
	Node_t *new_node = malloc(sizeof(Node_t));

	new_node->val = num;
	new_node->next = *head;

	*head = new_node;
}

/**************************************************************************
	Node_pop function
**************************************************************************/

int Node_pop(Node_t **head, int *num)
{
	Node_t *next_node;

	if (*head == NULL)
	{
		return 0;
	}

	*num = (*head)->val;
	next_node = (*head)->next;

	free(*head);

	*head = next_node;

	return 1;
}

/**************************************************************************
	Node_remove_last function
**************************************************************************/

int Node_remove_last(Node_t **head, int *num)
{
	if (*head == NULL)
	{
		return 0;
	}

	Node_t *prev;
	Node_t *current = *head;
	*num = (current)->val;

	if (current->next == NULL)
	{
		free(*head);
		*head = NULL;

		return 1;
	}

	while (current->next != NULL)
	{
		prev = current;
		current = current->next;
		*num = current->val;
	}

	free(prev->next);
	prev->next = NULL;
		
	return 1;
}

/**************************************************************************
	Node_insert_by_order function
**************************************************************************/

int Node_insert_by_order(Node_t **head, int num)
{
	Node_t **current = head;

	if ((*current)->val < num)
	{
		Node_push(current, num);
		return 1;
	}

	current = &(*current)->next;

	while ((*current)->next != NULL)
	{
		if ((*current)->val < num)
		{
			Node_push(current, num);
			return 1;
		}

		current = &(*current)->next;
	}

	Node_push(current, num);	

	return 0;
}

/**************************************************************************
	Node_insert function
**************************************************************************/

// int Node_insert(Node_t **head, int num)
// {
// 	if (*head == NULL)
// 	{
// 		return 0;
// 	}

// 	Node_t *prev;
// 	Node_t *current = *head;

// 	Node_t *next_node;	
	

// 	if (current->next != NULL)
// 	{
// 		prev = current;
// 		current = current->next;
// 	}
// 	else


// 	return 1;
// }

/**************************************************************************
	Node_insert_by_order function
**************************************************************************/

// int Node_insert_by_order(Node_t **head, int num)
// {
// 	if (*head == NULL)
// 	{
// 		return 0;
// 	}

// 	Node_t *prev;
// 	Node_t *current = *head;

// 	if (current->val > num)
// 	{
// 		Node_push(&current, num);

// 		return 1;
// 	}

// 	while (current->next != NULL)
// 	{
// 		prev = current;
// 		current = current->next;

// 		if (current->val > num)
// 		{
// 			Node_push(&current, num);

// 			return 1;
// 		}
// 	}

// 	Node_push(&current, num);

// 	return 1;
// }








