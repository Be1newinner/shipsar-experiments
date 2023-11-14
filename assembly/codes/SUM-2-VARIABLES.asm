DATA SEGMENT
    FIRST   DW 1h  ; Sample first number
    SECOND  DW 2h  ; Sample second number
    MESSAGE DB "Result: $"
    RESULT_STR DB 6 DUP (?) ; Buffer for the result as a string
DATA ENDS

CODE SEGMENT
    ASSUME CS:CODE, DS:DATA
START:
    MOV AX, DATA    ; Initialize data segment
    MOV DS, AX      ; Register DS to point to Data Segment

    ; Load the sample numbers from memory
    MOV AX, [FIRST]
    ADD AX, [SECOND]

    ; Convert the result to a string
    MOV CX, 10      ; Number base (decimal)
    MOV DI, OFFSET RESULT_STR + 5 ; Start at the end of the buffer
    MOV BYTE PTR [DI], '$'  ; Null-terminate the string

ConvertLoop:
    XOR DX, DX
    DIV CX
    ADD DL, '0'
    DEC DI
    MOV BYTE PTR [DI], DL
    TEST AX, AX
    JNZ ConvertLoop

    ; Display the result
    MOV DX, DI       ; Set DX to the address of the result string
    MOV AH, 09h
    INT 21h

    ; Terminate the program
    MOV AH, 4Ch     ; DOS function to exit
    INT 21h         ; Call DOS

CODE ENDS

END START

