#include<stdbool.h>
#include<stdio.h>


enum tipos{INT, FLOAT, DOUBLE, CHAR, STRING, VOID}; //enumeraciones que simularan los tipos de datos ofrecidos por el lenguaje
typedef enum tipos Tipo;                                 // se define un alias para los enum

/********************************Definiendo TDA Nodos *******************************************/
typedef struct ElementoNodo
{
    struct ElementoNodo *enlace;
    union{                           //se utilizara para almacenar los distitos tipos de datos
        int Int;
        float Float;
        double Double;
        char  *String;
        void *Void;
    }
} Nodo;
/*************************************************************************************************/


/********************************Definiendo TDA Lista *******************************************/
typedef struct ElementoLista{
    Nodo *primerNodo;
    Nodo *ultimoNodo;
    unsigned tamano;
    Tipo tipoDato;
}Lista;
/*************************************************************************************************/


/***************************************OPERACIONES************************************************
***************************************************************************************************/

void inicializarLista(Lista *lista, Tipo tipo){
    lista->primerNodo = NULL;
    lista->ultimoNodo = NULL;
    lista->tamano = 0;
    lista->tipoDato = tipo;
}

int tamanoLista(Lista *lista){
    //por implementar
}

bool insertarPorIndice(Lista *lista, int valor, unsigned int indice ){
    //por implementar
}

bool insertarPrimero(Lista *lista, int valor){
    //por implementar
}

bool insertarUltimo(Lista* lista, int valor){
    //por implementar
}

int localizarDato(Lista *lista, int valor){
    //por implementar
}

bool eliminarPorIndice(Lista *lista, unsigned int indice){
    //por implementar
}

void vaciarLista(Lista *lista){
    //por implementar
}

int obtenerDato(Lista *lista, int dato)
{
    //por implementar
}

int obtenerPorIndice(Lista *lista, unsigned int indice){
    //por implementar
}

Tipo tipoDeLista(Lista *lista){
 //Por implementar
}
