org 100h

section .data
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
    
    scoreNumberWriting:
        mov word [letterpos], 13181
        call draw0
        ret
    ; END INITIALISATION SCORE --------------
; END SCORE ------------------------------------------------------------

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

    draw0:
        mov di, [letterpos]
        mov si, font0
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