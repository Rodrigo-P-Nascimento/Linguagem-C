#include <stdio.h>

int main(void){

    int idade;

    printf("Digite a sua idade: ");
    scanf("%d", &idade);

    if (0 <= idade && idade < 21){
        printf("Voce eh um jovem de %d anos!", idade);
    }else{
        if (idade < 60){
            printf("Voce eh um adulto de %d anos!", idade);
        }else{
            printf("voce eh um idoso de %d anos!", idade);
        }
    }

    return 0;
}