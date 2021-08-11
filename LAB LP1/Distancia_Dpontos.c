#include <stdio.h>
#include <math.h>

typedef struct { //Definição de uma estrutura que armazena as coordenadas inteiras X e Y de um ponto, 
    int x, y;
}Ponto_Proximo;

int Distancia(Ponto_Proximo p1, Ponto_Proximo p2){
    return (pow((p2.x - p1.x), 2) + pow(p2.y - p1.y, 2)); //Calcula da distância entre dois pontos
}

int main(){

    Ponto_Proximo p1, p2;

    int dist;

    //Lendo os valores para as variáveis
    scanf("%d", &p1.x);
    scanf("%d", &p1.y);
    scanf("%d", &p2.x);
    scanf("%d", &p2.y);

    dist = Distancia(p1, p2);
    printf("%d", dist);

    return 0;
}