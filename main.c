/* Autumn Hale
* CSCI 4100
* Assignment 1
* This program reads and displays text
from both standard input and from a file.
Simple C version of kittycat.
*/

#include <stdio.h>
#include <stdlib.h>

FILE *stream;
FILE *stdin;

void display_stream(FILE *stream);

int main (int argc, char *argv[]) {
	
	// File name(s) are given and displayed
	if (argc > 1) {
       		 for (int i = 0; i < argc; i++) {
			stream =  fopen(argv[i], "r");

			// If files do not exist, error displayed
			if (stream == NULL) {
			perror("Error: ");
			fclose(stream);
			exit(-1);
			}

			display_stream(stream);
		}
	}

	// Files do not exist, error displayed
	if (stream == NULL) {
		perror("Error: ");
		fclose(stream);
		exit(-1);
	}

	// No files given, input stream processed and displayed
	if (argc == 1) {
	char c;
	//	while (c != EOF){
			c = fgetc(stdin);
			display_stream(stdin);
	//	}
	}

	return 0;
}

void display_stream(FILE *stream) {
	int character = fgetc(stream);

	while (character != EOF ) {
		putchar(character);
		character = fgetc(stream);
	}
	
	fclose(stream);

}


