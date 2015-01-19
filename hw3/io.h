#ifndef INCLUDE_IO_H
#define INCLUDE_IO_H

// Defined in loader.s  Writes a byte to the given port number.
void outb(unsigned short port, unsigned char data);

#endif // INCLUDE_IO_H
