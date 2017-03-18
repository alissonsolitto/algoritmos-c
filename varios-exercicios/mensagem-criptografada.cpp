#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <String.h>
#include ".\layout.h"

#define ARQ ".\\Mensagem.dat"
#define BAK ".\\Mensagem.bak"

FILE *fp;

char alfabeto[26] = {'A' , 'B' , 'C' , 'D' , 'E' , 'F' , 'G' , 'H' , 'I' , 'J' , 'K' , 'L' , 'M' , 'N' , 'O' , 'P' , 'Q' , 'R' , 'S' , 'T' , 'U' , 'V' , 'W' , 'X' , 'Y' , 'Z'};

typedef struct Pessoa
{
	char st;
	char nome  [30];
	char email [100];
	char msg   [1000];
	char cMsg  [1000];
};


void cadastrar(Pessoa p)
{
	fseek(fp,0,SEEK_END); //Posiciona no final do arquivo
	fwrite(&p, sizeof(Pessoa), 1, fp);
	
	printf("\n Registro cadastrado com sucesso!");
}

void listar()
{
  Pessoa p;
	int total = 0;
	
	fseek(fp,0,SEEK_SET); //Posiciona no inicio do arquivo

	printf("\n**************** RELATORIO ****************\n");

	while((fread(&p, sizeof(Pessoa), 1, fp)) == 1 )
	{
		if(p.st != '*')
		{
		  printf("Nome:....................... %s\n", &p.nome);
			printf("E,Mail:..................... %s\n", &p.email);
	    printf("Mensagem:................... %s\n", &p.msg);
	    total++;
    }
	}
 	printf("**************** %d Iten(s) ****************", total);
}

Pessoa consultar(char nome[30], char email[100])
{
	Pessoa p;
	Pessoa aux;
	
	fseek(fp,0,SEEK_SET); //Posiciona no inicio do arquivo

	while((fread(&p, sizeof(Pessoa), 1, fp)) == 1 )
	{
		if ((strcmp(p.nome, nome) == 0) && (strcmp(p.email, email) == 0))
		{
		  if(p.st != '*')
			{
			  aux = p;
			  break;
			}
		}
	}
	return aux;
}

void excluir(char nome[30], char email[100])
{
	Pessoa p;
	int opcao = 0;
	long int pos = 0;
	
	p = consultar(nome, email);
	
	if (strlen(p.nome) > 0)
	{
		printf("\nA busca encontrou o seguinte registro:\n");
		printf("Nome:....................... %s\n", &p.nome);
		printf("E-Mail:..................... %s\n", &p.email);

		printf("Deseja realmente excluir o registro?(0 - Nao / 1 - Sim) \n");
		scanf("%d", &opcao);

		if(opcao == 1)
		{
			pos  = ftell(fp);
			pos -= sizeof(p);
			fseek(fp, pos, SEEK_SET);
			p.st = '*';
			fwrite(&p, sizeof(p), 1, fp);
			
			printf("\nRegistro excluido com sucesso!");
		}
	}else
	  printf("Nao foi encontrado nenhum registro para exclusao");
}

void atualizar(char nome[30], char email[100])
{
	Pessoa p;
	long int pos = 0;

	p = consultar(nome, email);
	
	if (strlen(p.nome) > 0)
	{
		printf("Digite o novo nome:");
		fflush(stdin);
		scanf("%s", &p.nome);

		printf("Digite o novo e-mail:");
		fflush(stdin);
		scanf("%s", &p.email);

		printf("Digite a nova mensagem:");
		fflush(stdin);
		scanf("%s", &p.msg);

  	pos  = ftell(fp);
		pos -= sizeof(p);
		fseek(fp, pos, SEEK_SET);
		

		fwrite(&p, sizeof(p), 1, fp);
		
		printf("\nRegistro atualizado com sucesso!");
	}
	else
		printf("Nao foi encontrado nenhum registro para alteracao");
}

void reorganizar()
{
	FILE *bak;
	Pessoa p;
	
	fseek(fp,0,SEEK_SET); //Posiciona no inicio do arquivo
	
	bak = fopen(BAK, "wb");
	
	while((fread(&p, sizeof(Pessoa), 1, fp)) == 1)
	{
		if(p.st != '*')
		{
		  fwrite(&p, sizeof(Pessoa), 1, bak);
    }
	}

	fclose(bak);
	fclose(fp);
	remove(ARQ);
	rename(BAK,ARQ);
}

