#include <stdio.h>

int main(void){

    int anterior, atual, razao_geral;
    int razao_dif, ehPa;

    printf("Digite o primeiro numero: ");
    scanf("%d", &anterior);
    printf("Digite o segundo: ");
    scanf("%d", &atual);

    razao_geral = atual - anterior;

    ehPa = 1;

    while (atual != -1){
        razao_dif = atual - anterior;

        if (razao_dif != razao_geral){
            ehPa = 0;
        }

        anterior = atual;
        printf("Digite o proximo numero da sequencia: ");
        scanf("%d", &atual);

    }

    if (ehPa == 1){
        printf("Essa sequencia formou uma PA de razao %d.\n", razao_geral);
    }else{
        printf("Essa sequencia nao formou uma PA");
    }
    
    return 0;
}