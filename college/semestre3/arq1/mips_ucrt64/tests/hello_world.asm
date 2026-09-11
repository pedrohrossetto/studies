bits 64

extern puts
extern exit

section .data
	hello_world_string db "Hello World!",0 
section .text
	global main

main:
	mov rcx, hello_world_string ;test
	call puts
	
	mov ecx, 0
	jmp exit