section .data
%define FONT_SIZE 5

    nblives db 5
    nbdrawlives db 0
    initlivespos dw 0
    livespos dw 0

    scorenb1 dw 0
    scorenb2 dw 0
    scorenb3 dw 0
    scorenb4 dw 0
    scorenb5 dw 0
    scorenb6 dw 0

    displaynumber dw font0
                  dw font1
                  dw font2
                  dw font3
                  dw font4
                  dw font5
                  dw font6
                  dw font7
                  dw font8
                  dw font9

    enterpressed db 0
    letterpos dw 0

section .text
; READY ---------------------------------------------------------------
    readyDraw:
        mov di, 32776
        mov si, ready
        call drawReady
        ret

    readyClear:
        mov byte [enterpressed], 1
        mov di, 32776
        mov si, clearready
        call drawReady
        jmp keyBottomLeft

    drawReady:
        mov dx, 7
        eachlineReady:
            mov cx, 48
            rep movsb
            add di, 320-48
            dec dx
            jnz eachlineReady
        ret
; END READY ------------------------------------------------------------

; SCORE ----------------------------------------------------------------
    ; INITIALISATION SCORE -------------
    initScore:
        call drawScoreTitleBox
        call drawScoreNumberBox
        call scoreTitleWriting
        call scoreNumberWriting
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
    ; DISPLAY SCORE -------------------------
    scoreNumberWriting:
        mov word [letterpos], 13181
        call draw0
        sub word [letterpos], 6
        mov ax, [scorenb1]
        call setNumber
        sub word [letterpos], 6
        mov ax, [scorenb2]
        call setNumber
        sub word [letterpos], 9
        mov ax, [scorenb3]
        call setNumber
        sub word [letterpos], 6
        mov ax, [scorenb4]
        call setNumber
        sub word [letterpos], 6
        mov ax, [scorenb5]
        call setNumber
        sub word [letterpos], 9
        mov ax, [scorenb6]
        call setNumber
        ret

    setNumber:
        mov bx, displaynumber
        mov cx, 2
        mul cx
        add bx, ax
        mov si, [bx]
        call drawLetter
        ret
    ; END DISPLAY SCORE ---------------------
; END SCORE ------------------------------------------------------------

; LIVES ----------------------------------------------------------------
    initLives:
        mov word [livespos], GET_LINEAR_CELL(40,70)
        mov ax, [nblives]
        dec ax
        mov [nbdrawlives], ax
        cmp byte [nbdrawlives], 0
        je return
        .eachLives:
            mov di, [livespos]
            mov si, pacManWaka1R
            mov dx, 10
            .eachLineLives:
                mov cx, 10
                rep movsb
                add di, 320-10 
                dec dx
                jnz .eachLineLives
            add word [livespos], 3840
            dec byte [nbdrawlives]
            jnz .eachLives
        return:
            ret

    clearLives:
        mov word [livespos], GET_LINEAR_CELL(40,70)
        mov bx, 5
        .eachLives:
            mov di, [livespos]
            mov si, clear
            mov dx, 10
            .eachLineLives:
                mov cx, 10
                rep movsb
                add di, 320-10 
                dec dx
                jnz .eachLineLives
            add word [livespos], 3840
            dec bx
            jnz .eachLives
        ret
; END LIVES ------------------------------------------------------------

; FRUITS ---------------------------------------------------------------
    ; INITIALISATION FRUITS ------------------
    initFruits:
        call drawFruitTitleBox
        call drawFruitsWriting
        ret

    drawFruitTitleBox:
        mov di, 8571
        mov si, fruitTitleBox
        mov dx, 10
        .eachLineFruit:
            mov cx, 39
            rep movsb
            add di, 320-39
            dec dx
            jnz .eachLineFruit
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
    ; END INITIALISATION FRUITS --------------
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

