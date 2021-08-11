#include <stdio.h>

int main(){

    int op=1; //Variavel que guarda a resposta do usuario;

    while (op != 4){
        //Menu basico de opções disponiveis
        puts("1 - Item 1");
        puts("2 - Item 2");
        puts("3 - Item 3");
        puts("4 - Sair");

        scanf("%d", &op);

        switch (op){
            case 1:
                printf("Item 1\n");
                break;
            case 2:
                printf("Item 2\n");
                break;
            case 3:
                printf("Item 3\n");
                break;
            case 4:
                printf("Sair\n");
                break;
            default:
                printf("Opcao %d Invalida\n", op);
                break;
        }
    }

    return 0;
}