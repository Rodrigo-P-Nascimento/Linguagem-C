#include <stdio.h>

int main(void){

    int a, b, soma_total, x;

    soma_total = 0;

    puts("Digite os valores inteiros para a e b.");
    printf("A: ");
    scanf("%d", &a);
    printf("B: ");
    scanf("%d", &b);

    if (a > b){
        x = a;
        a = b;
        b = x;
    }

    x = a;

    while (a <= b){
        printf("%d\n", a);
        soma_total += a;
        a += 1;
        
    }
    printf("A soma dos valores do intervalo [%d-%d] eh: %d", x, b, soma_total);
    return 0;
}