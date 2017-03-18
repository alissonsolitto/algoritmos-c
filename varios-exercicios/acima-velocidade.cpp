#include <stdio.h>
#include ".\layout.h"

main(){
	
	int vel,car;
	
	header("AULA 02 / EXERCICIO 03","1.0","*",70);
	
	printf("Digite a velocidade maxima da rodovia: ");
	scanf("%d",&vel);
	
	printf("Digite a velocidade que o veiculo esta transitando: ");
	scanf("%d",&car);
	
	if(car > vel)
	{
		printf("O carro esta acima da velocidade permitida na rodovia. Multado!!");
	}
	
	trailer("FIM DO PROCESSAMENTO EXERCICIO 03",true,"Exer12.exe","*",70);
	
}

