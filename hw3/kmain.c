#include "framebuffer.h"

int sum_of_three(int arg1, int arg2, int arg3) {
  fb_move_cursor(12, 49);

  fb_write_cell(10, 10, 'C', FB_BRIGHTWHITE, FB_BLACK);
  fb_write_cell(10, 11, 'a', FB_RED, FB_BLACK);
  fb_write_cell(10, 12, 's', FB_MAGENTA, FB_BLACK);
  fb_write_cell(10, 13, 'k', FB_YELLOW, FB_BLACK);
  fb_write_cell(10, 14, 'e', FB_PINK, FB_BLACK);
  fb_write_cell(10, 15, 'y', FB_BRIGHTCYAN, FB_BLACK);

  return arg1 + arg2 + arg3;
}

void kmain() {
  fb_init();
  clear_screen();
  int i;
  for (i = 0; i < 250; ++i) {
    write_text("Hello, world! ", 14);
  }
  write_text("X X X", 5);
  return;
}
