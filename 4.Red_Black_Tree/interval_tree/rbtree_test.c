#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "interval_tree.h"
#include "interval_tree_generic.h"

struct interval_tree_node *
interval_tree_subtree_search( 
		struct interval_tree_node *, 
		unsigned long, unsigned long);


typedef struct
{
	unsigned long  start;
	unsigned long  last;
	unsigned long  __subtree_last;
	int  color;
} INFO;

void __display( struct rb_node *temp, 
		  INFO (*a)[10], int *row, int *col )
{
	struct interval_tree_node *s;
	int i;
	if( temp==0 ) 
		return;

	++*row;
	__display( temp->rb_left,a,row,col );
	s = rb_entry( temp, struct interval_tree_node, rb );
	a[*row][*col].color=rb_color(temp);
	a[*row][*col].start=s->start;
	a[*row][*col].last=s->last;
	a[*row][(*col)++].__subtree_last=s->__subtree_last;
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
			if( a[i][j].__subtree_last  )
			{
				if( a[i][j].color == RB_RED )
					printf("<%2lu,%2lu,%2lu>", 
							a[i][j].start, a[i][j].last,
							a[i][j].__subtree_last);
				else
					printf("[%2lu,%2lu,%2lu]", 
							a[i][j].start, a[i][j].last,
							a[i][j].__subtree_last);
			}
			else
				printf("%10c", ' ');
		}
		printf("\n");
	}
	getchar();
}

int main()
{
	struct rb_root root = {0};
	int i, index;
	struct interval_tree_node *temp;
	struct interval_tree_node nodes[] = {
		{{0,},17,19,},
		{{0,}, 5,11,},
		{{0,},22,23,},
		{{0,}, 4, 8,},
		{{0,},15,18,},
		{{0,}, 7,10,}
	};
	display(&root);
	for(i=0; i<6; i++ )
	{
		interval_tree_insert( nodes+i, &root );
		display(&root);
	}
	temp = interval_tree_subtree_search( nodes, 12, 16 );
	if( temp )
		printf("%lu,%lu 구간과 겹치는 구간은 %lu,%lu 입니다\n", 12UL, 16UL, temp->start, temp->last);
	else
		printf("%lu,%lu 구간과 겹치는 구간은 없습니다.\n",
				12UL, 16UL); 
	return 0;
}













