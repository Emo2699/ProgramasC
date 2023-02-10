/**
 * Author:           Ramirez Morales Erick Hazel
 * Date:             10/02/23
 * Description:      Desarrollar una función que devuelva el producto de dos números n y m mediante sumas
 *                   sucesivas
*/

//BIBLIOTECAS
#include<stdio.h>
#include<stdlib.h>

//PROTOTIPO DE FUNCIONES
int sumasSucesivas(int m, int n);
//PROGRAMA PRINCIPAL
int main(){
    int m,n;
    printf("Ingresa el primer numero\n");
    scanf("%d",&m);
    printf("Ingresa el segundo numero\n");
    scanf("%d",&n);

    printf("El resultado del producto entre ambos numeros es: %d\n",sumasSucesivas(m,n));
    return 0;
}

//DEFINICION DE FUNCIONES
/**
 * @param m --> numero el cual usaremos para realizar las sumas
 * @param n --> numero que usaremos para controlar las veces que haremos las sumas de m
 * @return --> resultado de las sumas sucesivas
*/
int sumasSucesivas(int m, int n){
    int resultado = 0, i;
    for(i = 0; i < n; i++){
        resultado += m;
        //resultado = resultado + m;
    }

    return resultado;
}//fin sumasSucesivas()