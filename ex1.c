#include <stdio.h>
#include <string.h>

int main() {

    char letras[50];

    scanf("%s", letras);
    for (int i = 0; i < strlen(letras); i++) {
        int cont = 1;
        while (letras[i] == letras[i + 1]) {
            cont += 1;
            i++;
            //printf("%c%d - ", letras[i], cont);
        }
        printf("%c%d", letras[i], cont);
        if (i < (strlen(letras) - 1)) {
            printf("-");
        }
    }

    

}