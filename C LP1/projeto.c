#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

#ifdef _WIN32
#include <Windows.h>
#define LIMPAR "cls"
#elif _linux_
#include <unistd.h>
#define LIMPAR "clear"
// Dá mensagem de erro informando que o sistema não é suportado.
#error "Sistema nao suportado."
#endif

#define TAM_NOME 100
#define TAM_IMOVEIS 10

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

int ConsultaImoveisLivres(Casa *imovel1, Apartamento *imovel2, Terreno *imovel3, int *cas, int *apt, int *ter);

void ExibeImoviesDisp(int tipo, Casa *imovel1, Apartamento *imovel2, Terreno *imovel3);//imovel pode ser 1, 2 o u 3

void MenuDeOpcoes();

void CadastraImovel(Casa *imovel1, Apartamento *imovel2, Terreno *imovel3);


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
            Sleep(1000);
            break;
        case 1:
            CadastraImovel(CSImovies, ATImoveis, TRImoveis);
            break;

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

int ConsultaImoveisLivres(Casa *imovel1, Apartamento *imovel2, Terreno *imovel3, int *cas, int *apt, int *ter){

    int i = 0;
    int imoveisDisponiveis = 0, casas = 0, apart = 0, terre = 0;

    for(i =0; i < TAM_IMOVEIS; i++){
        if(strcmp(imovel1[i].tituloAnuncio,  "VAZIO") == 0){
            imoveisDisponiveis++;
            casas++;
        }
        if(strcmp(imovel2[i].tituloAnuncio,  "VAZIO") == 0){
            imoveisDisponiveis++;
            apart++;
        }
        if(strcmp(imovel3[i].tituloAnuncio,  "VAZIO") == 0){
            imoveisDisponiveis++;
            terre++;
        }
    }
    *cas = casas;
    *apt = apart;
    *ter = terre;

    return imoveisDisponiveis;
}

void ExibeImoviesDisp(int tipo, Casa *imovel1, Apartamento *imovel2, Terreno *imovel3){

    int i = 0;

    if(tipo == 1){//CASA
        printf("Temos disponível as seguintes casas:\n");
        for(i=0; i < TAM_IMOVEIS; i++){
            if(strcmp(imovel1[i].tituloAnuncio,  "VAZIO") == 0){
                printf("\t Casa numero: [%d]\n", i+1);
            }
        }
    }else if(tipo == 2){//APARTAMENTO
        printf("Temos disponível os seguintes Apartamentos:\n");
        for(i=0; i < TAM_IMOVEIS; i++){
            if(strcmp(imovel2[i].tituloAnuncio,  "VAZIO") == 0){
                printf("\t Apartamento numero: [%d]\n", i+1);
            }
        }
    }else if(tipo == 3){//TERRENO
        printf("Temos disponível os seguintes Terrenos:\n");
        for(i=0; i < TAM_IMOVEIS; i++){
            if(strcmp(imovel3[i].tituloAnuncio,  "VAZIO") == 0){
                printf("\t Terreno numero: [%d]\n", i+1);
            }
        }
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

void CadastraImovel(Casa *imovel1, Apartamento *imovel2, Terreno *imovel3){

    int flag1 = 1;
    int op1;

    int CasaEscolhida, NumApt, NumTer;


    while (flag1){
    
        puts("[1]-> Casa \t [2]-> Apartamento \t [3]-> Terreno");
        printf("Qual o tipo do seu imóvel? ");
        scanf("%d", &op1);


        if(op1 == 1 || op1 == 2 || op1 == 3){
            flag1 = 0;
            break;
        }else{
            puts("OPÇÃO INVÁLIDA, TENTE NOVAMENTE!");
            Sleep(1000);
            system(LIMPAR);
        } 
    }
    if(op1 == 1){
            system(LIMPAR);
            puts("\nVocê escolheu cadastrar uma casa!");
            ExibeImoviesDisp(1, imovel1,  imovel2, imovel3);
            flag1 = 1;
            do{
                puts("Escolha uma casa para cadastar: ");
                scanf("%d", &CasaEscolhida);

                if(strcmp(imovel1[CasaEscolhida-1].tituloAnuncio, "VAZIO") == 0){
                    printf("Boa escolha, a Casa [%d] será perfeita para você.\n", CasaEscolhida);
                    flag1 = 0;
                    break;
                    
                }else{
                    puts("Esta casa já esta ocupada, escolha outra.\n");
                }
            }while(flag1);
            
    } 
}
