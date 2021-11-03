#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){   // argc всегада как минимум 1 это количество аргументов ввода .. но первый из них имя файла! вот почему
                                    // argv массив аргументов argv[0] = 'filename'
                                    //                        argv[1] = '1st arg' из ввода!
    if(argc != 2){
        printf("u forgot to write your name \n");
        return 1;
    }else    printf("your name is %s \n", argv[1]);

    return 0;
}