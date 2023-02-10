/**
 * Author:           Ramirez Morales Erick Hazel
 * Date:             10/02/23
 * Description:      Desarrollar una función que invierta una cadena dada
*/

//BIBLIOTECAS
#include<stdio.h>
#include<stdlib.h>
#include<string.h> // Biblioteca necesaria para usar gets() y fgets()

#define TAM 50 //Definimos el tam maximo de la cadena que podriamos recibir


//PROTOTIPO DE FUNCIONES
void recepcionCadena(char *cadena);
void invertirCadena(char *cadena);

//PROGRAMA PRINCIPAL
int main(){

    char cadena[TAM];
    recepcionCadena(cadena);

    //Limpieza de la cadena del espacio
    cadena[strcspn(cadena, "\n\r")] = '\0';
    
    //Inversion de la cadena
    invertirCadena(cadena);
    
    return 0;
}

//DEFINICION DE FUNCIONES

/**
 * @param cadena --> arreglo de caracteres donde guardaremos la cadena que pueda ingresar el usuario
 * @brief Esta funcion guarda por referencia la cadena que ingrese el usuario desde el teclado
*/
void recepcionCadena(char *cadena){
    printf("Ingresa cualquier palabra.\n");
    /**
     * *fgets() guarda la cadena ingresada en el flujo inluyendo el salto de linea \n
     * * Es importante tener esto en cuenta, por lo que hay que limpiar la cadena de ese salto de linea
     */ 
    fgets(cadena,TAM,stdin);
}//fin de recepcionCadena()


/**
 * @param cadena --> cadena que invertiremos
 * @brief --> fuencion que invierte la cadena recibida como parametro, utilizando una variable auxiliar
 * para guardar temporalmente el caracter y no perderlo en el proceso.
*/
void invertirCadena(char *cadena){
    int i = 0,j = strlen(cadena) -1;
    char aux;

    for(; i < j; i++,j--){
        aux = cadena[i];
        cadena[i] = cadena[j];
        cadena[j] = aux;
    }
    printf("%s",cadena);
}//fin invertirCadena()