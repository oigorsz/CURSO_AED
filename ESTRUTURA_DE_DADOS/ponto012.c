/*
Escreva uma função que receba duas strings e verifique se elas são iguais. 
A função deve retornar 1 se as strings forem iguais e 0 caso contrário.
*/

#include <stdio.h>

int equalStr(char *str1, char *str2){

    while(*str1 != '\0' && *str2 != '\0'){
        if(*str1 != *str2){
            return 0;
        }

        *str1++;
        *str2++;
    }

    return (*str1 == '\0' && *str2 == '\0');
}

int main(void){

    char str1[] = "igor";
    char str2[] = "Igor";
    char str3[] = "igor";

    printf("%s e %s = %d\n", str1, str2, equalStr(str1, str2));
    printf("%s e %s = %d\n", str1, str3, equalStr(str1, str3));
    printf("%s e %s = %d\n", str2, str3, equalStr(str2, str3));

    return 0;
}