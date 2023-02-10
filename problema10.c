/**
 * Author:           Ramirez Morales Erick Hazel
 * Date:             10/02/23
 * Description:      Desarrollar una función que indique si un número es primo o no
 * NOTA: Recordar que un numero primo es cualquier numero natural mayor a 1, que SOLAMENTE
 * es dividible entre si mismo y entre 1.
*/


//BIBLIOTECAS
#include<stdio.h>
#include<stdlib.h>

//PROTOTIPO DE FUNCIONES
int esPrimo(int x);
//PROGRAMA PRINCIPAL
int main(){
    int numero;
    printf("Ingresa un numero: \n");
    scanf("%d",&numero);

    switch(esPrimo(numero)){
        case 0:
            printf("El numero NO es Primo -_-\n");
        break;
        case 1:
            printf("El numero ES Primo 7u7\n");
        break;
        default:
            printf("El numero 1 no se considera primo o no primo XD\n");    
    }
   
   return 0;
}//fin main


//DEFINICION DE FUNCIONES
/**
 * @param x --> numero al que determinaremos si es primo o no.
 * @return --> La funcion devolvera 1 si el numero ES PRIMO, en caso contrario
 *              devolvera 0, si x es 1, devolvera -1
*/
int esPrimo(int x){
    //Validacion de que x sea 1
    int i = 2;
    if(x == 1)
        return -1;
    for(; i < x; i++){
        if(x%i == 0)
            return 0;
    }
    return 1; 

}//fin esPrimo()