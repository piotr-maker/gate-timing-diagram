#include <stdio.h>
#include "diagram.h"
#include "diag_menu.h"

int main(){
	int c;

	initscr();
	cbreak();
	keypad(stdscr, TRUE);
	noecho();

	openMenu();

	while((c = wgetch(my_menu_win)) != KEY_F(1)) {
		switch(c) {	
			case KEY_DOWN:
				menu_driver(my_menu, REQ_DOWN_ITEM);
				wrefresh(my_menu_win);
				break;
			case KEY_UP:
				menu_driver(my_menu, REQ_UP_ITEM);
				wrefresh(my_menu_win);
				break;
			case 10: // ENTER
				clear();
				switch(item_index(current_item(my_menu))) {
					case 0: drawDiagram(AND); closeMenu(); break;
					case 1: drawDiagram(OR); closeMenu(); break;
					case 2: drawDiagram(NAND); closeMenu(); break;
					case 3: drawDiagram(NOR); closeMenu(); break;
					case 4: drawDiagram(XOR); closeMenu(); break;
					case 5: drawDiagram(XNOR); closeMenu(); break;
					case 6: goto end; break;
				}
				
				clear();
				openMenu();

				break;
		}
	}	

	end:
	closeMenu();
	endwin();

	return 0;
}
