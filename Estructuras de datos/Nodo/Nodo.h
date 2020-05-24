#ifndef NODO_H
#define NODO_H

#include <stdlib.h>

//Nodo que recibe datos de tipo caracter

typedef struct 
{
    char dato;
    struct Nodo* siguiente;
}Nodo;

/**
	Crea una nodo para una estructura de datos.
	@return Apuntador a la nodo creado
**/

Nodo* crearNodo();

/**
	Crea una nodo y lo inicializa con un valor.
	@param dato: Dato con el que se inicializa el nodo.
	@return Apuntador a la nodo creado
**/

Nodo* iniciarNodo(char dato);

#endif

Nodo* crearNodo(){
	Nodo* nodo = malloc(sizeof(Nodo)); //Creamos un nodo de tamaño del nodo
	return nodo;
}

Nodo* iniciarNodo(char dato){
    Nodo* nodo = crearNodo();
    nodo->dato = dato;
    nodo->siguiente = NULL;
    return nodo;
}