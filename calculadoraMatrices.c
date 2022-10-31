/**
 * @file                calculadoraMatrices.c
 * @author              Ramirez Morales Erick Hazel
 * @brief               Programa dedicado a simular una calculadora de algebra
 *                      lineal, es decir, a realizar operaciones entre matrices
 * @date                30-10-22
 * @version             0.1
 * 
 */ 

//BIBLIOTECAS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int **Matriz1, **Matriz2;
//PROTOTIPO DE FUNCIONES
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
int validacionMultiplicacion(int filas1, int columnas1, int filas2, int columnas2);
void multiplicarMatrices(int **Matriz_resultante, int **matriz1, int **matriz2, int filas1, int columnas1,int filas2, int columnas2);
// PROGRAMA PRINCIPAL
int main(){
    char opcion;
    int filas1,columnas1,filas2,columnas2;
    do{
        opcion = menu();
        switch (opcion){
            case '1': ;
                // CODIGO PARA SUMAR MATRICES
                printf("NOTA: Recuerda que las matrices a sumar deben tener las mismas dimensiones\n");
                leerDimensiones(&filas1,&columnas1,&filas2,&columnas2);
                if(validacionTamanios(filas1,columnas1,filas2,columnas2)){
                    Matriz1 = crearMatriz(filas1,columnas1);
                    Matriz2 = crearMatriz(filas2,columnas2);
                    printf("------- MATRIZ 1 --------\n");
                    llenarMatriz(Matriz1,filas1,columnas1);
                    printf("------- MATRIZ 2 --------\n");
                    llenarMatriz(Matriz2,filas2,columnas2);
                    sumarMatrices(Matriz1,Matriz2,filas1,columnas1);
                    free(Matriz1);
                    free(Matriz2);
                    getchar();
                    printf("\n");
                }
                else
                    printf("No se pueden sumar las matrices -_-\n");
            break;

            case '2': ;
                //CODIGO PARA RESTAR MATRICES
                printf("NOTA: Recuerda que las matrices a restar deben tener las mismas dimensiones\n");
                leerDimensiones(&filas1,&columnas1,&filas2,&columnas2);
                if(validacionTamanios(filas1,columnas1,filas2,columnas2)){
                    Matriz1 = crearMatriz(filas1,columnas1);
                    Matriz2 = crearMatriz(filas2,columnas2);
                    printf("------- MATRIZ 1 --------\n");
                    llenarMatriz(Matriz1,filas1,columnas1);
                    printf("------- MATRIZ 2 --------\n");
                    llenarMatriz(Matriz2,filas2,columnas2);
                    restarMatrices(Matriz1,Matriz2,filas1,columnas1);
                    free(Matriz1);
                    free(Matriz2);
                    getchar();
                    printf("\n");
                }
                else
                    printf("No se pueden restar las matrices -_-\n");
            break;

            case '3': ;
                //CODIGO PARA MULTIPLICAR POR UN ESCALAR UNA MATRIZ
                int multiplo;
                leerMultiplo(&multiplo);
                leerDimensiones2(&filas1,&columnas1);
                Matriz1 = crearMatriz(filas1,columnas1);
                printf("------- MATRIZ  --------\n");
                llenarMatriz(Matriz1,filas1,columnas1);
                multiplicacionEscalar(Matriz1,filas1,columnas1,multiplo);
                free(Matriz1);
                printf("\n");
                getchar();
            break;

            case '4':
                /* code */
                printf("MULTIPLICACION ENTRE MATRICES\n");
                printf("Para multiplicar matrices se debe cumplir que las columnas de la primer matriz sea igual a las filas de la segunda\n");
                leerDimensiones(&filas1,&columnas1,&filas2,&columnas2);
                if(validacionMultiplicacion(filas1, columnas1, filas2, columnas2)){
                    Matriz1 = crearMatriz(filas1,columnas1);
                    Matriz2 = crearMatriz(filas2,columnas2);
                    int **Matriz_resultante = crearMatriz(filas1,columnas2); //matriz resultante de la multiplicacion entre matrices.
                    printf("------- MATRIZ 1 --------\n");
                    llenarMatriz(Matriz1,filas1,columnas1);
                    printf("------- MATRIZ 2 --------\n");
                    llenarMatriz(Matriz2,filas2,columnas2);
                    multiplicarMatrices(Matriz_resultante,Matriz1,Matriz2,filas1,columnas1,filas2,columnas2);
                    free(Matriz1);
                    free(Matriz2);
                    free(Matriz_resultante);
                    printf("\n");
                    getchar();
                }

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


// DEFINICION DE FUNCIONES
/**
 * DEFINICION: Esta funcion muestra un menu con las distintas opciones que puede escoger 
 * el ususario para hacer uso de la calculadora de matrices.
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
    printf("!!!!   NOTA: LA CALCULADORA UNICAMENTE FUNCIONA CON VALORES ENTEROS   !!!!\n");
    printf("----------------------------------------\n");
    gets(op);
    return op[0];
} //FIN menu()


/**
 * DEFINICION: Esta funcion le pide al usuario que ingrese las dimensiones de las matrices con las 
 * que va a operar, esta las guarda en variables pasando el valor por referencia, es por ello que 
 * la funcion tiene tipo de retorno VOID
*/
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
    getchar(); //funcion utilizada para leer el salto de linea que se queda en el buffer
}// fin leerDimensiones()

/**
 * DEFINICION: Esta funcion crea una matriz mediante memoria dinamica, con la funcion malloc.
 * el valor para asignar el numero de filas y columnas a la matriz lo toma de las variables que recibe
 * como parametro. Finalmente al terminar de crear la matriz la regresa.
 * @param filas --> variable entera que tiene el numero de FILAS
 * @param columnas --> variable entera que tiene el numero de COLUMNAS
 * @return --> devuelve un apuntador doble el cual apunta a la matriz creada.
*/
int **crearMatriz(int filas,int columnas){
    int i,j,**matriz;

    matriz = (int **) malloc(filas*sizeof(int *));
    for(i = 0; i < filas; i++){
        matriz[i] = (int *) malloc(columnas*sizeof(int));
    }
    return matriz;
} //fin crearMatriz()

/**
 * DEFINICION: Verifica si una matriz, que se le pasa como parametro, se ha creado correctamente, 
 * si la matriz tiene valor NULL, significa que la matriz no se creo y muestra un mensaje al usuario.
 * @param matriz --> Matriz a verificar si se creo correctamente.
 * @return --> devuelve 1 si la matriz tiene valor NULL, 0 si la matriz existe. 
*/
int validacionMatriz(int **matriz){
    if(matriz == NULL){
        printf("La matriz no se creo correctamente :v\n");
        return 1;
    }
    return 0;
}//FIN validacion()

/**
 * DEFINICION: Esta funcion permite ir llenando la matriz que se le pasa como parametro 
 * con valores que el usuario desee. A lo largo del proceso se le va preguntando al usuario
 * por el valor en cada posicion (x,y) de la matriz.
 * los otros parametros, filas y columnas, sirven para conocer los limites en los bucles para 
 * recorrer la matriz.
 * @param matriz --> Matriz a llenar
 * @param filas --> Numero de filas de la matriz
 * @param columnas --> Numero de columnas de la matriz
*/
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
}//fin llenarMatriz()

/**
 * DEFINICION: Funcion que permite imprimir los valores de la matriz que se le pasa
 * como parametro. Se busca que el formato de la impresion sea lo mas cercano a la forma
 * de la matriz, en dos dimensiones. tambien se necesita el valor de filas y columnas
 * para conocer los limites de los bucles y recorrrer la matriz.
 * @param matriz --> Matriz a imprimir.
 * @param filas --> Numero de filas de la matriz
 * @param columnas --> Numero de columnas de la matriz
*/
void imprimirMatriz(int **matriz,int filas,int columnas){
    int i,j;
    printf("La matriz quedo asi:\n");
    for(i = 0; i < filas; i++){
        for(j = 0; j < columnas; j++){
            printf("%d ",matriz[i][j]);
        }
        printf("\n");
    }
}// fin imprimirMatriz()

/**
 * DEFINCION: Esta funcion nos ayuda a determinar si las dimensiones de ambas 
 * matriz con las que se va a operar tienen las mismas dimensiones, en caso de que esto
 * no se cumpla devolvera 0.
 * @param filas1 --> filas de la primer matriz
 * @param columnas1 --> columnas de la primer matriz
 * @param filas1 --> filas de la segunda matriz
 * @param columnas2 --> filas de la segunda columnas
 * @return --> Devuelve 1 si las matrices tienen las mismas dimensiones y 0 si no se cumple esto
*/
int validacionTamanios(int filas1, int columnas1, int filas2, int columnas2){
    if(filas1 != filas2 || columnas1 != columnas2)
        return 0;
    return 1;
}//fin validacionTamanios

/**
 * DEFINICION: Esta funcion ya realiza la operacion de SUMA entre dos matrices las 
 * cuales recibe como parametro. Para recorrer las matrices necesitamos los valores de
 * filas y columnas.
 * @param matriz1 --> Matriz 1 para operar
 * @param matriz2 --> Matriz 2 para operar
 * @param filas --> numero de filas de las matrices.
 * @param columnas --> numero de filas de las matrices.
*/
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
}// fin sumarMatrices()

