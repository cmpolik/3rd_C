#include <stdint.h> 
#include <string.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[]){

    unsigned int mode;
    int fd;

    mode = O_RDWR | O_CREAT | O_TRUNC;                                   
    fd = open(argv[1], mode, 0644);

    if (fd == -1)
        perror("Ошибка открытия файла");
    
    else
    {
        unsigned int nwritten;

        printf("\n Файл '%s' открыт для чтения и записи\n", argv[1]);
        nwritten = write(fd, argv[2], strlen(argv[2]));                                  
        printf(" %u байтов записано в файл\n содержание: %s \n\n", nwritten, argv[2]);      
        close(fd);                                                                          
    }
}       

//и с dprintf ботает и с write... тогда в чем фишка dprinf и соотв.но фишка задачи 2.2
//нормально что записывает только 2ой argv[2] и ни как не может записать текс состоящий из более чем 1ого слова
//мало того каждый раз новое слово заминяет старым!??!? 
