org 100h

%include "sprite.inc"

section .data
    enterpressed db 0
    letterpos dw 0
    scorenb1 dw 0
    scorenb2 dw 0
    scorenb3 dw 0

    blinkyPos dw 20635
    inkyPos dw 26704
    pinkyPos dw 26715
    clydePos dw 26726

section .text
    mov ah, 00h     ;--------------------------------
    mov al, 13h     ; set screen 320x200 256colours
    int 10h         ;--------------------------------

    initGame:       ; initialise the game
        call clearScreen
        jmp Maze
        initAll:
            call initScore
            call initFruits
            call initPac
            call initBlinky
            call initInky
            call initPinky
            call initClyde
            call readyDraw
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

; SCORE ----------------------------------------------------------------
    ; INITIALISATION SCORE -------------
    initScore:
        call drawScoreTitleBox
        call drawScoreNumberBox
        call scoreTitleWriting
        ret

    drawScoreTitleBox:
        mov di, 8350
        mov si, scoreTitleBox
        mov dx, 10
        eachLineScoreTitleBox:
            mov cx, 39
            rep movsb
            add di, 320-39
            dec dx
            jnz eachLineScoreTitleBox
        ret

    drawScoreNumberBox:
        mov di, 12497
        mov si, scoreNumberBox
        mov dx, 10
        eachLineScoreNumberBox:
            mov cx, 52
            rep movsb
            add di, 320-52
            dec dx
            jnz eachLineScoreNumberBox
        ret

    scoreTitleWriting:
        mov word [letterpos], 8993
        call drawS 
        add word [letterpos], 6
        call drawC 
        add word [letterpos], 6
        call drawO 
        add word [letterpos], 6
        call drawR 
        add word [letterpos], 6
        call drawE 
        add word [letterpos], 5
        call drawDblDot
        ret
    ; END INITIALISATION SCORE --------------
; END SCORE ------------------------------------------------------------

; FRUITS ---------------------------------------------------------------
    ; INITIALISATION SCORE ------------------
    initFruits:
        call drawFruitTitleBox
        call drawFruitsWriting
        ret

    drawFruitTitleBox:
        mov di, 8571
        mov si, fruitTitleBox
        mov dx, 10
        eachLineFruit:
            mov cx, 39
            rep movsb
            add di, 320-39
            dec dx
            jnz eachLineFruit
        ret

    drawFruitsWriting:
        mov word [letterpos], 9215
        call drawF 
        add word [letterpos], 6
        call drawR 
        add word [letterpos], 6
        call drawU 
        add word [letterpos], 6
        call drawI 
        add word [letterpos], 6
        call drawT 
        add word [letterpos], 5
        call drawDblDot
        ret
    ; END INITIALISATION SCORE --------------
; END FRUITS -----------------------------------------------------------

; PAUSE ----------------------------------------------------------------
    pauseMenu:
        call drawPause
        mov byte [enterpressed], 0
        jmp keyBottomLeft

    drawPause:
        mov word [letterpos], 32786
        call drawP 
        add word [letterpos], 6
        call drawA 
        add word [letterpos], 6
        call drawU 
        add word [letterpos], 6
        call drawS 
        add word [letterpos], 6
        call drawE 
        ret
; END PAUSE ------------------------------------------------------------

; EXTRA UI -------------------------------------------------------------
    extraUI:
        call drawTopLeft
        call drawTopRight
        call drawBottomLeft
        jmp drawBottomRight
    
    drawTopLeft:
        mov di, 968
        mov si, topleft
        mov dx, 14
        eachLineTopLeft:
            mov cx, 62
            rep movsb
            add di, 320-62
            dec dx
            jnz eachLineTopLeft
        ret

    drawTopRight:
        mov di, 1211
        mov si, topright
        mov dx, 14
        eachLineTopRight:
            mov cx, 62
            rep movsb
            add di, 320-62
            dec dx
            jnz eachLineTopRight
        ret

    drawBottomLeft:
        mov word [letterpos], 54439
        call drawP 
        add word [letterpos], 6
        call drawR 
        add word [letterpos], 6
        call drawE 
        add word [letterpos], 6
        call drawS 
        add word [letterpos], 6
        call drawS 
        mov di, 57000
        mov si, bottomleft
        mov dx, 5
        eachLineBottomLeft:
            mov cx, 26
            rep movsb
            add di, 320-26
            dec dx
            jnz eachLineBottomLeft
        ret

        drawBottomRight:
        mov word [letterpos], 54650
        call drawP 
        add word [letterpos], 6
        call drawR 
        add word [letterpos], 6
        call drawE 
        add word [letterpos], 6
        call drawS 
        add word [letterpos], 6
        call drawS 
        keyBottomLeft:
        cmp byte [enterpressed], 1
        je drawEscKey
        cmp byte [enterpressed], 0
        je drawEnterKey

        drawEscKey:
            mov word [letterpos], 57210
            call drawE 
            add word [letterpos], 6
            call drawS 
            add word [letterpos], 6
            call drawC 
            add word [letterpos], 6
            call drawClearLetter 
            add word [letterpos], 6
            call drawClearLetter
            jmp moveLeft

        drawEnterKey:
            mov word [letterpos], 57210
            call drawE 
            add word [letterpos], 6
            call drawN 
            add word [letterpos], 6
            call drawT 
            add word [letterpos], 6
            call drawE 
            add word [letterpos], 6
            call drawR 
            jmp start
; DRAW LETTERS ---------------------------------------------------------
    drawClearLetter:
        mov di, [letterpos]
        mov si, clearletter
        call drawLetter
        ret

    drawA:
        mov di, [letterpos]
        mov si, fontA
        call drawLetter
        ret

    drawC:
        mov di, [letterpos]
        mov si, fontC
        call drawLetter
        ret

    drawE:
        mov di, [letterpos]
        mov si, fontE
        call drawLetter
        ret

    drawF:
        mov di, [letterpos]
        mov si, fontF
        call drawLetter
        ret

    drawI:
        mov di, [letterpos]
        mov si, fontI
        call drawLetter
        ret

    drawN:
        mov di, [letterpos]
        mov si, fontN
        call drawLetter
        ret

    drawO:
        mov di, [letterpos]
        mov si, fontO
        call drawLetter
        ret

    drawP:
        mov di, [letterpos]
        mov si, fontP
        call drawLetter
        ret

    drawR:
        mov di, [letterpos]
        mov si, fontR
        call drawLetter
        ret

    drawS:
        mov di, [letterpos]
        mov si, fontS
        call drawLetter
        ret

    drawT:
        mov di, [letterpos]
        mov si, fontT
        call drawLetter
        ret
        
    drawU:
        mov di, [letterpos]
        mov si, fontU
        call drawLetter
        ret 

    drawDblDot:
        mov di, [letterpos]
        mov si, fontDblDot
        call drawLetter
        ret


    drawLetter:
    mov dx, 5
    eachLineLetter:
        mov cx, 5
        rep movsb
        add di, 320-5
        dec dx
        jnz eachLineLetter
    ret
; END DRAW LETTERS -------------------------------------------------------
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
%include "pacMovement.inc"