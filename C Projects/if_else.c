#include <stdio.h>
#include <stdlib.h>

int main(){
    int palpite;

    puts("Ola, humano EU o Temido PC, te desafio a advinhar um numero!");
    scanf("%d", &palpite);

    printf("O seu palpite foi %d.\n", palpite);

    if (palpite == 5){
        puts("Parabens humano, vc acertou!");
    }else{
        puts("Voce errou!");
        if (palpite > 5){
            puts("Tente um numero um pouco mais baixo.");
        }else{
            puts("Tente um numero um pouco mais alto.");
        }
        
    }
    
    return 0;
}