/**
 * DEFINICION: Esta funcion ya realiza la operacion de RESTA entre dos matrices las 
 * cuales recibe como parametro. Para recorrer las matrices necesitamos los valores de
 * filas y columnas.
 * @param matriz1 --> Matriz 1 para operar
 * @param matriz2 --> Matriz 2 para operar
 * @param filas --> numero de filas de las matrices.
 * @param columnas --> numero de filas de las matrices.
*/
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
}// fin restarMatrices()

/**
 * DEFINICION: Esta funcion realiza la operacion de multiplicar una matriz
 * por otro numero, el cual recibe como parametro, al momento de operar 
 * va imprimiendo matriz resultante. para multiplicar la matriz se requiere recorrerla
 * y en cada posicion de la misma realizar la multiplicacion por el numero que recibimos.
 * @param matriz --> Matriz con la que se va a operar.
 * @param filas --> filas de la matriz
 * @param columnas --> columnas de la matriz
 * @param escalar --> numero por el que se va a multiplicar la matriz
*/
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
}//fin MultiplicacionEscalar()

/**
 * DEFINICION: Esta funcion lee el numero por el que desea multiplicar una matriz el
 * usuario, este lo pasa por referencia a la variable que recibe como parametro.
 * @param multiplo --> variable donde se guarda el numero que ingresa el usuario.
*/
void leerMultiplo(int *multiplo){
    int numero;
    printf("Ingresa el escalar (numero) por el que vas a multiplicar la matriz:\n");
    scanf("%d",&numero);
    getchar();
    *multiplo = numero;
}// fin leerMultiplo()