; GAME OVER ------------------------------------------------------------
    gameOver: 
        mov byte [started], 0
        mov word [letterpos], GET_LINEAR_CELL(133,102)
        call drawG 
        add word [letterpos], 6
        call drawA 
        add word [letterpos], 6
        call drawM 
        add word [letterpos], 6
        call drawE 
        add word [letterpos], 12
        call drawO 
        add word [letterpos], 6
        call drawV 
        add word [letterpos], 6
        call drawE 
        add word [letterpos], 6
        call drawR 
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
        mov byte [nblives], 5
        mov word [scorenb1], 0
        mov word [scorenb2], 0
        mov word [scorenb3], 0
        mov word [scorenb4], 0
        mov word [scorenb5], 0
        mov word [scorenb6], 0
        waitRestart:
            mov ah, 01h 
            int 16h
            jz waitRestart
            mov ah, 00h 
            int 16h
            cmp ah, 1Ch
            jne waitRestart
            jmp preStart
        ret

; END GAME OVER --------------------------------------------------------

; EXTRA UI -------------------------------------------------------------
    extraUI:
        mov byte [started], 1
        call drawTopLeft
        call drawTopRight
        call drawBottomLeft
        jmp drawBottomRight
    
    drawTopLeft:
        mov di, 968
        mov si, topleft
        mov dx, 14
        .eachLineTopLeft:
            mov cx, 62
            rep movsb
            add di, 320-62
            dec dx
            jnz .eachLineTopLeft
        ret

    drawTopRight:
        mov di, 1211
        mov si, topright
        mov dx, 14
        .eachLineTopRight:
            mov cx, 62
            rep movsb
            add di, 320-62
            dec dx
            jnz .eachLineTopRight
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
        .eachLineBottomLeft:
            mov cx, 26
            rep movsb
            add di, 320-26
            dec dx
            jnz .eachLineBottomLeft
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
            jmp actualDirection

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
        mov si, clearletter
        call drawLetter
        ret

    drawA:
        mov si, fontA
        call drawLetter
        ret

    drawC:
        mov si, fontC
        call drawLetter
        ret

    drawE:
        mov si, fontE
        call drawLetter
        ret

    drawF:
        mov si, fontF
        call drawLetter
        ret

    drawG:
        mov si, fontG
        call drawLetter
        ret

    drawI:
        mov si, fontI
        call drawLetter
        ret

    drawM:
        mov si, fontM
        call drawLetter
        ret

    drawN:
        mov si, fontN
        call drawLetter
        ret

    drawO:
        mov si, fontO
        call drawLetter
        ret

    drawP:
        mov si, fontP
        call drawLetter
        ret

    drawR:
        mov si, fontR
        call drawLetter
        ret

    drawS:
        mov si, fontS
        call drawLetter
        ret

    drawT:
        mov si, fontT
        call drawLetter
        ret
        
    drawU:
        mov si, fontU
        call drawLetter
        ret 

    drawV:
        mov si, fontV
        call drawLetter
        ret

    draw0:
        mov si, font0
        call drawLetter
        ret

    draw1:
        mov si, font1
        call drawLetter
        ret
        
    draw2:
        mov si, font2
        call drawLetter
        ret

    draw3:
        mov si, font3
        call drawLetter
        ret

    draw4:
        mov si, font4
        call drawLetter
        ret

    draw5:
        mov si, font5
        call drawLetter
        ret

    draw6:
        mov si, font6
        call drawLetter
        ret

    draw7:
        mov si, font7
        call drawLetter
        ret

    draw8:
        mov si, font8
        call drawLetter
        ret

    draw9:
        mov si, font9
        call drawLetter
        ret

    drawDblDot:
        mov si, fontDblDot
        call drawLetter
        ret


    drawLetter:
    mov di, [letterpos]
    mov dx, FONT_SIZE
    eachLineLetter:
        mov cx, FONT_SIZE
        rep movsb
        add di, 320-FONT_SIZE
        dec dx
        jnz eachLineLetter
    ret
; END DRAW LETTERS -------------------------------------------------------