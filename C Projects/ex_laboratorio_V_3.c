#include <stdio.h>

int main(void){

    int numero, cont, i;

    cont = 0;

    printf("Digite o numero: ");
    scanf("%d", &numero);

    for (i = 1; i <= numero; i += 1){
        if (numero % i == 0){
            cont += 1;
        }
    }

    if (cont == 2){
        printf("\nO numero %d, possui apenas %d divisores, portanto ele eh um numero primo!", numero, cont);
    }else{
        printf("\nO numero %d possui %d divisores, portanto ele nao eh um numero primo!", numero, cont);
    }
    
    return 0;
}