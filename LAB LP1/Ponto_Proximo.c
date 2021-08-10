#include <stdio.h>
#include <math.h>

typedef struct 
{
    int x, y;
}Ponto_Proximo;

float Distancia(Ponto_Proximo p1, Ponto_Proximo p2){
    return sqrt(pow(p2.x, 2) - pow(p1.x, 2) + pow(p2.y, 2) - pow(p1.y, 2));
}

int main(){

    Ponto_Proximo p, atual, MDist;


    scanf("%d", &p.x);
    scanf("%d", &p.y);

    int i, n;
    float distMenor, distanciaAtual;

    scanf("%d", &n);

    for(i=0; i < n;i++){
        scanf("%d", &atual.x);
        scanf("%d", &atual.y);

        if( i == 0){
            distMenor = Distancia(p, atual);
        }else{
            distanciaAtual  = Distancia(p, atual);

            if(distMenor >= distanciaAtual){
                distMenor  = distanciaAtual;
                MDist.x = atual.x;
                MDist.y = atual.y;
            }
        }
    }
    printf("%.2f\n", distMenor);
    printf("Ponto mais perto eh (%d, %d)\n", MDist.x, MDist.y);

    return 0;
}