#include "diagram.h"

void drawSignal(const char *label, int value, int max_col) {
	int index = 1;
	int bit = 0;
	int row, col;
	enum STATE { LOW, HEIGH, FALL, RAISE };
	enum STATE state;
	
	getyx(stdscr, row, col);
	col += 5;

	mvprintw(row + 1, 1, "%s", label);

	while(1) {
		bit = index / TICK_WIDTH;

		if((value >> bit) & 1) state = HEIGH;
		else state = LOW;
 
		if(!(index % TICK_WIDTH) && index != 0) {
			if(((value >> bit) & 1) == 0 && ((value >> (bit-1)) & 1) == 1) state = FALL;
			else if(((value >> bit) & 1) == 1 && ((value >> (bit-1)) & 1) == 0) state = RAISE;
		}

		switch(state) {
			case LOW: 
				mvaddch (row + 2, index + col, ACS_HLINE);
				break;
			case HEIGH: 
				mvaddch (row + 0, index + col, ACS_HLINE);
				break;
			case FALL: 
				mvaddch (row + 0, index + col, ACS_URCORNER); 
				mvaddch (row + 1, index + col, ACS_VLINE); 
				mvaddch (row + 2, index + col, ACS_LLCORNER); 
				break;
			case RAISE:  
				mvaddch (row + 0, index + col, ACS_ULCORNER); 
				mvaddch (row + 1, index + col, ACS_VLINE); 
				mvaddch (row + 2, index + col, ACS_LRCORNER); 
				break;
		}

		index += 1;
		if(index + col == max_col) break;
	}

	move(row + 4, 0);
}

void drawDiagram(enum OPERATION op) {
	int a = 0xAAAAAAAA;
	int b = 0xCCCCCCCC;
	int result;
	int rows, cols;
	char *c;
	char label[30];

	switch(op) {
		case AND: result = a & b; c = "AND"; break;
		case OR: result = a | b; c = "OR"; break;
		case NAND: result = ~(a & b); c = "NAND"; break;
		case NOR: result = ~(a | b); c = "NOR"; break;
		case XOR: result = a ^ b; c = "XOR"; break;
		case XNOR: result = ~(a ^ b); c = "XNOR"; break;
	}

	getmaxyx(stdscr, rows, cols);

	sprintf(label, "Timing diagram %s gate", c);
	attron(A_BOLD);
	mvprintw(0, (cols - strlen(label)) / 2, label);
	move(2, 0);

	drawSignal("IN1", a, cols);
	drawSignal("IN2", b, cols);
	drawSignal("OUT", result, cols);

	attroff(A_BOLD);
	move(rows - 2, 1);
	printw("Press any key to return to menu.\n");
	getch();
}
