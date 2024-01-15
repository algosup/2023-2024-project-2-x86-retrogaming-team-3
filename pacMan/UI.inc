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

    levelnb1 dw 1
    levelnb2 dw 0
    levelnb3 dw 0

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

    displayfruit dw 0
                 dw cherry
                 dw strawberry
                 dw orange
                 dw orange
                 dw apple
                 dw apple
                 dw melon
                 dw melon
                 dw galaxian
                 dw galaxian
                 dw bell
                 dw bell
    
    selectfruit dw 0

    enterpressed db 0
    letterpos dw 0

    fruitposUI dw 0
    selectfruitpos dw 0
    isfruiteated db 1
    timefruitspawned dw 0

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

    gainlife: 
        mov byte [gotlife], 1
        add byte [nblives], 1
        call initLives
        call scoreNumberWriting
        jmp afterGumEated
; END LIVES ------------------------------------------------------------

; FRUITS ---------------------------------------------------------------
    ; INITIALISATION FRUITS ------------------
    initFruits:
        call drawFruitTitleBox
        call drawFruitsWriting
        call drawFruits
        ret

    drawFruitTitleBox:
        mov di, 8571
        mov si, fruitTitleBox
        mov dx, 10
        .eachLineFruitBox:
            mov cx, 39
            rep movsb
            add di, 320-39
            dec dx
            jnz .eachLineFruitBox
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

    drawFruits:
        mov di, [selectfruitpos]
        mov si, clearselectfruitBox
        mov dx, 14
        .eachLineSelect:
            mov cx, 14
            rep movsb
            add di, 320-14
            dec dx
            jnz .eachLineSelect
        mov word [fruitposUI], 13372
        mov di, [fruitposUI]
        mov si, cherry
        call drawFruit
        add word [fruitposUI], 14
        mov di, [fruitposUI]
        mov si, strawberry
        call drawFruit
        add word [fruitposUI], 14
        mov di, [fruitposUI]
        mov si, orange
        call drawFruit
        add word [fruitposUI], 4452
        mov di, [fruitposUI]
        mov si, apple
        call drawFruit
        add word [fruitposUI], 14
        mov di, [fruitposUI]
        mov si, melon
        call drawFruit
        add word [fruitposUI], 14
        mov di, [fruitposUI]
        mov si, galaxian
        call drawFruit
        add word [fruitposUI], 4452
        mov di, [fruitposUI]
        mov si, bell
        call drawFruit
        add word [fruitposUI], 14
        mov di, [fruitposUI]
        mov si, key
        call drawFruit
        ret

    selectFruit:
        mov si, selectfruitBox
        call chooseFruit
        cmp word [selectfruit], 1
        je selectCherry
        cmp word [selectfruit], 2
        je selectStrawberry
        cmp word [selectfruit], 4
        jle selectOrange
        cmp word [selectfruit], 6
        jle selectApple
        cmp word [selectfruit], 8
        jle selectMelon
        cmp word [selectfruit], 10
        jle selectGalaxian
        cmp word [selectfruit], 12
        jle selectBell
        cmp word [selectfruit], 13
        jge selectKey

    drawFruit:
        mov dx, 9
        .eachLineFruit:
            mov cx, 11
            rep movsb
            add di, 320-11
            dec dx
            jnz .eachLineFruit
        ret

    drawSelectFruit:
        mov di, [selectfruitpos]
        mov dx, 14
        .eachLineSelectFruit:
            mov cx, 14
            .eachPixel:
                lodsb                   
                cmp al, 0     
                je .skipDraw            
                stosb                   
                jmp .nextPixel          
            .skipDraw:
                add di, 1               
                .nextPixel:
                loop .eachPixel         
            add di, 320-14      
            dec dx
            jnz .eachLineSelectFruit
        ret

        selectCherry:
            mov word [selectfruitpos], 12730
            call drawSelectFruit
            jmp isGameStarted

        selectStrawberry:
            mov word [selectfruitpos], 12744
            call drawSelectFruit
            jmp isGameStarted

        selectOrange:
            mov word [selectfruitpos], 12758
            call drawSelectFruit
            jmp isGameStarted

        selectApple:
            mov word [selectfruitpos], 17210
            call drawSelectFruit
            jmp isGameStarted

        selectMelon:
            mov word [selectfruitpos], 17224
            call drawSelectFruit
            jmp isGameStarted

        selectGalaxian:
            mov word [selectfruitpos], 17238
            call drawSelectFruit
            jmp isGameStarted

        selectBell:
            mov word [selectfruitpos], 21690
            call drawSelectFruit
            jmp isGameStarted

        selectKey:
            mov word [selectfruitpos], 21704
            call drawSelectFruit
            jmp isGameStarted

        chooseFruit:
            mov ax, [levelnb1]
            mov word [selectfruit], ax
            mov ax, [levelnb2]
            mov cx, 10
            mul cx
            add word [selectfruit], ax
            mov ax, [levelnb3]
            mov cx, 100
            mul cx
            add word [selectfruit], ax
            ret

        spawnFruit:
            cmp byte [isfruiteated], 1
            je actualDirection
            call chooseFruit
            mov ax, [selectfruit]
            cmp ax, 13
            jge drawKeyFruit
            mov bx, displayfruit
            mov cx, 2
            mul cx
            add bx, ax
            mov si, [bx]
            mov di, 32156
            call drawFruit
            add word [timefruitspawned], 1
            cmp word [timefruitspawned], 750
            je noMoreFruit
            jmp actualDirection

        drawKeyFruit:
            mov si, key
            mov di, 32156
            call drawFruit
            jmp actualDirection
    ; END INITIALISATION FRUITS --------------
        noMoreFruit:
            mov word [timefruitspawned], 0
            mov byte [isfruiteated], 1
            call clearFruit
            jmp actualDirection
