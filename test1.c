#include <stdio.h>
#define ARRAY_SIZE 5
int main () {
	FILE *fOut;
	FILE *fIn;
	int v[ARRAY_SIZE] = {99, 11, 22, 44, 55};
	int v2[ARRAY_SIZE];
	fOut = fopen ("Output.txt", "w");
	if (!fOut) {
		printf ("ERROR: File not created!\n");
		return 1;
	}
	for (int i=0; i<ARRAY_SIZE; i++) {
		printf ("%4d", v[i]);
		fprintf (fOut, "%4d", v[i]);
	}
	fclose(fOut);
	printf ("\n");
	printf ("Array before reading from file:\n");
	for (int i=0; i<ARRAY_SIZE; i++) {
		printf ("%4d", v2[i]);
	}
	printf ("\n");
	fIn = fopen("output.txt", "r");
	if (!fIn) {
		printf ("ERROR: File not found!\n");
	}
	for (int i=0; i<ARRAY_SIZE; i++) {
		fscanf(fIn, "%4d", &v2[i]);
	}
	fclose(fIn);
	printf ("Array after reading from file: \n");
	for (int i=0; i<ARRAY_SIZE; i++) {
		printf ("%4d", v2[i]);
	}
	return 0;
}

