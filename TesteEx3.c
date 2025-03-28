#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    
    char letras[50], palavrasComp[50] = "", palavrasComp1[50] = "", letrasComp[50][10], qtdLista[50];
    char letra, letraLida;

    //int qtd = 1,
    int n = 0, tamComp, k, qtd = 1;

    scanf("%s", letras);

    int tamS = strlen(letras);

    for (int j = 0; j < tamS; j++) {  //Padroniza as letras em minúsculas
        letras[j] = tolower(letras[j]);
    }

    letra = letras[0];
    printf("String: %s\n", letras);
    printf("tamS: %d\n", tamS);

    for (int i = 0; i < tamS; i++) { // z z[1] letra = z[2] xyxy
        //letra = letras[0];
        printf("Letra escolhida %d: %c\n", i, letra);
        strncat(palavrasComp, &letras[i], 1); //"zz" 
        k = i + 1;

        if (letras[k] == letra || letras[k] == '\0') { // z[0]z[1]z[2] xy xy
            //i = 1 k = 2
            if (i == 0) {
                qtd = 1;
            } else if (i == tamComp - 1) {
                //strcpy(letrasComp[n], palavrasComp[0]);
                letrasComp[n][0] = palavrasComp[0];
                letrasComp[n][1] = '\0';
                qtd = tamS;
                n++;
            } else {
                tamComp = strlen(palavrasComp);
                //tamComp = strlen(palavrasComp);
                //printf("tamComp: %d\n", tamComp);
                letra = letras[i];
                // if (letras[k] != letra) { //zzcarloscarlos
                //     strcpy(letrasComp[n], palavrasComp);
                //     n++;
                //     palavrasComp[0] = '\0';
                // }
            }
        } else if (letras[k] != letra) { //zzz xyxy
            strncat(palavrasComp1, &letras[i], 1);
            for (int l = k; l < tamS; l++) { //zzz Letra = c arl o[i] s[k] carlos
                strncat(palavrasComp1, &letras[l], 1); 
                if (letras[l + 1] == letra) {
                    letra = letras[l + 1];
                    qtd += 1;
                    strcpy(letrasComp[n], palavrasComp1);
                    n++;
                }
            }
        }
    }

    for (int j = 0; j < n; j++) {
        if (strcmp(letrasComp[j], letrasComp[j + 1]) == 0) {
            qtd += 1;
        } else {
            printf("%s%d", letrasComp[j], qtd);
            if (j < n - 2) {
                printf("-");
            }   
        qtd = 1; // Reinicia a contagem
        }
    }

    return 0;
}