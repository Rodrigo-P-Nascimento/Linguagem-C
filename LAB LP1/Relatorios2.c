#include <stdio.h>
#include <string.h>

typedef struct{

    char descricao[50];
    float peso;
    char tipo;

}Movel;

//Função que tira o '\n' do final da string, usando o fgets
void TiraN( char *linhaString ){
    linhaString[strcspn ( linhaString, "\n" )] = '\0';
}
//Função que limpa o buffer de entrada, usado antes de ler strings
void limparBuffer(void){
    char c;
    while((c = getchar()) != '\n' && c != EOF);
}
//Função que verifica qual é o tipo do movel, se for do tipo 's' é adicionado +1 em um contador
int Acima10TipoS(Movel m[], int tam){
    int i, cont=0;

    for(i=0; i < tam; i++){
        if(m[i].tipo == 's'){
            if(m[i].peso > 10.0){
                cont++;
            }
        }
    }
    return cont;
}
//Função verifica se uma string termina com a palavra "Real"
int TerminaReal(Movel m, int tam){
    int cont=0;
    int tamanhoString;

    tamanhoString = strlen(m.descricao);

    if(m.descricao[tamanhoString-1]  == 'l'){
        if(m.descricao[tamanhoString-2] == 'a'){
            if(m.descricao[tamanhoString-3] == 'e'){
                if(m.descricao[tamanhoString-4] == 'R'){
                    cont = 1;
                }
            }
        }
    }

    return cont;
}


int main(){

    int numMoveis, i, cont=0, PosiPesado;
    float MaisPesado = -999999; //foi declarado com esse valor pequeno para fazer uma verificação mais basica, pois não existe peso negativo na realidade

    scanf("%d", &numMoveis);

    Movel matriz[numMoveis];
    
    for(i=0; i < numMoveis; i++){
        limparBuffer();
        fgets(matriz[i].descricao, 50, stdin);
        TiraN(matriz[i].descricao);
        scanf("%f", &matriz[i].peso);
        limparBuffer();// Para o scanf não pegar o '\n' limpamos o buffer de entrada com essa função
        scanf("%c", &matriz[i].tipo);
    }

    printf("Tipo 's' acima de 10Kg: %d\n", Acima10TipoS(matriz, numMoveis));
    for(i=0; i < numMoveis; i++){
        if(TerminaReal(matriz[i], numMoveis) == 1){
            cont++;
        }
    }
    printf("Termina em \"Real\": %d\n", cont);
    
    for(i=0; i < numMoveis; i++){
        if(matriz[i].peso >= MaisPesado){
            MaisPesado = matriz[i].peso;
            PosiPesado = i;
        }
    }
    printf("Mais pesado: \"%s\"\n", matriz[PosiPesado].descricao);

    return 0;
}
