#include <stdio.h>
#include <string.h>

#define TAM 100

typedef struct {
    char nome[TAM];
    int numero;
    int QVotos;
}tCandidato;

void TiraN(char *linhaString){
    linhaString[strcspn(linhaString, "\n")] = '\0';
}
void LimparBuffer(){
    char c;
    while((c = getchar()) != '\n' && c != EOF);
}

//Função para fazer o calculo da poncetagem dos votos 
float ContagemVotos(int numVotos, int Candvotos){
    return ((Candvotos*100)/ (float)numVotos);
}

int main(){

    int numCandidatos, i, posVencedor;
    int voto=1, votoNulo=0, numVotos=0;
    float vencedor = -9999.999;

    scanf("%d", &numCandidatos);

    tCandidato cand[numCandidatos];
    float porVotos[numCandidatos]; //Array para guardar a porcentagem dos votos dos candidatos

    for(i=0; i < numCandidatos; i++){
        scanf("%d", &cand[i].numero);
        LimparBuffer();
        fgets(cand[i].nome, TAM, stdin);
        TiraN(cand[i].nome);
        cand[i].QVotos = 0; //Iniciar todos os candidatos com 0 na contagem de votos.
    }
    //Leitura dos votos
    while(voto >= 0){
        scanf("%d", &voto);

        for(i=0; i < numCandidatos; i++){
            if(voto == cand[i].numero){
                cand[i].QVotos++;
                numVotos++;
                break;
            }
            if(i == numCandidatos-1 && voto > 0){
                votoNulo++;
                numVotos++;
            }
        }
    }
    for(i=0; i < numCandidatos; i++){
        porVotos[i] = ContagemVotos(numVotos, cand[i].QVotos);
        if(porVotos[i] > vencedor){
            vencedor = porVotos[i];
            posVencedor = i;
        }
    }
    
    for(i=0; i < numCandidatos; i++){
        if(posVencedor == i){
            printf("%.2f - %d - %s VENCEDOR\n", porVotos[i], cand[i].numero, cand[i].nome);
        }else{
            printf("%.2f - %d - %s\n", porVotos[i], cand[i].numero, cand[i].nome);
        }
    }
    printf("%.2f - Nulos\n", ContagemVotos(numVotos, votoNulo));

    return 0;
}