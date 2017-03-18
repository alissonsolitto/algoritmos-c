#include ".\layout.h"

main(){
	
	int intervalo,
	    inicial, 
		final, 
		divisor, 
		primo1, 
		primo2, 
		gemeos,
		erro;			
		
    header("Primos Gemeos","1.0","*",70);
    
	printf("Digite a quantidade de intervalos a ser verificado: ");
	scanf("%d", &intervalo);
	
	if ((intervalo <= 0) || (intervalo > 100))		
	{
	  printf("Numero de intervalos digitado invalido. O programa sera encerrado.");	  
    }
    else
	{
	    for(int i = 1; i <= intervalo; i++)
		{
		  primo1  = 0;
		  primo2  = 0;
		  gemeos  = 0;
		  divisor = 0;
		  erro    = 0;
		
		   do{	   
		       printf("\nIntervalo Inicial: ");
			   scanf("%d",&inicial);
			   
			   printf("Intervalo Final: ");
			   scanf("%d",&final);
			   
			   if((final - inicial <= 0) || (inicial < 0) || (final < 0))
		       {
		         printf("Intervalo invalido, por favor digite novamente um intervalo valido.\n");
				 erro = 1;		         
		       }else erro = 0; 
			   
		   }while(erro == 1);	 
		   
		   while (inicial <= final)
		   {
		   	  for(int j = 2;((j < inicial) && (divisor == 0)); j++ )
		   	  {
		   	  	 if(inicial % j == 0)
	               divisor++;
		   	  }
		   	  
		   	  if((primo1 == 0) && (divisor == 0)) 
		   	    primo1 = inicial;	   	  	
		   	  else if((primo2 == 0) && (divisor == 0)) 
			    primo2 = inicial;	   	  
		   	  
		   	  if((primo1 != 0) && (primo2 != 0))
		   	  {
		   	     if(primo2 - primo1	== 2) 
				   gemeos++;
				   	   	    
		   	     primo1 = primo2;
				 primo2 = 0; 	   	    
		   	  }
		   	
		   	  divisor = 0;
		   	  inicial++;
		   }
		   
		   printf("Quantidade de primos gemeos: %d \n",gemeos);
		}
    }

    trailer("FIM DO PROCESSAMENTO PRIMOS GEMEOS",true,"Projeto_01.exe","*",70);
}

