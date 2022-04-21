#include <stdio.h>
#include <stdlib.h>
typedef struct _node
{
	int data;
	struct _node *next;
} NODE;

void insert_data( NODE *temp, NODE *head )
{
	temp->next = head->next;
	head->next = temp;
}

void reverse( NODE *head )
{
	NODE *prev = head;
	NODE *curr = prev->next;
	NODE *next;
	while( curr != head )
	{
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	} 
	curr->next = prev;
}

//-----------------------------------------

void display(NODE *head)
{
	NODE *temp;
	system("clear");
	printf("[head]");
	for( temp = head->next; temp != head ; temp=temp->next )
		printf("->[%d]", temp->data);
	printf("->[head]\n");
	getchar();
}

int main()
{
	NODE head = {0,&head};
	NODE temps[7];
	int i;
	display(&head);
	for(i=0; i<7; i++ )
	{
		temps[i].data = i+1;
		insert_data( temps+i , &head );
		display(&head);
	}
	reverse(&head);
	display(&head);
	reverse(&head);
	display(&head);
	return 0;
}




