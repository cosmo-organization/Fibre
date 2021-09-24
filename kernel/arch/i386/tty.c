#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <string.h>

#include <kernel/tty.h>

#include "vga.h"

static const size_t VGA_WIDTH = 80;
static const size_t VGA_HEIGHT = 25;
static uint16_t *const VGA_MEMORY = (uint16_t *)0xB8000;

static size_t terminal_row;
static size_t terminal_column;
static uint8_t terminal_color;
static uint16_t *terminal_buffer;
static unsigned char asup = 0x0;
//Terminal Intialization
void terminal_initialize(uint8_t asup)
{
	terminal_row = 0;
	asup = asup;
	terminal_column = 0;
	terminal_color = vga_entry_color(VGA_COLOR_LIGHT_GREY, VGA_COLOR_BLACK);
	terminal_buffer = VGA_MEMORY;
	/*for (size_t y = 0; y < VGA_HEIGHT; y++) {
		for (size_t x = 0; x < VGA_WIDTH; x++) {
			const size_t index = y * VGA_WIDTH + x;
			terminal_buffer[index] = vga_entry(' ', terminal_color);
		}
	}*/
	for (size_t i = 0; i < VGA_HEIGHT * VGA_WIDTH; i++)
	{
		terminal_buffer[i] = vga_entry(' ', terminal_color);
	}
}

void update_coord()
{
	if (asup != 0x00)
	{
		if (terminal_column==VGA_WIDTH-1){
			terminal_column=0;
			if (terminal_row==VGA_HEIGHT-1){
				terminal_row=0;
			}else{
				terminal_row++;
			}
		}else{
			terminal_column++;
		}
	}else if(asup==0x01){
		if (terminal_column==VGA_WIDTH-1){
			terminal_column=0;
			if (terminal_row==VGA_HEIGHT-1){
				auto_scroll_up();
			}else{
				terminal_row++;
			}
		}else{
			terminal_column++;
		}
	}
}

void terminal_setcolor(uint8_t color)
{
	terminal_color = color;
}

void terminal_putentryat(unsigned char c, uint8_t color, size_t x, size_t y)
{
	const size_t index = y * VGA_WIDTH + x;
	terminal_buffer[index] = vga_entry(c, color);
}

void terminal_putentryat_whole(uint16_t buff, size_t x, size_t y)
{
	terminal_putentryat((uint8_t)(buff)&0x00FF, (uint8_t)((buff >> 8) & 0x00FF), x, y);
}

void terminal_putchar(char c)
{
	terminal_putentryat(c,terminal_color,terminal_column,terminal_row);
	update_coord();
}

void terminal_write(const char *data, size_t size)
{
	for (size_t i = 0; i < size; i++)
		terminal_putchar(data[i]);
}

void terminal_writestring(const char *data)
{
	terminal_write(data, strlen(data));
}

void terminal_putachar(unsigned char color, char c)
{
	unsigned char uc = c;
	terminal_putentryat(uc, color, terminal_column, terminal_row);
	update_coord();
}

size_t get_terminal_color()
{
	return terminal_color;
}

size_t get_terminal_x()
{
	return terminal_column;
}
size_t get_terminal_y()
{
	return terminal_row;
}
void set_terminal_pos(size_t x, size_t y)
{
	terminal_column = x;
	terminal_row = y;
	if (++x == VGA_WIDTH)
	{
		terminal_column = 0;
		if (++y == VGA_HEIGHT)
		{
			terminal_row = 0;
		}
	}
}

void auto_scroll_up()
{
	if (asup == 0x1)
	{
		if (terminal_row > 0)
		{
			uint16_t idx = 1;
			uint16_t ctr = 0;
			terminal_row--;
			for (idx = 1; idx < VGA_HEIGHT; idx++)
			{
				for (ctr = 0; ctr < VGA_WIDTH; ctr++)
				{
					terminal_putentryat(get_terminal_char_at(ctr, idx), get_terminal_color_at(ctr, idx), ctr, idx - 1);
				}
			}
		}
	}
}

uint8_t get_terminal_char_at(size_t x, size_t y)
{
	const size_t index = y * VGA_WIDTH + x;
	return (uint8_t)(VGA_MEMORY[index] & 0x00FF);
}
uint8_t get_terminal_color_at(size_t x, size_t y)
{
	const size_t index = y * VGA_WIDTH + x;
	return (uint8_t)((VGA_MEMORY[index] >> 8) & 0x00FF);
}

uint8_t entry_get_color(uint16_t buff)
{
	return (uint8_t)(buff >> 8) & 0x00FF;
}
uint8_t entry_get_char(uint16_t buff)
{
	return (uint8_t)(buff)&0x00FF;
}
