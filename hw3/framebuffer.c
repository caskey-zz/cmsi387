#include "io.h"
#include "framebuffer.h"

void fb_move_cursor(unsigned char row, unsigned char col) {
  unsigned short pos = (row * 80) + col;
  outb(FB_COMMAND_PORT, FB_CMD_CURSOR_HIGH_BYTE);
  outb(FB_DATA_PORT, ((pos >> 8) & 0x00ff));
  outb(FB_COMMAND_PORT, FB_CMD_CURSOR_LOW_BYTE);
  outb(FB_DATA_PORT, pos & 0x00ff);
}

void fb_write_cell(unsigned char row, unsigned char col, char c,
                   unsigned char fg_color, unsigned char bg_color) {
  char *fb = (char*)(0x000B8000 + (2 * 80 * row) + (2 * col));

  fb[0] = c;
  fb[1] = ((bg_color << 4) & 0xf0) | (fg_color & 0x0f);
}
