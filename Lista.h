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

/*******************************************************************************************************************/

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

bool insertarPorIndice(Lista *lista, void * dato, unsigned int indice ){
   bool exito = false;
   if((indice>=0) && ((indice < lista->tamano) || indice == 0)){
        Nodo *nuevo = (Nodo*)malloc(sizeof(nuevo));             //declaracion del nuevo nodo
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
                lista->primerNodo = nuevo;
                lista->tamano +=1;
                exito = true;
            }else{
                Nodo *nodoActual = (Nodo*)malloc(sizeof(nodoActual));
                if(nodoActual == NULL)
                    return false;
                nodoActual = lista->primerNodo;
                for(unsigned int i = 0; i<tamanoLista(lista); i++){
                    if(i == (indice - 1)){
                        Nodo *copiaNodo = (Nodo *)malloc(sizeof(copiaNodo));
                        copiaNodo = nodoActual->enlace;
                        nodoActual->enlace = nuevo;
                        nuevo->enlace = copiaNodo;
                        lista->tamano +=1;
                        exito = true;
                    }
                    nodoActual = nodoActual->enlace;
                }
            }
        }

   }
    return exito;
}

bool insertarPrimero(Lista *lista, void *dato){
    if(insertarPorIndice(lista, dato, 0)==true)
        return true;
    else
        return false;
}

bool insertarUltimo(Lista* lista, void* dato){
    Nodo *nuevo = (Nodo*)malloc(sizeof(nuevo));             //declaracion del nuevo nodo
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
        temporal = (Nodo*)malloc(sizeof(temporal));
        if(temporal == NULL)
            return false;
        temporal = lista->ultimoNodo;
        temporal->enlace = nuevo;
        lista->ultimoNodo =nuevo;
        lista->tamano++;
        return true;
    }

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

Nodo obtenerPorIndice(Lista *lista, unsigned int indice){
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
                    for(unsigned int i = 0; i<(lista->tamano-1); i++){
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
