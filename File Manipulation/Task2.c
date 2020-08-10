/*
The Purpose of this Program is to read data from a file
and write it to the console screen
*/
#include <sys/types.h>
#include<fcntl.h>
#include<unistd.h>
#include <stdio.h>

int main() {
    // File Descriptor for read file
    int fd;
    // A variable to store filename from the user
    char filename[20];
    // Filename to read
    printf("Enter the filename to read: ");
    scanf("%s", filename);
    // Open the file
    fd = open(filename, O_RDWR);

    printf(" Opening the file...\n");
    // if read file does not exist, terminate the program
    if (fd== -1) {
        printf("Error Opening the file\n\n"); return 0;
    }
    else printf(" File Opened Successfully\n\n");
    // A temporary storage to keep data, read from the readfile
    char buffer;
    // Reading data from readfile by read() function
    // and writing it to the console screen by write() function
    while (read(fd, &buffer, 1) > 0)
        write(1, &buffer, 1);

    printf("\n\n Write to console Operation done successfully\n");
    // Close the file
    close(fd);
    return 0;
}