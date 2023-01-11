#include <stdio.h>
#include <stdlib.h>
#include "traversal.h"

//compare function
int compare(const void *a, const void *b) {
  
    struct Files *filesA = (struct Files *)a;
    struct Files *filesB = (struct Files *)b;
  
    return (filesB->count - filesA->count);
}

//report funciton
void report(struct Files *files, int count){
    //prints a message and sorts the struct
    printf("** Search Report **\n\n");

    qsort(files, count, sizeof(files[0].path) + sizeof(files[0].count),compare);

    printf("Updates  File Name\n");
    for(int i = 0; i < count; i++){
        printf("%i        %s\n", files[i].count, files[i].path);
    }
}