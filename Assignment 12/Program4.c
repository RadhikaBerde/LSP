/* 4. Write a program which map any file in memory and read the data from that mapped file. */

#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main() 
{
    int fd;
    struct stat fileStat;
    char *mapped_file;

    // Open the file in read-only mode
    fd = open("Demo.txt", O_RDONLY);
    if (fd == -1) 
    {
        printf("Unable to open file\n");
        return 1;
    }
 
    printf("File is opened successfully with fd : %d\n", fd);
 
    // Get the size of the file
    fstat(fd, &fileStat);
    
    // Map the file into memory
    mapped_file = mmap(NULL, fileStat.st_size, PROT_READ, MAP_PRIVATE, fd, 0);
    
    if (mapped_file == MAP_FAILED) 
    {
        printf("Unable to map file");
        return 1;
    }

    // Read and print the data from the mapped file
    printf("Data in the mapped file:\n%s\n", mapped_file);

    // Unmap the file from memory
    munmap(mapped_file, fileStat.st_size);

    // Close the file
    close(fd) ;
   
    return 0;
}
