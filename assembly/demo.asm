DATA SEGMENT
    FIRST DW 245H          ; DEFINE A 16-BIT VARIABLE WITH INITIAL VALUE 8H
    BUFFER DB 6 dup(?)     ; buffer to store the converted string 
    			            ; (up to 5 characters + null-terminator)
    MSG DB "VALUE: $"
DATA ENDS

CODE SEGMENT
    ASSUME CS:CODE, DS:DATA
START:
    MOV AX, DATA            ; INITIALIZE DS REGISTER
    MOV DS, AX

    MOV AX, FIRST           ; LOAD THE VALUE FROM FIRST INTO AX
    
    MOV CX, 10              ; SET CX TO 10 FOR DIVIDING BY 10
    LEA DI, BUFFER          ; LOAD THE ADDRESS OF BUFFER INTO DI (DESTINATION INDEX)
    ADD DI, 5               ; POINT DI TO THE END OF THE BUFFER
    MOV BYTE PTR [DI], '$'  ; NULL-TERMINATE THE STRING

CONVERT_LOOP:
    XOR DX, DX              ; CLEAR DX (DX WILL BE USED TO STORE THE REMAINDER)
    DIV CX                  ; DIVIDE AX BY 10, RESULT IN AX, REMAINDER IN DX
    ADD DL, '0'             ; CONVERT THE REMAINDER TO ASCII
    DEC DI                  ; MOVE DI BACKWARDS IN THE BUFFER
    MOV [DI], DL            ; STORE THE ASCII CHARACTER IN THE BUFFER
    TEST AX, AX             ; CHECK IF QUOTIENT IS ZERO
    JNZ CONVERT_LOOP        ; IF NOT, CONTINUE THE LOOP

    ; Display the result
    MOV AH, 9               ; DOS FUNCTION TO PRINT A STRING
    
    MOV DX, OFFSET MSG      ; LOAD THE OFFSET OF THE MESSAGE
    INT 21H                 ; PRINT THE MESSAGE

    MOV DX, OFFSET BUFFER   ; LOAD THE OFFSET OF THE CONVERTED STRING
    INT 21H                 ; PRINT THE MESSAGE

    ; TERMINATE PROGRAM
    MOV AH, 4CH             ; DOS FUNCTION TO EXIT
    INT 21H

CODE ENDS

END START
