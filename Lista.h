#include<stdbool.h>
#include<stdio.h>
#include<stdlib.h>


enum tipos{INT, FLOAT, DOUBLE, CHAR, STRING, VOID}; //enumeraciones que simularan los tipos de datos ofrecidos por el lenguaje
typedef enum tipos Tipo;                           // se define un alias para los enum

/*===================================================================================================*
 *                                    Definiendo TAD Nodos                                           *
 *===================================================================================================*/
typedef struct ElementoNodo
{
    struct ElementoNodo *enlace;
    union{                                         //se utilizara para almacenar los distitos tipos de datos
        int Int;
        float Float;
        double Double;
        char  *String;
        void *Void;
    };
} Nodo;
/*===================================================================================================*
 *                                                                                                   *
 *===================================================================================================*/


/*===================================================================================================*
 *                                    Definiendo TAD Lista                                           *
 *===================================================================================================*/
typedef struct ElementoLista{
    Nodo *primerNodo;
    Nodo *ultimoNodo;
    unsigned tamano;
    Tipo tipoDato;
}Lista;
/*===================================================================================================*
 *                                                                                                   *
 *===================================================================================================*/



/*===================================================================================================*
 *                                           Operaciones                                             *
 *===================================================================================================*/

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

bool insertarPorIndice(Lista *lista, void * dato, unsigned indice ){
   bool exito = false;
   if((indice>=0) && ((indice < lista->tamano) || indice == 0)){
        Nodo *nuevo = (Nodo*)malloc(sizeof(Nodo));             //declaracion del nuevo nodo
        if(nuevo == NULL)                                       //retorna un false si no se puede asginar memoria
            return false;
        nuevo->enlace = NULL;
        Tipo tipo = lista->tipoDato;
        switch(tipo){
            case INT :;  //al parecer no se puede declarar una variable despues de un case,primera declaracion vacia por esta razon
                int valorInt = *((int *)dato);
                nuevo->Int = valorInt;
                break;
            case FLOAT :;
                float valorFloat = *((float *)dato);
                nuevo->Float = valorFloat;
                break;
            case DOUBLE :;
                double valorDouble = *((double*)dato);
                nuevo->Double = valorDouble;
                break;
            case CHAR:;
                char *valorPtrChar = ((char*)dato);
                nuevo->String = valorPtrChar;
                break;
            case VOID :;
                nuevo->Void = dato;
        }
        if(vacia(lista)){
            lista->primerNodo = nuevo;
            lista->ultimoNodo = nuevo;
            lista->tamano = 1;          //conviene realizar un funcion obtener y establecer tamano de la lista
            exito = true;
        }else{
            if(indice == 0){
                nuevo->enlace = lista->primerNodo;
                lista->primerNodo = nuevo;  // se inserto en la primera posicion
                lista->tamano++;
                exito = true;
            }else{
                if(indice == (lista->tamano-1)){ // si el el elemento que se quiere instertar es el ultimo
                    Nodo *auxiliar  = lista->ultimoNodo;
                    auxiliar->enlace = nuevo;       // se inserto en la ultima posicion
                    nuevo->enlace = NULL;
                    lista->ultimoNodo = nuevo;
                    exito = true;
                    lista->tamano++;
                }else{
                    Nodo *auxiliar = lista->primerNodo;
                    for(unsigned i = 0; i<indice; i++){
                        if(i == (indice - 1)){
                            nuevo->enlace = auxiliar->enlace;
                            auxiliar->enlace = nuevo;    // se agrega el nuevo nodo en la posicion deseada
                            lista->tamano++;
                            return true;
                        }
                        auxiliar = auxiliar->enlace;
                    }
                }
            }
        }

   }
    return exito;
}

bool insertar(Lista *lista, void *dato){
    if(insertarPorIndice(lista, dato, 0))
        return true;
    else
        return false;
}

bool insertarUltimo(Lista* lista, void* dato){
 /* Nodo *nuevo = (Nodo*)malloc(sizeof(Nodo));             //declaracion del nuevo nodo
    if(nuevo == NULL)                                       //retorna un false si no se puede asginar memoria
        return false;
    nuevo->enlace = NULL;
    Tipo tipo = lista->tipoDato;
    switch(tipo){
        case INT :;  //al parecer no se puede declarar una variable despues de un case,primera declaracion vacia por esta razon
            int valorInt = *((int *)dato);
            nuevo->Int = valorInt;
            break;
        case FLOAT :;
            float valorFloat = *((float *)dato);
            nuevo->Float = valorFloat;
            break;
        case DOUBLE :;
            double valorDouble = *((double*)dato);
            nuevo->Double = valorDouble;
            break;
        case CHAR:;
            char *valorPtrChar = ((char*)dato);
            nuevo->String = valorPtrChar;
            break;
        case VOID :;
            nuevo->Void = dato;
     }
    if(vacia(lista)){
        lista->primerNodo = nuevo;
        lista->ultimoNodo = nuevo;
        lista->tamano = 1;
        return true;
    }else{
        Nodo *temporal;
        temporal = (Nodo*)malloc(sizeof(Nodo));
        if(temporal == NULL)
            return false;
        temporal = lista->ultimoNodo;
        temporal->enlace = nuevo;
        lista->ultimoNodo =nuevo;
        lista->tamano++;
        return true;
    }*/

    unsigned indice = (lista->tamano -1);
    if(insertarPorIndice(lista, dato,indice))
        return true;
    else
        return false;
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
/*
int obtenerDato(Lista *lista, int dato)
{
    //por implementar
}*/

Nodo obtenerPorIndice(Lista *lista, unsigned indice){
    if((indice>=0) && ((indice < lista->tamano) || indice == 0)){
        if(!vacia(lista)){
            if(indice == 0){
                Nodo nodoRetorno = *(lista->primerNodo);
                nodoRetorno.enlace=NULL;
                return nodoRetorno;
            }else{
                if(indice == (lista->tamano-1)){
                    Nodo nodoRetorno = *(lista->ultimoNodo);
                    nodoRetorno.enlace = NULL;
                    return nodoRetorno;
                }else{
                    Nodo *nodoActual = lista->primerNodo;
                    for(unsigned i = 0; i<(lista->tamano); i++){
                        if(indice == i){
                            Nodo nodoRetorno = *(nodoActual);
                            nodoRetorno.enlace = NULL;
                            return nodoRetorno;
                        }
                        nodoActual = nodoActual->enlace;
                    }
                }
            }
        }


    }
}

Tipo tipoDeLista(Lista *lista){
    return lista->tipoDato;
}
