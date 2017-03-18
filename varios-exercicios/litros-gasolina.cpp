#include <stdio.h>
#include ".\layout.h"

main(){
	
	float gas,val;
	
	header("AULA 02 / EXERCICIO 03","1.0","*",70);
	
	printf("Digite a preco da gasolina: ");
	scanf("%f",&gas);
	
	printf("Digite o valor do pagamento: ");
	scanf("%f",&val);
	
	printf("O total de litros abastecido e: %0.2f",val/gas);
	
	trailer("FIM DO PROCESSAMENTO EXERCICIO 03",true,"Exer3.exe","*",70);	
}