; END FRUITS -----------------------------------------------------------

; LEVEL NUMBER ---------------------------------------------------------
    initLevelNb:
        call drawLevelTitleBox
        call drawLevelNumberBox
        call levelTitleWriting
        call levelNumberWriting
        ret

    drawLevelTitleBox:
        mov di, 42491
        mov si, levelTitleBox
        mov dx, 10
        eachLineLevelTitleBox:
            mov cx, 39
            rep movsb
            add di, 320-39
            dec dx
            jnz eachLineLevelTitleBox
        ret

    drawLevelNumberBox:
        mov di, 46330
        mov si, levelNbBox
        mov dx, 10
        eachLineLevelNumberBox:
            mov cx, 22
            rep movsb
            add di, 320-22
            dec dx
            jnz eachLineLevelNumberBox
        ret

    levelTitleWriting:
        mov word [letterpos], 43455
        call drawL 
        add word [letterpos], 6
        call drawE 
        add word [letterpos], 6
        call drawV 
        add word [letterpos], 6
        call drawE 
        add word [letterpos], 6
        call drawL 
        add word [letterpos], 5
        call drawDblDot
        ret

    levelNumberWriting:
        mov word [letterpos], 47305
        mov ax, [levelnb1]
        call setLevelNumber
        sub word [letterpos], 6
        mov ax, [levelnb2]
        call setLevelNumber
        sub word [letterpos], 6
        mov ax, [levelnb3]
        call setLevelNumber
        ret

    setLevelNumber:
        mov bx, displaynumber
        mov cx, 2
        mul cx
        add bx, ax
        mov si, [bx]
        call drawLetter
        ret
; END LEVEL NUMBER -----------------------------------------------------

; PAUSE ----------------------------------------------------------------
    pauseMenu:
        call clearFruit
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
        mov word [timefruitspawned], 0
        mov byte [isfruiteated], 1
        mov word [delayforwaitloop], 1
        mov word [waitframedeathanim], 1
        mov byte [levelstarted], 0
        mov byte [levelnb1], 1
        mov byte [levelnb2], 0
        mov byte [levelnb3], 0
        mov byte [gotlife], 0
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
            jmp Maze

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

    drawL:
        mov si, fontL
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