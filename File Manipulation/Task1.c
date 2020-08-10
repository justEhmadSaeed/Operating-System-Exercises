/* 
The Purpose of this Program is to read data from one file
and write it into another file 
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    // Two File Descriptors for read & write file
    FILE *fd1, *fd2;
    // A variable to store filename from the user
    char filename[20];
    // Filename to read
    printf("Enter the filename to read: ");
    scanf("%s", filename);
    // Open the file
    fd1 = fopen(filename, "r");

    printf(" Opening the file...\n");
    // if read file does not exist, terminate the program
    if (fd1== NULL) {
        printf("Error Opening the file\n\n"); return 0;
    }
    else printf(" File Opened Successfully\n\n");

    // Filename to write 
    printf("Enter the filename to write: ");
    scanf("%s", filename);
    // Open the file
    fd2 = fopen(filename, "w");

    printf(" Opening the file...\n");
    // if write file does not exist, the program will create one
    if (fd2== NULL) printf("Error Opening the file\n\n");
    else printf(" File Opened Successfully\n\n");
    // A temporary storage to keep data, read from the readfile
    char buffer[1000];
    // Fetching data from readfile by fgets() function
    // and storing it in writefile using fputs() function
    while (fgets(buffer, 1000, fd1)!=NULL)
        fputs(buffer, fd2);

    printf(" File Write Operation done successfully\n");
    // Closing Both Files
    fclose(fd1);
    fclose(fd2);
    return 0;
}