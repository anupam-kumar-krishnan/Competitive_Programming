#include<stdio.h>
#include<stdlib.h>


void inputmatrix(int A[][10], int row, int column) 
{

   printf("\nENTER EKEMENT OF MATRIX: \n");

   for (int i = 0; i < row; ++i) {
      for (int j = 0; j < column; ++j) {
         printf("Enter a[%d][%d]: ", i + 1, j + 1);
         scanf("%d", &A[i][j]);
      }
   }
}

void display(int C[][10], int row, int column) 
{

   printf("\nMATRIX MULTIPLICATION:\n");
   for (int i = 0; i < row; ++i) {
      for (int j = 0; j < column; ++j) {
         printf("%d ", C[i][j]);
         if (j == column - 1)
            printf("\n");
      }
   }
}

void naive(int A[][10], int B[][10], int C[][10], int r1, int c1, int r2, int c2) 
{
   for (int i = 0; i < r1; ++i) {
      for (int j = 0; j < c2; ++j) {
         C[i][j] = 0;
      }
   }

   for (int i = 0; i < r1; ++i) 
   {
      for (int j = 0; j < c2; ++j) 
      {
         for (int k = 0; k < c1; ++k) 
         {
            C[i][j] += A[i][k] * B[k][j];
         }
      }
   }
}

void vsqmatmul()
{
      int a[5][5], b[5][5], c[5][5], i, j;
  int m1, m2, m3, m4 , m5, m6, m7;
 
  for(i = 0;i < 2; i++)
    {
        for(j = 0;j < 2; j++)
        {
            printf("a[%d][%d]=",i+1,j+1);
            scanf("%d", &a[i][j]);
        }
         
    }

  for(i = 0; i < 2; i++)
    { 
        for(j = 0;j < 2; j++)
        {  
            printf("b[%d][%d]=",i+1,j+1);
            scanf("%d", &b[i][j]);
        }
    }
  printf("\nYOUR FIRST MATRIX IS:-\n");
  for(i = 0; i < 2; i++)
  {
      printf("\n");
      for(j = 0; j < 2; j++)
      {
           printf("%d\t", a[i][j]);
      }
  }

  printf("\nYOUR SECOND MATRIX IS:-\n");
  for(i = 0;i < 2; i++)
  {
      printf("\n");
      for(j = 0;j < 2; j++)
      {
           printf("%d\t", b[i][j]);
      }
  }

  m1= a[0][0] * (b[0][1] - b[1][1]);
  m2= (a[0][0] + a[0][1]) * b[1][1];
  m3= (a[1][0] + a[1][1]) * b[0][0];
  m4= a[1][1] * (b[1][0] - b[0][0]);
  m5= (a[0][0] + a[1][1]) * (b[0][0] + b[1][1]);
  m6= (a[0][1] - a[1][1]) * (b[1][0]+b[1][1]);
  m7= (a[1][0] - a[0][0]) * (b[0][0]+b[0][1]);
 

  c[0][0] = m5 + m4- m2 + m6;
  c[0][1] = m1 + m2;
  c[1][0] = m3 + m4;
  c[1][1] = m1 - m3 + m5 + m7;

   printf("\nAfter multiplication using Strassen's algorithm \n");
   for(i = 0; i < 2 ; i++){
      printf("\n");
      for(j = 0;j < 2; j++)
      {
           printf("%d\t", c[i][j]);
           }
   }


}

int main()
{
   int x, A[10][10], B[10][10], C[10][10], r1, c1, r2, c2;
   do 
   {
      printf("\n1.***Matrix multiplication using Naive Approach***:-\n");
      printf("2.***Matrix Multiplication using VALKNER STRASSEN METHOD***:-\n");
      scanf("%d",&x);
      switch (x)
      {
      case 1:
      printf("Enter rows and column for the **FIRST** matrix: ");
      scanf("%d %d", &r1, &c1);
      printf("Enter rows and column for the **SECOND** matrix: ");
      scanf("%d %d", &r2, &c2);
      while (c1 != r2) 
      {
         printf("Error! Enter rows and columns again.\n");
         printf("Enter rows and columns for the first matrix: ");
         scanf("%d%d", &r1, &c1);
         printf("Enter rows and columns for the second matrix: ");
         scanf("%d%d", &r2, &c2);
      }
      inputmatrix(A, r1, c1);
      inputmatrix(B, r2, c2);
      naive(A, B, C, r1, c1, r2, c2);
      display(C, r1, c2);
      break;
      case 2:
      vsqmatmul();
      break;
      }

   }while (x < 3);
   return 0;
}