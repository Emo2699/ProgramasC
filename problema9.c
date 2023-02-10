/**
 * Author:           Ramirez Morales Erick Hazel
 * Date:             10/02/23
 * Description:      Desarrollar una función que a partir de un numero dado, devuelva el
 *                   último digito del número
*/

//BIBLIOTECAS
#include<stdio.h>
#include<stdlib.h>
#include<string.h> // Biblioteca necesaria para usar gets() y fgets()

#define TAM 30 //Definimos el tam maximo de la cadena que podriamos recibir


//PROTOTIPO DE FUNCIONES
void recepcionCadena(char *numero);
char devolverUltimoDigito(char *numero);
char devolverUltimoDigito2(char *numero);

//PROGRAMA PRINCIPAL
int main(){

    char numero[TAM];
    recepcionCadena(numero);

    //Limpieza de la cadena del espacio
    numero[strcspn(numero, "\n\r")] = '\0';
    
    /*
        Devolucion del último digito.
        Hay dos formas de solucionar esto: 
        1. Una es utilizando la funcion de la biblioteca string.h y con eso obtenemos el tamanio de la cadena, y solo devolvemos el último caracter del arreglo

        2. Utilizamos un ciclo para recorrer el arreglo hasta que encuentre el termiandor de cadena
        y con nuestro iterador ya tenemos la posicion del último digito, y solo lo devolvemos.
    */

    printf("%c\n",devolverUltimoDigito(numero));
    printf("%c\n",devolverUltimoDigito2(numero));

    
    return 0;
}//fin de main()

//DEFINICION DE FUNCIONES

/**
 * @param numero --> arreglo de caracteres donde guardaremos el numero que pueda ingresar el usuario
 * @brief Esta funcion guarda por referencia la cadena que ingrese el usuario desde el teclado
*/
void recepcionCadena(char *numero){
    printf("Ingresa cualquier numero.\n");
    /**
     * *fgets() guarda la cadena ingresada en el flujo inluyendo el salto de linea \n
     * * Es importante tener esto en cuenta, por lo que hay que limpiar la cadena de ese salto de linea
     */ 
    fgets(numero,TAM,stdin);
}//fin de recepcionCadena()

/**
 * Opcion 1 --> Utilizando strlen()
 * @param numero --> numero del cual buscaremos el último digito.
 * @return --> ultimo digito del numero recibido como parametro.
*/
char devolverUltimoDigito(char *numero){
    return numero[strlen(numero)-1];
}//fin devolverUltimoDigito()

/**
 * Opcion 2 --> recorriendo la cadena
 * @param numero --> numero del cual buscaremos el último digito.
 * @return --> ultimo digito del numero recibido como parametro.
*/
char devolverUltimoDigito2(char *numero){
    int i;
    for(i = 0; numero[i] != '\0'; i++);
    return numero[i-1];
}//fin devolverUltimoDigito2()
