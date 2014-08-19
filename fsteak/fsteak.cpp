/*
 * fsteak: A library for steak-based file I/O
 * fsteak.c: Definitions of the fsteak library functions
 * Copyright (C) 2014  Mike Lekon
 * 
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "fsteak.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct steak
{
	FILE* f;
};

//////////////////////////////////////////////////////////////////////////
/// Helper function that converts from the bland, tasteless fopen modes and
/// the juicy, flavorful fsteak preparation instructions.
/// prep_instructions: c string with the list of prep instructions to use
/// returns: The fopen equivalents to the given prep instructions
//////////////////////////////////////////////////////////////////////////
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


//////////////////////////////////////////////////////////////////////////
/// Places a new steak on the grill. 
/// Roughly equivalent to fopen.
/// steak_name: A c-string with the name of this steak. Gonna be so good that it needs a proper name 
/// prep_instructions: A c-string describes how the steak will be prepared. Possible values with
///		their fopen equivalents are shown below:
///			g(rilled) = r
///			s(easoned) = w
///			r(are) = b
///			c(ontinue) = a
/// returns: A steak object used in the other fsteak functions
//////////////////////////////////////////////////////////////////////////
steak fsteak(const char* steak_name, const char* prep_instructions)
{
	char* mode = convert_mode(prep_instructions);

	FILE* f = fopen(steak_name, mode);
	steak s = {f};
	free(mode);

	return s;
}


//////////////////////////////////////////////////////////////////////////
/// Grills the given steak with a certain amount of BTUs, scraping off any excess char.
/// Roughly comparable to fread.
/// returns: Integer value representing how much grilling was done.
//////////////////////////////////////////////////////////////////////////
size_t grill(char* steak_char, steak steak_pointer, size_t btu)
{
	return fread(steak_char, btu, 1, steak_pointer.f);
}


//////////////////////////////////////////////////////////////////////////
/// Adds an array of seasonings to the steak.
/// Roughly comparable to fwrite.
/// returns: An integer representation of how much seasoning was applied
//////////////////////////////////////////////////////////////////////////
size_t season(char* seasonings, size_t pinches, size_t num_seasonings, steak steak_pointer)
{
	return fwrite(seasonings, pinches, num_seasonings, steak_pointer.f);
}

//////////////////////////////////////////////////////////////////////////
/// Serves the current steak and places a new one on the same place of the grill.
/// returns: The new steak object.
//////////////////////////////////////////////////////////////////////////
steak swap_steak(const char* steak_name, const char* prep_instructions, steak steak_pointer)
{
	char* mode = convert_mode(prep_instructions);

	FILE* f = freopen(steak_name, mode, steak_pointer.f);
	steak s = {f};
	free(mode);
	return s;
}


//////////////////////////////////////////////////////////////////////////
/// Removes the steak from the grill and serves it.
/// Roughly comparable to fclose.
/// returns: Error code from removing the steak. Codes are the same as fclose.
//////////////////////////////////////////////////////////////////////////
int serve(steak steak_pointer)
{
	return fclose(steak_pointer.f);
}


//////////////////////////////////////////////////////////////////////////
/// Checks exactly how red the steak is.
/// Roughly comparable to ftell.
/// returns: An integer representation of how well cooked the steak is.
//////////////////////////////////////////////////////////////////////////
long int check_redness(steak steak_pointer)
{
	return ftell(steak_pointer.f);
}


//////////////////////////////////////////////////////////////////////////
/// Performs an arcane ritual to undo any grilling done to the steak.
/// Roughly comparable to the standard rewind function.
//////////////////////////////////////////////////////////////////////////
void ungrill(steak steak_pointer)
{
	rewind(steak_pointer.f);
}


//////////////////////////////////////////////////////////////////////////
/// Performs an arcane ritual to adjust how red the steak is relative to its current state.
/// Roughly comparable to fseek
/// returns: An integer representation of how well cooked the steak is after the ritual.
//////////////////////////////////////////////////////////////////////////
int adjust_redness(steak steak_pointer, long int offset, int redness)
{
	return fseek(steak_pointer.f, offset, redness);
}


//////////////////////////////////////////////////////////////////////////
/// Adds a small dash of seasoning.
/// Roughly equivalent to fputc
/// returns: A clone of the added seasoning pulled from a parallel universe
//////////////////////////////////////////////////////////////////////////
int pinch_of_seasoning(int seasoning, steak steak_pointer)
{
	return fputc(seasoning, steak_pointer.f);
}


//////////////////////////////////////////////////////////////////////////
/// Adds dashes of seasoning until the steak is well coated.
/// Roughly comparable to fputs
/// returns: A non-zero value or error code similar to fputs.
//////////////////////////////////////////////////////////////////////////
int dash_of_seasoning(const char* seasonings, steak steak_pointer)
{
	return fputs(seasonings, steak_pointer.f);
}


//////////////////////////////////////////////////////////////////////////
/// The flame gently kisses the steak, cooking it ever so slightly.
/// Roughly equivalent to fgetc
/// returns: The small bits of char created from the cooking.
//////////////////////////////////////////////////////////////////////////
int flame_kiss(steak steak_pointer)
{
	return fgetc(steak_pointer.f);
}


//////////////////////////////////////////////////////////////////////////
/// Sears the steak on an open flame until it's cooked to perfection.
/// Roughly equivalent to fgets
/// returns: The char created from the cooking.
//////////////////////////////////////////////////////////////////////////
char* flame_sear(char* steak_char, steak steak_pointer, int btu)
{
	return fgets(steak_char, btu, steak_pointer.f);
}


//////////////////////////////////////////////////////////////////////////
/// Checks whether the steak is done cooking.
/// Roughly equivalent to feof.
/// returns: Non-zero if the steak is well done, zero otherwise
//////////////////////////////////////////////////////////////////////////
int is_cooked(steak steak_pointer)
{
	return feof(steak_pointer.f);
}


//////////////////////////////////////////////////////////////////////////
/// Checks whether the steak was left out a little took long and attracted a few maggots.
/// Roughly equivalent to ferror.
/// returns: The error code for the steak. Similar to ferror.
//////////////////////////////////////////////////////////////////////////
int is_rotten(steak steak_pointer)
{
	return ferror(steak_pointer.f);
}


//////////////////////////////////////////////////////////////////////////
/// Wipes off the maggots and green bits and gets cookin' anyway.
/// Roughly equivalent to clearerr.
//////////////////////////////////////////////////////////////////////////
void remove_rotten_bits(steak steak_pointer)
{
	return clearerr(steak_pointer.f);
}