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

void TiraN( char *linhaString );//função para tirar o '\n' das strings

void limparBuffer(void);//função personalizada para limpar o buffer de entrada

int VerificaCAT(void);//Função faz uma verificação de 3 opções simples.

void ImprimeDados(Casa *imovel1, Apartamento *imovel2, Terreno *imovel3);//Função que imprime os dados de um imóvel.

void PreencheImoveis(Casa *imovel1, Apartamento *imovel2, Terreno *imovel3); // Essa função ira preencher todos os imoveis com valores nulos

void ConsultaImoveis(Casa *imovel1, Apartamento *imovel2, Terreno *imovel3);

void ExibeImoviesDisp(int tipo, Casa *imovel1, Apartamento *imovel2, Terreno *imovel3);//imovel pode ser 1, 2 o u 3

void MenuDeOpcoes();

void CadastraImovel(Casa *imovel1, Apartamento *imovel2, Terreno *imovel3);

void BuscaTitulo(Casa *imovel1, Apartamento *imovel2, Terreno *imovel3);//Função que vai buscar imóveis por titúlo.

void BuscaBairro(Casa *imovel1, Apartamento *imovel2, Terreno *imovel3);//Função que vai buscar imóveis por bairro.

void BuscaValor(Casa *imovel1, Apartamento *imovel2, Terreno *imovel3);//Função que vai buscar imóveis por acima de um valor X.

void DispoVenda(Casa *imovel1, Apartamento *imovel2, Terreno *imovel3);//Função vai RETORNA todos os imoveis disponiveis para venda

void DispoAluga(Casa *imovel1, Apartamento *imovel2, Terreno *imovel3);//Função vai RETORNA todos os imoveis disponiveis para alugar

void RemoveImovel(Casa *imovel1, Apartamento *imovel2, Terreno *imovel3);//Função que Remove um imóvel do sistema

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
            break;
        case 3: 
            ImprimeDados(CSImovies, ATImoveis, TRImoveis);
            break;
        case 4:
            BuscaTitulo(CSImovies, ATImoveis, TRImoveis);
            break;
        case 5: 
            BuscaBairro(CSImovies, ATImoveis, TRImoveis);
            break;
        case 6: 
            BuscaValor(CSImovies, ATImoveis, TRImoveis);
            break;
        case 7: 
            DispoVenda(CSImovies, ATImoveis, TRImoveis);
            break; 
        case 8: 
            DispoAluga(CSImovies, ATImoveis, TRImoveis);
            break;   
        case 9: 
            RemoveImovel(CSImovies, ATImoveis, TRImoveis);
            break;  
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

void TiraN( char *linhaString ){
    linhaString[strcspn ( linhaString, "\n" )] = '\0';
}

void limparBuffer(void){
    char c;

    while((c = getchar()) != '\n' && c != EOF);
}

int VerificaCAT(){

    int flagg = 1; 
    int opp;

    while (flagg){
        puts("  [1]-> Casa \n  [2]-> Apartamento \n  [3]-> Terreno");
        printf("\nQual o tipo do seu imóvel? ");
        scanf("%d", &opp);

        if(opp == 1 || opp == 2 || opp == 3){
            flagg = 0;
            break;
        }else{
            puts("OPÇÃO INVÁLIDA, TENTE NOVAMENTE!");
            mysleep(1000);
            system(LIMPAR);
        }
    }
    return opp;
}

