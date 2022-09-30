/**
 * @file                calculadoraMatrices.c
 * @author              Ramirez Morales Erick Hazel
 * @brief               Programa dedicado a simular una calculadora de algebra
 *                      lineal, es decir, a realizar operaciones entre matrices
 * @date                30-09-22
 * @version             0.1
 * 
 */ 

// * BIBLIOTECAS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int **Matriz1, **Matriz2;
// * PROTOTIPO DE FUNCIONES
char menu();
void leerDimensiones(int *filas1,int *columnas1,int *filas2,int *columnas2);
void leerDimensiones2(int *filas,int *columnas);
void leerMultiplo(int *multiplo);
int validacionTamanios(int filas1, int columnas1, int filas2, int columnas2);
int **crearMatriz(int filas,int columnas);
int validacionMatriz(int **matriz);
void llenarMatriz(int **matriz,int filas,int columnas);
void imprimirMatriz(int **matriz,int filas,int columnas);
void sumarMatrices(int **matriz1, int **matriz2, int filas, int columnas);
void restarMatrices(int **matriz1, int **matriz2, int filas, int columnas);
void multiplicacionEscalar(int **matriz, int filas, int columnas, int escalar);


// * PROGRAMA PRINCIPAL
int main(){
    char opcion;
    int filas1,columnas1,filas2,columnas2;
    do{
        opcion = menu();
        switch (opcion){
            case '1': ;
                //* CODIGO PARA SUMAR MATRICES
                //int filas1,columnas1,filas2,columnas2;
                printf("NOTA: Recuerda que las matrices a sumar deben tener las mismas dimensiones\n");
                leerDimensiones(&filas1,&columnas1,&filas2,&columnas2);
                if(validacionTamanios(filas1,columnas1,filas2,columnas2)){
                    Matriz1 = crearMatriz(filas1,columnas1);
                    Matriz2 = crearMatriz(filas2,columnas2);
                    printf("Matriz 1\n");
                    llenarMatriz(Matriz1,filas1,columnas1);
                    printf("Matriz 2\n");
                    llenarMatriz(Matriz2,filas2,columnas2);
                    sumarMatrices(Matriz1,Matriz2,filas1,columnas1);
                    free(Matriz1);
                    free(Matriz2);
                    getchar();
                }
                else
                    printf("No se pueden sumar las matrices -_-\n");
            break;

            case '2': ;
                //* CODIGO PARA RESTAR MATRICES
                //int filas1,columnas1,filas2,columnas2;
                printf("NOTA: Recuerda que las matrices a restar deben tener las mismas dimensiones\n");
                leerDimensiones(&filas1,&columnas1,&filas2,&columnas2);
                if(validacionTamanios(filas1,columnas1,filas2,columnas2)){
                    Matriz1 = crearMatriz(filas1,columnas1);
                    Matriz2 = crearMatriz(filas2,columnas2);
                    printf("Matriz 1\n");
                    llenarMatriz(Matriz1,filas1,columnas1);
                    printf("Matriz 2\n");
                    llenarMatriz(Matriz2,filas2,columnas2);
                    restarMatrices(Matriz1,Matriz2,filas1,columnas1);
                    free(Matriz1);
                    free(Matriz2);
                    getchar();
                }
                else
                    printf("No se pueden restar las matrices -_-\n");
            break;

            case '3': ;
                //* CODIGO PARA MULTIPLICAR POR UN ESCALAR UNA MATRIZ
                //int multiplo,filas,columnas;
                int multiplo;
                leerMultiplo(&multiplo);
                leerDimensiones2(&filas1,&columnas1);
                Matriz1 = crearMatriz(filas1,columnas1);
                printf("Matriz 1\n");
                llenarMatriz(Matriz1,filas1,columnas1);
                multiplicacionEscalar(Matriz1,filas1,columnas1,multiplo);
                free(Matriz1);
                getchar();
            break;

            case '4':
                /* code */
                printf("MULTIPLICACION ENTRE MATRICES\n");
            break;

            case '5':
                /* code */
                printf("TRANSPUESTA\n");
            break;

            case '6':
                /* code */
                printf("AIOS :V\n");
            break;

            default:
                printf("OPCION INCORRECTA -_-\n");
        }
    }while(opcion != '6');

    return 0;

}//fin main


// * DEFINICION DE FUNCIONES
/**
 * @return char --> caracter correspondiente a la opcion seleccionada por el usuario
 */ 
