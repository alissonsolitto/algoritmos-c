#include <stdio.h>
#include ".\layout.h"

main(){
	
  float soma;
  int n,i;

  i    = 1;
  soma = 0;

  header("LISTA 02 / EXERCICIO 01","1.0","*",70);

  do{
    printf("Digite um numero: ");
    scanf("%d",&n);

	if (n <= 0){
      printf("\nNumero invalido !");
      system("cls");
      header("LISTA 02 / EXERCICIO 01","1.0","*",70);
	} 

  }while(n <= 0);


  while (i <= n){
    soma += (1.00 / i);
	printf("%d",i);
    i++;
  }

  printf("\nA soma e: %f", soma);

  trailer("FIM DO PROCESSAMENTO EXERCICIO 01",true,"List2Exer1.exe","*",70);
	
}
