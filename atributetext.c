#include <ncurses.h>

int main()
{
	attron(A_BOLD);
	addstr("Hello, ");
	attron(A_UNDERLINE);
	addstr("wonderful");
	attroff(A_BOLD | A_UNDERLINE);
	addstr(" world!");
	addch('*' | A_BOLD | A_BLINK);
}