#include <stdio.h>
#include <string.h>

#define TAM 25

typedef struct {
    int CPF;
    char nome[TAM];
    char sobrenome[TAM];
    char endereco[TAM + TAM];
    char telefone[TAM];
}tDados;
//Função que tira o '\n' do final da string, usando o fgets
void TiraN(char *linhaString){
    linhaString[strcspn(linhaString, "\n")] = '\0';
}
//Função que limpa o buffer de entrada, usado antes de ler strings
void LimparBuffer(){
    char c;
    while((c = getchar()) != '\n' && c != EOF);
}

int main(){

    int numPessoas, i;

    scanf("%d", &numPessoas);
    
    tDados pessoas[numPessoas]; //Criação do vetor de pessoas,para armazenar os dados
    //Leitura dos dados das pessoas
    for(i=0; i < numPessoas; i++){
        scanf("%d", &pessoas[i].CPF);
        LimparBuffer();
        fgets(pessoas[i].nome, TAM,stdin);
        TiraN(pessoas[i].nome);
        fgets(pessoas[i].sobrenome, TAM,stdin);
        TiraN(pessoas[i].sobrenome);
        fgets(pessoas[i].endereco, (TAM+TAM),stdin);
        TiraN(pessoas[i].endereco);
        fgets(pessoas[i].telefone, TAM,stdin);
        TiraN(pessoas[i].telefone);
    }
    //Criando um arquivo .csv
    FILE *arq;
    arq = fopen("dados.csv", "w");

    fprintf( arq,"CPF,nome,snome,endereço,telefone\n");
    for(i=0; i < numPessoas; i++){
        fprintf(arq, "%d,%s,%s,%s,%s\n", pessoas[i].CPF, pessoas[i].nome, pessoas[i].sobrenome, pessoas[i].endereco, pessoas[i].telefone);
    }
    fclose(arq);//Fechando o arquivo

    //Lendo dados de um arquivo
    
    FILE *arq1;
    arq1 = fopen("dados.csv", "r");

    tDados p1[numPessoas];
    char nomes[10000];

    for(i=0; i < numPessoas+1; i++){
        fgets(nomes, 10000, arq1);
        printf("%s", nomes);
    }

    fclose(arq1);//Fechando od arquivo

    return 0;
}