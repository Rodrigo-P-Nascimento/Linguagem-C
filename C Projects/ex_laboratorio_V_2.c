#include <stdio.h>
#include <math.h>

int main(void){

    char caractere_tabela;
    float pri_termo, razao, num_termos;
    float potencia, ultimo_termo, soma_total;
    float i;
    

    puts("Este programa realiza progressao aritmetica ou geometrica.");
    puts("Digite A para progressao aritmetica ou G para geometrica");
    printf("\nQual sera a progressao[A-G]:");
    scanf("%c", &caractere_tabela);
    printf("\nPrimeiro termo da progressao: ");
    scanf("%f", &pri_termo);
    printf("Razao: ");
    scanf("%f", &razao);
    printf("Numero de termos da progressao: ");
    scanf("%f", &num_termos);

    if (caractere_tabela == 'A' || caractere_tabela == 'a' ){
        ultimo_termo = pri_termo + (num_termos - 1) * razao;
        soma_total = (pri_termo + ultimo_termo) * num_termos / 2;
        puts("");
        for (i = pri_termo; i <= ultimo_termo; i += razao){
            printf("%.0f ", i);
    }
    }
    if (caractere_tabela == 'G'|| caractere_tabela == 'g'){
        potencia = pow(razao, num_termos - 1);
        ultimo_termo = pri_termo * potencia;
        soma_total = pri_termo * (pow(razao, num_termos) - 1) / (razao - 1);
        puts("");
        for (i = pri_termo; i <= ultimo_termo; i *= razao){
            printf("%.0f ", i);
        }
    }

    printf("\nSoma total: %.0f", soma_total);
    
    return 0;
}