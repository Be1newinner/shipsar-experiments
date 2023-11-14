section .data
    hello db 'Hello, world!', 0

section .text
    mov ah, 9         ; Set the function number for 'print string' in AH register
    lea dx, hello     ; Load the address of hello into DX
    int 21h           ; Call DOS interrupt 21h to print the string

    mov ah, 4Ch       ; Set the function number for 'exit program' in AH register
    int 21h           ; Call DOS interrupt 21h to exit the program
