/* LINE Is Not Ed
 * Warning, far from complete as this stage.
 * A small text editor, designed for embedded and recovery systems.
 * Also designed to be extremely portable, written in pure ANSI C and only with the standard library.
 * Highly suggested to compile yourself, for row and column configuration.
 */

#include <stdio.h>
#include <string.h>

 /* Avoid use of malloc and free and stuff */
#define malloc(void) return 0
#define free(void) return 0
#define realloc(void) return 0
/* We assume the terminal is 30 rows CHANGE THIS */
#define TERM_ROWS (30 - 3)
/* Also assume the terminal has 60 columns CHANGE THIS */
#define TERM_COLUMNS 60
/* Maximum buffer size */
#define BUF_SIZE (TERM_ROWS * TERM_COLUMNS)

/* Returns length of file, side effect of creating the file if it doesn't exist */
long filelen(char* filename) {
	FILE* temp = fopen(filename, "a");
	long ret = ftell(temp);
	fclose(temp);
	return ret;
}

/* Read entire file into a 2 dimensional char array, (ab)uses filelen()'s side effect */
char** readfile(char* filename) {
	char** ret;
	long len = filelen(filename);
	FILE* tfile = fopen(filename, "r");
	char chr;
	int line = 0;
	for (long i = 0; i < len; i++) {
		chr = fgetc(tfile);
		if (feof(tfile) != 0) {
			break;
		}
		else if (chr == '\n') {
			line++;
			i = 0;
		}
		else {
			ret[line][i] = chr;
			i++;
		}
	}
	return ret;
}

/* Center text, padding with octothorpes (slightly off but who cares) */
char* hashpad(char* text, int columns) {
	char ret[TERM_COLUMNS] = "";
	int columnhalf = (columns * 0.5);
	int hashnum = (columnhalf - (strlen(text) * 0.5));
	char hash[TERM_COLUMNS] = "";
	for (int r = 0; r < hashnum; r++) {
		hash[r] = '#';
	}
	strcat(ret, hash);
	strcat(ret, text);
	strcat(ret, hash);
	return ret;
}

/* Reprints the screen (best portable method I could come up with) */
void reprint(char* text, char* filename, int rows, int columns) {
	printf("%s\n", hashpad(filename, columns));
	printf(text);

};

int main(int argc, char** argv) {
	FILE* file = fopen("e.txt", "a");
	fputs("hello", file);
	printf("%d", ftell(file));
	/*reprint("hi", "./e.txt", TERM_ROWS, TERM_COLUMNS);*/
	printf("hi");
	exit(3);
}
