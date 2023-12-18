org 100h

%include "sprite.inc"

section .data
%define GET_LINEAR_CELL( X , Y )  ((Y*320)+X)

    started db 0

    blinkyPos dw 20635
    inkyPos dw 26704 
    pinkyPos dw 26715
    clydePos dw 26726

section .text
    mov ah, 00h     ;--------------------------------
    mov al, 13h     ; set screen 320x200 256colours
    int 10h         ;--------------------------------

    preStart:
    call clearScreen

    initGame:       ; initialise the game
        jmp Maze
        initAll:
            call initFruits
            call initLives
            call initPac
            call initBlinky
            call initInky
            call initPinky
            call initClyde
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

; INITIALISATION GHOST -------------------------------------------------
    initBlinky:
        mov si, blinky1L
        mov di, [blinkyPos]
        call drawGhosts
        ret

    initInky:
        mov si, inky1U
        mov di, [inkyPos]
        call drawGhosts
        ret

    initPinky:
        mov si, pinky1D
        mov di, [pinkyPos]
        call drawGhosts
        ret

    initClyde:
        mov si, clyde1U
        mov di, [clydePos]
        call drawGhosts
        ret

    drawGhosts:
    mov dx, 10
        eachLineGhosts:
            mov cx, 10
            rep movsb
            add di, 320-10 
            dec dx
            jnz eachLineGhosts
        ret
; END INITIALISATION GHOSTS --------------------------------------------

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