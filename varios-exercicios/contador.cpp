#include <stdio.h>
#include ".\layout.h"

main(){

  int i;

  i = 1000;

  header("LISTA 02 / EXERCICIO 02","1.0","*",70);

  while (i >= 199){
    printf("\n%d",i);
    i-=3;
  }

  trailer("FIM DO PROCESSAMENTO EXERCICIO 02",true,"List2Exer2.exe","*",70);

}
