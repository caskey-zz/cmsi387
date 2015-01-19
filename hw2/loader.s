global loader
MAGIC_NUMBER equ 0x1BADB002
FL_ALIGN equ 1 << 0
FL_MEMINFO equ 1 << 1
FLAGS equ FL_ALIGN | FL_MEMINFO
CHECKSUM equ -(MAGIC_NUMBER + FLAGS)
KERNEL_STACK_SIZE equ 4096

section .text
align 4
  dd MAGIC_NUMBER
  dd FLAGS
  dd CHECKSUM

loader:
  mov eax, 0xCAFEBABE

.loop:
  mov esp, kernel_stack + KERNEL_STACK_SIZE
  jmp .loop

section .bss
align 4
kernel_stack:
  resb KERNEL_STACK_SIZE
