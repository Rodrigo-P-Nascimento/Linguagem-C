#include <stdio.h>

int main(void){

    int n1,n2,n3;

    puts("Digite 3 numeros inteiros:");
    printf("O primeiro numero: ");
    scanf("%d", &n1);
    printf("O segundo numero: ");
    scanf("%d", &n2);
    printf("O terceiro numero: ");
    scanf("%d", &n3);

    if (n1 == n2 && n2 == n3){
        puts("Os 3 valores informados sao iguais.");
        }
    else if (n1 >= n2 && n1 >= n3){
        printf("\nO numero %d eh o maior.", n1);
        }
    else if(n2 >= n1 && n2 >= n3){
        printf("\nO numero %d eh o maior.", n2);
        }
    else if(n3 >= n2 && n3 >= n1){
        printf("\nO numero %d eh o maior.", n3);
        }

    return 0;
}