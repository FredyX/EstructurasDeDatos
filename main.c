#include<stdio.h>
#include "Lista.h"

typedef struct {
    char *nombre;
    char *apellido;
    unsigned edad;
    char* cargo;
}Empleado;

int main(){
    Lista *lista = (Lista *)malloc(sizeof(Lista));//se reserva un espacio de memoria dinamica
    Empleado empleado1,empleado2,empleado3;
    empleado1.nombre = "Pepe";
    empleado2.nombre = "Juana";
    empleado3.nombre = "Maria";
    inicializarLista(lista,VOID);
    printf("*****El tamano de la lista es :  %d\n\n",lista->tamano);
    for(unsigned i = 0; i<5 ; i++){
        insertar(lista,&empleado1);
        insertarUltimo(lista,&empleado2);


    }
    printf("*********Se imprimiran todos los elementos de la lista*********\n\n");
    unsigned contador = 0;
    while(contador <(lista->tamano)){
        Empleado *ptrEmpleado = obtenerPorIndice(lista, contador).Void;
        printf("====El nombre del empleado es==== : %s\n",ptrEmpleado->nombre);
        contador++;
    }
    printf("\n*****El tamano de la lista es :  %d\n\n",lista->tamano);
    eliminarPorIndice(lista,2);
    eliminarPrimero(lista);
    eliminarUltimo(lista);
    printf("\n*****El tamano de la lista es :  %d\n\n",lista->tamano);

    unsigned contador1 = 0;
    while(contador1 <(lista->tamano)){
        Empleado *ptrEmpleado = obtenerPorIndice(lista, contador1).Void;
        printf("====El nombre del empleado es==== : %s\n",ptrEmpleado->nombre);
        contador1++;
    }
    free(lista);
return 0;
}
