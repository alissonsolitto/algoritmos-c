#include <stdio.h>
#include ".\layout.h"

main(){
	
	int i,a,calc;
	
	i = 0;
	calc = 0;
	
	header("AULA 06 / EXERCICIO 04","1.0","*",70);
	
	printf("Digite um numero: ");
	scanf("%d",&a);
	
	while(i < a)
	{
		calc += (i+1);		
		i++;		
	}
	
	printf("Total e : %d",calc);
	
	trailer("FIM DO PROCESSAMENTO EXERCICIO 04",true,"Aula6_Exer4.exe","*",70);
	
}
