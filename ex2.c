#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

char letraNumero(char letNum[50]);

int main() {

    char letNum[50];
    char num[] = "";
    int index = 0, letra = 0, caracteres = 0;

    letraNumero(letNum);
    
    for (int i = 0; i < strlen(letNum); i++) { // Percorre a string letNum
        //Verifica se só possui letras
        if (!isalpha(letNum[i])) { 
            letra = 0;
            //printf("!is alpha: %c\n", letNum[i]);
        } else {
            letra = 1;
            if (i == (strlen(letNum) - 1) && letra == 1) {
                printf("\nDigite de acordo com o formato correto.\nEx: LetraNumero-LetraNumero\nOu digite '/sair' para sair.\n");
                letraNumero(letNum);
                i = -1;
                num[0] = '\0';
                index = 0;
            }
        }

        // Verifica se só possui pontuações
        if (!ispunct(letNum[i])) {
            caracteres = 0;
            //printf("!is punct: %c\n", letNum[i]);
        } else {
            caracteres = 1;
            if (i == (strlen(letNum) - 1) && caracteres == 1) {
                printf("\nDigite de acordo com o formato correto.\nEx: LetraNumero-LetraNumero\nOu digite '/sair' para sair.\n");
                letraNumero(letNum);
                i = -1;
                num[0] = '\0';
                index = 0;
            }
         } 

        if (isdigit(letNum[i])) {
            while (!isalpha(letNum[i - 1]) || isdigit(letNum[0])) { // Verifica se a letra antes do número realmente é uma letra do alfabeto ou se a primeira letra da string também é realmente uma letra, pois se a primeira letra da string for um número, ele não estava conseguindo dizer se a letra antes desse número era ou não uma letra(alpha) e por isso estava dando erro. Se as condições derem como verdadeira, pede para que se siga o formato correto. (LetraNumero-LetraNumero)
                printf("\nDigite de acordo com o formato correto.\nEx: LetraNumero-LetraNumero\nOu digite '/sair' para sair.\n");
                letraNumero(letNum);
                i = -1; // Reinicia a leitura da string para a primeira letra
                num[0] = '\0'; // Reinicia cada posição da string num sem nada
                index = 0; // Reinicia o index para 0
                break;
            }
        } 
    }

    for (int n = 0; n < strlen(letNum); n++) {
        if (isdigit(letNum[n])) {
            num[index] = letNum[n];
            index++;
            if (!isdigit(letNum[n + 1]) || letNum[n + 1] == '\0') {
                int numero = atoi(num);

                for (int l = 0; l < numero; l++) {
                    printf("%c", letNum[n - (index)]);
                }

                for (int m = 0; m < index; m++) {
                    num[m] = '\0';
                }
                index = 0;
            }
        } else {
            if (index > 0) { // Verifica se o index é maior que 0, o que significa que tem um número com mais de 1 algarismo (Ex: 10)
                int numero = atoi(num); // Converte o número de string para inteiro
                for (int j = 0; j < numero; j++) {
                    printf("%c", letNum[n - (index - 1)]);
                }

                for (int k = 0; k < index; k++) { // Reinicia a string sem nada para o próximo número	
                    num[k] = '\0';
                }
                index = 0; // Reinicia o index para 0
            }          
        }
    }

        return 0;
}

char letraNumero(char letNum[50]) {
    scanf("%s", letNum);
    for (int i = 0; i < strlen(letNum); i++) {
        letNum[i] = tolower(letNum[i]);
    }
    if (strcmp(letNum, "/sair") == 0) { // Verifica se o usuário digitou '/sair' corretamente
        exit(0); // Para de rodar o código
    }
}
