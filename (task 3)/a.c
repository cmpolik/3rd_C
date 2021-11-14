#include <unistd.h>  // for read
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>

// read() 
// ssize_t read(int fd, void *buf, size_t count);
// returns number of bites(file posision) on success
// and -1 if smth wrong
// read()  attempts to read up to count bytes from file descriptor fd into the buffer starting at buf.

int main(int argc, char *argv[]) 
{ 
    int fd1, fd2;
    char buffer[1000000] = "";
    unsigned int mode1, mode2, bytes, bytes_out;

    mode1 = O_RDWR; 
    mode2 = O_RDWR | O_CREAT | O_TRUNC; 

    scanf("%u", &bytes);
    fd1 = open(argv[1], mode1, 0644);
    fd2 = open(argv[2], mode2, 0644);
    bytes = read(fd1, buffer, bytes);
    bytes_out = write(fd2, buffer, bytes);
   
    if(fd1 == -1) {
        perror("Ошибка открытия файла");
        exit(1);
    }
    if(fd2 == -1) {
        perror("Ошибка открытия файла");
        exit(1);
    }
    if (bytes == -1){
        perror ("Possible read error.");
        exit(1);
    }
    if(bytes_out == -1){
        perror("Write Error");
        exit(1);
    }

    printf("%u байтов была успешно скапирована \n", bytes);
    printf("%u байтов было успешно ставлена в новый файл\n", bytes_out);

    close(fd1);
    close(fd2);

    return 0;
}