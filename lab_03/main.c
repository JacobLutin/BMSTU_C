#include <stdio.h>
#include "list.h"

int main(int argc, char *argv[])
{
	int num;
	Node_t *head = Node_init(1);

	Node_push(&head, 2);
	Node_push(&head, 3);
	Node_push(&head, 4);
	Node_push(&head, 5);
	Node_print(head);


	Node_remove_last(&head, &num);

	// printf("%d\n", Node_insert_by_order(&head, 2));
	// printf("%d\n", Node_insert_by_order(&head, 1));
	// printf("%d\n", Node_insert_by_order(&head, 4));


	Node_print(head);



	// print_list(head);

	return 0;
}
