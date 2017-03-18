#include <stdio.h>
#include ".\layout.h"

main(){

  int maior,id,soma;

  maior = 0;
  id    = 0;
  soma  = 0;

  header("LISTA 02 / EXERCICIO 03","1.0","*",70);

  do{
	printf("Digite uma idade: ");
	scanf("%d",&id);

	if (id > maior) maior = id;
    soma += id;

  }while(id > 0);

  printf("A soma das idades e: %d \nA maior idade e: %d",soma,maior);

  trailer("FIM DO PROCESSAMENTO EXERCICIO 03",true,"List2Exer1.exe","*",70);

}