void ImprimeDados(Casa *imovel1, Apartamento *imovel2, Terreno *imovel3){

    int op3,imo;

    system(LIMPAR);

    puts("Qual o tipo de imóvel você deseja olhar as informações: ");
    op3 = VerificaCAT();
    ExibeImoviesDisp(op3, imovel1, imovel2, imovel3);
    printf("Escolha um dentre os demais: ");
    scanf("%d", &imo);
    imo = imo - 1;//Pois os arrays começam em 0.
    puts("");
    if(op3 == 1){//CASA
        
        printf("Titúlo do anúncio: %s\n", imovel1[imo].tituloAnuncio);
        printf("Disponibilidade: %s\n", imovel1[imo].imovel.disponibilidade);
        printf("Rua: %s\n", imovel1[imo].imovel.logradouro);
        printf("Bairro: %s\n", imovel1[imo].imovel.bairro);
        printf("Cidade: %s\n", imovel1[imo].imovel.cidade);
        printf("Número da Casa: %d\n",imovel1[imo].imovel.numeroImovel);
        printf("CEP: %d\n", imovel1[imo].imovel.cep);
        printf("Valor: R$%.2lf\n", imovel1[imo].imovel.valor);

        printf("Área construída: %.2lf m2\n", imovel1[imo].areaConstruida);
        printf("Área do terreno: %.2lf m2\n",imovel1[imo].areaTerreno); 
        printf("Número de pavimentos: %d\n", imovel1[imo].numPavimentos); 
        printf("Número de quartos: %d\n", imovel1[imo].numQuartos);

    }else if(op3 == 2){
        printf("Titúlo do anúncio: %s\n", imovel2[imo].tituloAnuncio);
        printf("Disponibilidade: %s\n", imovel2[imo].imovel.disponibilidade);
        printf("Posição em relação ao sol: %s\n", imovel2[imo].posicao);
        printf("Rua: %s\n", imovel2[imo].imovel.logradouro);
        printf("Bairro: %s\n", imovel2[imo].imovel.bairro);
        printf("Cidade: %s\n", imovel2[imo].imovel.cidade);
        printf("Número do Apartamento: %d\n",imovel2[imo].imovel.numeroImovel);
        printf("CEP: %d\n", imovel2[imo].imovel.cep);
        printf("Valor: R$%.2lf\n", imovel2[imo].imovel.valor);

        printf("Andar: %d\n", imovel2[imo].andar);
        printf("Área: %.2lfm2\n", imovel2[imo].area);
        printf("Número de quartos: %d\n", imovel2[imo].numQuartos);
        printf("Número de Vagas na garagem: %d\n", imovel2[imo].numVagasGaragem);
        printf("Valor do condominio: R$%.2lf\n", imovel2[imo].valorDoCondominio);

    }else if(op3 == 3){
        printf("Titúlo do anúncio: %s\n", imovel3[imo].tituloAnuncio);
        printf("Disponibilidade: %s\n", imovel3[imo].imovel.disponibilidade);
        printf("Rua: %s\n", imovel3[imo].imovel.logradouro);
        printf("Bairro: %s\n", imovel3[imo].imovel.bairro);
        printf("Cidade: %s\n", imovel3[imo].imovel.cidade);
        printf("Número da Casa: %d\n",imovel3[imo].imovel.numeroImovel);
        printf("CEP: %d\n", imovel3[imo].imovel.cep);
        printf("Valor: R$%.2lf\n", imovel3[imo].imovel.valor);
        printf("Área do terreno: %.2lf m2\n", imovel3[imo].area);
    }
    system("pause");
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
            if(strcmp(imovel1[i].tituloAnuncio,  "VAZIO") != 0){
                printf("\t Casa numero: [%d]\n", i+1);
            }
        }
    }else if(tipo == 2){//APARTAMENTO
        printf("Temos disponível os seguintes Apartamentos:\n");
        for(i=0; i < TAM_IMOVEIS; i++){
            if(strcmp(imovel2[i].tituloAnuncio,  "VAZIO") != 0){
                printf("\t Apartamento numero: [%d]\n", i+1);
            }
        }
    }else if(tipo == 3){//TERRENO
        printf("Temos disponível os seguintes Terrenos:\n");
        for(i=0; i < TAM_IMOVEIS; i++){
            if(strcmp(imovel3[i].tituloAnuncio,  "VAZIO") != 0){
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
    puts("[3]\tImprmir dados de um imóvel.");
    puts("[4]\tBuscar um imóvel pelo titúlo.");
    puts("[5]\tBuscar um imóvel pelo bairro.");
    puts("[6]\tBuscar um imóvel pelo valor.");
    puts("[7]\tBuscar por todos os imóveis para venda.");
    puts("[8]\tBuscar por todos os imóveis para alugar.");
    puts("[9]\tPara remover um imóvel.");
    puts("[-1]\t Para sair do programa.");
    puts("----------------------------------------\n");
    printf("Digite uma das opções: ");

}

void CadastraImovel(Casa *imovel1, Apartamento *imovel2, Terreno *imovel3){

    int i=0;
    int ReIMV=0;
    int op1;
    int flag1=1;

    op1 = VerificaCAT();

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
            TiraN(imovel1[ReIMV].tituloAnuncio);

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
            TiraN(imovel1[ReIMV].imovel.logradouro);

            printf("|>| Número da casa: ");
            scanf("%d", &imovel1[ReIMV].imovel.numeroImovel);

            printf("|>| Bairro[MAX %d caracteres]: ", TAM_NOME - 1);
            limparBuffer();
            fgets(imovel1[ReIMV].imovel.bairro, TAM_NOME, stdin);
            TiraN(imovel1[ReIMV].imovel.bairro);

            printf("|>| CEP[Apenas o número]: ");
            scanf("%d", &imovel1[ReIMV].imovel.cep);

            printf("|>| Cidade[MAX %d caracteres]:  ", TAM_NOME - 1);
            limparBuffer();
            fgets(imovel1[ReIMV].imovel.cidade, TAM_IMOVEIS, stdin);
            TiraN(imovel1[ReIMV].imovel.cidade);

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
        TiraN(imovel2[ReIMV].tituloAnuncio);

        printf("|>| Área interna: ");
        scanf("%lf", &imovel2[ReIMV].area);

        printf("|>| Número de quartos: ");
        scanf("%d", &imovel2[ReIMV].numQuartos);

        printf("|>| Posição[MAX %d caracteres]: ", TAM_NOME-1);
        limparBuffer();
        fgets(imovel2[ReIMV].posicao, TAM_NOME, stdin);
        TiraN(imovel2[ReIMV].posicao);

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
        TiraN(imovel2[ReIMV].imovel.logradouro);

        printf("|>| Número do apartamento: ");
        scanf("%d", &imovel2[ReIMV].imovel.numeroImovel);

        printf("|>| Bairro[MAX %d caracteres]: ", TAM_NOME - 1);
        limparBuffer();
        fgets(imovel2[ReIMV].imovel.bairro, TAM_NOME, stdin);
        TiraN(imovel2[ReIMV].imovel.bairro);

        printf("|>| CEP[Apenas o número]: ");
        scanf("%d", &imovel2[ReIMV].imovel.cep);

        printf("|>| Cidade[MAX %d caracteres]:  ", TAM_NOME - 1);
        limparBuffer();
        fgets(imovel2[ReIMV].imovel.cidade, TAM_IMOVEIS, stdin);
        TiraN(imovel2[ReIMV].imovel.cidade);

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
        TiraN(imovel3[ReIMV].tituloAnuncio);

        printf("|>| Área do terreno: ");
        scanf("%lf", &imovel3[ReIMV].area);

        printf("----------------------------------------------------------------------\n");
        printf("\nENDEREÇO DO TERRENO\n");

        printf("\n|>| Logradouro[MAX %d caracteres]: ", TAM_NOME-1);
        limparBuffer();
        fgets(imovel3[ReIMV].imovel.logradouro, TAM_NOME, stdin);
        TiraN(imovel3[ReIMV].imovel.logradouro);

        printf("|>| Número do terreno: ");
        scanf("%d", &imovel3[ReIMV].imovel.numeroImovel);

        printf("|>| Bairro[MAX %d caracteres]: ", TAM_NOME - 1);
        limparBuffer();
        fgets(imovel3[ReIMV].imovel.bairro, TAM_NOME, stdin);
        TiraN(imovel3[ReIMV].imovel.bairro);

        printf("|>| CEP[Apenas o número]: ");
        scanf("%d", &imovel3[ReIMV].imovel.cep);

        printf("|>| Cidade[MAX %d caracteres]:  ", TAM_NOME - 1);
        limparBuffer();
        fgets(imovel3[ReIMV].imovel.cidade, TAM_IMOVEIS, stdin);
        TiraN(imovel3[ReIMV].imovel.cidade);

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

        
        printf("\nTERRENO [%d] CADASTRADO COM SUCESSO!\n", ReIMV+1);
        mysleep(2500);
    }
}

void BuscaTitulo(Casa *imovel1, Apartamento *imovel2, Terreno *imovel3){
    
    int cont=0;
    int op2, i;
    char procura[TAM_NOME];


    system(LIMPAR);
  
    puts("Para buscar um imóvel pelo titúlo, você deve escolher o tipo primeiro.");
    op2 = VerificaCAT();

    if(op2 == 1){
        printf("Digite o titúlo da casa que procura[MAX %d caracteres]: ", TAM_NOME-1);
        limparBuffer();
        fgets(procura, TAM_NOME, stdin);
        TiraN(procura);
        for(i=0; i < TAM_IMOVEIS; i++){
            if(strcmp(procura, imovel1[i].tituloAnuncio) == 0){
                printf("Encontramos uma casa com essa descrição: Casa[%d]\n", i+1);
                cont++;
            }
        }
        if(cont == 0){
            puts("Não tem nenhuma casa com esse titúlo.\n");
        }
    }else if(op2 == 2){
        cont= 0;
        printf("Digite o titúlo do apartamento que procura[MAX %d caracteres]: ", TAM_NOME-1);
        limparBuffer();
        fgets(procura, TAM_NOME, stdin);
        TiraN(procura);

        for(i=0; i < TAM_IMOVEIS; i++){
            if(strcmp(procura, imovel2[i].tituloAnuncio) == 0){
                printf("Encontramos um apartamento com essa descrição: Apartamento[%d]\n", i+1);
                cont++;
            }
        }
        if(cont == 0){
            puts("Não tem nenhum apartamento com esse titúlo.\n");
        }
    }else if(op2 == 3){
        cont= 0;
        printf("Digite o titúlo do terreno que procura[MAX %d caracteres]: ", TAM_NOME-1);
        limparBuffer();
        fgets(procura, TAM_NOME, stdin);
        TiraN(procura);

        for(i=0; i < TAM_IMOVEIS; i++){
            if(strcmp(procura, imovel3[i].tituloAnuncio) == 0){
                printf("Encontramos um terreno com essa descrição: Terreno[%d]\n", i+1);
                cont++;
            }
        }
        if(cont == 0){
            puts("Não tem nenhum terreno com esse titúlo.\n");
        }
    }
    puts("");
    system("pause");
}

void BuscaBairro(Casa *imovel1, Apartamento *imovel2, Terreno *imovel3){
    int cont=0;
    int op4, i;
    char procura[TAM_NOME];

    system(LIMPAR);
  
    puts("Para buscar um imóvel pelo bairros, você deve escolher o tipo primeiro.");
    op4 = VerificaCAT();

    if(op4 == 1){
        printf("Digite o bairro da casa que procura[MAX %d caracteres]: ", TAM_NOME-1);
        limparBuffer();
        fgets(procura, TAM_NOME, stdin);
        TiraN(procura);
        for(i=0; i < TAM_IMOVEIS; i++){
            if(strcmp(procura, imovel1[i].imovel.bairro) == 0){
                printf("Encontramos uma casa nesse bairro: Casa[%d]\n", i+1);
                cont++;
            }
        }
        if(cont == 0){
            puts("Não tem nenhuma casa nesse bairro.\n");
        }
    }else if(op4 == 2){
        cont= 0;
        printf("Digite o bairro do apartamento que procura[MAX %d caracteres]: ", TAM_NOME-1);
        limparBuffer();
        fgets(procura, TAM_NOME, stdin);
        TiraN(procura);

        for(i=0; i < TAM_IMOVEIS; i++){
            if(strcmp(procura, imovel2[i].imovel.bairro) == 0){
                printf("Encontramos um apartamento nesse bairro: Apartamento[%d]\n", i+1);
                cont++;
            }
        }
        if(cont == 0){
            puts("Não tem nenhum apartamento nesse bairro.\n");
        }
    }else if(op4 == 3){
        cont= 0;
        printf("Digite o bairro do terreno que procura[MAX %d caracteres]: ", TAM_NOME-1);
        limparBuffer();
        fgets(procura, TAM_NOME, stdin);
        TiraN(procura);

        for(i=0; i < TAM_IMOVEIS; i++){
            if(strcmp(procura, imovel3[i].imovel.bairro) == 0){
                printf("Encontramos um terreno nesse bairro: Terreno[%d]\n", i+1);
                cont++;
            }
        }
        if(cont == 0){
            puts("Não tem nenhum terreno nesse bairro.\n");
        }
    }
    puts("");
    system("pause");
}

void BuscaValor(Casa *imovel1, Apartamento *imovel2, Terreno *imovel3){
    int cont=0;
    double valorPESQ;
    int op5, i;
    char procura[TAM_NOME];

    system(LIMPAR);
  
    puts("Para buscar um imóvel pelo valor, você deve escolher o tipo primeiro.");
    op5 = VerificaCAT();

    if(op5 == 1){
        printf("Digite o valor em reais da casa que procura: R$");
        scanf("%lf", &valorPESQ);

        for(i=0; i < TAM_IMOVEIS; i++){
            if(valorPESQ <= imovel1[i].imovel.valor){
                printf("Encontramos uma casa nesse valor ou acima: Casa[%d]\n", i+1);
                cont++;
            }
        }
        if(cont == 0){
            puts("Não tem nenhuma casa nesse valor.\n");
        }
    }else if(op5 == 2){
        cont= 0;
        printf("Digite o valor em reais do apartamento que procura: R$");
        scanf("%lf", &valorPESQ);

        for(i=0; i < TAM_IMOVEIS; i++){
            if(valorPESQ <= imovel2[i].imovel.valor){
                printf("Encontramos um apartamento nesse valor ou acima: Apartamento[%d]\n", i+1);
                cont++;
            }
        }
        if(cont == 0){
            puts("Não tem nenhum apartamento nesse valor.\n");
        }
    }else if(op5 == 3){
        cont= 0;
        printf("Digite o valor em reais do terreno que procura: R$");
        scanf("%lf", &valorPESQ);

        for(i=0; i < TAM_IMOVEIS; i++){
            if(valorPESQ <= imovel3[i].imovel.valor){
                printf("Encontramos um terreno nesse valor ou acima: Terreno[%d]\n", i+1);
                cont++;
            }
        }
        if(cont == 0){
            puts("Não tem nenhum Terreno nesse valor.\n");
        }
    }
    puts("");
    system("pause");

}

void DispoVenda(Casa *imovel1, Apartamento *imovel2, Terreno *imovel3){

    int i = 0;
    int op6;

    puts("Para mostrar os imóveis a venda digite o tipo.");
    op6 = VerificaCAT();

    if(op6 == 1){//CASA
        printf("Temos disponível para venda as seguintes casas:\n");
        for(i=0; i < TAM_IMOVEIS; i++){
            if(strcmp(imovel1[i].imovel.disponibilidade,  "VENDA") == 0){
                printf("\t Casa: [%d]\n", i+1);
            }
        }
    }else if(op6 == 2){//APARTAMENTO
        printf("Temos disponível para venda os seguintes Apartamentos:\n");
        for(i=0; i < TAM_IMOVEIS; i++){
            if(strcmp(imovel2[i].imovel.disponibilidade,  "VENDA") == 0){
                printf("\t Apartamento: [%d]\n", i+1);
            }
        }
    }else if(op6 == 3){//TERRENO
        printf("Temos disponível para venda os seguintes Terrenos:\n");
        for(i=0; i < TAM_IMOVEIS; i++){
            if(strcmp(imovel3[i].imovel.disponibilidade,  "VENDA") == 0){
                printf("\t Terreno: [%d]\n", i+1);
            }
        }
    }
    system("pause");
}

void DispoAluga(Casa *imovel1, Apartamento *imovel2, Terreno *imovel3){

    int i = 0;
    int op7;

    puts("Para mostrar os imóveis para alugar digite o tipo.");
    op7 = VerificaCAT();

    if(op7 == 1){//CASA
        printf("Temos disponível para alugar as seguintes casas:\n");
        for(i=0; i < TAM_IMOVEIS; i++){
            if(strcmp(imovel1[i].imovel.disponibilidade,  "ALUGUEL") == 0){
                printf("\t Casa: [%d]\n", i+1);
            }
        }
    }else if(op7 == 2){//APARTAMENTO
        printf("Temos disponível para alugar os seguintes Apartamentos:\n");
        for(i=0; i < TAM_IMOVEIS; i++){
            if(strcmp(imovel2[i].imovel.disponibilidade,  "ALUGUEL") == 0){
                printf("\t Apartamento: [%d]\n", i+1);
            }
        }
    }else if(op7 == 3){//TERRENO
        printf("Temos disponível para alugar os seguintes Terrenos:\n");
        for(i=0; i < TAM_IMOVEIS; i++){
            if(strcmp(imovel3[i].imovel.disponibilidade,  "ALUGUEL") == 0){
                printf("\t Terreno: [%d]\n", i+1);
            }
        }
    }
    system("pause");
}

void RemoveImovel(Casa *imovel1, Apartamento *imovel2, Terreno *imovel3){


    int op8;
    char res;
    int flag1; 
    int imovelEscolhido;


    puts("Para remover um imóvel digite um dos tipos abaixo: ");
    op8 = VerificaCAT();

    switch(op8){
        case 1://CASA
            flag1 = 1;
            while(flag1){

                printf("Tem certeza que deseja remover uma casa do sistema[S/N]? ");
                limparBuffer();
                scanf("%c", &res);

                if(res ==  'S' || res == 's'){
                    ExibeImoviesDisp(op8, imovel1, imovel2, imovel3);
                    printf("Selecione uma casa: ");
                    scanf("%d", &imovelEscolhido);

                    imovelEscolhido = imovelEscolhido - 1; //Array inicia em 0, então temos que tirar 1 do valor original aqui

                    strcpy(imovel1[imovelEscolhido].imovel.logradouro, "VAZIO");
                    strcpy(imovel1[imovelEscolhido].imovel.bairro, "VAZIO");
                    strcpy(imovel1[imovelEscolhido].imovel.cidade, "VAZIO");
                    strcpy(imovel1[imovelEscolhido].imovel.disponibilidade, "VAZIO");
                    imovel1[imovelEscolhido].imovel.numeroImovel = 0;
                    imovel1[imovelEscolhido].imovel.cep = 0;
                    imovel1[imovelEscolhido].imovel.valor = 0;

                    strcpy(imovel1[imovelEscolhido].tituloAnuncio, "VAZIO");
                    imovel1[imovelEscolhido].areaConstruida = 0;
                    imovel1[imovelEscolhido].areaTerreno = 0;
                    imovel1[imovelEscolhido].numPavimentos = 0;
                    imovel1[imovelEscolhido].numQuartos = 0;

                    printf("Remoção completa\n");
                    flag1 = 0;
                    break;
                }else if(res == 'N' || res == 'n'){
                    puts("Você optou por não remover nada.");
                    flag1 = 0;
                    break;
                }else{
                    puts("RESPOSTA INVÁLIDA!");
                    system(LIMPAR);
                }
            }
            
            break;
        case 2://APARTAMENTO
            flag1 = 1;
            while(flag1){

                printf("Tem certeza que deseja remover um apartamento do sistema[S/N]? ");
                limparBuffer();
                scanf("%c", &res);

                if(res ==  'S' || res == 's'){
                    ExibeImoviesDisp(op8, imovel1, imovel2, imovel3);
                    printf("Selecione um apartamento: ");
                    scanf("%d", &imovelEscolhido);

                    imovelEscolhido = imovelEscolhido - 1; //Array inicia em 0, então temos que tirar 1 do valor original aqui

                    strcpy(imovel2[imovelEscolhido].imovel.logradouro, "VAZIO");
                    strcpy(imovel2[imovelEscolhido].imovel.bairro, "VAZIO");
                    strcpy(imovel2[imovelEscolhido].imovel.cidade, "VAZIO");
                    strcpy(imovel2[imovelEscolhido].imovel.disponibilidade, "VAZIO");
                    imovel2[imovelEscolhido].imovel.numeroImovel = 0;
                    imovel2[imovelEscolhido].imovel.cep = 0;
                    imovel2[imovelEscolhido].imovel.valor = 0;

                    strcpy(imovel2[imovelEscolhido].tituloAnuncio, "VAZIO");
                    strcpy(imovel2[imovelEscolhido].posicao, "VAZIO");
                    imovel2[imovelEscolhido].andar = 0;
                    imovel2[imovelEscolhido].area = 0;
                    imovel2[imovelEscolhido].numQuartos = 0;
                    imovel2[imovelEscolhido].numVagasGaragem = 0;
                    imovel2[imovelEscolhido].valorDoCondominio = 0;
                    
                    printf("Remoção completa\n");
                    flag1 = 0;
                    break;
                }else if(res == 'N' || res == 'n'){
                    puts("Você optou por não remover nada.");
                    flag1 = 0;
                    break;
                }else{
                    puts("RESPOSTA INVÁLIDA!");
                    system(LIMPAR);
                }
            }
            
            break;
        case 3://TERRENO
            flag1 = 1;
            while(flag1){

                printf("Tem certeza que deseja remover um terreno do sistema[S/N]? ");
                limparBuffer();
                scanf("%c", &res);

                if(res ==  'S' || res == 's'){
                    ExibeImoviesDisp(op8, imovel1, imovel2, imovel3);
                    printf("Selecione um terreno: ");
                    scanf("%d", &imovelEscolhido);

                    imovelEscolhido = imovelEscolhido - 1; //Array inicia em 0, então temos que tirar 1 do valor original aqui

                    strcpy(imovel3[imovelEscolhido].imovel.logradouro, "VAZIO");
                    strcpy(imovel3[imovelEscolhido].imovel.bairro, "VAZIO");
                    strcpy(imovel3[imovelEscolhido].imovel.cidade, "VAZIO");
                    strcpy(imovel3[imovelEscolhido].imovel.disponibilidade, "VAZIO");
                    imovel3[imovelEscolhido].imovel.numeroImovel = 0;
                    imovel3[imovelEscolhido].imovel.cep = 0;
                    imovel3[imovelEscolhido].imovel.valor = 0;

                    strcpy(imovel3[imovelEscolhido].tituloAnuncio, "VAZIO");
                    imovel3[imovelEscolhido].area = 0;

                    printf("Remoção completa\n");
                    flag1 = 0;
                    break;
                }else if(res == 'N' || res == 'n'){
                    puts("Você optou por não remover nada.");
                    flag1 = 0;
                    break;
                }else{
                    puts("RESPOSTA INVÁLIDA!");
                    system(LIMPAR);
                }
            }

            break;
        default:
            printf("OPÇÃO INVÁLIDA!\n");
            break;
    
    }
    system("pause");
}