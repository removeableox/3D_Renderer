#include "includes.h"

float* getVerticesFromFile(const char* filename, int* size) {
	FILE *fptr;
	fptr = fopen(filename, "r");
	if (fptr == NULL) {
		printf("Error opening file!");
		return NULL;
	}

	char myString[100];
	float *vertices3d = NULL;
	int index = 0;
	int capacity = 0;

	while (fgets(myString, 100, fptr)) {
		char* splitted = strtok(myString, ": \t\n");
		while (splitted != NULL) {
			if (index >= capacity) {
				capacity += 10;
				float *temp = realloc(vertices3d, capacity * sizeof(float));
				if (temp == NULL) {
					free(vertices3d);
					fprintf(stderr, "Memory allocation failed\n");
					fclose(fptr);
					return NULL;
				}
				vertices3d = temp;
			}
			float num = atof(splitted);
			vertices3d[index] = num;
			index++;
			splitted = strtok(NULL, ": \t\n");
		}
	}

	*size = index;	

	fclose(fptr);
	return vertices3d;
}
