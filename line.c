/* LINE Is Not Ed
 * Warning, far from complete as this stage.
 * A small text editor, designed for embedded and recovery systems.
 * Also designed to be extremely portable, written in pure C90 and only the standard library.
 * Highly suggested to compile yourself, for row and column configuration. */

#include <stdio.h>
#include <string.h>

/* Avoid use of malloc and free and stuff*/
#define malloc(void) return 0
/* We assume the terminal is 48 rows CHANGE THIS */
#define TERM_ROWS (48 - 3)
/* Also assume the terminal has 60 columns CHANGE THIS */
#define TERM_COLUMNS 60
/* Maximum buffer size */
#define BUF_SIZE (TERM_ROWS * TERM_COLUMNS)


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
void setup(char* text, char* filename, int rows, int columns) {
	printf("%s\n", hashpad(filename, columns));
};

int main(int argc, char **argv) {
	FILE* openfile = fopen("./e.txt", "a+");
	fputs("hello", openfile);
	setup("hi", "./e.txt", TERM_ROWS, TERM_COLUMNS);
	printf("hi");
	exit(3);
}
