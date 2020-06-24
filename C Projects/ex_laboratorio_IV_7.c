#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void){
	int palpite, numeroCorreto, cont;

    srand(time(NULL));
    numeroCorreto = rand() % 100;
	puts("Bem-vindo!");

	puts("Adivinhe o numero:");
	scanf("%d", &palpite);

    cont = 1;

    while(palpite != numeroCorreto){
        if (palpite > numeroCorreto){
            puts("Palpite alto!");
        }else{
            puts("Palpite foi baixo!");
        }
        printf("\nDigite seu novo palpite: ");
        scanf("%d", &palpite);
        cont += 1;
    }
    puts("\nVoce ganhou!");
    printf("Voce ganhou o jogo com %d tentativas.\n", cont);
	puts("Fim do jogo.");

	return 0;
}
