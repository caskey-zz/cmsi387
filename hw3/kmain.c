#include "framebuffer.h"
#include "io.h"

void kmain() {

  serial_init();

  // Set up the frame buffer structures.
  fb_init();

  // Get a nice clean screen.
  clear_screen();

  serial_write_text(SERIAL_COM1, "Booted.\n", 8);

  int i;
  // Cause lots of text to scroll around.
  for (i = 0; i < 300; ++i) {
    fb_write_text("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789", 62);
  }

  serial_write_text(SERIAL_COM1, "Shutting down.\n", 14);
  // Bail back to the loader for no particular reason.
  return;
}
