#include <stdio.h>
#include <stdlib.h>

typedef struct _node
{
	int data;
	struct _node *left;
	struct _node *right;
} NODE;

NODE *root;

void __display( NODE *temp, 
		  int (*a)[10], int *row, int *col )
{
	int i;
	if( temp==0 ) 
		return;

	++*row;
	__display( temp->left,a,row,col );
	a[*row][(*col)++]=temp->data;
	__display( temp->right,a,row,col );
	--*row;
}


void display( NODE *temp )
{
	int row=-1;
	int col=0;
	int a[10][10]={0,};      
	int i,j;
	__display(temp,a,&row,&col);
	system("clear");
	for(i=0; i<10; i++ )
	{
		for(j=0; j<10; j++ )
		{
			if( a[i][j] )
				printf("%4d", a[i][j]);
			else
				printf("%4c", ' ');
		}
		printf("\n");
	}
	getchar();
}

void insert_data(int data)
{
	NODE *temp;
	NODE *p=root;
	NODE *prev;
	temp=malloc(sizeof(NODE));
	temp->data = data;
	temp->left = 0;
	temp->right = 0;
	if( root == 0 )
	{
		root = temp;
		return;
	}
	while(p)
	{
		prev = p;
		if( p->data > data )
			p=p->left;
		else if( p->data < data )
			p=p->right;
		else
			return;
	}
	if( prev->data > data )
		prev->left = temp;
	else
		prev->right = temp;
}

int main()
{
	int a[] = {4,2,1,3,6,5,7};
	int i;
	display( root );
	for(i=0; i<7; i++ )
	{
		insert_data( a[i] );
		display( root );
	}
	return 0;
}













