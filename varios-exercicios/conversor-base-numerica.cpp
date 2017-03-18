#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<conio.h>
#include<String.h>
#include ".\layout.h"

int base_dec(int num, int base)
{
	int cont   = 0,
	    resto  = 0,
			result = 0;
	
	while(num > 0)
	{
		resto = num % 10;
		result+= pow(resto*base, cont);
		num = num / 10;
		cont++;
	}
	
	return result;
}

int dec_base(int num, int base)
{
	int a[100],
			k      = 1,
			cont   = 0,
			result = 0;

	while(k > 0)
	{
	  a[cont] = num % base;
		k = num / base;
		num = k;
		cont++;
	}

	for(int i = 0; i < cont; i++)
	{
		result += pow(10, i) * a[i];
	}
	
	return result;
}

int base_base(int num, int base_inicial, int base_final)
{
	num = base_dec(num, base_inicial);

	return dec_base(num, base_final);
}

main()
{
	int opcao, num, base_inicial, base_final;

	header("CONVERSOR","1.4","*",70);
	
	puts("1 - Converter numero na base 'x' para a base decimal");
	puts("2 - Converter numero decimal para base 'x'");
	puts("3 - Converter numero de base 'x' para base 'y'");
	
	printf("\n\nEscolha uma das as opcoes acima:");
	scanf("%d", &opcao);
	
	if(opcao == 1)
	{
		printf("\nDigite o numero: ");
		scanf("%d", &num);
		printf("Digite a base: ");
		scanf("%d", &base_inicial);
		
		printf("O numero %d(%d) em decimal e: %d", num, base_inicial, base_dec(num,base_inicial));
	}
	else if(opcao == 2)
	{
		printf("\nDigite o numero decimal: ");
		scanf("%d", &num);
		printf("Digite a nova base: ");
		scanf("%d", &base_inicial);

		printf("O numero em decimal %d foi convertido para: %d(%d) ", num, dec_base(num,base_inicial), base_inicial);
	}
	else if(opcao == 3)
	{
		printf("\nDigite o numero: ");
		scanf("%d", &num);
		printf("Digite a base: ");
		scanf("%d", &base_inicial);
		printf("Digite a nova base: ");
		scanf("%d", &base_final);

		printf("O numero %d(%d) foi convertido para: %d(%d) ", num, base_inicial,  base_base(num, base_inicial, base_final), base_final);
	}
	
	trailer("FIM DA CONVERSAO",false,"Conversor.exe", "*", 70);
}


