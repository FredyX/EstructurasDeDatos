#include<stdbool.h>
#include<stdio.h>
/******************************Definiendo TDA Nodos *****************************************/
struct Nodos
{
    struct Nodos *enlace;
    int dato;
};
typedef struct Nodos Nodo; // asignado un alias para el tipo de dato struct Nodos
/********************************************************************************************/

/**********************************OPERACIONES************************************************
*********************************************************************************************/

int tamanoLista(Nodo *primeroNodo){
    int contador = 1;
    Nodo * enlaceTemporal = (*primeroNodo).enlace;
    while (enlaceTemporal !=NULL){
        contador++;
        enlaceTemporal = (*enlaceTemporal).enlace;
    }

    return contador;
}
bool agregarFinal(Nodo * primerNodo, int valor){
    Nodo nodo = *primerNodo;
    if(nodo.enlace != NULL){
        Nodo nodoAnterior;
        bool finalEncontrado = false;
        while (!finalEncontrado)
        {
            nodoAnterior = nodo;
            nodo = *nodo.enlace;
            if(nodo.enlace == NULL){
                Nodo nuevo;
                nuevo.dato = valor;
                nuevo.enlace = NULL;
                (*nodoAnterior.enlace).enlace = &nuevo;
                finalEncontrado = true;
               break;
            }
        }

    }
    else
    {
        Nodo nuevo;
        nuevo.dato = valor;
        nuevo.enlace = NULL;
        (*primerNodo).enlace = &nuevo;
    }

    return false;
}
