#include <stdio.h>
#include <stdlib.h>


// Lineal O(n)
// Esta función regresa el indice del elemento buscado
// dentro del arreglo; si no lo encuentra regresa -1
// Recibe el arreglo, la busqueda y la longitud de arreglo,
// recuerda que la longitud se debe pasar por que al pasar por
// referencia no se puede obtener la longitud
int busquedaLineal(int arr[],int busqueda,int longitud){
    for (int i=0;i<longitud;i++){
		if(arr[i] == busqueda){
			return i;
		}
    }
    return -1;
}

int main(){
	// O(n)
	int edades[] = {23,25,10,2,55};
	int busqueda = 1;
	// sizeof devuelve el tamaño en bytes
	int longitud = sizeof edades / sizeof edades[0];
	int existe = busquedaLineal(edades, busqueda, longitud);
	printf("Posición de %d en arreglo es : %d\n ", busqueda, existe);
    return 0;
}