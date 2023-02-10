#include<stdio.h>
#include<stdlib.h>

int **Matriz1, **Matriz2;


int **crearMatriz2(int f,int c);
void llenarMatriz(int **matriz,int f,int c);
int validacionMatriz(int **matriz);
int validacionTamanios(int filas1, int columnas1, int filas2, int columnas2);
void sumarMatrices(int **matriz1, int **matriz2, int filas, int columnas);
void imprimirMatriz(int **matriz,int f,int c);


int main(){
    int filas = 2, columnas = 2,filas2 = 3, columnas2 = 2;

    //Creacion de matrices
    Matriz1 = crearMatriz2(filas,columnas);
    Matriz2 = crearMatriz2(filas2,columnas2);
    
    printf("Matriz 1\n");
    llenarMatriz(Matriz1,filas,columnas);
    printf("Matriz 2\n");
    llenarMatriz(Matriz2,filas2,columnas2);
    
    if(validacionTamanios(filas,columnas,filas2,columnas2)){
        sumarMatrices(Matriz1,Matriz2,filas,columnas);
    }
    else
        printf("No se puede sumar\n");
    
    
    return 0;
}


int **crearMatriz2(int f,int c){
    int i,j,**matriz;

    matriz = (int **) malloc(f*sizeof(int *));
    for(i = 0; i < f; i++){
        matriz[i] = (int *) malloc(c*sizeof(int));
    }
    return matriz;
}

void imprimirMatriz(int **matriz,int f,int c){
    int i,j;
    printf("La matriz quedo asi:\n");
    for(i = 0; i < f; i++){
        for(j = 0; j < c; j++){
            printf("%d ",matriz[i][j]);
        }
        printf("\n");
    }
}

void llenarMatriz(int **matriz,int f,int c){
    int i,j;
    if(matriz == NULL){
        perror("La matriz esta vacia -_-\n");
        return;
    }

    for(i = 0; i < f; i++){
        for(j = 0; j < c; j++){
            printf("Ingresa el valor de la posicion [%d][%d]:\n",i,j);
            scanf("%d",&matriz[i][j]);
        }
    }
    imprimirMatriz(matriz,f,c);
}

int validacionMatriz(int **matriz){
    if(matriz == NULL){
        printf("La matriz no se creo correctamente :v\n");
        return 1;
    }
    return 0;
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


