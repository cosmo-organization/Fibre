#ifndef _Include_VGA_SERVICE_H
#define _Include_VGA_SERVICE_H
#include <stdint.h>
#define VGA_WIDTH  80
#define VGA_HEIGHT 25

#define COLOR_WHITE 0x0F
#define COLOR_

struct vga_terminal_display{
	i32 terminal_width;
	i32 terminal_height;
	u16* terminal_buffer;
	u8 terminal_color;
	u16 cursor_pos_x;
	u16 cursor_pos_y;
};

void init_terminal_dispay(vga_terminal_display* pvga);
void clear_vga_display();
void restore_default_setting();
void set_terminal_color(u8 bgcolor,u8 fgcolor);
void set_cursor_pos_xy(u16 x,u16 y);
void get_cursor_pos_xy(u16* px,u16* py);

#endif
