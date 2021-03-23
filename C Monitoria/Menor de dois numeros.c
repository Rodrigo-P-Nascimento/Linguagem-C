#include <stdio.h>

int main(void){

    float n1, n2;

    puts("Digite dois numeros para ser feita a analise.");
    printf("Primeiro numero: ");
    scanf("%f", &n1);
    printf("Segundo numero: ");
    scanf("%f",&n2);

    if (n1 == n2){
        printf("Os valores informados (%.2f e %.2f) sao iguais.", n1, n2);
    }else{
        if (n1 < n2){
            printf("O numero %.2f eh menor que %.2f", n1, n2);
        }else{
            printf("O numero %.2f eh menor que %.2f", n2, n1);
        }
    }
    
    return 0;
}