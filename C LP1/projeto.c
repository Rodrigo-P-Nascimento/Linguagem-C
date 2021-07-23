#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

#ifdef _WIN32
    #include <Windows.h>
    #define LIMPAR "cls"
#elif __linux__
    #include <unistd.h>
    #define LIMPAR "clear"
// Dá mensagem de erro informando que o sistema não é suportado.
#error "Sistema nao suportado."
#endif

#define TAM_NOME 101
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

void mysleep(int tempoMS);//função que é analoga ao Sleep() e unsleep()

void limparBuffer(void);//função personalizada para limpar o buffer de entrada

void PreencheImoveis(Casa *imovel1, Apartamento *imovel2, Terreno *imovel3); // Essa função ira preencher todos os imoveis com valores nulos

void ConsultaImoveis(Casa *imovel1, Apartamento *imovel2, Terreno *imovel3);

void ExibeImoviesDisp(int tipo, Casa *imovel1, Apartamento *imovel2, Terreno *imovel3);//imovel pode ser 1, 2 o u 3

void MenuDeOpcoes();

void CadastraImovel(Casa *imovel1, Apartamento *imovel2, Terreno *imovel3);


int main(void){


    int opcao=1;
    int contadorCS=0, contadorAp=0, contadorTR=0;

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
            mysleep(1000);
            break;
        case 1:
            CadastraImovel(CSImovies, ATImoveis, TRImoveis);    
            break;
        case 2:
            ConsultaImoveis(CSImovies, ATImoveis, TRImoveis);
        default:
            puts("VALOR INVÁLIDO!");
            break;
        }

    }while(opcao != -1);

    limparBuffer();
    puts("\nOBRIGADO POR USAR O NOSSO PROGRAMA!");
    printf("\nPressione ENTER para finalizar o programa.");
    getchar();
	return 0;
}

void mysleep(int tempoMS){
#ifdef __linux__
    usleep(tempoMS * 1000);
#elif _WIN32
    Sleep(tempoMS);
#else

#endif
}