char menu(){
    /**
     * *  Al momento de leer un caracter en C, nos enfrentamos al problema
     * *  de que en el buffer se guarda el salto de linea (/n) cuando 
     * *  ingresamos la opcion que elegimos. Por ello utilizamos una cadena 
     * *  de dos caracteres por dos razones, la primera para utilizar la funcion
     * *  gets(), la cual almacena la cadena ingresada desde el teclado sin leer
     * *  el salto de linea y éste no queda en el buffer, por lo que al terminar
     * *  de ejecutarse la accion de la opción seleccionada, no se vera dos 
     * *  veces el menú, la segunda es que al utilizar una cadena de dos caracteres
     * *  nos ocupamos mucha memoria al momento que se ejecuta nuestro programa
     * *  y solo regresamos el caracter en la primera posicion de nuestro arreglo
     * *  debido a que es el que nos interesa. 
     */ 
    char op[2];
    printf("----------------------------------------\n");
    printf("!!!HOLA, BIENVENIDO A LA CALCULADORA DE OPERACIONES ENTRE MATRICES!!!\n");
    printf("Elige entre las siguientes opciones:\n");
    printf("Ingresa 1. Para Suma\n");
    printf("Ingresa 2. Para Resta\n");
    printf("Ingresa 3. Para Multiplicacion por un escalar\n");
    printf("Ingresa 4. Para Multiplicar matrices\n");
    printf("Ingresa 5. Para Obtener la matriz transpuesta\n");
    printf("Ingresa 6. Para salir :3\n");
    printf("!!!!   NOTA: LA CALCULADORA UNICAMENTE FUNCIONA CON VALORES ENTEROS   !!!!");
    printf("----------------------------------------\n");
    gets(op);
    return op[0];
}

void leerDimensiones(int *filas1,int *columnas1,int *filas2,int *columnas2){
    int fi1,co1,fi2,co2;
    printf("Ingresa las filas de la primera matriz\n");
    scanf("%d",&fi1);
    printf("Ingresa las columnas de la primera matriz\n");
    scanf("%d",&co1);
    printf("Ingresa las filas de la segunda matriz\n");
    scanf("%d",&fi2);
    printf("Ingresa las columnas de la segunda matriz\n");
    scanf("%d",&co2);
    (* filas1) = fi1;
    (* columnas1) = co1;
    (* filas2) = fi2;
    (* columnas2) = co2;
    getchar();
}

int **crearMatriz(int filas,int columnas){
    int i,j,**matriz;

    matriz = (int **) malloc(filas*sizeof(int *));
    for(i = 0; i < filas; i++){
        matriz[i] = (int *) malloc(columnas*sizeof(int));
    }
    return matriz;
}

int validacionMatriz(int **matriz){
    if(matriz == NULL){
        printf("La matriz no se creo correctamente :v\n");
        return 1;
    }
    return 0;
}

void llenarMatriz(int **matriz,int filas,int columnas){
    int i,j;
    if(matriz == NULL){
        perror("La matriz esta vacia -_-\n");
        return;
    }

    for(i = 0; i < filas; i++){
        for(j = 0; j < columnas; j++){
            printf("Ingresa el valor de la posicion [%d][%d]:\n",i,j);
            scanf("%d",&matriz[i][j]);
        }
    }
    imprimirMatriz(matriz,filas,columnas);
}

void imprimirMatriz(int **matriz,int filas,int columnas){
    int i,j;
    printf("La matriz quedo asi:\n");
    for(i = 0; i < filas; i++){
        for(j = 0; j < columnas; j++){
            printf("%d ",matriz[i][j]);
        }
        printf("\n");
    }
}

int validacionTamanios(int filas1, int columnas1, int filas2, int columnas2){
    if(filas1 != filas2 || columnas1 != columnas2)
        return 0;
    return 1;
}

void sumarMatrices(int **matriz1, int **matriz2, int filas, int columnas){
    if(validacionMatriz(matriz1)){
        printf("La matriz 1 no existe -_-\n");
        return;
    }
    if(validacionMatriz(matriz2)){
        printf("La matriz 2 no existe -_-\n");
        return;
    }

    int i,j;
    printf("La suma de matrices es:\n");
    for(i = 0; i < filas; i++){
        for(j = 0; j < columnas; j++){
            printf("%d ",matriz1[i][j] + matriz2[i][j]);
        }
        printf("\n");
    } 
}

void restarMatrices(int **matriz1, int **matriz2, int filas, int columnas){
    if(validacionMatriz(matriz1)){
        printf("La matriz 1 no existe -_-\n");
        return;
    }
    if(validacionMatriz(matriz2)){
        printf("La matriz 2 no existe -_-\n");
        return;
    }

    int i,j;
    printf("La resta de matrices es:\n");
    for(i = 0; i < filas; i++){
        for(j = 0; j < columnas; j++){
            printf("%d ",matriz1[i][j] - matriz2[i][j]);
        }
        printf("\n");
    }
}

void multiplicacionEscalar(int **matriz, int filas, int columnas, int escalar){
    if(validacionMatriz(matriz)){
        printf("La matriz no existe -_-\n");
        return;
    }
    int i,j;
    printf("El resultado de multiplicxar la matriz por el escalar es:\n");
    for(i = 0; i < filas; i++){
        for(j = 0; j < columnas; j++){
            printf("%d ", matriz[i][j] * escalar);
        }
        printf("\n");
    }
}

void leerMultiplo(int *multiplo){
    int numero;
    printf("Ingresa el escalar (numero) por el que vas a multiplicar la matriz:\n");
    scanf("%d",&numero);
    getchar();
    *multiplo = numero;
}

void leerDimensiones2(int *filas,int *columnas){
    int fil,col;
    printf("Ingresa el numero de filas de la matriz\n");
    scanf("%d",&fil);
    printf("Ingresa el numero de columnas de la matriz\n");
    scanf("%d",&col);
    getchar();
    *filas = fil;
    *columnas = col;
}