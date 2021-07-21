#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

#define TAM_NOME 100
#define TAM_IMOVEIS 100

typedef struct {
    char logradouro[TAM_NOME]; // Nome da rua do imovel
    char bairro[TAM_NOME]; //Nome do Bairro
    char cidade[TAM_NOME]; //Nome da cidade
    char disponibilidade[10]; //STRING, que conterá VENDA ou ALUGUEL
    int numeroImovel;// Número do imovel
    unsigned int cep; //CEP
    double valor; //Valor em R$ do imovel
    
}Endereco;

typedef struct{   
    Endereco imovel;
    char tituloAnuncio[TAM_NOME];//Nome do anúncio da casa
    int numPavimentos; //Quantos andares tem a casa
    int numQuartos;
    double areaTerreno; //Quantos metros tem a area do terreno
    double areaConstruida; //Quantos metros tem de area construida
}Casa;

typedef struct {
    Endereco imovel;
    char tituloAnuncio[TAM_NOME];//Nome do anúncio do apartamento
    char posicao[TAM_NOME]; //Posição do partamento
    int numQuartos;
    int andar;
    int numVagasGaragem;
    double area; //Quantos metros quadrados tem o apartamento
    float valorDoCondominio;
}Apartamento;

typedef struct{
    Endereco imovel;
    char tituloAnuncio[TAM_NOME];//Nome do anúncio do apartamento
    double area; //Quantos metros quadrados tem o apartamento
}Terreno;


void PreencheImoveis(Casa *imovel1, Apartamento *imovel2, Terreno *imovel3); // Essa função ira preencher todos os imoveis com valores nulos

void MenuDeOpcoes();

void CadastraImovel();


int main(void){

    
    int opcao=1;

    Casa CSImovies[TAM_IMOVEIS];
    Apartamento ATImoveis[TAM_IMOVEIS];
    Terreno TRImoveis[TAM_IMOVEIS];

    setlocale(LC_ALL, "pt_BR");
    PreencheImoveis(CSImovies, ATImoveis, TRImoveis);

    do{
        MenuDeOpcoes();
        scanf("%d", &opcao);

        switch (opcao){
        case -1:
            puts("SAINDO....");
            //coloca um sleep aqui
            break;
        case 1:
            CadastraImovel();

        default:
            puts("VALOR INVÁLIDO!");
            break;
        }
        
    }while(opcao != -1);
    

    puts("\nOBRIGADO POR USAR O NOSSO PROGRAMA!");

	return 0;
}

void PreencheImoveis(Casa *imovel1, Apartamento *imovel2, Terreno *imovel3){
    int i;

    for( i=0; i < TAM_IMOVEIS; i++){
        strcpy(imovel1[i].imovel.logradouro, "VAZIO");
        strcpy(imovel1[i].imovel.bairro, "VAZIO");
        strcpy(imovel1[i].imovel.cidade, "VAZIO");
        strcpy(imovel1[i].imovel.disponibilidade, "VAZIO");
        imovel1[i].imovel.numeroImovel = 0;
        imovel1[i].imovel.cep = 0;
        imovel1[i].imovel.valor = 0;

        strcpy(imovel1[i].tituloAnuncio, "VAZIO");
        imovel1[i].areaConstruida = 0;
        imovel1[i].areaTerreno = 0;
        imovel1[i].numPavimentos = 0;
        imovel1[i].numQuartos = 0;
    }
    for( i=0; i < TAM_IMOVEIS; i++){
        strcpy(imovel2[i].imovel.logradouro, "VAZIO");
        strcpy(imovel2[i].imovel.bairro, "VAZIO");
        strcpy(imovel2[i].imovel.cidade, "VAZIO");
        strcpy(imovel2[i].imovel.disponibilidade, "VAZIO");
        imovel2[i].imovel.numeroImovel = 0;
        imovel2[i].imovel.cep = 0;
        imovel2[i].imovel.valor = 0;

        strcpy(imovel2[i].tituloAnuncio, "VAZIO");
        strcpy(imovel2[i].posicao, "VAZIO");
        imovel2[i].andar = 0;
        imovel2[i].area = 0;
        imovel2[i].numQuartos = 0;
        imovel2[i].numVagasGaragem = 0;
        imovel2[i].valorDoCondominio = 0;
        
    }
    for( i=0; i < TAM_IMOVEIS; i++){
        strcpy(imovel3[i].imovel.logradouro, "VAZIO");
        strcpy(imovel3[i].imovel.bairro, "VAZIO");
        strcpy(imovel3[i].imovel.cidade, "VAZIO");
        strcpy(imovel3[i].imovel.disponibilidade, "VAZIO");
        imovel3[i].imovel.numeroImovel = 0;
        imovel3[i].imovel.cep = 0;
        imovel3[i].imovel.valor = 0;

        strcpy(imovel3[i].tituloAnuncio, "VAZIO");
        imovel3[i].area = 0;
    }
}

void MenuDeOpcoes(){
    puts("\nSISTEMA DE GERENCIAMENTO DE IMÓVEIS");
    puts("----------------------------------------\n");
    puts("[1]\tCadastrar um novo imóvel.");
    puts("[-1]\t Para sair do programa.");
    puts("----------------------------------------\n");
    printf("Digite uma das opções: ");

}

void CadastraImovel(){

    int flag1 = 1;
    int op1 = 1;

    while (flag1){
    
        puts("[1]-> Casa \t [2]-> Apartamento \t [3]-> Terreno");
        printf("Qual o tipo do seu imóvel? ");
        scanf("%d", &op1);

        if(op1 != 1 || op1 != 2 || op1 != 3){
            puts("OPÇÃO INVÁLIDA, TENTE NOVAMENTE!");
        }else{
            flag1 = 0;
        } 
    }
    if(op1 == 1){
            puts("\nVocê escolheu cadastrar uma casa!");
            
        } 
}