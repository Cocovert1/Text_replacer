#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <stdlib.h>
#include "traversal.h"
#include "text.h"

//find the total file count
void fileCount(const char* dirname, int *count){
	//open directory and error check
	DIR* dir = opendir(dirname);
	if (dir == NULL){
		return; 
	}
	
	struct dirent* entity;
	entity = readdir(dir);

	//find all the txt file and increment the count variable
	while (entity != NULL){
		if (strstr(entity->d_name, ".txt") != NULL){
				(*count)++;
			}
		
		//find if there is a file and call the function recursively
		if (entity->d_type == DT_DIR && strcmp(entity->d_name, ".") != 0 && strcmp(entity->d_name, "..") != 0){
			char path[100] = {0};
			strcat(path, dirname);
			strcat(path, "/");
			strcat(path, entity->d_name);
			fileCount(path, count);
		}
		entity = readdir(dir);	
	}
	
	//close the directory
	closedir(dir);
}

//directory traversal function
void Listfiles(const char* dirname, char *target, struct Files* files, int i, int filecount){
	//open the directory
	DIR* dir = opendir(dirname);
	if (dir == NULL){
		return; 
	}
	
	struct dirent* entity;
	entity = readdir(dir);
	
	//check each directory for a .txt file and store its path in the struct array
	while (entity != NULL){
		if (strstr(entity->d_name, ".txt") != NULL){
				//copy the path
				char directory[100] = {0};
				strcat(directory, dirname);
				strcat(directory, "/");
				strcat(directory, entity->d_name);

				//modify struct element
				strcpy(files[i].path, directory);
				filechange(files[i].path, target, i, files);

				i++;
			}
		
		//recursively call the function if there is a file
		if (entity->d_type == DT_DIR && strcmp(entity->d_name, ".") != 0 && strcmp(entity->d_name, "..") != 0){
			char path[100] = {0};
			strcat(path, dirname);
			strcat(path, "/");
			strcat(path, entity->d_name);
			Listfiles(path, target, files, i, filecount);
		}
		entity = readdir(dir);	
	}
	//close the directory
	closedir(dir);
}

