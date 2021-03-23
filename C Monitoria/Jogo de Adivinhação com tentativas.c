#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void){
	int palpite, numeroCorreto, palpites;

    srand(time(NULL));
    numeroCorreto = rand() % 100;
	puts("Bem-vindo!");

	puts("Adivinhe o numero:");
	scanf("%d", &palpite);


    for (palpites = 5; palpite != numeroCorreto && palpites > 0; palpites -= 1){
        if (palpite > numeroCorreto){
            puts("Palpite alto!");
        }else{
            puts("Palpite foi baixo!");
        }
        printf("\nAgora so lhe restam %d palpites!", palpites);
        printf("\nDigite seu novo palpite: ");
        scanf("%d", &palpite);

    }
    if (palpite == numeroCorreto){
        puts("Voce ganhou!");
    }else{
        puts("Voce nao tem mais palpites, portanto voce perdeu!");
    }
    
	puts("Fim do jogo.");

	return 0;
}
