#ifndef DIAGRAM_H
#define DIAGRAM_H

#include <ncurses.h>
#include <string.h>

#define TICK_WIDTH 6

enum OPERATION { AND, OR, NAND, NOR, XOR, XNOR };

extern void drawSignal(const char *label, int value, int max_col);
extern void drawDiagram(enum OPERATION op);

#endif /* DIAGRAM_H */
