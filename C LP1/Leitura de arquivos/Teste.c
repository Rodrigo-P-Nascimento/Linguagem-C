#include <stdio.h>
#include <stdlib.h>

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
        fprintf(arquivo, "%d\n", vet[cont]+3);
    }
    
    fclose(arquivo);
}