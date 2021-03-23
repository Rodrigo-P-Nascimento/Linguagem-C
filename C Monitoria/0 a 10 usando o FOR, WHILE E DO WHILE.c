#include <stdio.h>

int main(void){

    int i;

    i = 0;

    puts("Usando o While");
    while (i <= 10){
        printf("%d ", i);
        i += 1;
    }

    i = 0;

    puts("");
    puts("\nUsando o do-while");
    do {
        printf("%d ", i);
        i += 1;
    }while (i <= 10);

    puts("");
    puts("\nUsando o for");
    for (i = 0; i <= 10; i += 1){
        printf("%d ", i);
    }
    
    return 0;
}