#include <stdio.h>
#include ".\layout.h"

main(){
	
	//variavel
	int notasTroco[4] = {100,50,10,5};
	int qtdNotas[4];
	int moedasTroco[6] = {100,50,25,10,5,1};
	int qtdMoedas[6];	
	
	float compra,pago,troco;
	int notas,i,moedas;	
	
	header("Tem Troco ?","1.0","*",70);	
		
	printf("Digite o valor da compra: ");
	scanf("%f",&compra);
	
	printf("Digite o valor pago: ");
	scanf("%f",&pago);
	
	if (pago >= compra) //calcula o troco
	{
		troco = pago - compra;
		
		notas  = (int) troco;
		troco = (troco - notas) * 100;
		moedas = (int) troco;
		
		for(i=0; i<4; i++)
		{
			if (i==0)
			{
			  qtdNotas[i] = (notas/notasTroco[i]);
		    }else			
		    {		    
			  qtdNotas[i] = ((notas % notasTroco[i-1]) / notasTroco[i]);
			  notas = (notas % notasTroco[i]);
		    }
		    
		    if(i==3)
		    {
		      moedas = ((notas % notasTroco[i]) *100) + moedas;
		    }	    
		}
		
		for(i=0; i<6; i++)
		{
			if (i==0)
			{
			  qtdMoedas[i] = (moedas / moedasTroco[i]);			  
		    }else			
		    {		    
			  qtdMoedas[i] = ((moedas % moedasTroco[i-1]) / moedasTroco[i]);			
			  moedas = (moedas % moedasTroco[i]);
		    }
		}
				
		for(i=0; i<4; i++)
		{
			printf("\n%d nota(s) de R$%d",qtdNotas[i], notasTroco[i]);
		}
			
		
		for(i=0; i<6; i++)
		{
			printf("\n%d moeda(s) de R$%0.2f",qtdMoedas[i], (moedasTroco[i] /100.00));
		}
	
	}
	else printf("Valor pago inferior ao valor da compra");
	
	
	trailer("TROCO DISTRIBUIDO COM SUCESSO",true,"Troco.exe","*",70);
	
}
