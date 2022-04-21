#include <stdio.h>
#include <stdlib.h>
typedef struct _node
{
	void *data;
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

typedef struct
{
	char name[20];
} SAWON;

void display(NODE *head)
{
	NODE *temp;
	SAWON *s;
	system("clear");
	printf("[head]");
	for( temp = head->next; temp != head ; temp=temp->next )
	{
		s = (SAWON*)temp->data;
		printf("<->[%s]", s->name);
	}
	printf("<->[head]\n");
	getchar();
}

int main()
{
	NODE head = {0,&head,&head};
	NODE temps[2];
	SAWON s[2] = { {"홍길동"}, {"임꺽정"} };
	int i;
	display(&head);
	for(i=0; i<2; i++ )
	{
		temps[i].data = &s[i];
		insert_back( temps+i , &head );
		display(&head);
	}
	return 0;
}




