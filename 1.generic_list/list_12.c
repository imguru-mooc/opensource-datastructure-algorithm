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

struct task_struct 
{
	char comm[16];
	struct list_head tasks;
	struct list_head children;
	struct list_head sibling;
};

void display(struct list_head *head)
{
	struct list_head *temp;
	struct task_struct *p;
	system("clear");
	printf("[head]");
	for( temp = head->next; temp != head ; temp=temp->next )
	{
		p = container_of( temp, struct task_struct, tasks );
		printf("<->[%s]", p->comm);
	}
	printf("<->[head]\n");
	getchar();
}

int main()
{
	struct list_head head = {&head,&head};
	struct task_struct tasks[2] = { {"ls"}, {"vi"} };
	int i;
	display(&head);
	for(i=0; i<2; i++ )
	{
		list_add_tail( &tasks[i].tasks , &head );
		display(&head);
	}
	return 0;
}




