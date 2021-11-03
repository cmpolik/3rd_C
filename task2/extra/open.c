// #include <stdio.h>
// #include <dos.h>
// #include <io.h>
// #include <sys/stat.h>

#include <stdint.h> // uint8_t
#include <string.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
                                        //int open (char *pathname, int rwmode);
int main(int argc, char *argv[]){

    //char *fname;
    unsigned int mode;
    int fd;
    
    // mode = O_RDONLY;                    //модификатор O_RDONLY - открытваем только для чтения.
    // fname = "file.dat";                 //?????????????
    // fd = open(fname, mode);             //Возвращает дескриптор файла в случае  успеха  и  -1  в
    //                                     //случае неудачи, устанавливая при этом errno.
    // if (fd==-1)
    //     perror("Ошибка открытия файла");
    // else
    // {
    //     printf("\n файл : %s открыт для чтения\n",
    //                                             fname);
    //     close(fd);
    // }


    // mode = O_WRONLY;                    //модификатор O_WRONLY - открытваем только для записи.
    // fname = "CON";                      //?????????????
    // fd = open(fname, mode);         

    // if (fd<0)
    // printf("\n Ошибка открытия консоли на запись: %s\n",
    //                                                     fname);
    // else
    // {
    //     printf("\n Файл %s открыт на запись\n",
    //                                                 fname);
    //     close(fd);                      //?????????????
    // }

    mode = O_RDWR | O_CREAT ;      // модификаторы вместе используются с 'или'                              
    //fname = "file.dat";             // O_CREATE - если нет файла с указнаным именем создать его!
    fd = open(argv[1], mode);

    if (fd==-1)
        perror("Ошибка открытия файла");
    else
        {
            printf("\n Файл %s открыт для чтения и записи\n", argv[1]);
            close(fd);
        }
}
