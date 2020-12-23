#ifndef DIAG_MENU_H
#define DIAG_MENU_H

#include <menu.h>
#include <stdlib.h>
#include <string.h>

#define ARRAY_SIZE(a) (sizeof(a) / sizeof(a[0]))

#define MENU_WIDTH 30
#define MENU_HEIGHT 12
#define TITLE "Timing diagrams"

static const char *choices[] = {
                        "AND  gate",
                        "OR   gate",
                        "NAND gate",
                        "NOR  gate",
                        "XOR  gate",
                        "XNOR gate",
						"Quit",
						(char *) NULL,
                  };


ITEM **my_items;
MENU *my_menu;
WINDOW *my_menu_win;
static const int n_choices = ARRAY_SIZE(choices);


extern void printInMiddle(int starty, int startx);
extern void openMenu();
extern void closeMenu(); 

#endif /*DIAG_MENU_H*/
