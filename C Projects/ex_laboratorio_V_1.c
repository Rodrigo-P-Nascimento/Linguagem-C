#include <stdio.h>

int main(void){

    int numero, expoente, cont, valor_fixo;

    printf("Digite o numero e seu expoente");
    printf("\nNumero: ");
    scanf("%d", &numero);
    printf("Expoente: ");
    scanf("%d", &expoente);

    valor_fixo = numero;

    for (cont = 1; cont < expoente; cont += 1) {
        numero = numero * valor_fixo;
    }
    printf("\nValor: %d", numero);
   
    return 0;
}