#include<stdio.h>
#include "Lista.h"
int main(){
    printf("%s\n","hola a todos");
    Nodo lista;
    lista.dato = 0;
    lista.enlace = NULL;
    agregarFinal(&lista, 12);
    printf(tamanoLista(&lista));
}
