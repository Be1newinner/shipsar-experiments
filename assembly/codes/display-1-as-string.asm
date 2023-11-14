DATA SEGMENT
    MESSAGE DB "1$"
DATA ENDS

CODE SEGMENT
    ASSUME CS:CODE, DS:DATA
START:
    MOV AX, DATA    ; Initialize data segment
    MOV DS, AX      ; Register DS to point to Data Segment

    ; Display the result
    MOV DX, OFFSET MESSAGE
    MOV AH, 09h
    INT 21h

    ; Terminate the program
    MOV AH, 4Ch     ; DOS function to exit
    INT 21h         ; Call DOS

CODE ENDS

END START

