#include <stdio.h>
#include <stdlib.h>

struct list_head {
	struct list_head *next, *prev;
};

void __list_add(struct list_head *new,
		struct list_head *prev,
		struct list_head *next)
{
	next->prev = new;
	new->next = next;
	new->prev = prev;
	prev->next = new;
}

void list_add( struct list_head *new, 
		struct list_head *head )
{
	__list_add(new, head, head->next);
}

void list_add_tail(struct list_head *new, struct list_head *head)
{
    __list_add(new, head->prev, head);
}

#define offsetof(TYPE, MEMBER)	((size_t)&((TYPE *)0)->MEMBER)

#define container_of(ptr, type, member) ({			\
	const typeof( ((type *)0)->member ) *__mptr = (ptr);	\
	(type *)( (char *)__mptr - offsetof(type,member) );})

//-----------------------------------------

typedef struct
{
	char name[20];
	struct list_head list1;
	struct list_head list2;
} SAWON;

void display(struct list_head *head)
{
	struct list_head *temp;
	SAWON *s;
	system("clear");
	printf("[head]");
	for( temp = head->next; temp != head ; temp=temp->next )
	{
		s = container_of( temp, SAWON, list2 );
		printf("<->[%s]", s->name);
	}
	printf("<->[head]\n");
	getchar();
}

int main()
{
	struct list_head head = {&head,&head};
	SAWON s[2] = { {"홍길동"}, {"임꺽정"} };
	int i;
	display(&head);
	for(i=0; i<2; i++ )
	{
		list_add_tail( &s[i].list2 , &head );
		display(&head);
	}
	return 0;
}




