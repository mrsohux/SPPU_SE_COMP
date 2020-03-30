

/* Write C/C++ program for storing matrix. Write functions for
a) Check whether given matrix is upper triangular or not
b) Compute summation of diagonal elements
c) Compute transpose of matrix
d) Add, subtract and multiply two matrices */

#include<stdio.h>
#include<stdlib.h>

void matrixAdd();
void matrixSub();
void matrixMul();
void matrixTrans();
void upperMatrix();
void diagonalSum();

int matrixa[10][10],matrixb[10][10];
int main()
{
        int i,j,ch;
	printf("\nEnter elements of matrix A :\n");
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			scanf("%d",&matrixa[i][j]);
		}
	}
	printf("\nEntered elements of matrix A :\n");
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			printf("\t%d",matrixa[i][j]);
		}
		printf("\n");
	}
	printf("\nEnter elements of matrix B :\n");
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			scanf("%d",&matrixb[i][j]);
		}
	}
	printf("\nEntered elements of matrix B :\n");
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			printf("\t%d",matrixb[i][j]);
		}
		printf("\n");
	}
		
	while(1)
	{
		printf("\n----------Menus----------\n1.Add two matrices\n2.Subtract two matrices\n3.Multiply two matrices\n4.Compute transpose of matrix\n5.Compute summation of diagonal elements\n6.Check whether given matrix is upper triangular or not \n7.Exit");
		printf("\nEnter ur choice :");
		scanf("%d",&ch);

		switch(ch)
		{
			case 1:
				matrixAdd();
				break;
			case 2:
				matrixSub();
				break;
			case 3:
				matrixMul();
				break;
			case 4:
				matrixTrans();
				break;
			case 5:
				diagonalSum();
				break;
			case 6:
				upperMatrix();
				break;
			case 7:
				exit(0);
		}
	}
return 0;
}
//definition for Add two matrices
void matrixAdd()
{
	int c[3][3],i,j;
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			c[i][j]=matrixa[i][j]+matrixb[i][j];
		}
	}
	printf("\nAddition of matrix A & B is = :\n");
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			printf("\t%d",c[i][j]);
		}
		printf("\n");
	}
}
//definition for Subtract two matrices
void matrixSub()
{
	int c[3][3],i,j;
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			c[i][j]=matrixa[i][j]-matrixb[i][j];
		}
	}
	printf("\nSubstraction of matrix A & B is = :\n");
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			printf("\t%d",c[i][j]);
		}
		printf("\n");
	}
}
//definition for Multiply two matrices
void matrixMul()
{
	int c[3][3],i,j,k;
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			c[i][j]=0;
                   	for(k=0;k<3;k++)
			{
				c[i][j]=c[i][j]+ (matrixa[i][k]*matrixb[k][j]);
			}
		}
	}
	printf("\nMultiplication of matrix A & B is = :\n");
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			printf("\t%d",c[i][j]);
		}
		printf("\n");
	}
}

//definition for Check whether given matrix is upper triangular or not (Matrix A)
void upperMatrix()
{
	int i,j,flag;
	for(i=0; i<3; i++)
	{
		for(j=0; j<3; j++)
	        {
	         	if(i>j && matrixa[i][j]==0)
	            	{
	            		flag=0;
	            	}
	        }
	}
	if(flag==0)
	{
		printf("\nGiven First matrix is Upper Triangular Matrix :\n\n");
		for(i=0;i<3;i++)
		{
			for(j=0;j<3;j++)
			{
				printf("\t%d",matrixa[i][j]);
			}
			printf("\n");
		}
	}
	else
		printf("\nGiven First matrix is Not Upper Triangular Matrix :\n\n");
}

//definition for Compute summation of diagonal elements from matrix A
void diagonalSum()
{
	int sum=0,i,j;
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			if(i==j)
			{
				sum=sum+matrixa[i][j];
			}
		}
	}
	printf("\nsummation of diagonal elements is :=  %d",sum);	
}

//definition for Compute transpose of matrix A
void matrixTrans()
{
	int t[3][3],i,j;

	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			t[j][i]=matrixa[i][j];
		}
	}

	printf("\nTranspose of matrix A :\n");
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			printf("\t%d",t[i][j]);
		}
		printf("\n");
	}
}

/* ************************ OUTPUT *************************************************
[student@localhost ~]$ g++ matrix_add.c
[student@localhost ~]$ ./a.out

Enter elements of matrix A :
1
2
3
0
5
6
0
0
4

Entered elements of matrix A :
	1	2	3
	0	5	6
	0	0	4

Enter elements of matrix B :
1
2
3
4
5
6
7
8
9

Entered elements of matrix B :
	1	2	3
	4	5	6
	7	8	9

----------Menus----------
1.Add two matrices
2.Subtract two matrices
3.Multiply two matrices
4.Compute transpose of matrix
5.Compute summation of diagonal elements
6.Check whether given matrix is upper triangular or not 
7.Exit
Enter ur choice :1

Addition of matrix A & B is = :
	2	4	6
	4	10	12
	7	8	13

----------Menus----------
1.Add two matrices
2.Subtract two matrices
3.Multiply two matrices
4.Compute transpose of matrix
5.Compute summation of diagonal elements
6.Check whether given matrix is upper triangular or not 
7.Exit
Enter ur choice :2

Substraction of matrix A & B is = :
	0	0	0
	-4	0	0
	-7	-8	-5

----------Menus----------
1.Add two matrices
2.Subtract two matrices
3.Multiply two matrices
4.Compute transpose of matrix
5.Compute summation of diagonal elements
6.Check whether given matrix is upper triangular or not 
7.Exit
Enter ur choice :3

Multiplication of matrix A & B is = :
	30	36	42
	62	73	84
	28	32	36

----------Menus----------
1.Add two matrices
2.Subtract two matrices
3.Multiply two matrices
4.Compute transpose of matrix
5.Compute summation of diagonal elements
6.Check whether given matrix is upper triangular or not 
7.Exit
Enter ur choice :4

Transpose of matrix A :
	1	0	0
	2	5	0
	3	6	4

----------Menus----------
1.Add two matrices
2.Subtract two matrices
3.Multiply two matrices
4.Compute transpose of matrix
5.Compute summation of diagonal elements
6.Check whether given matrix is upper triangular or not 
7.Exit
Enter ur choice :5

summation of diagonal elements is :=  10
----------Menus----------
1.Add two matrices
2.Subtract two matrices
3.Multiply two matrices
4.Compute transpose of matrix
5.Compute summation of diagonal elements
6.Check whether given matrix is upper triangular or not 
7.Exit
Enter ur choice :6

Given First matrix is Upper Triangular Matrix :

	1	2	3
	0	5	6
	0	0	4

----------Menus----------
1.Add two matrices
2.Subtract two matrices
3.Multiply two matrices
4.Compute transpose of matrix
5.Compute summation of diagonal elements
6.Check whether given matrix is upper triangular or not 
7.Exit
Enter ur choice :7
[student@localhost ~]$ 
*/

