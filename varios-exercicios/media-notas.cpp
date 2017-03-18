#include <stdio.h>
#include ".\layout.h"

main(){
	
	float n1,n2;
	
	header("AULA 02 / EXERCICIO 01","1.0","*",70);	
	
	printf("Digite a primeira nota: ");
	scanf("%f",&n1);
	
	printf("Digite a segunda nota: ");
	scanf("%f",&n2);
	
	printf("A media entre as notas e: %0.2f",(n1+n2)/2);		
	
	trailer("FIM DO PROCESSAMENTO EXERCICIO 01",true,"Exer1.exe","*",70);	
}
