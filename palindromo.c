/**
 * @file                palindromo.c
 * @author              Ramirez Morales Erick Hazel
 * @brief               Programa dedicado a determiar si una cadena ingresada por 
 *                      el usuario es palindromo o no, el programa funcionará con 
 *                      espacios.
 * @date                18-09-22
 * @version             0.1
 * 
 */ 

// * BIBLIOTECAS
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h> // * Biblioteca necesaria para usar gets() y fgets()

// * PROTOTIPO DE FUNCIONES
void recepcionCadena(char *cad);
void esPalindromo(char *cad);
void esPalindromo2(char *cad);
int esMayuscula(char letra);
// * PROGRAMA PRINCIPAL
int main(){

    char cadena[20];
    int i;
    
    recepcionCadena(cadena);
    //* LIMPIEZA DE CADENA
    cadena[strcspn(cadena, "\n\r")] = '\0';
    //* VERIFICACION DE PALINDROMO
    //esPalindromo(cadena);
    esPalindromo2(cadena);
    return 0;
}


// * DEFINICION DE FUNCIONES
/**
 * void recepcionCadena(char *cad)
 * cad es la referencia donde se guardara la cadena ingresada por el usuario, el valor se regresa por referencia
 */ 
void recepcionCadena(char *cad){
    printf("Ingresa una cadena:\n");
    /**
     * *fgets() guarda la cadena ingresada en el flujo inluyendo el salto de linea \n
     * * Es importante tener esto en cuenta, por lo que hay que limpiar la cadena de ese salto de linea
     */ 
    fgets(cad,20,stdin);
} //FIN recepcionCadena(char *cad)


/**
 * void esPalindromo(char *cad)
 * cad es la referencia a la cadena que estamos analizando.
 */ 
void esPalindromo(char *cad){
    //* NOTA: La funcion strlen() cuenta los caracteres de la cadena incluyendo el terminador '\0'
    //* por lo que el tam real es -->  tam = strlen(cad) -1;
    int i,j = strlen(cad) - 1,bandera = 1;
    
    for(i = 0; i <= j; i++){
        printf("i = %c    j = %c\n",cad[i],cad[j]);
        if(cad[i] != cad[j]){
             bandera = 0;
             break;
        }
        j--;
    }//fin de for
    
    if(bandera == 1){
        printf("La cadena es PALINDROMO\n");
    }
    else{
        printf("La cadena NO ES PALINDROMO\n");
    }
}//FIN esPalindromo(char *cad)

/**
 * void esPalindromo2(char *cad)
 * Funcion que valida minusculas y mayúculas
 */ 
void esPalindromo2(char *cad){
    // * La variable "bandera" se usa para determinar si la palabra es palindromo
    // * La variable "bandera2" se usa para determinar si el caracter es mayucula o minuscula,
    // * siendo bandera2 = 0 --> minuscula; bandera2 = 1 --> mayuscula
    int i,j = strlen(cad) - 1,bandera = 1,bandera2;
    
    for(i = 0; i <= j; i++){
        bandera2 = esMayuscula(cad[i]);
        //* Analisis considerando al caracter que apunta i como minuscula
        if(bandera2 == 0){
            if(cad[i] != cad[j] && cad[i] != (cad[j])+32){
                bandera = 0;
                break;
            }
        }//fin if 
        //* Analisis considerando al caracter que apunta i como mayuscula
        else{
            if(cad[i] != cad[j] && cad[i] != (cad[j])-32){
                bandera = 0;
                break;
            }
        }
        j--;
    }//fin for 
    if(bandera == 1)
        printf("La cadena es PALINDROMO\n");
    else    
        printf("La cadena NO ES PALINDROMO\n");    
}//fin esPalindromo2(char *cad)

/**
 * int esMayuscula(char letra);
 * @param char letra --> caracter a analizar
 * @return int --> 0 si es minuscula, 1 si es mayuscula
 */ 
int esMayuscula(char letra){
    if(letra >= 65 && letra <= 90)
        return 1;
    else
        return 0;    
}//FIN int esMayuscula(char letra)