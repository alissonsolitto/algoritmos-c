#include <stdio.h>
#include ".\layout.h"

main(){
	
	float gas,aut,vig,gasto,preco;
	
	header("VIAGEM","1.0","*",70);
	
	printf("Digite o preco do combustivel: ");
	scanf("%f",&gas);
	
	printf("Digite a autonomia do carro km/l: ");
	scanf("%f",&aut);	
	
	printf("Digite a distancia da viagem: ");
	scanf("%f",&vig);	
	
	gasto = 2*(vig / aut);
	preco = 2*(gasto * gas);
	
	printf("Litos: %0.2f \nPreco: %0.2f",gasto,preco);
	
	
	trailer("FIM DO PROCESSAMENTO",true,"Exer2.exe","*",70);
	
}
