#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
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
    x = 0,
    long_cad, long_oper;

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
        part = strtok(NULL, operadores);
        identificadores[numero_identificadores].identificador = part;
        }
    for(int i = 0; i < long_cad; i++){
        // Ciclo para iterar sobre la cadena
        for(int j = 0; j < long_oper; j++)
            // Ciclo para iterar sobre los operadores
            if(cadena2[i] == operadores[j]){
                operadores_encontrados[x] = cadena2[i];
                x++;
            }
        }
    printf("\nEncontrado:\n%s\n",operadores_encontrados);
    printf("\n\nIdentificadores encontrados:\n");
    for(int i = 0; i < numero_identificadores; i++){
        if(not isdigit(identificadores[i].identificador[0])){
            printf("\n%s",identificadores[i].identificador);
        }
    }
    printf("\n\nConstantes encontradas:\n");
    for(int i = 1; i < numero_identificadores; i++){
        if(isdigit(identificadores[i].identificador[0])){
            printf("\n%s",identificadores[i].identificador);
            identificadores[i].valor = atoi(identificadores[i].identificador);
        }
        else{
            printf("Introduce el valor de '%s':\n>>", identificadores[i].identificador);
            scanf("%d", &identificadores[i].valor);
        }
    }
    long_oper = strlen(operadores_encontrados); // Se reutiliza la variable.
    for(int i = 0; i < long_oper; i++){
        if(operadores_encontrados[i] == 61)
            identificadores[0].valor = identificadores[i+1].valor;
        if(operadores_encontrados[i] == 43)
            identificadores[0].valor += identificadores[i+1].valor;
        if(operadores_encontrados[i] == 45)
            identificadores[0].valor -= identificadores[i+1].valor;
        if(operadores_encontrados[i] == 42)
            identificadores[0].valor  *= identificadores[i+1].valor;
        if(operadores_encontrados[i] == 47)
            identificadores[0].valor /= identificadores[i+1].valor;
    }
    printf("\n\n\nResultado:\n\t%s = %d\n", identificadores[0].identificador, identificadores[0].valor);
    return 0;
}
