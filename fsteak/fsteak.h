/*
 * fsteak: A library for steak-based file I/O
 * fsteak.h: Declarations of the fsteak structures and library functions 
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

#ifndef F_STEAK_H
#define F_STEAK_H

struct steak;
	
/* Places a new steak on the grill (fopen) */
steak fsteak(const char* steak_name, int steak_prep);

/* Grills the given steak with a certain amount of BTUs, scraping off any excess char (fread) */
size_t grill(char* steak_char, steak steak_pointer, int btu);

/* Adds an array of seasonings to the steak (fwrite) */
size_t season(char* seasonings, size_t pinches, size_t num_seasonings, steak steak_pointer);

/* Serves the current steak and places a new one on the same place of the grill */
steak swap_steak(const char* steak_name, int steak_prep, steak steak_pointer);

/* Removes the steak from the grill and serves it (fclose) */
int serve(steak steak_pointer);

/* Checks exactly how red the steak is (ftell) */
long int check_redness(steak steak_pointer);

/* Performs an arcane ritual to undo any grilling done to the steak (rewind) */
void ungrill(steak steak_pointer);

/* Performs an arcane ritual to adjust how red the steak is relative to its current state (fseek) */
int adjust_redness(steak steak_pointer, long int offset, int redness);

/* Adds a small dash of seasoning (fputc) */
int pinch_of_seasoning(int seasoning, steak steak_pointer);

/* Adds dashes of seasoning until the steak is well coated (fputs) */
int dash_of_seasoning(const char* seasonings, steak steak_pointer);

/* The flame gently kisses the steak, cooking it ever so slightly (fgetc) */
int flame_kiss(steak steak_pointer);

/* Sears the steak on an open flame until it's cooked to perfection (fgets) */
char* flame_sear(char* steak_char, steak steak_pointer, int btu);

/* Checks whether the steak is done cooking (feof) */
int is_cooked(steak steak_pointer);

/* Checks whether the steak was left out a little took long and attracted a few maggots (ferror) */ 
int is_rotten(steak steak_pointer);

/* Wipes off the maggots and green bits and gets cookin' anyway (clearerr) */
void remove_rotten_bits(steak steak_pointer);

#endif