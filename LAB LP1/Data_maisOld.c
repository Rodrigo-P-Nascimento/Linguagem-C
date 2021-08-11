#include <stdio.h>

//Dedinição da estrutura tData, para guardar as datas de uma pessoa
typedef struct{
    int dia;
    int mes;
    int ano;
}tData;

//função que avalia qual das duas pessoas é a mais velha, sendo que se elas foram da exata mesma idade ela retorna 0
int MaisVelho(tData p1, tData p2){
//12 13
    if(p1.ano == p2.ano && p1.dia == p2.dia && p1.mes == p2.mes){
        return 0;
    }
    if(p1.ano < p2.ano){
        return 1;
    }else if(p1.ano > p2.ano){
        return -1;
    }else if(p1.mes < p2.mes){
        return 1;
    }else if(p1.mes > p2.mes){
        return -1;
    }else if(p1.dia < p2.dia){
        return 1;
    }else if(p1.dia > p2.dia){
        return -1;
    }
    
}

int main(){

    tData pes1, pes2;
    int resul;
    //Lendo os valores de entrada para as duas pessoas
    scanf("%d", &pes1.dia);
    scanf("%d", &pes1.mes);
    scanf("%d", &pes1.ano);

    scanf("%d", &pes2.dia);
    scanf("%d", &pes2.mes);
    scanf("%d", &pes2.ano);
    
    resul = MaisVelho(pes1, pes2);

    if(resul == 1){
        printf("Pessoa 1 é mais velha\n");
    }else if(resul == 0){
        printf("Pessoas são da mesma idade\n");
    }else if(resul == -1){
        printf("Pessoa 2 é mais velha\n");
    }

    return 0;
}