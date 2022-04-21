#include <stdio.h>
#include <stdlib.h>
#include "rbtree_augmented.h"

typedef struct 
{
	int sid;
	struct rb_node node;
} SAWON;

typedef struct
{
	int sid;
	int color;
} INFO;

void __display( struct rb_node *temp, 
		  INFO (*a)[10], int *row, int *col )
{
	SAWON *s;
	int i;
	if( temp==0 ) 
		return;

	++*row;
	__display( temp->rb_left,a,row,col );
	s = rb_entry( temp, SAWON, node );
	a[*row][*col].color=rb_color(temp);
	a[*row][(*col)++].sid=s->sid;
	__display( temp->rb_right,a,row,col );
	--*row;
}


void display( struct rb_root *root )
{
	int row=-1;
	int col=0;
	INFO a[10][10]={0,};      
	int i,j;
	__display(root->rb_node,a,&row,&col);
	system("clear");
	for(i=0; i<10; i++ )
	{
		for(j=0; j<10; j++ )
		{
			if( a[i][j].sid )
			{
				if( a[i][j].color == RB_RED )
					printf("<%2d>", a[i][j].sid);
				else
					printf("[%2d]", a[i][j].sid);
			}
			else
				printf("%4c", ' ');
		}
		printf("\n");
	}
	getchar();
}

int my_insert(struct rb_root *root, SAWON *s)
{
	struct rb_node **p=&root->rb_node;
	struct rb_node *parent = 0;
	SAWON *temp; 

	while(*p)
	{
		parent = *p;
	    temp = rb_entry( parent, SAWON, node ); 
		if( temp->sid > s->sid )
			p=&(*p)->rb_left;
		else if( temp->sid < s->sid )
			p=&(*p)->rb_right;
		else
			return 0;
	}
	rb_link_node(&s->node, parent, p );  // node의 삽입
	rb_insert_color( &s->node, root );   // 밸런스를 맞춤
	return 1;
}

int main()
{
	struct rb_root root = {0};
	int a[] = {1,2,3,4,5,6,7,8};
	int i;
	int sid;
	SAWON sawon[8];
	for(i=0; i<8; i++ )
	{
		sawon[i].sid = a[i];
		my_insert( &root, sawon+i );
	}

	display(&root);
	while(1)
	{
		printf("삭제할 노드 입력 : ");
		scanf("%d", &sid );
		rb_erase( &sawon[sid-1].node, &root );
		display(&root);
	}
	return 0;
}













