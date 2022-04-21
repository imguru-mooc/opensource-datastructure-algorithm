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
	NODE **p=&root;
	temp=malloc(sizeof(NODE));
	temp->data = data;
	temp->left = 0;
	temp->right = 0;
	while(*p)
	{
		if( (*p)->data > data )
			p=&(*p)->left;
		else if( (*p)->data < data )
			p=&(*p)->right;
		else
			return;
	}
	*p = temp;
}

void __fill(NODE *temp, int *a, int *n)
{
	if( temp == 0 )
		return;
	__fill( temp->left , a, n);
	a[(*n)++] = temp->data;
	__fill( temp->right , a, n);
}

NODE* __bal(int *a, int n)
{
	int mid;
	NODE *temp;
	if( n <= 0 )
		return 0;
	mid = n/2;
	temp=malloc(sizeof(NODE));
	temp->data=a[mid];
	temp->left =__bal(a,mid);
	temp->right=__bal(a+mid+1,n-mid-1);
	return temp;
}

void bal( NODE *temp )
{
	int a[100];
	int n=0;
	__fill( temp, a, &n );
	root=__bal( a, n );
}

int main()
{
	int a[] = {7,6,5,4,3,2,1};
	int i;
	for(i=0; i<7; i++ )
		insert_data( a[i] );
	display( root );
	bal(root);
	display( root );
	return 0;
}













