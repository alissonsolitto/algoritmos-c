#include <stdio.h>
#include ".\layout.h"

main(){
	
	float c,l;
	
	header("AULA 02 / EXERCICIO 02","1.0","*",70);
	
	printf("Digite a largura do terreno: ");
	scanf("%f",&l);
	
	printf("Digite o comprimento do terreno: ");
	scanf("%f",&c);
	
	printf("A area do terreno e: %0.2f \nO perimetro do terreno e: %0.2f",(l*c),2*(l+c));
	
	trailer("FIM DO PROCESSAMENTO EXERCICIO 02",true,"Exer2.exe","*",70);	
}
