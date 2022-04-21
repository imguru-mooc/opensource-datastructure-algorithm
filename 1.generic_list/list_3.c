#include <stdio.h>
#include <stdlib.h>
typedef struct _node
{
	int data;
	struct _node *next;
} NODE;

void insert_data( int data, NODE *head )
{
	NODE *temp;
	temp = (NODE*)malloc(sizeof(NODE));
	temp->data = data;
	temp->next = head->next;
	head->next = temp;
}
//-----------------------------------------

void display(NODE *head)
{
	NODE *temp;
	system("clear");
	printf("[head]");
	for( temp = head->next; temp; temp=temp->next )
		printf("->[%d]", temp->data);
	printf("\n");
	getchar();
}

int main()
{
	NODE head = {0,};
	int i;
	display(&head);
	for(i=0; i<7; i++ )
	{
		display(&head);
		insert_data( i+1 , &head );
	}
	return 0;
}




