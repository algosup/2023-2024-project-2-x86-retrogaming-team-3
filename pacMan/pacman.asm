org 100h

%include "sprite.inc"

section .data
%define GET_LINEAR_CELL( X , Y )  ((Y*320)+X)

    started db 0

    %define blinkyIndex 0
    %define pinkyIndex 2
    %define inkyIndex 4
    %define clydeIndex 6

section .text
    mov ah, 00h     ;--------------------------------
    mov al, 13h     ; set screen 320x200 256colours
    int 10h         ;--------------------------------

    preStart:
    call clearScreen

    initGame:       ; initialise the game
        jmp initMaze
        initAll:
            call initFruits
            call initLives
            call initPac
            mov word [frameFromStart], 0

            mov word [ghostIndex], blinkyIndex
            call initGhost

            mov word [ghostIndex], pinkyIndex
            call initGhost

            mov word [ghostIndex], inkyIndex
            call initGhost

            mov word [ghostIndex], clydeIndex
            call initGhost

            call readyDraw
            call initScore
            call initLevelNb
            jmp selectFruit
            isGameStarted:
            cmp byte [started], 1
            je keyBottomLeft
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
        ret

    end:
        int 21h

%include "maze.inc"
%include "UI.inc"
%include "pacMovement.inc"
%include "ghost.inc"
%include "ghostAI.inc"