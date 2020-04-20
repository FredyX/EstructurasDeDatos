#include<stdio.h>
#include "Lista.h"
/* EL main es utilizado para testear la estructuras de Datos */
typedef struct {
    char *nombre;
    char *apellido;
    unsigned edad;
    char* cargo;
}Empleado;
void imprimirLista(Lista*);
void agregarNumerosLista(Lista* ,int);

int main(){
    Lista *lista = (Lista *)malloc(sizeof(Lista));
    inicializarLista(lista, INT);

return 0;
}

void imprimirLista(Lista* lista){
    Nodo *auxiliar = lista->primerNodo;
    printf("El tamano de la lista es : %d \n\n",lista->tamano);
    for(unsigned i = 0; i<(lista->tamano); i++){
        printf("\n %d direccion del elemento : %p\n",i,auxiliar);
        auxiliar = auxiliar->enlace;
    }
}

void agregarNumerosLista(Lista* lista, int limite){
    if(limite>0){
        for(unsigned i = 0; i<limite; i++){
            int numero = i;
            insertarUltimo(lista,&numero);
        }
    }
}
