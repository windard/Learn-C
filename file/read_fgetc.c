#include <stdio.h> 
#include <stdlib.h> // For exit() 

#define MAX_FILE_SIZE 1024

int main() 
{ 
    FILE *fptr; 

    char c; 
    
    // Open file 
    fptr = fopen("read_file.c", "r"); 
    if (fptr == NULL) 
    { 
        printf("Cannot open file \n"); 
        exit(0); 
    } 

    // Read contents from file 
    c = fgetc(fptr); 
    while (c != EOF) 
    {
        printf ("%c", c); 
        c = fgetc(fptr); 
    }
  
    fclose(fptr); 
    return 0; 
}