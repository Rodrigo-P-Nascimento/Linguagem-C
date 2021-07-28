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

void organizaArquivo(int *vet);

int main(void){

    int vect[11];

    organizaArquivo(&vect[0]);

    printf("Arquivo ordenado com sucesso!\n");
    system("pause");

    return 0;
}

void organizaArquivo(int *vet){

    int i, j, aux;

    FILE *ar1;

    ar1 = fopen("testeNumDes.txt", "r");

    for(i=0; i < 10; i++){              //Vamos copiar os valores do arquivo para o array
        fscanf(ar1, "%d\n", &vet[i]);
        printf(" %d ", vet[i]);
    }

    ar1 = fopen("teste03.txt", "w");    //Vamos criar um arquivo, que vai receber os numeros em ordem

    for(i=0;i<10;i++){
        //bubble sort 
        for(j=0;j < 10;j++){
            if(vet[i] > vet[j]){

                aux = vet[i];
                vet[i] = vet[j];
                vet[j] = aux;
            }
        }
        printf("Num: %d\n", vet[i]);
        fprintf(ar1, "%d\n", vet[i]);   //Vamos escrever os valores no arquivo teste03.txt
    }

    fclose(ar1);
    
}