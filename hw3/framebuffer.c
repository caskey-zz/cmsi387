#include "io.h"
#include "framebuffer.h"

#define FB_BASE_ADDR 0x000B8000
#define FB_CHAR_PTR ((char *) FB_BASE_ADDR)
#define FB_SHORT_PTR ((unsigned short *) FB_BASE_ADDR)

struct {
  int row;
  int col;
  unsigned char fg_color;
  unsigned char bg_color;
} fb_state;

void fb_init() {
  fb_state.row = 0;
  fb_state.col = 0;
  fb_state.fg_color = FB_WHITE;
  fb_state.bg_color = FB_BLACK;
}

void fb_move_cursor(unsigned char row, unsigned char col) {
  unsigned short pos = (row * 80) + col;
  outb(FB_COMMAND_PORT, FB_CMD_CURSOR_HIGH_BYTE);
  outb(FB_DATA_PORT, ((pos >> 8) & 0x00ff));
  outb(FB_COMMAND_PORT, FB_CMD_CURSOR_LOW_BYTE);
  outb(FB_DATA_PORT, pos & 0x00ff);
}

void fb_write_cell(unsigned char row, unsigned char col, char c,
                   unsigned char fg_color, unsigned char bg_color) {
  char *cell = FB_CHAR_PTR;
  cell += (2 * 80 * row) + (2 * col);

  cell[0] = c;
  cell[1] = ((bg_color << 4) & 0xf0) | (fg_color & 0x0f);
}

void clear_screen() {
  int i;
  for (i = 0; i < (80 * 25); ++i) {
    FB_SHORT_PTR[i] = 0;
  }
  fb_state.fg_color = FB_WHITE;
  fb_state.bg_color = FB_BLACK;
  fb_move_cursor(0, 0);
}

void write_text(const char *buffer, const int length) {
  int i;
  for (i = 0; i < length; ++i) {
    fb_write_cell(fb_state.row, fb_state.col, buffer[i], fb_state.fg_color, fb_state.bg_color);
    ++fb_state.col;
    if (fb_state.col >= 80) {
      fb_state.col = 0;
      ++fb_state.row;
    }
    if (fb_state.row >= 25) {
      fb_state.row = 0;
    }
  }
  fb_move_cursor(fb_state.row, fb_state.col);
}
