#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {

    char letNum[50];

    scanf("%s", letNum);
    
    for (int i = 0; i < strlen(letNum); i++) {
        while (isdigit(letNum[i])) {
            int numero = letNum[i] - '0'; // Converte  o caractere para inteiro
            printf("Numero %d", numero);
            i++;
            // if (isdigit(letNum[i])) {
            //     int numero = letNum[i] - '0';
            // }
            if (isdigit(letNum[i]) == 1) {
                for (int j = 0; j < numero; j++) {
                    printf("%c", letNum[i - 1]);
                }
            } else if (isdigit(letNum[i] == 2)) {
                for (int j = 0; j < numero; j++) {
                    printf("%c", letNum[i - 2]);
                }
            } else {
                printf(" ");
            }
            }
        }
    }
