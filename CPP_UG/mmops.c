#include <stdio.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int fd;
    char *addr;

    //open the file
    fd = open("examples.txt", O_RDONLY);
    if(fd == -1) {
        perror("Error opening file for reading");
        return 1;
    }

    //map the file to memory
    addr = mmap(NULL, 4096, PROT_READ, MAP_PRIVATE, fd, 0);
    if(addr == MAP_FAILED) {
        perror("Error mapping file to memory");
        return 1;
    }

    //Read from the memory mapped file
    printf("The first byte of the file is %c\n", addr[0]);
    printf("The contents of the file are: %s\n", addr);

    //unmap the file
    if(munmap(addr, 4096) == -1) {
        perror("Error unmapping file");
        return 1;
    }

    //close the file
    if(close(fd) == -1) {
        perror("Error closing file");
        return 1;
    }

    return 0;

}