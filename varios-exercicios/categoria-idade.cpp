#include <stdio.h>
#include ".\layout.h"

main(){
	
	int i;
	char *cat;
	
	header("AULA 05 / EXERCICIO 02","1.0","*",70);	
		
	
	printf("Digite a idade da pessoa: ");
	scanf("%d",&i);
	
	if (i <= 8) cat = "Infantil A";
	else 
	  if (i < 13) cat = "Infantil B";
	else 
	  if (i < 18) cat = "Juvenil A"; 
	else
	  if (i < 21) cat = "Juvenil B";
	else 
	  cat = "Categoria Senior";
	  
	printf("A categoria e %s",cat);
	
	
	trailer("FIM DO PROCESSAMENTO EXERCICIO 02",true,"Exer14.exe","*",70);	
	
	
}
