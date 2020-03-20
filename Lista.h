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
    };
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


/*==================================================================================================*
 *                                           Operaciones                                            *
 *==================================================================================================*/

void inicializarLista(Lista *lista, Tipo tipo){
    lista->primerNodo = NULL;
    lista->ultimoNodo = NULL;
    lista->tamano = 0;
    lista->tipoDato = tipo;
}

unsigned int tamanoLista(Lista *lista){
    //por implementar
    return lista->tamano;
}

bool vacia(Lista *lista){
    if((lista->primerNodo == NULL) && (lista->ultimoNodo == NULL))
        return true;
    else
        return false;

}

bool insertarPorIndice(Lista *lista, void * dato, unsigned int indice ){
   bool exito = false;
   if((indice>=0) && (indice < lista->tamano)){
        Nodo nuevo;
        nuevo.enlace = NULL;
        Tipo tipo = lista->tipoDato;
        switch(tipo){
            case INT :;  //al parecer no se puede declarar una variable despues de un case,primera declaracion vacia por esta razon
                int valorInt = *((int *)dato);
                nuevo.Int = valorInt;
                break;
            case FLOAT :;
                float valorFloat = *((float *)dato);
                nuevo.Float = valorFloat;
                break;
            case DOUBLE :;
                double valorDouble = *((double*)dato);
                nuevo.Double = valorDouble;
                break;
            case CHAR:;
                char *valorPtrChar = ((char*)dato);
                nuevo.String = valorPtrChar;
                break;
            case VOID :;
                nuevo.Void = dato;
        }

   }

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
