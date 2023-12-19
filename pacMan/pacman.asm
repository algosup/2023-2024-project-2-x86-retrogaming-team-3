org 100h

%include "sprite.inc"

section .data
%define GET_LINEAR_CELL( X , Y )  ((Y*320)+X)

    started db 0

section .text
    mov ah, 00h     ;--------------------------------
    mov al, 13h     ; set screen 320x200 256colours
    int 10h         ;--------------------------------

    call clearScreen

    initGame:       ; initialise the game
        jmp Maze
        initAll:
            call initFruits
            call initLives
            call initPac

            mov ax, 0
            mov [ghostIndex], ax
            call initGhost

            mov ax, 2
            mov [ghostIndex], ax
            call initGhost

            mov ax, 4
            mov [ghostIndex], ax
            call initGhost

            mov ax, 6
            mov [ghostIndex], ax
            call initGhost

            call readyDraw
            cmp byte [started], 1
            je keyBottomLeft
            call initScore
            jmp extraUI
        start:          ; press enter to play the game
            mov ah, 01h 
            int 16h
            jz start
            mov ah, 00h 
            int 16h
            cmp ah, 1Ch
            jne start
            jmp readyClear

    gameLoop:
        jmp pacmanMovement

; CLEAR SCREEN ---------------------------------------------------------
    clearScreen:
        mov ax, 0xA000
        mov es, ax
        mov di, 0
        mov cx, 320*200
        rep stosb
        ret
; END CLEAR SCREEN -----------------------------------------------------
    waitLoop:
        loop waitLoop
        ret

    resetRegisters: 
        xor ax, ax
        xor bx, bx
        xor cx, cx
        xor dx, dx
        xor si, si
        xor di, di
        ret

    end:
        int 21h

%include "maze.inc"
%include "UI.inc"
%include "pacMovement.inc"
%include "ghost.inc"