/**
 * DEFINCION: Esta funcion tiene el mismo objetivo de leerDimensiones(), solamente 
 * que unicamente se leen las dimensiones para una sola matriz. Las dimensiones 
 * se pasan por referencia a las variables que reciben como parametro.
 * @param filas --> variable donde se guardan las filas de la matriz
 * @param columnas --> vvariable donde se guardan las columnas de la matriz
*/
void leerDimensiones2(int *filas,int *columnas){
    int fil,col;
    printf("Ingresa el numero de filas de la matriz\n");
    scanf("%d",&fil);
    printf("Ingresa el numero de columnas de la matriz\n");
    scanf("%d",&col);
    getchar();
    *filas = fil;
    *columnas = col;
}//fin leerDimensiones2()

/**
 * DEFINICION: Esta funcion valida la condicion para que una multiplicacion entre matrices
 * se pueda llevar a cabo, la condicion es columnas1 = filas2. Si esto se cumple regresara
 * 1, en caso contrario regresara 0.
*/
int validacionMultiplicacion(int filas1, int columnas1, int filas2, int columnas2){
    if(columnas1 != filas2)
        return 0;
    return 1;    
}//fin validacionMultiplicacion()

/**
 * DEFINICION: Esta funcion realiza la operacion de multiplicacion entre matrices
 * @param Matriz_resultante --> matriz donde se guarda el resultado de la multiplicacion 
 * @param matriz1 --> matriz 1
 * @param matriz2 --> matriz 2
 * @param filas1 --> Numero de filas de la matriz 1
 * @param columnas1 --> Numero de columnas de la matriz 1
 * @param filas2 --> Numero de filas de la matriz 2
 * @param columnas2 --> Numero de columnas de la matriz 2
*/
void multiplicarMatrices(int **Matriz_resultante, int **matriz1, int **matriz2, int filas1, int columnas1,int filas2, int columnas2){
    int i,j,k,aux = 0;
    for(i = 0; i < filas1; i++){
        for(j = 0; j < columnas2; j++){
           for(k = 0; k < columnas1; k++){
            aux = aux +(matriz1[i][k] * matriz2[k][j]);
           }//fin for k
           Matriz_resultante[i][j] = aux;
           aux = 0;
        }// fin for j
    }//fin for i

    printf("La matriz resultante es...\n");
    imprimirMatriz(Matriz_resultante,filas1,columnas2);
}//fin multiplicarMatrices()