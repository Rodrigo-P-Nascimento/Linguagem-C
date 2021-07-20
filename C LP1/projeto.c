#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define TAM_NOME 100

typedef struct {
    char logradouro[TAM_NOME]; // Nome da rua do imovél
    int numeroImovel;// Número do imovél
    char bairro[TAM_NOME]; //Nome do Bairro
    unsigned int cep; //CEP
    char cidade[TAM_NOME]; //Nome da cidade
    double valor; //Valor em R$ do imovél
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

    setlocale(LC_ALL, "portuguese");
    printf("Meu coração por ti bate mamãe!\n");

	return 0;
}
