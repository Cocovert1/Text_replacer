#ifndef TRAVERSAL_H
#define TRAVERSAL_H

struct Files {
 char path[100];
 int count;
};

void Listfiles(const char *dirname, char *target, struct Files *files, int i, int filecount);
void fileCount(const char* dirname, int *count);

#endif