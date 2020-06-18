#include <stdio.h>

int main(void){
    float altura, peso_ideal;
    int sexo;

    puts("Para saber o seu peso ideal precisamos da sua sexo e altura.");
    printf("Sexo[1  para masc.| 0 para fem.]: ");
    scanf("%d", &sexo);
    printf("Altura[m]: ");
    scanf("%f", &altura);

    if (sexo == (0||1)){
        if (sexo == 0){
            peso_ideal = (62.1*altura) - 44.7;
            printf("O peso ideal dessa mulher de %.2f eh: %.2fkg", altura, peso_ideal);
        }else{
            peso_ideal = (72.7*altura) - 58;
            printf("O peso ideal desse homem de %.2f eh: %.2fkg", altura, peso_ideal);
        }
    }else{
        puts("Informe o seu sexo respeitando as regras!");
    }
    
    return 0;
}