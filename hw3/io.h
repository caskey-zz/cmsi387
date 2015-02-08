#ifndef INCLUDE_IO_H
#define INCLUDE_IO_H

#define SERIAL_COM1 0x3F8

// Defined in loader.s  Writes a byte to the given port number.
void outb(unsigned short port, unsigned char data);

// Defined in loader.s  Reads a byte from the given port number.
char inb(unsigned short port);

void serial_init();
void serial_write_text(unsigned short com, char *buffer, int length);

#endif // INCLUDE_IO_H
