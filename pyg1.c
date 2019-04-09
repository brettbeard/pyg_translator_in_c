/* include files */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* prototypes */
char * pyg_translator(const char * input);

/* pyg_translator function*/
char * pyg_translator(const char * input)
{
	char * working_input = malloc(strlen(input) + 1);
	char * output = malloc(strlen(input) + 1);
	char first_ch[2] = { 0 };

	/* Make a working copy of input */
	strcpy(working_input, input);

	/* Check if the input has a carriage return */
	if (working_input[strlen(working_input) - 1] == '\n')
	{
		working_input[strlen(working_input) - 1] = 0;
	}

	/* save off first character */
	first_ch[0] = working_input[0];

	/* copy the string (except the first character) */
	strcpy(output, &working_input[1]);

	/* append the first character */
	strcat(output, first_ch);

	/* append the pyg latin ending */
	strcat(output, "ay");

	return output;
}

int main(void) {
	char input[256] = { 0 };

	printf("Enter a word:\n");

	/* get input from the user */
	fgets(input, sizeof(input), stdin);

	/* translate the input */
	char * translated = pyg_translator(input);

	/* print out the translation */
	printf("Translated = %s\n", translated);

	/*printf("Hello World\n");*/
	return 0;
}