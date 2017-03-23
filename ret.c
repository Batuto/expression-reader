#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>


char cadena[100], cadena2[100], *part;
char operadores[] = {'=','+','-','*','/'},
     operadores_encontrados[50];
struct estructura_identificador{
    char * identificador;
    int valor;
}identificadores[100];
int main(void),
    numero_identificadores = 0,
    x = 0, j, i,
    long_cad,
    long_oper;

int main(void){
    system("clear");
    long_oper = strlen(operadores);
    printf("Introduce una expresión:\n");
    scanf("%[^\n]", &cadena);
    strcpy(cadena2, cadena);
    long_cad = strlen(cadena);
    part = strtok(cadena, operadores);
    identificadores[numero_identificadores].identificador = part;
    while(part != NULL){
        numero_identificadores++;
        printf("%s\n",part);
        part = strtok(NULL, operadores);
        identificadores[numero_identificadores].identificador = part;
        }

    for(i = 0; i < long_cad; i++){
        // Ciclo para iterar sobre la cadena
        for(j = 0; j < long_oper; j++)
            // Ciclo para iterar sobre los operadores
            if(cadena2[i] == operadores[j]){
                operadores_encontrados[x] = cadena2[i];
                printf("%c","x");
                x++;
            }
        }

    printf("\nCantidad de identificadores:\n%d\n", numero_identificadores);
    printf("\nEncontrado:\n%s\n",operadores_encontrados);
    printf("\n\nIdentificadores encontrados:\n");
    for(int i = 0; i < numero_identificadores; i++){
        if(not isdigit(identificadores[i].identificador[0])){
            printf("\n%s",identificadores[i].identificador);
        }
    }
    printf("\n\nConstantes encontradas:\n");
    for(int i = 0; i < numero_identificadores; i++){
        if(isdigit(identificadores[i].identificador[0])){
            printf("\n%s",identificadores[i].identificador);
        }


    }
    printf("\n\n");
    return 0;
}
