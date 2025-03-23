#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    
    char letras[50], palavrasComp[50] = "", letrasComp[20][10];
    char letra;

    int qtd = 1, n = 0, tamComp;

    scanf("%s", letras);

    int tamS = strlen(letras);

    for (int j = 0; j < tamS; j++) {
        letras[j] = tolower(letras[j]);
    }

    for (int i = 0; i < tamS; i++) { // xyxyzzz
        letra = letras[0];
        strncat(palavrasComp, &letras[i], 1); //xyxyzzz
        if (letras[i + 1] == letra || letras[i + 1] == '\0') {
            strcpy(letrasComp[n], palavrasComp);
            tamComp = strlen(palavrasComp);
            n++;
            letra = letras[i + 1];
            palavrasComp[0] = '\0';
        // } else if (letras[i + 1] != letra || letras[i + 1] == '\0') {
        //     i += tamComp;
        //     letra = letras[i];
        //     if (letras[i + 1] == letra || letras[i + 1] == '\0') {
        //         strcpy(letrasComp[n], palavrasComp);
        //         tamComp = strlen(palavrasComp);
        //         n++;
        //         letra = letras[i + 1];
        //         palavrasComp[0] = '\0';
        //    }
        }
    }

    for (int j = 0; j < n; j++) {
        if (strcmp(letrasComp[j], letrasComp[j + 1]) == 0) {
            qtd += 1;
        } else {
            printf("%s%d", letrasComp[j], qtd);
            if (j < n - 1) {
                printf("-");
            }
            qtd = 1; // Reinicia a contagem
        }
    }

    return 0;
}