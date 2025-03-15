#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main() {

    char letNum[50];
    char num[10] = "";
    int index = 0;

    scanf("%s", letNum);
    
    for (int i = 0; i < strlen(letNum); i++) {
        //printf("i[%d] = %c\n", i, letNum[i]);
        if (isdigit(letNum[i])) {
            num[index] = letNum[i];
            //printf("i[%d] = %c\n", i, letNum[i]);
            //printf("index antes: %d\n", index);
            //printf("num[%d] = %c\n", index, num[index]);
            index++;
            //printf("index depois: %d\n", index);
            //printf("num: %s\n", num);
            //printf("num[%d] = %c\n", index, num[index]);
            if (!isdigit(letNum[i + 1]) || letNum[i + 1] == '\0') {
                //printf("Entrando no if...\n");
                //printf("num[%d] = %c\n", index, num[index]);
                //printf("index if: %d\n", index);
                int numero = atoi(num);
                //printf("num: %d", numero);
                //printf("i[%d] = %c\n", i, letNum[i]);
                //printf("index: %d\n", index);
                for (int l = 0; l < numero; l++) {
                    printf("%c", letNum[i - (index)]);
                }

                for (int k = 0; k < index; k++) {
                    num[k] = '\0';
                }
                //num[0] = '\0';
                index = 0;
                //printf("\nindex dps do print: %d", index);
                //printf("num: %d", num);

                //printf("index depois depois: %d\n", index);
            }
        } else {
            //printf("index (else): %d\n", index);
            //printf("ELSE: i[%d] = %c\n", i, letNum[i]);
            if (index > 0) {
                int numero = atoi(num);
                for (int j = 0; j < numero; j++) {
                    printf("%c", letNum[i - (index - 1)]);
                }

                for (int k = 0; k < index; k++) {
                    num[k] = '\0';
                }
                //num[0] = '\0';
                index = 0;
            } //else {
                //if ()
                //printf("\ni[%d] = %c", i, letNum[i]);
                
            //}
            //

        }
    }

    return 0;
}