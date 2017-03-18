#include <stdio.h>
#include ".\layout.h"

main(){
	
	int num[3];
	int i,maior;	
	
	header("AULA 04 / EXERCICIO 04","1.0","*",70);	
		
	for (i = 1;i <= 3; i++)
	{
		printf("Digite o %d numero: ",i);
		scanf("%d",&num[i]);
	}
	
	for (i = 1;i <= 3; i++ )
	{
		if (num[i] > num[i+1])
		  maior = num[i];
	}	
	
	printf("\nO maior numero entre os digitados e : %d",maior);		
	
	trailer("FIM DO PROCESSAMENTO EXERCICIO 04",true,"Exer11.exe","*",70);	
	
	
}
