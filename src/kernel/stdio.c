#include "stdio.h"
#include "terminal.h"

void print(const char* data) {
	terminal_writestring(data);
}

void println(const char* data) {
	print(data);
	terminal_handle_newline();
}
