#include <stdio.h>
#include ".\layout.h"

main(){
	
	
	int i,a,maior;
	int num[3];
	
		
	header("EXERCICIO 15","1.0","*",70);
	
	for(i = 1; i <= 3; i++)
	{
		printf("Digite um numero: ");
		scanf("%d",&num[i]);		
	}
	
	for(a = 1; a <= 2; a++)
	{			
		for(i = 1; i <= 3; i++)
		{
			if (num[i] > num[i+1])
			{
				maior    = num[i+1];
				num[i+1] = num[i];
				num[i]   = maior;							
			}		
		}
    }
	
	for(i = 1; i <= 3; i++)
	{
		printf("\n%d",num[i]);
	}
	
	
	
	
	
	
	
	trailer("FIM DO PROCESSAMENTO EXERCICIO 15",true,"Exer15.exe","*",70);
	
}
