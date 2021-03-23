#include <stdio.h>

int main(void){

    int f1, f2, f3,  repeticoes, i;

    f1 = 0;
    f2 = 1;

    printf("Digite o numero de repeticoes: ");
    scanf("%d", &repeticoes);

    if (repeticoes > 2){
        printf("\n1 ");
        for (i = 1; i < repeticoes; i += 1){
            f3 = f1 + f2;
            f1 = f2;
            f2 = f3;

            printf("%d ", f3);
        }
    }else{
        printf("Coloque um valor maior que 2");
    }

    return 0;
}