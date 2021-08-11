#include <stdio.h>
#include <string.h>

#define TAM 51 //Tamanho da string a ser declarada

typedef struct {
    char modelo[TAM];
    char marca[TAM];
    int anoFabricacao;
    float preco;
}tVeiculo;

//Função que tira o '\n' do final da string, usando o fgets
void TiraN( char *linhaString ){
    linhaString[strcspn ( linhaString, "\n" )] = '\0';
}
//Função que limpa o buffer de entrada, usado antes de ler strings
void limparBuffer(void){
    char c;
    while((c = getchar()) != '\n' && c != EOF);
}

int main(){

    tVeiculo vei1, vei2;
    //Leitura das informações que são necessarias
    fgets(vei1.modelo, TAM, stdin);
    TiraN(vei1.modelo);
    fgets(vei1.marca, TAM, stdin);
    TiraN(vei1.marca);
    scanf("%d", &vei1.anoFabricacao);
    scanf("%lf", &vei1.preco);

    limparBuffer();
    fgets(vei2.modelo, TAM, stdin);
    TiraN(vei2.modelo);
    fgets(vei2.marca, TAM, stdin);
    TiraN(vei2.marca);
    scanf("%d", &vei2.anoFabricacao);
    scanf("%lf", &vei2.preco);

    //Se um carro for mais velho ele será exbido na tela, caso os sejam do mesmo ano o mais barato será exibido
    if(vei1.anoFabricacao < vei2.anoFabricacao){
        printf("%s %s\n", vei1.marca, vei1.modelo);
    }else if (vei1.anoFabricacao == vei2.anoFabricacao){
        if(vei1.preco < vei2.preco){
            printf("%s %s\n", vei1.marca, vei1.modelo);
        }else{
            printf("%s %s\n", vei2.marca, vei2.modelo);
        }
    }else{
        printf("%s %s\n", vei2.marca, vei2.modelo);
    }
    
    return 0;
}