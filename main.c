#include<stdio.h>
#include "Lista.h"

int main(){
    Lista *lista = (Lista *)malloc(sizeof(Lista)); //se reserva un espacio de memoria dinamica
    inicializarLista(lista,INT);
    int numero1 = 1;
    int numero2 = 2;
    int numero3 = 3;
    int numero4 = 4;
    int numero5 = 5;
    printf("El tamano de la lista es %d: \n",tamanoLista(lista));
    insertarPrimero(lista,&numero1);
    insertarPrimero(lista,&numero2);
    insertarPrimero(lista,&numero3);
    insertarPrimero(lista,&numero4);
    insertarPrimero(lista,&numero5);

    printf("El tamano de la lista es %d: \n",tamanoLista(lista));
    printf("El valor almacenado es  %d \n",obtenerPorIndice(lista,0).Int);
    printf("El valor almacenado es  %d \n",obtenerPorIndice(lista,1).Int);
    printf("El valor almacenado es  %d \n",obtenerPorIndice(lista,2).Int);
    printf("El valor almacenado es  %d \n",obtenerPorIndice(lista,3).Int);
    printf("El valor almacenado es  %d \n",obtenerPorIndice(lista,4).Int);
return 0;
}
