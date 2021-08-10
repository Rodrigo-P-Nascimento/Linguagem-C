#include <stdio.h>
#include <math.h>

typedef struct { //Definição de uma estrutura que armazena as coordenadas inteiras X e Y de um ponto, 
    int x, y;
}Ponto_Proximo;

float Distancia(Ponto_Proximo p1, Ponto_Proximo p2){
    return sqrt(pow((p2.x - p1.x), 2) + pow(p2.y - p1.y, 2)); //Calcula da distância entre dois pontos
}

int main(){

    Ponto_Proximo p, pontoAtual, MenorPonto;

    int i, n;
    float distMenor, distanciaAtual;

    scanf("%d", &p.x);
    scanf("%d", &p.y);
    //Leitura do ponto inicial, na qual chamamos |p|
    scanf("%d", &n);
    //Leitura do número de pontos que serão usados em uma comparação para ver qual é o mais proximo do ponto |p|
    for(i=0; i < n;i++){
        scanf("%d", &pontoAtual.x);
        scanf("%d", &pontoAtual.y);

        if( i == 0){    //Iniciamos a variavél disMenor com a primeira distancia, na qual será uma base para as proxímas análises
            distMenor = Distancia(p, pontoAtual);
            MenorPonto.x = pontoAtual.x;
            MenorPonto.y = pontoAtual.y;
        }else{
            distanciaAtual  = Distancia(p, pontoAtual);
            if(distMenor >= distanciaAtual){
                distMenor = distanciaAtual;
                MenorPonto.x = pontoAtual.x;
                MenorPonto.y = pontoAtual.y;
            }
        }
    }
    printf("Ponto mais perto é (%d, %d)\n", MenorPonto.x, MenorPonto.y);

    return 0;
}