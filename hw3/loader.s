global loader

MAGIC_NUMBER equ 0x1BADB002
FL_ALIGN equ 1 << 0
FL_MEMINFO equ 1 << 1
FLAGS equ FL_ALIGN | FL_MEMINFO
CHECKSUM equ -(MAGIC_NUMBER + FLAGS)
KERNEL_STACK_SIZE equ 4096

extern kmain
global outb
global inb

section .text
align 4
  dd MAGIC_NUMBER
  dd FLAGS
  dd CHECKSUM

; A function which writes a byte to a port.
outb:
  mov al, [esp + 8]
  mov dx, [esp + 4]
  out dx, al
  ret

inb:
  mov dx, [esp + 4]
  in  al, dx
  ret

loader:
  mov esp, kernel_stack + KERNEL_STACK_SIZE
  ; This code will shift the cursor to the 50th character on the first line
  mov dx, 0x3D4
  mov ax, 14
  out dx, ax
  mov dx, 0x3D5
  xor ax, ax
  out dx, ax
  mov dx, 0x3D4
  mov ax, 15
  out dx, ax
  mov dx, 0x3D5
  mov ax, 0x50
  out dx, ax
  ; Phew, assembly sucks.
  push dword 3
  push dword 2
  push dword 1
  mov word [0x000B8002], 0x2841

  call kmain

  ; And here a little infinite loop
.loop:
  jmp .loop

section .bss
align 4
kernel_stack:
  resb KERNEL_STACK_SIZE
