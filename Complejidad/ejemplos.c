#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


// Constante O(1)
// Esta función solo retorna un valor booleano
// Es por eso que es constante

bool esPar(int numero){
	return numero % 2 == 0;
} 

// Logaritmica O(log n)
// Esta función divide la entrada a la mitad es por eso que es una función logaritmica 
// Otro ejemplo es la busqueda binaria

float dividir(float n){
	while(n > 1){
		n /= 2;
	}
	return n;
}

// Lineal O(n)
// Esta función regresa el indice del elemento buscado
// dentro del arreglo; si no lo encuentra regresa -1
// Recibe el arreglo, la busqueda y la longitud de arreglo,
// recuerda que la longitud se debe pasar por que al pasar por
// referencia no se puede obtener la longitud

int busquedaEnArreglo(const int arreglo[], int busqueda, int longitud){
	for(int x = 0; x < longitud; x++){
		if(arreglo[x] == busqueda){
			return x;
		}
	}
	return -1;
}


// Lineal logaritmico O(n log n)
// Quick sort, ordena un arreglo de mayor a menor
// Recursivo

void intercambia (int *a, int *b){
	int c = *a;
	*a = *b;
	*b = c;
}

int particion(int arreglo[], int izq, int der){
	int pivote = arreglo[der];
	int i = (izq -1); //Indice del menor elemento

	for (int j = izq; j <= der - 1; j++){
		if(arreglo[j] < pivote){
			i++;
			intercambia(&arreglo[i], &arreglo[j]);
		}
	}
	intercambia(&arreglo[i + 1], &arreglo[der]);
	return (i + 1);
}

void quickSort(int arreglo[], int izq, int der){
	if(izq < der){
		int indPart = particion(arreglo, izq, der);
		quickSort(arreglo, izq,indPart-1);
		quickSort(arreglo, indPart + 1, der);
	}
}



void imprime(int arreglo[], int tamano){
	int i;
	for (i = 0; i < tamano; i++){
		printf("%d ", arreglo[i]);
	}
	printf("\n");
}



int main(){

	// O(1)
	bool a  = esPar(3);
	printf("%d\n", a);

	// O(log n)
	float b = dividir(50.0);
	printf("%f\n",b);

	// O(n)
	int edades[] = {23,25,10,2,55};
	int busqueda = 10;
	// sizeof devuelve el tamaño en bytes
	int longitud = sizeof edades / sizeof edades[0];
	int existe = busquedaEnArreglo(edades, busqueda, longitud);
	printf("Posición de %d en arreglo es : %d\n ", busqueda, existe);

	//O(n log n)
	 int numeros[] = {10,2,4,62,3,7,1,3,9,4,5};
	 int n = sizeof(numeros)/sizeof(numeros[0]);
	 printf("Arreglo desordenado: \n");
	 imprime(numeros,n);
	 quickSort(numeros,0,n-1);
	 printf("Arreglo ordenado: \n");
	 imprime(numeros, n);

	return 0;
}










