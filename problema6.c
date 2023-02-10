/**
 * Author:           Ramirez Morales Erick Hazel
 * Date:             10/02/23
 * Description:      Desarrollar una función que devuelva el promedio de un arreglo de enteros dado.
 * 
 * NOTA: Para este problema el arreglo es definido desde adentro del codigo, esto por mayor comodidad para
 * la prueba de la funcion que resuelve el problema planteado inicialmente, el codigo puede cambiar en un
 * futuro para que el usuario desde el teclado ingrese los valores al arreglo.
*/

//BIBLIOTECAS
#include<stdio.h>
#include<stdlib.h>

int numeros[] = {10,10,3,10,10,10,9,5};

//PROTOTIPO DE FUNCIONES

float promedio(int *numeros, int tamArreglo);

//PROGRAMA PRINCIPAL
int main(){
    
    /*
        La forma de obtener el tamanio del arreglo es la siguiente.
        1. Obtenemos el espacio total de memoria que ocupa todo el arreglo.
        2. Obtenemos el espacio de memroia que ocupa el primer elemento del arreglo.
        3. Hacemos division sencilla del numero obbtenido del punto 1 entre el numero obtenido del punto 2

        la funcion en la que nos apoyamos es sizeof.
    
    */
    int tamArreglo = sizeof(numeros) / sizeof(numeros[0]);
    
    //Impresion solamente de dos decimales del resultado
    printf("El promedio es: %.2f\n", promedio(numeros, tamArreglo));
    return 0;
}


//DEFINICION DE FUNCIONES
/**
 * @param numeros --> arreglo de numeros de los que sacaremos promedio. al trabajar con arreglos y punteros en C
 * hay que recordar que si pasamos de esta forma el arreglo como parametro a la funcion, solo pasamos la
 * direccion del primer elemento del arreglo
 * @param tamArreglo --> tamanio del areglo de enteros previamente calculado.
*/
float promedio(int *numeros, int tamArreglo){
    int i;
    float resultado = 0;

    for(i = 0; i < tamArreglo; i++){
        resultado += numeros[i];
    }
    return resultado / tamArreglo;
}//fin promedio()