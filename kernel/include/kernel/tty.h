#ifndef _KERNEL_TTY_H
#define _KERNEL_TTY_H

#include <stddef.h>

void terminal_initialize(void);
void terminal_putchar(char c);
void terminal_putachar(unsigned char color,char c);
void terminal_write(const char* data, size_t size);
void terminal_writestring(const char* data);
size_t get_terminal_color();


#endif
