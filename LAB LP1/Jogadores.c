#include <stdio.h>
#include <string.h>

#define TAM 51

typedef struct {
    char nomeJogador[TAM];
    int idade;
    int chutesGol;
    int gol;
}tJogador;

//Função que tira o '\n' do final da string, usando o fgets
void TiraN( char *linhaString ){
    linhaString[strcspn ( linhaString, "\n" )] = '\0';
}
//Função que limpa o buffer de entrada, usado antes de ler strings
void limparBuffer(void){
    char c;
    while((c = getchar()) != '\n' && c != EOF);
}
///Função que calcula a pontaria do jogador
float PorGol(int chgol, int gol){
    return (float)chgol / gol;
}

int main(){

    tJogador jg1, jg2;
    float pgol1, pgol2;
    //Leitura das informações que são necessarias
    fgets(jg1.nomeJogador, TAM, stdin);
    TiraN(jg1.nomeJogador);
    scanf("%d", &jg1.idade);
    scanf("%d", &jg1.chutesGol);
    scanf("%d", &jg1.gol);
    pgol1 = PorGol(jg1.chutesGol, jg1.gol);

    limparBuffer();
    fgets(jg2.nomeJogador, TAM, stdin);
    TiraN(jg2.nomeJogador);
    scanf("%d", &jg2.idade);
    scanf("%d", &jg2.chutesGol);
    scanf("%d", &jg2.gol);
    pgol2 = PorGol(jg2.chutesGol, jg2.gol);

    if(pgol1 < pgol2){
        printf("%s (%d)\n", jg1.nomeJogador, jg1.idade);
    }else{
        printf("%s (%d)\n", jg2.nomeJogador, jg2.idade);
    }

    return 0;
}