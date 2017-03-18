#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <windows.h>
#include <unistd.h>
#include <stdlib.h>

void header(char *nm_programa, char *versao, char *simb, const int ast)
{
  int tam = 0;
  int pos = 0;
  int i   = 0;
  
  tam = strlen(nm_programa);
  pos = (ast - tam) / 2;	
	
  for (i = 0;i <= ast; i++)
  {
  	printf(simb);
  }
  
  printf("\n");    
    
  for (i = 0;i <= ast; i++)
  {
  	  printf(simb);
  	  
  	  if (i == pos)
  	  {
  	  	printf(" %s ",nm_programa);  	  	
  	  	i = i + tam + 2;
  	  }			  
  }

  printf("\n");
  
  tam = strlen(versao);
  pos = (ast - (tam + 8));
  
  for (i = 0;i <= ast; i++)
  {
  	printf(simb);
  	
  	if (i == pos) 
	{
	  printf(" Versao %s \n \n",versao); 
	  break;
    }
  	
  }    
}

void trailer(char *mensagem,bool reiniciar,char *exe, char *simb, const int ast)
{
  //Recuperando o diretorio corrente.
  char currentDirectory [MAX_PATH]; 
  GetCurrentDirectory (MAX_PATH, currentDirectory); 
  
  char program[500];    
  int tam = 0;
  int pos = 0;
  int i   = 0;
  char resp[1];
  
  tam = strlen(mensagem);
  pos = (ast - tam) / 2;
  
  printf("\n \n");	
	
  for (i = 0;i <= ast; i++)
  {
  	printf(simb);
  }
  
  printf("\n");    
    
  for (i = 0;i <= ast; i++)
  {
  	  printf(simb);
  	  
  	  if (i == pos)
  	  {
  	  	printf(" %s ",mensagem);  	  	
  	  	i = i + tam + 2;
  	  }			  
  }
  
  printf("\n");
  
  for (i = 0;i <= ast; i++)
  {
  	printf(simb);
  }  
  
  printf("\n");   
 
  pos = (ast - 62) / 2;  	
  
  if (reiniciar)
  {
  	if (pos > 0)
  	{  	
      for (i = 1;i <= ast; i++)
      {
  	    printf(simb);
  	    if (i == pos)
  	    {  	    
  	      printf(" Deseja executar novamente o programa? ('S' - Sim / 'N' - Nao) ")	;
  	      i = i + 62;
  	    }
      }  
    }else 
	  printf("Deseja executar novamente o programa? ('S' - Sim / 'N' - Nao)");
	  printf("\n");
	  
	scanf("%s",&resp); 
	
	if (stricmp (resp, "S") == 0) 
	{
      system("cls");//limpa tela
	  snprintf(program, 500, "%s\\%s", currentDirectory, exe);//concatena string
	 	  
      execl(program,0);//executa programa
	}		
  } else getch(); 
  
}
