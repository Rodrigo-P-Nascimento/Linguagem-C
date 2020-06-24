#include <stdio.h>

int main(void){

    int i;

    for (i = 1; i <= 200; i += 1){
        if ( i % 2 == 0 ){
            printf("%d - So aprende a programar quem escreve programas\n", i);
        }else{
            printf("%d - Quem nao escreve programas nao aprende a programar\n", i);
        }
    }
   
    return 0;
}