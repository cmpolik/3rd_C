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

    printf("%s", argv[0]);
    mode = O_RDWR | O_CREAT | O_TRUNC;                                   
    fd = open(argv[1], mode, 0644);

    if (fd == -1)
        perror("Ошибка открытия файла");
    
    else
    {
        unsigned int nwritten = 0;

        printf("\n Файл '%s' открыт для чтения и записи\n", argv[1]);
    
    for(int i = 2; i < argc; ++i){
        nwritten += write(fd, argv[i], strlen(argv[i]));
        if (i < argc - 1)   
        nwritten += write(fd, " ", 1);
    }

        printf(" %u байтов записано в файл \n", nwritten);     
        close(fd);                                                                          
    }
    return 0;
}       
