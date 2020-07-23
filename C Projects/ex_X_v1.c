#include <stdio.h>

#define INDECES 10

//Esta parte abaixo se refere a questao 3 do exercicio.
float MediaArray(int conjunto[], int tam){
    int somaTotal = 0, i;

    for(i = 0; i < tam; i++){
        somaTotal += conjunto[i];
    }
    return somaTotal / tam;
}
//Esta parte acima se refere a questao 3 do exercicio.

//Esta parte abaixo se refere a questao 4 do exercicio.
int EmArray(int conjunto[], int tam, int elemento){
    int i;

    for(i = 0; i < tam; i++){
        if(elemento == conjunto[i]) return 1;
    }
    return 0;
}
//Esta parte acima se refere a questao 4 do exercicio.

//Esta parte abaixo se refere a questao 5 do exercicio.
int MaximoValorArray(int conjunto[], int tam){

    int maiorValor , i;

    for(i = 0; i < tam; i++){
        if(i == 0) maiorValor = conjunto[i];
        if(conjunto[i] > maiorValor) maiorValor = conjunto[i];
    }
    return maiorValor;
}
//Esta parte acima se refere a questao 5 do exercicio.

//Esta parte abaixo se refere a questao 6 do exercicio.
int EhArrayOrdenado(int conjunto[], int tam){
    int i, maiorValor;

    maiorValor = MaximoValorArray(conjunto, tam);

    for(i = 0; i < tam; i++){
        if(i == tam - 1){
            if(maiorValor == conjunto[i]) return 1;
            else return 0;
        }
    }
}
//Esta parte acima se refere a questao 6 do exercicio.


int main(void){

    /*
    Esta parte abaixo se refere a questao 1 
    int conjunto[INDECES] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    */
    int conjunto[INDECES], i, soma=0, elemento;
    float media;
    int elementoPresent, maiorValor,arrayOrdenada;
    
    //Esta parte abaixo se refere a questao 2 do exercicio.

    printf("Digite os 10 valores para o Array.\n");
    
    for(i = 0; i < INDECES; i++){
        printf("%d valor: ", i+1);
        scanf("%d", &conjunto[i]);
    }
    
    //Esta parte acima se refere a questao 2 do exercicio.


    //Esta parte abaixo se refere a questao 1 do exercicio.

    for(i = 0; i < INDECES; i++){
        printf("%d ", conjunto[i]);
        if(i == 9) puts("");
    }

    for(i = 9; i >= 0; i--){
        printf("%d ", conjunto[i]);
        if(i == 0) puts("");
    }

    printf("O quinto elemento do Array eh: %d\n", conjunto[4]);

    for(i = 0; i < INDECES; i++){
        if(i == 0) printf("Os elementos armazenados em indices impares: ");
        if(i % 2 != 0) printf("%d ", conjunto[i]);
    }

    for(i = 0; i < 10; i++){
        soma+=conjunto[i];
    }

    printf("\nA soma de todos os elementos presentes do Array eh %d\n", soma);

    //Esta parte acima se refere a questao 1 do exercicio.


    //Esta parte abaixo se refere a questao 3 do exercicio.

    media = MediaArray(conjunto, INDECES);

    printf("A media dos elementos do Array eh: %.2f\n", media);

    //Esta parte acima se refere a questao 3 do exercicio.


    //Esta parte abaixo se refere a questao 4 do exercicio.

    printf("Qual valor voce deseja procurar no Array: ");
    scanf("%d", &elemento);

    elementoPresent = EmArray(conjunto, INDECES, elemento);
    if(elementoPresent == 0) printf("O valor %d nao existe no Array\n", elemento);
    else printf("O valor %d existe no Array\n", elemento);

    //Esta parte acima se refere a questao 4 do exercicio.


    //Esta parte abaixo se refere a questao 5 do exercicio.

    maiorValor = MaximoValorArray(conjunto, INDECES);
    printf("O maior valor do Array foi: %d\n", maiorValor);

    //Esta parte acima se refere a questao 5 do exercicio.


    //Esta parte abaixo se refere a questao 6 do exercicio.

    arrayOrdenada = EhArrayOrdenado(conjunto, INDECES);
    if(arrayOrdenada == 0) printf("Este Array nao esta ordenado");
    else printf("Este Array esta ordenado");
    
    //Esta parte acima se refere a questao 6 do exercicio.

    return 0;
}

