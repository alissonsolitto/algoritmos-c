#include <stdio.h>
#include ".\layout.h"

main(){
	
	float b,n,v, total;
	
	header("TOTAL DE ELEITORES","1.0","*",70);
	
	puts("Digite o total de votos brancos: ");
	scanf("%f",&b);
	
	puts("Digite o total de votos nulos: ");
	scanf("%f",&n);
	
	puts("Digite o total de votos validos: ");
	scanf("%f",&v);
	
	total = b + n + v;
	
	b = (b*100.00) / total;
	n = (n*100.00) / total;
	v = (v*100.00) / total;
	
	printf("Percentuais: \nVotos brancos: %0.4f \nVotos nulos: %0.4f \nVotos validos: %0.4f",b,n,v);	
	
	
	trailer("FIM DO PROCESSAMENTO",true,"Exer1.exe","*",70);
	
}
