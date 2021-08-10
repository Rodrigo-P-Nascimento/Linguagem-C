#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
int main(void){

    FILE *arquivo;                         //Cria-se um ponteiro para um arquivo

    arquivo = fopen("teste.txt", "w");      //Criando um arquivo em modo de escrita

    fprintf(arquivo, "Hello World!!!");     //escrevendo num arquivo

    fclose(arquivo);                        //Fechando um arquivo
    system("pause");

    return 0;
}
*/
/*
void LeArquivo(int *vet);

int main(void){

    int vet[10];

    LeArquivo(vet);

    printf("Arquivo criado com sucesso!\n");
    system("pause");
}

void LeArquivo(int *vet){

    FILE *arquivo;
    int cont;

    arquivo = fopen("testeNum.txt", "r");   //Abrindo arquivo em modo leitura

    for(cont = 0; cont < 10;cont++){
        fscanf(arquivo, "%d\n", &vet[cont]);
    }

    arquivo = fopen("teste02.txt", "w");

    for(cont=0; cont < 10; cont++){
        fprintf(arquivo, "%d\n", vet[cont]+1);
    }
    
    fclose(arquivo);
}
*/
/*
void organizaArquivo(int *vet);
void bubble_sort(int vetor[], int n);

int main(void){

    int vect[10];

    organizaArquivo(&vect[0]);

    printf("Arquivo ordenado com sucesso!\n");
    system("pause");

    return 0;
}

void bubble_sort (int vetor[], int n) {
    int k, j, aux;

    for (k = 1; k < n; k++) {
        
        for (j = 0; j < n - 1; j++) {

            if (vetor[j] > vetor[j + 1]) {
                aux          = vetor[j];
                vetor[j]     = vetor[j + 1];
                vetor[j + 1] = aux;
            }
        }
    }
}
void organizaArquivo(int *vet){

    int i, j, aux;

    FILE *ar1;

    ar1 = fopen("testeNumDes.txt", "r");

    for(i=0; i < 10; i++){              //Vamos copiar os valores do arquivo para o array
        fscanf(ar1, "%d\n", &vet[i]);
    }

    ar1 = fopen("teste03.txt", "w");    //Vamos criar um arquivo, que vai receber os numeros em ordem
   
    bubble_sort(&vet[0], 10);
    puts("");
    for(i=0; i < 10; i++){              //Vamos copiar os valores do arquivo para o array
        printf("NOVO VALOR[%d]: %d\n",i , vet[i]);
        fprintf(ar1, "Novo valor Mâção: %d\n", vet[i]);
    }
    fclose(ar1);
    
}
*/


#define TAM 30

void TiraN( char *linhaString ){
    linhaString[strcspn ( linhaString, "\n" )] = '\0';
}
typedef struct
{
    char nome[TAM];
    int idade;
    double peso;

}Registo_t;


int main(){

    FILE *arq1;
    Registo_t Pessoas[5];
    char nomes[TAM];
    int age;
    double ppeso;



    arq1 = fopen("frases.txt", "r");

    if(arq1 == NULL){
        printf("Algo de errado aconteceu com o arquivo, sendo impossivel abri-lo\n");
        return 0;
    }

    for(int i=0; i < 5;i++){
        //fscanf(arq1, "%s\n", Pessoas[i].nome);
      
        fgets(nomes, sizeof(nomes), arq1);
        //printf("Nome do cara: %s\n", nomes);
        TiraN(nomes);
        strcpy(Pessoas[i].nome, nomes); 

        fscanf(arq1, "%d", &age);
        //printf("Idade do cara: %d\n", age);
        Pessoas[i].idade = age;

        fscanf(arq1, "%lf", &ppeso);
        //printf("Peso do cara: %lf\n", ppeso);
        Pessoas[i].peso = ppeso;
    }
    puts("Lido com sucesso\n");

    for(int i=0; i < 5;i++){
        printf("Nome do cara: %s\n", Pessoas[i].nome);
        printf("Idade do cara: %d\n", Pessoas[i].idade);
        printf("Peso do cara: %.2lf\n\n", Pessoas[i].peso);
    }

    fclose(arq1);   
    printf("Arquivo fechado com sucesso");

    return 0;
}