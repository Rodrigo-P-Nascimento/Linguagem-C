#include <stdio.h>

int main(void){

    int senha_correta,senha;

    senha_correta = 2020;
    senha = 0;

    while (senha != senha_correta)
    {
        printf("Digite a senha: ");
        scanf("%d", &senha);
        if(senha != senha_correta){
            puts("Senha Invalida");
        }else{
            puts("Acesso Permitido");
        }
    }

    return 0;
}