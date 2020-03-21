#include<stdio.h>
#include "Lista.h"

int main(){
    Lista *lista = (Lista *)malloc(sizeof(Lista)); //se reserva un espacio de memoria dinamica
    inicializarLista(lista,INT);
    int numero = 9998;
    printf("El tamano de la lista es %d: \n",tamanoLista(lista));
    insertarUltimo(lista,&numero);
    insertarUltimo(lista,&numero);
    insertarUltimo(lista,&numero);
    insertarUltimo(lista,&numero);
    insertarPrimero(lista,&numero);
    insertarPrimero(lista,&numero);
    insertarPorIndice(lista,&numero,3);
    insertarPrimero(lista,&numero);
    insertarPorIndice(lista,&numero,7);
    printf("El tamano de la lista es %d: \n",tamanoLista(lista));
return 0;
}
