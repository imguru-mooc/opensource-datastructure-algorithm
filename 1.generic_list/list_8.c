#include <stdio.h>
#include <stdlib.h>
typedef struct _node
{
	int data;
	struct _node *next;
	struct _node *prev;
} NODE;

void __insert_data( NODE *temp, NODE *prev, NODE *next )
{
	temp->next = next;
	prev->next = temp;
	temp->prev = prev;
	next->prev = temp;
}

void insert_front( NODE *temp, NODE *head )
{
	__insert_data( temp, head, head->next );
}

void insert_back( NODE *temp, NODE *head )
{
	__insert_data( temp, head->prev, head );
}
//-----------------------------------------

void display(NODE *head)
{
	NODE *temp;
	system("clear");
	printf("[head]");
	for( temp = head->next; temp != head ; temp=temp->next )
		printf("<->[%d]", temp->data);
	printf("<->[head]\n");
	getchar();
}

int main()
{
	NODE head = {0,&head,&head};
	NODE temps[7];
	int i;
	display(&head);
	for(i=0; i<7; i++ )
	{
		temps[i].data = i+1;
		insert_back( temps+i , &head );
		display(&head);
	}
	return 0;
}




