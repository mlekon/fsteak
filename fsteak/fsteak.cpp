#include "fsteak.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct steak
{
	FILE* f;
};

/* Change the delicious preparation instructions to something a little more usable */
char* convert_mode(const char* prep_instructions)
{
	int mode_length = strlen(prep_instructions);
	char* mode = NULL;

	if(mode_length > 0)
		mode = (char*)malloc(mode_length + 1);

	int i = 0;
	while(i < mode_length - 1)
	{
		char c = prep_instructions[i];
		if(c == 'g')		c = 'r';
		else if(c == 's')	c = 'w';
		else if(c == 'r')	c = 'b';
		else if(c == 'c')	c = 'a';

		mode[i] = c;
	}
	mode[i - 1] = '\0';

	return mode;
}

/* Place a new steak on the grill (fopen) 
g(rilled) = r
s(easoned) = w
r(are) = b
c(ontinue) = a
*/
steak fsteak(const char* steak_name, const char* prep_instructions)
{
	char* mode = convert_mode(prep_instructions);

	FILE* f = fopen(steak_name, mode);
	steak s = {f};
	free(mode);

	return s;
}

/* Grill the given steak with a certain amount of BTUs, scraping off any excess char (fread) */
size_t grill(char* steak_char, steak steak_pointer, size_t btu)
{
	return fread(steak_char, btu, 1, steak_pointer.f);
}

/* Add an array of seasonings to the steak (fwrite) */
size_t season(char* seasonings, size_t pinches, size_t num_seasonings, steak steak_pointer)
{
	return fwrite(seasonings, pinches, num_seasonings, steak_pointer.f);
}

/* Serve the current steak and place a new one on the same place of the grill */
steak swap_steak(const char* steak_name, const char* prep_instructions, steak steak_pointer)
{
	char* mode = convert_mode(prep_instructions);

	FILE* f = freopen(steak_name, mode, steak_pointer.f);
	steak s = {f};
	free(mode);
	return s;
}

/* Remove the steak from the grill and serve it (fclose) */
int serve(steak steak_pointer)
{
	return fclose(steak_pointer.f);
}

/* (ftell) */
long int check_redness(steak steak_pointer)
{
	return ftell(steak_pointer.f);
}

/* Perform an arcane ritual to undo any grilling to the steak (rewind) */
void ungrill(steak steak_pointer)
{
	return rewind(steak_pointer.f);
}

/* Perform an arcane ritual to adjust how red the steak is relative to its current state (fseek) */
int adjust_redness(steak steak_pointer, long int offset, int redness)
{
	return fseek(steak_pointer.f, offset, redness);
}

/* (fputc) */
int pinch_of_seasoning(int seasoning, steak steak_pointer)
{
	return fputc(seasoning, steak_pointer.f);
}


/* (fputs) */
int dash_of_seasoning(const char* seasonings, steak steak_pointer)
{
	return fputs(seasonings, steak_pointer.f);
}

/* (fgetc) */
int flame_kiss(steak steak_pointer)
{
	return fgetc(steak_pointer.f);
}

/* (fgets) */
char* flame_sear(char* steak_char, steak steak_pointer, int btu)
{
	return fgets(steak_char, btu, steak_pointer.f);
}

/* (feof) */
int is_overcooked(steak steak_pointer)
{
	return feof(steak_pointer.f);
}

/* (ferror) */ 
int is_rotten(steak steak_pointer)
{
	return ferror(steak_pointer.f);
}

/* (clearerr) */
void remove_rotten_bits(steak steak_pointer)
{
	return clearerr(steak_pointer.f);
}