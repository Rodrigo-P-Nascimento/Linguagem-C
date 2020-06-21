#include <stdio.h>

int main(void){

    float imc, altura, peso;

    puts("CALCULADORA DE IMC");
    puts("Nos informe a sua altura[metros] e o seu peso[kg].");
    printf("Altura[m]: ");
    scanf("%f", &altura);
    printf("Peso[kg]: ");
    scanf("%f", &peso);

    imc = peso / (altura * altura);

    if (imc <= 18.5){
        printf("O seu IMC eh de %.2fkg/m2.\nPortanto voce esta ABAIXO DO PESO.", imc);
    }
    if (imc > 18.5 && imc <= 25){
        printf("O seu IMC eh de %.2fkg/m2.\nPortanto o seu peso esta NORMAL.", imc);
    }
    if (imc > 25 && imc <= 30){
        printf("O seu IMC eh de %.2fkg/m2.\nPortanto voce esta SOBREPESO.", imc);
    } 
    if (imc > 30){
        printf("O seu IMC eh de %.2fkg/m2.\nPortanto voce esta OBESO.", imc);
    }      

    return 0;
}