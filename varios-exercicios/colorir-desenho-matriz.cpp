#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define DIM 15

void PintaDesenho(char matrix[DIM][DIM], int linha, int coluna, char cor, int st_desenho)
{
	int e = 0,
			d = 0;

	if(matrix[linha][coluna] != '*')
	{
  	//percorre para a esquerda.
		for(int coluna_aux = coluna;coluna_aux >= 0; coluna_aux--)
		{
			if(matrix[linha][coluna_aux] == '*')
			{
				e = 1;
				break;
			}
		}
	
		//percorre para a direita.
		for(int coluna_aux = coluna;coluna_aux < DIM; coluna_aux++)
		{
			if(matrix[linha][coluna_aux] == '*')
			{
				d = 1;
				break;
			}
		}

		//pinta a matrix
		if((d == 1) && (e == 1))
		{
    	if (st_desenho == 1)
		    matrix[linha][coluna] = cor;
		}else
		{
    	if (st_desenho == 2)
		    matrix[linha][coluna] = cor;
		}
	}
	
	//define o que será preenchido:  1 - desenho; 2 - fundo;
	if(st_desenho == 0)
	{
		//volta para o começo da matrix
		linha  = 0;
		coluna = -1;
		
    if((d == 1) && (e == 1)) st_desenho = 1;
	  else
			st_desenho = 2;
	}

	if(st_desenho != 0)
	{
		if((coluna == DIM) && (linha < DIM))
		{
			coluna = -1; //porque coloco +1 na chamda da funcao
			linha++;
		}
		
		if((coluna != DIM) && (linha != DIM))
			PintaDesenho(matrix, linha, coluna + 1, cor, st_desenho);
	}
}

void Desenha(char matrix[DIM][DIM])
{
  for(int i = 0; i < DIM; i++)
	{
		for(int j = 0; j < DIM; j++)
		{
			printf("%c", matrix[i][j]);
		}

		printf("\n");
	}
}

main()
{
	char desenho[DIM][DIM] = {'.','.','.','.','.','.','.','.','.','.','.','.','.','.','.',
													  '.','.','*','*','*','*','*','*','*','*','*','*','.','.','.',
													  '.','.','*','.','.','.','.','.','.','.','.','*','.','.','.',
													  '.','.','*','.','.','.','.','.','.','.','.','*','.','.','.',
													  '.','.','*','.','.','.','.','.','.','.','.','*','.','.','.',
													  '.','.','*','.','.','.','*','*','*','*','*','*','.','.','.',
													  '.','.','*','.','.','.','*','.','.','.','.','.','.','.','.',
													  '.','.','*','.','.','.','*','*','*','*','*','*','*','*','.',
													  '.','.','*','.','.','.','.','.','.','.','.','.','.','*','.',
													  '.','.','*','.','.','.','.','.','.','.','.','.','.','*','.',
													  '.','.','*','.','.','.','.','.','.','.','.','.','.','*','.',
													  '.','.','*','.','.','.','.','.','.','.','.','.','.','*','.',
													  '.','.','*','*','*','*','*','*','*','*','*','*','*','*','.',
													  '.','.','.','.','.','.','.','.','.','.','.','.','.','.','.',
													  '.','.','.','.','.','.','.','.','.','.','.','.','.','.','.'};


	int linha  = 0,
			coluna = 0;
			
	char cor;
														
	//Desenha na tela
	Desenha(desenho);
	
	printf("Escolha uma cedula do desenho para ser preenchida!\n");
	
	printf("Digite a linha: ");
	scanf("%d", &linha);
	
	printf("Digite a coluna: ");
	scanf("%d", &coluna);
	
	printf("Digite o preenchimento: ");
	fflush(stdin);
	cor = getchar();
	
	if(desenho[linha][coluna] != '*')
	  PintaDesenho(desenho,linha,coluna,cor,0);
	else
		printf("Selecione uma cedula valida!");
	
	//Desenha na tela
	printf("\n\n");

  Desenha(desenho);

}
