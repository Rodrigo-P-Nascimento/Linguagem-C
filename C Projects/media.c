#include <stdio.h>

int main(void){
    float nota1, nota2, nota3;
    float media;

    printf("Para calcular a media do aluno, digite a primeira nota: ");
    scanf("%f", &nota1);
    printf("A segunda nota: ");
    scanf("%f", &nota2);
    printf("A terceira nota: ");
    scanf("%f", &nota3);

    media = (nota1 + nota2 + nota3)/3;

    printf("A media do aluno foi de: %.2f.", media);


    return 0;
}
