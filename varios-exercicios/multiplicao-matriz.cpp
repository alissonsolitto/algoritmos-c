#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
#include<windows.h>


main(){

  int a[3][2], b[2][3];
  
  printf("MATRIZ A: \n");
  
  for(int i = 0; i < 3; i++)
  {
  	for(int j = 0; j < 2; j++)
  	{
  	  Sleep(1342);
  	  srand((unsigned)time(NULL));
  	  
  	  a[i][j] = (rand() % 100);
  	  
  	  printf("\nA[%d][%d] = %d",i+1,j+1,a[i][j]);
  	}
  }
  
  printf("\n\n\nMATRIZ B: \n");
  
  for(int i = 0; i < 2; i++)
  {
  	for(int j = 0; j < 3; j++)
  	{
  	  Sleep(1342);
  	  srand((unsigned)time(NULL));
  	  
  	  b[i][j] = (rand() % 100);
  	  
  	  printf("\nB[%d][%d] = %d",i+1,j+1,b[i][j]);
  	}
  }
  
  printf("\n\n\nMULTIPLICACAO DAS MATRIZES: \n");
  
  for(int i = 0; i < 3; i++)
  {
  	for(int j = 0; j < 2; j++)
  	{
  	  for(int k = 0; k < 3; k++)
		
		sum = sum + (a[i][j] * b[j][i]);
  	  
  	  
  	  
  	  
  	  
  	}
  }


  getch();
}

