#include <stdio.h>
#include ".\layout.h"

main(){
	
	float sal,per,novoSal;
	
	header("NOVO SALARIO","1.0","*",70);
	
	printf("Digite o salario do funcionario: ");
	scanf("%f",&sal);
	
	printf("Digite o percentual de aumento: ");
	scanf("%f",&per);	
	
	novoSal = (1+(per/100)) * sal;
			
	printf("Salario com reajuste e : %0.2f", novoSal);		
	
	trailer("FIM DO PROCESSAMENTO",true,"Exer2.exe","*",70);
	
}
