#include "diag_menu.h"

void printInMiddle(int starty, int startx){
	int length, x, y;
	float temp;

	if(my_menu_win == NULL)
		my_menu_win = stdscr;
	getyx(my_menu_win, y, x);
	if(startx != 0)
		x = startx;
	if(starty != 0)
		y = starty;

	length = strlen(TITLE);
	temp = (MENU_WIDTH - length)/ 2;
	x = startx + (int)temp;
	wattron(my_menu_win, A_BOLD);
	mvwprintw(my_menu_win, y, x, "%s", TITLE);
	wattron(my_menu_win, A_BOLD);
	refresh();
}

void openMenu() {
	// Create items
	int cols, rows;

	getmaxyx(stdscr, rows, cols);
    my_items = (ITEM **)calloc(n_choices, sizeof(ITEM *));
    for(int i = 0; i < n_choices; ++i) my_items[i] = new_item(choices[i], "\0");

	// Create menu
	my_menu = new_menu((ITEM **)my_items);

	// Create the window to be associated with the menu
    my_menu_win = newwin(MENU_HEIGHT, MENU_WIDTH, (rows - MENU_HEIGHT) / 2, (cols - MENU_WIDTH) / 2);
    keypad(my_menu_win, TRUE);
     
	// Set main window and sub window
    set_menu_win(my_menu, my_menu_win);
    set_menu_sub(my_menu, derwin(my_menu_win, 7, MENU_WIDTH - 2, 3, 1));

	/* Set menu mark to the string " * " */
    set_menu_mark(my_menu, " * ");

	/* Print a border around the main window and print a title */
   	box(my_menu_win, 0, 0);
	printInMiddle(1, 0);
	mvwaddch(my_menu_win, 2, 0, ACS_LTEE);
	mvwhline(my_menu_win, 2, 1, ACS_HLINE, MENU_WIDTH - 2);
	mvwaddch(my_menu_win, 2, MENU_WIDTH - 1, ACS_RTEE);
	mvprintw(LINES - 2, 1, "Press F1 to quit");
	refresh();
        
	/* Post the menu */
	post_menu(my_menu);
	wrefresh(my_menu_win);	
}

void closeMenu() {
	/* Unpost and free all the memory taken up */
	unpost_menu(my_menu);
	free_menu(my_menu);
	for(int i = 0; i < n_choices; i++)
		free_item(my_items[i]);
}
