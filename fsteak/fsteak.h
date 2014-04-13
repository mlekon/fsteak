#ifndef F_STEAK_H
#define F_STEAK_H

struct steak;
	
/* Place a new steak on the grill (fopen) */
steak fsteak(const char* steak_name, int steak_prep);

/* Grill the given steak with a certain amount of BTUs, scraping off any excess char (fread) */
size_t grill(char* steak_char, steak steak_pointer, int btu);

/* Add an array of seasonings to the steak (fwrite) */
size_t season(char* seasonings, size_t pinches, size_t num_seasonings, steak steak_pointer);

/* Serve the current steak and place a new one on the same place of the grill */
steak swap_steak(const char* steak_name, int steak_prep, steak steak_pointer);

/* Remove the steak from the grill and serve it (fclose) */
int serve(steak steak_pointer);

/* (ftell) */
long int check_redness(steak steak_pointer);

/* Perform an arcane ritual to undo any grilling to the steak (rewind) */
void ungrill(steak steak_pointer);

/* Perform an arcane ritual to adjust how red the steak is relative to its current state (fseek) */
int adjust_redness(steak steak_pointer, long int offset, int redness);

/* (fputc) */
int pinch_of_seasoning(int seasoning, steak steak_pointer);

/* (fputs) */
int dash_of_seasoning(const char* seasonings, steak steak_pointer);

/* (fgetc) */
int flame_kiss(steak steak_pointer);

/* (fgets) */
char* flame_sear(char* steak_char, steak steak_pointer, int btu);

/* (feof) */
int is_overcooked(steak steak_pointer);

/* (ferror) */ 
int is_rotten(steak steak_pointer);

/* (clearerr) */
void remove_rotten_bits(steak steak_pointer);

#endif