void criptografar(Pessoa p)
{
	char chave[100];
	char mensagemCri[1000];
	int tamChave = 0, aux = 0, posMsg = 0, posChave = 0;
	long int pos = 0;

	
	printf("Digite uma palavra chave para criptografar: ");
	fflush(stdin);
	scanf("%s", &chave);
	
	strupr(chave);
	tamChave = strlen(chave);
	
	for(int i = 0; i < strlen(p.msg); i++)
	{
		
		for(int j = 0; j < 26; j++)
		{
			if (chave[aux] == alfabeto[j])
			{
				posChave = j + 1;
			  break;
			}
		}
		
		for(int j = 0; j < 26; j++)
		{
			if (p.msg[i] == alfabeto[j])
			{
				posMsg = j + 1;
			  break;
			}
		}
		
		posMsg = posMsg + posChave;
		if (posMsg > 26)
		{
			posMsg = posMsg - 26;
		}
		
		p.cMsg[i] = alfabeto[posMsg - 1];
		
		aux++;
		if(aux == tamChave)
			aux = 0;
	}

	pos  = ftell(fp);
	pos -= sizeof(p);
	fseek(fp, pos, SEEK_SET);

	fwrite(&p, sizeof(p), 1, fp);
}

main()
{
	Pessoa p;
	int op = 99;
	char nome  [30];
	char email [100];
	
	//Inicia o arquivo
	if ((fp = fopen(ARQ,"rb+")) == NULL)
	{
    if ((fp = fopen(ARQ,"wb")) == NULL)
		{
		  printf("Erro ao criar o arquivo");
		  exit(1);
		}
		fclose(fp);
		fp = fopen(ARQ,"rb+");
	}
	
	header("GERENCIADOR DE MENSAGENS","1.0","*",70);
	
	puts("0 - Cadastrar");
	puts("1 - Listar");
	puts("2 - Consultar");
	puts("3 - Alterar");
	puts("4 - Remover");
	puts("5 - Reorganizar");
	
	puts("6 - Criptografar");
	puts("7 - Descriptografar\n");
	
	printf("Escolha uma opcao: ");
	scanf("%d", &op);
	
	if(op == 0)
	{
	  p.st = ' ';
		printf("Digite o novo nome: ");
		fflush(stdin);
		scanf("%s", &p.nome);

		printf("Digite o novo e-mail: ");
		fflush(stdin);
		scanf("%s", &p.email);

		printf("Digite a nova mensagem: ");
		fflush(stdin);
		scanf("%s", &p.msg);
		
		//criptografar mensagem e gravar.
		
		cadastrar(p);
	}
	else if(op == 1)
	{
		listar();
	}
	else if(op == 2)
	{
		printf("Digite o nome: ");
		fflush(stdin);
		scanf("%s", &nome);

		printf("Digite o e-mail: ");
		fflush(stdin);
		scanf("%s", &email);
		
		p = consultar(nome, email);
		
		if(strlen(p.nome) > 0)
		{
			printf("\nA busca encontrou o seguinte registro:\n");
			printf("Nome:....................... %s\n", &p.nome);
			printf("E-Mail:..................... %s\n", &p.email);
	    printf("Mensagem:................... %s\n", &p.msg);
		}
		else
			printf("\nNao foi encontrado nenhum registro registro");
	}
	else if((op == 3) || (op == 4))
	{
		printf("Digite o nome: ");
		fflush(stdin);
		scanf("%s", &nome);

		printf("Digite o e-mail: ");
		fflush(stdin);
		scanf("%s", &email);
		
		if(op == 3)
		  atualizar(nome, email);
		else
			excluir(nome, email);
	}
	else if (op == 5)
	{
		reorganizar();
	}
	else if(op == 6)
	{
		printf("Digite o nome: ");
		fflush(stdin);
		scanf("%s", &nome);

		printf("Digite o e-mail: ");
		fflush(stdin);
		scanf("%s", &email);

		p = consultar(nome, email);
		
		if(strlen(p.nome) > 0)
			criptografar(p);
		else
			printf("Nao foi encontrada nenhuma pessoa");
	
	}else if(op == 7)
	{
		printf("Digite o nome: ");
		fflush(stdin);
		scanf("%s", &nome);

		printf("Digite o e-mail: ");
		fflush(stdin);
		scanf("%s", &email);

		p = consultar(nome, email);
		
		if(strlen(p.nome) > 0)
		{
	    printf("\nMensagem:................... %s\n", &p.msg);
	    printf("Mensagem Criptografada:..... %s\n\n", &p.cMsg);
		}
	}

  //Fecha o arquivo
	fclose(fp);

	getch();
}
