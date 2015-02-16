#include "terminal.h"
#include "vga.h"
#include "string.h"

size_t terminal_row;
size_t terminal_column;
uint8_t terminal_color;
uint16_t* terminal_buffer;

/*
 *  Resets the terminal to a clean state ready for use
 */
void terminal_initialize()
{
	terminal_row = 0;
	terminal_column = 0;
	terminal_color = make_color(COLOR_GREEN, COLOR_BLACK);
	terminal_buffer = (uint16_t*) 0xB8000;
	for ( size_t y = 0; y < VGA_HEIGHT; y++ )
	{
		for ( size_t x = 0; x < VGA_WIDTH; x++ )
		{
			const size_t index = y * VGA_WIDTH + x;
			terminal_buffer[index] = make_vgaentry(' ', terminal_color);
		}
	}
}

/*
 *  Sets the foreground color in the terminal
 */
void terminal_setcolor(uint8_t color)
{
	terminal_color = color;
}

/*
 *  Writes a character at the specified location in the buffer
 */
void terminal_putentryat(char c, uint8_t color, size_t x, size_t y)
{
	const size_t index = y * VGA_WIDTH + x;
	terminal_buffer[index] = make_vgaentry(c, color);
}

/*
 *  Processes a newline character when it's sent to the terminal
 */
void terminal_handle_newline()
{
    if(++terminal_row == VGA_HEIGHT)
        terminal_row = 0;

    terminal_column = 0;
}

/*
 *  Writes a character to the terminal
 */
void terminal_putchar(char c)
{
    // Handle newline characters
    if (c == '\n') {
        terminal_handle_newline();
        return;
    }

	terminal_putentryat(c, terminal_color, terminal_column, terminal_row);
	if ( ++terminal_column == VGA_WIDTH )
	{
		terminal_column = 0;
		if ( ++terminal_row == VGA_HEIGHT )
		{
			terminal_row = 0;
		}
	}
}

/*
 *  Writes a series of characters to the terminal
 */
void terminal_writestring(const char* data)
{
	size_t datalen = strlen(data);
	for ( size_t i = 0; i < datalen; i++ )
        terminal_putchar(data[i]);
}

void terminal_scroll()
{
}
