#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    
    char letras[50];
    char letra;
    int qtd;
    int index[50];

    scanf("%s", letras);
    
    for (int m = 0; m < strlen(letras); m++) {
        letras[m] = tolower(letras[m]);
    }

    for (int i = 0; i < strlen(letras); i++) {
        letra = letras[i];
        qtd = 1;
        for (int j = i + 1; j < strlen(letras); j++) { //ababab
            if (letras[j] == letra) {
                qtd += 1;
                index[i] = j;
            }

            if (j == (strlen(letras) - 1)) {
                printf("Resposta: %c%d\n", letra, qtd);
            }
        }

        for (int l = 0; l < qtd; l++) {
            if (index[l] == '\0') {
                continue;
            } else {
                if (i == index[l]) {
                    break;
                }
            }
        }

        for (int n = 0; n < 50; n++) {
            index[n] = '\0';
        }
        qtd = 0;
    }

    return 0;
}