#include <stdio.h>
#include ".\layout.h"

main(){
	
	int t,h,m,s;
	
	header("AULA 03 / EXERCICIO 10","1.0","*",70);		
	
	printf("Digite um tempo em segundos: ");
	scanf("%d",&t);
	
	
	h = t / 3600;
	m = (t % 3600) / 60;
	s = (t % 3600) % 60;
	
	printf("Hora : %d \nMinuto: %d \nSegundo: %d",h,m,s);	
	
	trailer("FIM DO PROCESSAMENTO EXERCICIO 05",true,"Exer10.exe","*",70);	
}
