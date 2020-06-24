#include <stdio.h>

int main(void){

    int a, b;

    puts("Digite os valores inteiros para a e b.");
    printf("A: ");
    scanf("%d", &a);
    printf("B: ");
    scanf("%d", &b);

    while (a <= b){
        printf("%d\n", a);
        a += 1;
    }

    return 0;
}