#include <stdio.h>
#include <conio.h>

main(){
	
  int num[3];
  int i = 1;
  
  for (i=0; i<3; i++)
  {
  	printf("%d\n",i);
  	
  	printf("Digite o %d lado do triangulo: ",i);
  	scanf("%d",&num[i]);
  }
  
  
  
  
  if ((num[0] < num[2] + num[1]) || (num[2] < num[0] + num[1]) || (num[1] < num[2] + num[0]))
  {
  	  if ((num[0] == num[2]) && (num[2] == num[1]))
	  {
	  	printf("O triangulo e equilatero");
	  }
	  else if ((num[0] == num[2]) || (num[0] == num[1]) || (num[2] == num[1]))
	  {
	  	printf("O triangulo e isoceles");
	  }
	  else{
	  	printf("O triangulo e escaleno");
	  }
	            
  }else printf("Digite uma medida para o lado valida");  	
  
  getch();
  
  
  
	
}
