#include <stdio.h>
#include <stdlib.h>
typedef struct _node
{
	int data;
	struct _node *next;
} NODE;

NODE *head;

void insert_data( int data )
{
	NODE *temp;
	temp = (NODE*)malloc(sizeof(NODE));
	temp->data = data;
	temp->next = head;
	head = temp;
}
//-----------------------------------------

void display(void)
{
	NODE *temp;
	system("clear");
	printf("head");
	for( temp = head; temp; temp=temp->next )
		printf("->[%d]", temp->data);
	printf("\n");
	getchar();
}

int main()
{
	int i;
	display();
	for(i=0; i<7; i++ )
	{
		display();
		insert_data( i+1 );
	}
	return 0;
}




