#include <stdio.h>
#include ".\layout.h"

main(){
	
	int n,c,d;
	
	header("AULA 03 / EXERCICIO 03","1.0","*",70);		
	
	printf("Digite um numero inteiro de 3 algarismos: ");
	scanf("%d",&n);
	
	if ((n < 0) || (n > 999 ))
	{
		printf("Numero invalido!");		
		goto fim;
	}
	
	c = n-(n % 100);
	d = (n-c)-(n % 10);	
	
	printf("\nCentena: %d",c);
	printf("\nDezena: %d",d);
	printf("\nUnidade: %d",n -(c+d));	
	
	fim:
	trailer("FIM DO PROCESSAMENTO EXERCICIO 03",true,"Exer7.exe","*",70);	
}
