#include <stdio.h>
#include ".\layout.h"

main(){

	float nota;	
		
	header("*","1.0","*",70);
	
	do{
		
		printf("\nDigite uma nota:");
		scanf("%f",&nota);
		
		if (!(nota >= 0 && nota <=10))
		{
			printf("\nNota invalida");
		}else 
		  printf("\nNota valida");		
		
	}while(nota < 0 || nota > 10);
	
	printf("\nA nota digitada foi:  %0.2f",nota);
	
	trailer("*",true,"Exer20.exe","*",70);
	
}
