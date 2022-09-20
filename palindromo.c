/**
 * @file                palindromo.c
 * @author              Ramirez Morales Erick Hazel
 * @brief               Programa dedicado a determiar si una cadena ingresada por 
 *                      el usuario es palindromo o no, el programa funcionará con 
 *                      espacios.
 * @date                18-09-22
 * @version             0.2
 * 
 */ 

// * BIBLIOTECAS
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h> // * Biblioteca necesaria para usar gets() y fgets()

#define TAM 50     //* Tamaño maximo de la palabra que se va a analizar

// * PROTOTIPO DE FUNCIONES
void recepcionCadena(char *cad);
void esPalindromo(char *cad);
void esPalindromo2(char *cad);
void esPalindromo3(char *cad);
int esMayuscula(char letra);
int esEspacio(char letra);

// * PROGRAMA PRINCIPAL
int main(){

    char cadena[TAM];
    recepcionCadena(cadena);
    
    //* LIMPIEZA DE CADENA
    cadena[strcspn(cadena, "\n\r")] = '\0';
    
    //* VERIFICACION DE PALINDROMO
    //esPalindromo(cadena);
    //esPalindromo2(cadena);
    esPalindromo3(cadena);
    
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
    fgets(cad,TAM,stdin);
} //FIN recepcionCadena(char *cad)

/**
 * void esPalindromo(char *cad)
 * @param cad --> cadena que se analizara si es palindromo o no
 * *NOTA: Esta funcion solo funciona correctamente si la cadena viene en minusculas y sin espacios
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
    if(bandera == 1)
        printf("La cadena es PALINDROMO\n");
    else    
        printf("La cadena NO ES PALINDROMO\n");    
}//FIN esPalindromo(char *cad)

/**
 * void esPalindromo2(char *cad)
 * @param cad --> cadena que se analizara si es palindromo o no
 * * NOTA: Esta funcion ya valida si la cadena tiene mayusculas y minusculas
 * * Ejemplo: si cad = "REConocer"
 * * El programa arroja "Es PALINDROMO"
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
            }//fin if interno
        }//fin if 
        //* Analisis considerando al caracter que apunta i como mayuscula
        else{
            if(cad[i] != cad[j] && cad[i] != (cad[j])-32){
                bandera = 0;
                break;
            }//fin if interno
        }
        j--;
    }//fin for 
    if(bandera == 1)
        printf("La cadena es PALINDROMO\n");
    else    
        printf("La cadena NO ES PALINDROMO\n");    
}//fin esPalindromo2(char *cad)

/**
 * @param cad --> cadena que se analizara si es palindromo o no
 * *NOTA: Esta funcion ya valida si la cadena tiene espacios o si la cadena tiene mayusculas y 
 * *minusculas 
 * *Ejemplo: "Re_conoce_r" --> Output = "Es PALINDROMO"
 * *Los "_" representan a los espacios en el ejemplo, al momento de ejecutar no se ve nada en el
 * *espacio en blanco
 */ 
void esPalindromo3(char *cad){
    int i,j = strlen(cad) - 1,bandera = 1,bandera2;
    for(i = 0; i <= j; i++){
        // * VALIDACION DE ESPACIOS
        while(esEspacio(cad[i]))
            i++;
        while(esEspacio(cad[j]))
            j--;
        bandera2 = esMayuscula(cad[i]);
        //* Analisis considerando al caracter que apunta i como minuscula
        if(bandera2 == 0){
            if(cad[i] != cad[j] && cad[i] != (cad[j])+32){
                bandera = 0;
                break;
            }//fin if interno
        }//fin if 
        //* Analisis considerando al caracter que apunta i como mayuscula
        else{
            if(cad[i] != cad[j] && cad[i] != (cad[j])-32){
                bandera = 0;
                break;
            }//fin if interno
        }
        j--;
    }//fin for
    if(bandera == 1)
        printf("La cadena es PALINDROMO\n");
    else    
        printf("La cadena NO ES PALINDROMO\n");    
}//FIN void esPalindromo3(char *cad)

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

/**
 * int esEspacio(char letra)
 * @param letra --> caracter a analizar si es espacio o no
 * @return int --> devuelve 1 si es espacio, 0 si no es espacio
 * *NOTA: El analisis se hará de acuerdo al valor ascii del caracter "letra"
 */ 
int esEspacio(char letra){
    if(letra == 32)
        return 1;
    else
        return 0;   
}//FIN int esEspacio(char letra)