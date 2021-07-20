#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define TAM_NOME 100
#define TAM_IMOVEIS 100

void MenuDeOpcoes();

typedef struct {
    char logradouro[TAM_NOME]; // Nome da rua do imovel
    int numeroImovel;// Número do imovel
    char bairro[TAM_NOME]; //Nome do Bairro
    unsigned int cep; //CEP
    char cidade[TAM_NOME]; //Nome da cidade
    double valor; //Valor em R$ do imovel
    char disponibilidade[10]; //STRING, que conterá VENDA ou ALUGUEL
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
    double area; //Quantos metros quadrados tem o apartamento
    int numQuartos;
    char posicao[TAM_NOME]; //Posição do partamento
    int andar;
    float valorDoCondominio;
    int numVagasGaragem;
}Apartamento;

typedef struct{
   char tituloAnuncio[TAM_NOME];//Nome do anúncio do apartamento
   double area; //Quantos metros quadrados tem o apartamento
}Terreno;

int main(void){

    int opcao=1;
    Casa CSImovies[TAM_IMOVEIS];
    Apartamento ATImoveis[TAM_IMOVEIS];
    Terreno TRImoveis[TAM_IMOVEIS];

    //setlocale(LC_ALL, "portuguese");
    //printf("Meu coração por ti bate mamãe!\n");

    while(opcao){
        MenuDeOpcoes();
        scanf("%d", &opcao);
    }



	return 0;
}

void MenuDeOpcoes(){
    puts("\nSISTEMA DE GERENCIAMENTO DE IMÓVEIS");
    puts("LISTA DE OPÇÕES DISPONIVÉIS\n");


    printf("Digite uma das opções: ");

}