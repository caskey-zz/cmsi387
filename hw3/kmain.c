#include "framebuffer.h"

void kmain() {

  // Set up the frame buffer structures.
  fb_init();
  // Get a nice clean screen.
  clear_screen();

  int i;
  // Cause lots of text to scroll around.
  for (i = 0; i < 300; ++i) {
    write_text("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789", 62);
  }

  // Bail back to the loader for no particular reason.
  return;
}
