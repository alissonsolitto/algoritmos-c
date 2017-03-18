#include <stdio.h>
#include ".\layout.h"

main(){
	
	float alt,peso;
	char sexo;
	
	header("AULA 05 / EXERCICIO 01","1.0","*",70);	
		
	
	printf("Digite a altura da pessoa: ");
	scanf("%f",&alt);
	
	printf("Digite o sexo da pessoa(M - Masculino / F - Feminino): ");
	scanf("%s",&sexo);
	
	if (sexo == 'M')
	{
		peso = (72.4 * alt) - 58;
	}else
	  peso = (62.1 * alt) - 44.7;
	
	printf("Seu peso ideal e: %0.2f",peso);
	
	
	
	trailer("FIM DO PROCESSAMENTO EXERCICIO 01",true,"Exer13.exe","*",70);	
	
	
}
