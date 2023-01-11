#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "traversal.h"
#include "report.h"

//Assignment 1 Nicholas Pop 

//main function
int main(int argc, char *argv[]){
    //initialize variables
    long size;
    char *buf;
    char *ptr;
    int arrcount = 0;

    //find file count
    int count;
    fileCount(".", &count);

    //create struct array
    struct Files files[count];

    //get current directory
    size = pathconf(".", _PC_PATH_MAX);
    if ((buf = (char *)malloc((size_t)size)) != NULL)
        ptr = getcwd(buf, (size_t)size);

    printf("Target string: %s\n", argv[1]);
    printf("Current directory is %s\n\n\n", ptr);

    //free memory
    free(ptr);

    //call the traversal function
    Listfiles(".", argv[1], files, arrcount, count);

    //call the report
    report(files, count);
}
