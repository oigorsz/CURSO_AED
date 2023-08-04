/*
Escreva uma função que receba uma string como parâmetro e 
retorne uma nova string com todas as letras em maiúsculo. 
A string original não deve ser modificada.
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

char* formatar(const char *str){
    //TAMANHO DA STRING
    int tamanho = 0;
    const char *p = str;

    while (*p != '\0')
    {
        tamanho++;
        p++;
    }

    //ALOCANDO MEMORIA
    char *novaStr = (char*)malloc((tamanho+1) * sizeof(char));

    if(novaStr == NULL){
        printf("Erro na alocação de memória.\n");
        exit(EXIT_FAILURE);
    }

    //COPIAR A STRING ORIGINAL PARA A NOVA

    for(int i = 0; i < tamanho; i++){
        novaStr[i] = toupper(str[i]);
    }

    novaStr[tamanho] = '\0';

    return novaStr;
    
}


int main(void){
    const char *str = "Igor de Souza Monteiro";
    char *strMaiuscula = formatar(str);

    printf("A STRING ORIGIAL: %s.\n", str);
    printf("A STRING FORMATADA: %s.\n", strMaiuscula);

    free(strMaiuscula);

    return 0;
}