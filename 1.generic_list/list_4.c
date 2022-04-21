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
//-----------------------------------------

void display(NODE *head)
{
	NODE *temp;
	system("clear");
	printf("[head]");
	for( temp = head->next; ; temp=temp->next )
		printf("->[%d]", temp->data);
	printf("\n");
	getchar();
}

int main()
{
	NODE head = {0,};
	NODE temps[7];
	int i;
	display(&head);
	for(i=0; i<7; i++ )
	{
		temps[i].data = i+1;
		display(&head);
		insert_data( temps+i , &head );
	}
	return 0;
}




