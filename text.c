#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "traversal.h"

void filechange(char *filename, char *target, int pos, struct Files* filestr){
	FILE *file;

	file = fopen(filename, "r"); //read
	if (file == NULL){ //error checking.
		return;
	}
	
	fseek(file, 0, SEEK_END); //move pointer to the end
	int length = ftell(file); 
	
	fseek(file, 0, SEEK_SET); //move pointer to beggining
	
	char *string = malloc(sizeof(char) * (length+1)); //+1 to include null terminator \0

	//initialize variables
	int size = strlen(target);
	char temp[size];	
	char c;
	int i = 0;
	int count = 0;
	int changecounter = 0;

	//will take each character, if character is the same as target, store it in temp and then compare.
	while ( (c = fgetc(file)) != EOF){
		string[i] = c;

		if(tolower(c) == tolower(target[count])){ //check for each character and store
			temp[count] = tolower(c);
			count++;
		} else { //empty temp if not the correct character
			count = 0;
			for(int k = 0; k < strlen(target); k++){
				temp[k] = '\0';
			}
			if(tolower(c) == tolower(target[count])){
				temp[count] = tolower(c);
				count++;
			}
		}

		if(strncmp(temp,target, size) == 0){ //compare if same and uppercase and increment counter
			for(int k =0; k < strlen(target); k++){
				string[i-k] = toupper(string[i-k]);
			}
			count = 0;
			for(int k = 0; k < strlen(target); k++){
				temp[k] = '\0';
			}
			changecounter++;
		}
		i++;
	}
	
	//add a string null termination case
	string[i] = '\0';

	//close read file
	fclose(file);

	//open write file
	FILE *p;
	p = fopen(filename, "w");
	fputs(string, p);
	if (p == NULL){ //error checking.
		return;
	}

	//free memory
	free(string);

	//store the change counter
	filestr[pos].count = changecounter;

	//close write file
	fclose(p);
}




