#ifndef INCLUDE_FRAMEBUFFER_H
#define INCLUDE_FRAMEBUFFER_H

#define FB_BLACK 0
#define FB_BLUE 1
#define FB_GREEN 2
#define FB_CYAN 3
#define FB_RED 4
#define FB_MAGENTA 5
#define FB_BROWN 6
#define FB_WHITE 7
#define FB_DARKGRAY 8
#define FB_BRIGHTBLUE 9
#define FB_BRIGHTGREEN 10
#define FB_BRIGHTCYAN 11
#define FB_PINK 12
#define FB_BRIGHTMAGENTA 13
#define FB_YELLOW 14
#define FB_BRIGHTWHITE 15
#define FB_COMMAND_PORT 0x3D4
#define FB_DATA_PORT 0x3D5

void fb_init();
void fb_move_cursor(unsigned char row, unsigned char col);
void fb_write_cell(unsigned char row, unsigned char col, char c,
                   unsigned char fg_color, unsigned char bg_color);

void clear_screen();
void fb_write_text(const char *buffer, const int length);

#endif // INCLUDE_FRAMEBUFFER_H
