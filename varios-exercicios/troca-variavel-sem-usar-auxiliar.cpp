#include <stdio.h>
#include ".\layout.h"

main(){
	
	int a,b;
	
	header("AULA 03 / EXERCICIO 04","1.0","*",70);		
	
	printf("Digite um valor para variavel A: ");
	scanf("%d",&a);
	
	printf("Digite um valor para variavel B: ");
	scanf("%d",&b);	
	
	a = a + b;
	b = a - b;
	a = a - b;	
	
	printf("Valor de A = %d \nValor de B = %d",a,b);	
	
	trailer("FIM DO PROCESSAMENTO EXERCICIO 04",true,"Exer8.exe","*",70);	
}
