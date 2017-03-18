#include <stdio.h>
#include ".\layout.h"

main(){
	
	//variavel
	int ang;
	
	header("AULA 02 / EXERCICIO 01","1.0","*",70);
	
	printf("Digite um angulo: ");
	scanf("%d",&ang);
	
	if (ang > 360);
	  ang = ang % 360;
	  
	if (ang <= 90)  {
	  printf("Primeiro quadrante");}
	else if(ang <=180)  {
	  printf("Segundo quadrante");}
	else if(ang <=270)  {
	  printf("Terceiro quadrante");}
	else if(ang <=360)  {
	  printf("Quarto quadrante");  }
	  
	
	
	
	
	trailer("FIM DO PROCESSAMENTO EXERCICIO 01",true,"Exer01.exe","*",70);
	
}
