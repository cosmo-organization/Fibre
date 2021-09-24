#ifndef _KERNEL_TTY_H
#define _KERNEL_TTY_H

#include <stddef.h>
#include <stdint.h>

void terminal_initialize(unsigned char asup);
void terminal_putchar(char c);
void terminal_putachar(unsigned char color,char c);
void terminal_write(const char* data, size_t size);
void terminal_writestring(const char* data);
void terminal_setcolor(uint8_t color);
uint8_t get_terminal_char_at(size_t x,size_t y);
uint8_t get_terminal_color_at(size_t x,size_t y);
const char* get_line_at(size_t y);
size_t get_terminal_color();
size_t get_terminal_x();
size_t get_terminal_y();
void set_terminal_pos(size_t x,size_t y);
void auto_scroll_up();
uint8_t entry_get_color(uint16_t buff);
uint8_t entry_get_char(uint16_t buff);
void new_line();
#endif
