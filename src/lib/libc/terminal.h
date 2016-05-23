#ifndef TERMINAL_H_INCLUDED
#define TERMINAL_H_INCLUDED

#if !defined(__cplusplus)
#include <stdbool.h> /* C doesn't have booleans by default. */
#endif
#include <stddef.h>
#include <stdint.h>

void terminal_initialize();
void terminal_setcolor(uint8_t color);
void terminal_putentryat(char c, uint8_t color, size_t x, size_t y);
void terminal_handle_newline();
void terminal_putchar(char c);
void terminal_writestring(const char* data);
void terminal_scroll();

#endif // TERMINAL_H_INCLUDED
