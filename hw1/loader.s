global loader
MAGIC_NUMBER equ 0x1BADB002
FL_ALIGN equ 1 << 0
FL_MEMINFO equ 1 << 1
FLAGS equ FL_ALIGN | FL_MEMINFO
CHECKSUM equ -(MAGIC_NUMBER + FLAGS)

section .text
align 4
  dd MAGIC_NUMBER
  dd FLAGS
  dd CHECKSUM

loader:
  mov eax, 0xCAFEBABE

.loop:
  jmp .loop
