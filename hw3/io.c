#include "io.h"

#define SERIAL_DATA_PORT(base)  (base)
#define SERIAL_FIFO_COMMAND_PORT(base)  (base+2)
#define SERIAL_LINE_COMMAND_PORT(base)  (base+3)
#define SERIAL_MODEM_COMMAND_PORT(base)  (base+4)
#define SERIAL_LINE_STATUS_PORT(base)  (base+5)

#define SERIAL_LINE_ENABLE_DLAB  0x80
#define SERIAL_8N1 0x03
#define SERIAL_FIFO_14 0xC7

void serial_configure_baud_rate(unsigned short com, unsigned short divisor) {
  outb(SERIAL_LINE_COMMAND_PORT(com), SERIAL_LINE_ENABLE_DLAB);
  outb(SERIAL_DATA_PORT(com), (divisor >>8) & 0x00FF);
  outb(SERIAL_DATA_PORT(com), divisor & 0x00FF);
}

void serial_configure_line(unsigned short com, char config) {
  outb(SERIAL_LINE_COMMAND_PORT(com), config);
}

void serial_configure_fifo(unsigned short com, char config) {
  outb(SERIAL_FIFO_COMMAND_PORT(com), config);
}

int serial_is_transmit_fifo_empty(unsigned int com) {
  return inb(SERIAL_LINE_STATUS_PORT(com)) & 0x20;
}

void serial_init() {
  serial_configure_baud_rate(SERIAL_COM1, 2);
  serial_configure_line(SERIAL_COM1, SERIAL_8N1);
  // If you don't set up the fifo, things will overrun!
  serial_configure_fifo(SERIAL_COM1, SERIAL_FIFO_14);
}

void serial_write_text(unsigned short com, char *buffer, int length) {
  while(length--) {
    // TODO(caskey) Check that the buffer is non-empty.
    outb(SERIAL_DATA_PORT(com), *buffer);
    buffer++;
  }
}
