#include <stdio.h>
#include <time.h>
#include ".\layout.h"

main(){
	
	int tipo,com;		
		
	header("EXERCICIO PPT","1.0","*",70);
	
    printf("\n1 - Papel");
    printf("\n2 - Pedra");
    printf("\n3 - Tesoura\n");
    
    scanf("%d",&tipo);
    
    srand( (unsigned)time(NULL) );

    com = 1 + (rand() % 3);
    
    printf("\n"); 
    
    if (com == 1) printf("Papel");
    if (com == 2) printf("Pedra");
    if (com == 3) printf("Tesoura");
    
    printf("\n");    
    
    if ((tipo == 1) && (com == 2))
      printf("Voce ganhou");
    else if ((tipo == 2) && (com == 3))
      printf("Voce ganhou");
    else if ((tipo == 3) && (com == 1))
      printf("Voce ganhou");
    else if (tipo == com)
      printf("Empate");	    
    else printf("Voce perdeu");
    
		
	trailer("FIM DO PROCESSAMENTO EXERCICIO PPT",true,"PPT.exe","*",70);
	
}