void limparBuffer(void){
    char c;

    while((c = getchar()) != '\n' && c != EOF);
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

void ConsultaImoveis(Casa *imovel1, Apartamento *imovel2, Terreno *imovel3){

    int i;

    puts("\nCasas disponíveis:");
    puts("-----------------------");
    for(i=0; i < TAM_IMOVEIS; i++){
        if(strcmp(imovel1[i].tituloAnuncio,  "VAZIO") != 0){
            printf("\tCasa[%d]\n", i+1);
            mysleep(200);
        }
    }
    
    puts("\nApartamentos disponíveis:");
    puts("-----------------------");

    for(i=0; i < TAM_IMOVEIS; i++){
        if(strcmp(imovel2[i].tituloAnuncio,  "VAZIO") != 0){
            printf("\tApartamento[%d]\n", i+1);
            mysleep(200);
        }
    }

    puts("\nTerrenos disponíveis:");
    puts("-----------------------");

    for(i=0; i < TAM_IMOVEIS; i++){
        if(strcmp(imovel3[i].tituloAnuncio,  "VAZIO") != 0){
            printf("\tTerreno[%d]\n", i+1);
            mysleep(200);
        }
    }
    //limparBuffer();
    //printf("\nPressione ENTER para voltar ao menu.");
    //getchar();

    system("pause");
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
    system(LIMPAR);
    puts("\nSISTEMA DE GERENCIAMENTO DE IMÓVEIS");
    puts("----------------------------------------\n");
    puts("[1]\tCadastrar um novo imóvel.");
    puts("[2]\tConsultar todos os imóvies dispóniveis.");
    puts("[-1]\t Para sair do programa.");
    puts("----------------------------------------\n");
    printf("Digite uma das opções: ");

}

void CadastraImovel(Casa *imovel1, Apartamento *imovel2, Terreno *imovel3){

    int flag1 = 1;
    int i=0;
    int op1;

    int ReIMV=0;

    while (flag1){

        puts("  [1]-> Casa \n  [2]-> Apartamento \n  [3]-> Terreno");
        printf("\n Qual o tipo do seu imóvel? ");
        scanf("%d", &op1);


        if(op1 == 1 || op1 == 2 || op1 == 3){
            flag1 = 0;
            break;
        }else{
            puts("OPÇÃO INVÁLIDA, TENTE NOVAMENTE!");
            mysleep(1000);
            system(LIMPAR);
        }
    }
    if(op1 == 1){
            system(LIMPAR);
            puts("\nVocê escolheu cadastrar uma casa!");
       
            for(i=0; i < TAM_IMOVEIS; i++){
                if(strcmp(imovel1[i].tituloAnuncio,  "VAZIO") == 0){
                    ReIMV = i;
                    break;
                }
            }
            
            printf("----------------------------------------------------------------------\n");
            printf("Informe alguns dados a seguir, sempre colocando apenas o que se pede.\n\n");
            printf("|>| Título do anúncio da casa[MAX %d caracteres]: ", TAM_NOME-1);
            limparBuffer();
            fgets(imovel1[ReIMV].tituloAnuncio, TAM_NOME, stdin);

            printf("|>| Número de pavimentos: ");
            scanf("%d", &imovel1[ReIMV].numPavimentos);

            printf("|>| Número de quartos: ");
            scanf("%d", &imovel1[ReIMV].numQuartos);

            printf("|>| Área do Terreno: ");
            scanf("%lf", &imovel1[ReIMV].areaTerreno);

            printf("|>| Área construída: ");
            scanf("%lf", &imovel1[ReIMV].areaConstruida);
            printf("----------------------------------------------------------------------\n");
            printf("\nENDEREÇO DA CASA\n");

            printf("\n|>| Logradouro[MAX %d caracteres]: ", TAM_NOME-1);
            limparBuffer();
            fgets(imovel1[ReIMV].imovel.logradouro, TAM_NOME, stdin);

            printf("|>| Número da casa: ");
            scanf("%d", &imovel1[ReIMV].imovel.numeroImovel);

            printf("|>| Bairro[MAX %d caracteres]: ", TAM_NOME - 1);
            limparBuffer();
            fgets(imovel1[ReIMV].imovel.bairro, TAM_NOME, stdin);

            printf("|>| CEP[Apenas o número]: ");
            scanf("%d", &imovel1[ReIMV].imovel.cep);

            printf("|>| Cidade[MAX %d caracteres]:  ", TAM_NOME - 1);
            limparBuffer();
            fgets(imovel1[ReIMV].imovel.cidade, TAM_IMOVEIS, stdin);

            printf("|>| Valor da casa: R$");
            scanf("%lf", &imovel1[ReIMV].imovel.valor);

            do{
                printf("|>| Disponibilidade para VENDA[1] ou ALUGUEL[2], digite openas 1 ou 2: ");
                scanf("%d", &flag1);
                if(flag1 == 1){
                    strcpy(imovel1[ReIMV].imovel.disponibilidade, "VENDA");
                    break;
                }else if (flag1 == 2){
                    strcpy(imovel1[ReIMV].imovel.disponibilidade, "ALUGUEL");
                    break;
                }else{
                    printf("VALOR INVÁLIDO\n");
                }
            }while(flag1 != 1 || flag1 != 2 );

            printf("\nCASA [%d] CADASTRADA COM SUCESSO!\n", ReIMV+1);
            mysleep(2500);

    }else if(op1 == 2){

        system(LIMPAR);
        puts("\nVocê escolheu cadastrar uma Apartamento!");

        for(i=0; i < TAM_IMOVEIS; i++){
                if(strcmp(imovel2[i].tituloAnuncio,  "VAZIO") == 0){
                    ReIMV = i;
                    break;
                }
        }

        printf("----------------------------------------------------------------------\n");
        printf("Informe alguns dados a seguir, sempre colocando apenas o que se pede.\n\n");
        printf("|>| Título do anúncio do apartamento[MAX %d caracteres]: ", TAM_NOME-1);
        limparBuffer();
        fgets(imovel2[ReIMV].tituloAnuncio, TAM_NOME, stdin);

        printf("|>| Área interna: ");
        scanf("%lf", &imovel2[ReIMV].area);

        printf("|>| Número de quartos: ");
        scanf("%d", &imovel2[ReIMV].numQuartos);

        printf("|>| Posição[MAX %d caracteres]: ", TAM_NOME-1);
        limparBuffer();
        fgets(imovel2[ReIMV].posicao, TAM_NOME, stdin);
        
        printf("|>| Andar: ");
        scanf("%d", &imovel2[ReIMV].andar);

        printf("|>| Valor do condomínio: R$");
        scanf("%lf", &imovel2[ReIMV].valorDoCondominio);

        printf("|>| Número de vagas na garagem: ");
        scanf("%d", &imovel2[ReIMV].numVagasGaragem);
        
        printf("----------------------------------------------------------------------\n");
        printf("\nENDEREÇO DO APARTAMENTO\n");

        printf("\n|>| Logradouro[MAX %d caracteres]: ", TAM_NOME-1);
        limparBuffer();
        fgets(imovel2[ReIMV].imovel.logradouro, TAM_NOME, stdin);

        printf("|>| Número do apartamento: ");
        scanf("%d", &imovel2[ReIMV].imovel.numeroImovel);

        printf("|>| Bairro[MAX %d caracteres]: ", TAM_NOME - 1);
        limparBuffer();
        fgets(imovel2[ReIMV].imovel.bairro, TAM_NOME, stdin);

        printf("|>| CEP[Apenas o número]: ");
        scanf("%d", &imovel2[ReIMV].imovel.cep);

        printf("|>| Cidade[MAX %d caracteres]:  ", TAM_NOME - 1);
        limparBuffer();
        fgets(imovel2[ReIMV].imovel.cidade, TAM_IMOVEIS, stdin);

        printf("|>| Valor do apartamento: R$");
        scanf("%lf", &imovel2[ReIMV].imovel.valor);

        do{
            printf("|>| Disponibilidade para VENDA[1] ou ALUGUEL[2], digite openas 1 ou 2: ");
            scanf("%d", &flag1);
            if(flag1 == 1){
                strcpy(imovel2[ReIMV].imovel.disponibilidade, "VENDA");
                break;
            }else if (flag1 == 2){
                strcpy(imovel2[ReIMV].imovel.disponibilidade, "ALUGUEL");
                break;
            }else{
                printf("VALOR INVÁLIDO\n");
            }
        }while(flag1 != 1 || flag1 != 2 );

        printf("\nAPARTAMENTO [%d] CADASTRADO COM SUCESSO!\n", ReIMV+1);
        mysleep(2500);
    }else{
        system(LIMPAR);
        puts("\nVocê escolheu cadastrar uma Terreno!");
       
        for(i=0; i < TAM_IMOVEIS; i++){
                if(strcmp(imovel3[i].tituloAnuncio,  "VAZIO") == 0){
                    ReIMV = i;
                    break;
                }
        }

        printf("----------------------------------------------------------------------\n");
        printf("Informe alguns dados a seguir, sempre colocando apenas o que se pede.\n\n");
        printf("|>| Título do anúncio do Terreno[MAX %d caracteres]: ", TAM_NOME-1);
        limparBuffer();
        fgets(imovel3[ReIMV].tituloAnuncio, TAM_NOME, stdin);

        printf("|>| Área do terreno: ");
        scanf("%lf", &imovel3[ReIMV].area);

        printf("----------------------------------------------------------------------\n");
        printf("\nENDEREÇO DO TERRENO\n");

        printf("\n|>| Logradouro[MAX %d caracteres]: ", TAM_NOME-1);
        limparBuffer();
        fgets(imovel3[ReIMV].imovel.logradouro, TAM_NOME, stdin);

        printf("|>| Número do terreno: ");
        scanf("%d", &imovel3[ReIMV].imovel.numeroImovel);

        printf("|>| Bairro[MAX %d caracteres]: ", TAM_NOME - 1);
        limparBuffer();
        fgets(imovel3[ReIMV].imovel.bairro, TAM_NOME, stdin);

        printf("|>| CEP[Apenas o número]: ");
        scanf("%d", &imovel3[ReIMV].imovel.cep);

        printf("|>| Cidade[MAX %d caracteres]:  ", TAM_NOME - 1);
        limparBuffer();
        fgets(imovel3[ReIMV].imovel.cidade, TAM_IMOVEIS, stdin);

        printf("|>| Valor do terreno: R$");
        scanf("%lf", &imovel3[ReIMV].imovel.valor);

        do{
            printf("|>| Disponibilidade para VENDA[1] ou ALUGUEL[2], digite openas 1 ou 2: ");
            scanf("%d", &flag1);
            if(flag1 == 1){
                strcpy(imovel3[ReIMV].imovel.disponibilidade, "VENDA");
                break;
            }else if (flag1 == 2){
                strcpy(imovel3[ReIMV].imovel.disponibilidade, "ALUGUEL");
                break;
            }else{
                printf("VALOR INVÁLIDO\n");
            }
        }while(flag1 != 1 || flag1 != 2 );

        puts("\nTERRENO CADASTRADO COM SUCESSO!\n");
        mysleep(2500);
    }
}
