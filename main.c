#include<stdio.h>
#include "Lista.h"
int main(){

Lista lista;
inicializarLista(&lista, INT);
int numero = 34;
int numero2 = 78;
printf("EL tamano de la lista es : %d \n",tamanoLista(&lista));
insertarPorIndice(&lista,&numero,0);
insertarPorIndice(&lista,&numero,0);
insertarPorIndice(&lista,&numero,0);
insertarPorIndice(&lista,&numero2,2);
insertarPorIndice(&lista, &numero2,2);
printf("valor : %d\n",insertarPorIndice(&lista,&numero,4));
printf("EL tamano de la lista es : %d \n",tamanoLista(&lista));
return 0;
}
