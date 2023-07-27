section .data
    hello_message db "Hello, Holberton", 0
    format db "%s", 0

section .text
    global main

extern printf, exit

main:
    ; Set up the stack frame for the printf call
    push rbp
    mov rdi, format
    mov rsi, hello_message
    xor rax, rax  ; Clear rax to indicate printf uses the vector calling convention
    call printf
    pop rbp

    ; Call the exit system call to terminate the program
    mov rdi, 0  ; Exit code 0 (success)
    call exit

    ; This part is not executed, but we need to have a label for the linker
    ret

