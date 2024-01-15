section .data
%define PACMAN_SIZE 10

    nbgumeated dw 0

    xPos dw 0
    yPos dw 0
    xTilePos dw 0
    yTilePos dw 0
    gumtilepos dw 0
    gumpos dw 0

    gotlife db 0

    initposition dw 43675
    position dw 0

    frame db 1

    wantgoleft db 0
    wantgoright db 0
    wantgoup db 0
    wantgodown db 0

    goleft db 0
    goright db 0
    goup db 0
    godown db 0

    postestcoll dw 0

    pacmandeath dw death0
                dw death1
                dw death2
                dw death3
                dw death4
                dw death5
                dw death6
                dw death7
                dw death8
                dw death9
                dw death10
                dw clear
    
    nbdeathanim db 12

    delayforwaitloop dw 1

    waitframedeathanim db 4

section .text
    pacmanMovement:
        keyCheck:
            mov cx, [delayforwaitloop]
            call waitLoop
            mov ah, 01h         ; is a key pressed ?
            int 16h
            jz wantGoDirection   ; if no, skip
            mov ah, 00h 
            int 16h         ; read the key
            cmp ah, 01h     ; Escape key
            je pauseMenu
            cmp ah, 4Bh     ; left arrow key 
            je beforeLeft
            cmp ah, 4Dh     ; right arrow key 
            je beforeRight
            cmp ah, 48h     ; up arrow key    
            je beforeUp 
            cmp ah, 50h     ; down arrow key
            je beforeDown
            jmp wantGoDirection
            
; INITIALISATION PACMAN ------------------------------------------------
    initPac:
        mov ax, [initposition]
        mov word [position], ax
        mov si, pacManWaka1L
        call drawPac
        ret

    drawPac:
        mov di, [position]
        mov dx, PACMAN_SIZE
        eachLinePac:
            mov cx, PACMAN_SIZE
            rep movsb
            add di, 320-PACMAN_SIZE 
            dec dx
            jnz eachLinePac
        ret
; END INITIALISATION PACMAN --------------------------------------------

; COLLISIONS -----------------------------------------------------------
    ; SIMPLE --------------------------
    wCollLeft:                  ; collision for straight direction to stop when seing a wall 
        mov ax, [position]  
        add ax, 1279 
        call collTest 
        cmp al, 0x10            ; test if the color is the same as the maze
        je pacLeft1
        cmp al, 0x11
        je tpRight
        cmp al, 0x57
        je verifyEatGumLeft
        cmp al, 0x28
        je pacDead
        cmp al, 0x3C
        je pacDead
        cmp al, 0x34
        je pacDead
        cmp al, 0x42
        je pacDead
        cmp al, 0xFF
        je fruitEated
        jmp continueMoveLeft
        
    wCollRight:
        mov ax, [position]
        add ax, 1290
        call collTest
        cmp al, 0x10        
        je pacRight1
        cmp al, 0x11
        je tpLeft
        cmp al, 0x57
        je verifyEatGumRight
        cmp al, 0x28
        je pacDead
        cmp al, 0x3C
        je pacDead
        cmp al, 0x34
        je pacDead
        cmp al, 0x42
        je pacDead
        cmp al, 0xFF
        je fruitEated
        jmp continueMoveRight
        
    wCollUp:
        mov ax, [position]
        sub ax, 315
        call collTest
        cmp al, 0x10        
        je pacUp1
        cmp al, 0x57
        je verifyEatGumUp
        cmp al, 0x28
        je pacDead
        cmp al, 0x3C
        je pacDead
        cmp al, 0x34
        je pacDead
        cmp al, 0x42
        je pacDead
        jmp continueMoveUp

    wCollDown:
        mov ax, [position]
        add ax, 3205
        call collTest
        cmp al, 0x10        
        je pacDown1
        cmp al, 0x57
        je verifyEatGumDown
        cmp al, 0x28
        je pacDead
        cmp al, 0x3C
        je pacDead
        cmp al, 0x34
        je pacDead
        cmp al, 0x42
        je pacDead
        jmp continueMoveDown
    ; END SIMPLE -----------------------
    ; COMPLEX --------------------------
    beforeLeft:             ; collision test before turning, if collision is detected, save the direction for when he can turn
        mov byte [wantgoleft], 1
        mov byte [wantgoright], 0
        mov byte [wantgoup], 0
        mov byte [wantgodown], 0
        mov ax, [position]
        sub ax, 1
        mov [postestcoll], ax
        call collTest     
        cmp al, 0x10                ; test if the color is the same as the maze
        je spawnFruit  
        mov ax, [postestcoll]
        add ax, 2880
        mov [postestcoll], ax
        call collTest 
        cmp al, 0x10            
        je spawnFruit 
        mov ax, [postestcoll]
        sub ax, 960
        mov [postestcoll], ax
        call collTest 
        cmp al, 0x10            
        je spawnFruit
        jmp moveLeft

    beforeRight:
        mov byte [wantgoleft], 0
        mov byte [wantgoright], 1
        mov byte [wantgoup], 0
        mov byte [wantgodown], 0
        mov ax, [position]
        add ax, 10
        mov [postestcoll], ax
        call collTest 
        cmp al, 0x10            
        je spawnFruit  
        mov ax, [postestcoll]
        add ax, 2880
        mov [postestcoll], ax
        call collTest 
        cmp al, 0x10            
        je spawnFruit 
        mov ax, [postestcoll]
        sub ax, 960
        mov [postestcoll], ax
        call collTest 
        cmp al, 0x10            
        je spawnFruit  
        jmp moveRight

    beforeUp:
        mov byte [wantgoleft], 0
        mov byte [wantgoright], 0
        mov byte [wantgoup], 1
        mov byte [wantgodown], 0
        mov ax, [position]
        sub ax, 320
        mov [postestcoll], ax
        call collTest 
        cmp al, 0x10            
        je spawnFruit 
        mov ax, [postestcoll]
        add ax, 9
        mov [postestcoll], ax
        call collTest 
        cmp al, 0x10            
        je spawnFruit
        mov ax, [postestcoll]
        sub ax, 3
        mov [postestcoll], ax
        call collTest
        cmp al, 0x10            
        je spawnFruit
        jmp moveUp

    beforeDown:
        mov byte [wantgoleft], 0
        mov byte [wantgoright], 0
        mov byte [wantgoup], 0
        mov byte [wantgodown], 1
        mov ax, [position]
        add ax, 3200
        mov [postestcoll], ax
        call collTest
        cmp al, 0x10            
        je spawnFruit  
        mov ax, [postestcoll]
        add ax, 9
        mov [postestcoll], ax
        call collTest 
        cmp al, 0x10            
        je spawnFruit 
        mov ax, [postestcoll]
        sub ax, 3
        mov [postestcoll], ax
        call collTest
        cmp al, 0x10            
        je spawnFruit
        jmp moveDown
    ; END COMPLEX -----------------------
    ; TEST PIXEL ------------------------
    collTest:
        mov dx, 1
        mov bx, 320             ; nb of pixels in a row
        div bx                  ; division to calculate the x and y position of the pixel where we test the collision
        mov bx, ax              ; save the quotient
        mov ah, 0Dh             ; int to read the pixel color
        mov cx, dx              ; remainder goes to x position
        mov dx, bx              ; quotient goes to y position
        int 10h 
        ret
    ; END TEST PIXEL ---------------------
; END COLLISIONS -------------------------------------------------------

; PACMAN MOVEMENTS -----------------------------------------------------
    ; CHECK WANTED MOVEMENT --------------
    wantGoDirection:            ; test wich direction he wants to go
        cmp byte [wantgoleft], 1
        je beforeLeft
        cmp byte [wantgoright], 1
        je beforeRight
        cmp byte [wantgoup], 1
        je beforeUp
        cmp byte [wantgodown], 1
        je beforeDown
        jmp spawnFruit
    ; END CHECK WANTED MOVEMENT ----------
    ; ACTUAL DIRECTION --------------------
    actualDirection:        ; test wich direction he is going
        cmp byte [goleft], 1
        je moveLeft
        cmp byte [goright], 1
        je moveRight
        cmp byte [goup], 1
        je moveUp
        cmp byte [godown], 1
        je moveDown
        jmp moveLeft
    ; END ACTUAL DIRECTION ----------------
    ; ACTUAL MOVEMENT ---------------------
    moveLeft:         
        mov byte [wantgoleft], 0
        mov byte [goleft], 1        ; use to save wich direction he is going
        mov byte [goright], 0       ;
        mov byte [goup], 0          ;
        mov byte [godown], 0        ;
        jmp wCollLeft
    continueMoveLeft:
        call clearPac
        jmp animLeft

    moveRight:
        mov byte [wantgoright], 0
        mov byte [goleft], 0 
        mov byte [goright], 1
        mov byte [goup], 0   
        mov byte [godown], 0       
        jmp wCollRight
    continueMoveRight:
        call clearPac
        jmp animRight
    
    moveUp:
        mov byte [wantgoup], 0
        mov byte [goleft], 0 
        mov byte [goright], 0
        mov byte [goup], 1   
        mov byte [godown], 0         
        jmp wCollUp
    continueMoveUp:
        call clearPac
        jmp animUp

    moveDown:
        mov byte [wantgodown], 0
        mov byte [goleft], 0 
        mov byte [goright], 0
        mov byte [goup], 0   
        mov byte [godown], 1        
        jmp wCollDown
    continueMoveDown:
        call clearPac
        jmp animDown

    tpRight:
        call clearPac
        mov word [position], 26473
        jmp moveLeft

    tpLeft:
        call clearPac
        mov word [position], 26317
        jmp moveRight
    ; END ACTUAL MOVEMENT ----------------
    ; PACMAN DIE -------------------------
    pacDead:
        mov dx, 50
        waitBeforeDie:
            mov cx, 50000
            call waitLoop
            dec dx
            jnz waitBeforeDie
        mov word [ghostIndex], blinkyIndex
        call resetFrame
        call clearGhost
        mov word [ghostIndex], inkyIndex
        call resetFrame
        call clearGhost
        mov word [ghostIndex], pinkyIndex
        call resetFrame
        call clearGhost
        mov word [ghostIndex], clydeIndex
        call resetFrame
        call clearGhost
        mov bx, pacmandeath
        mov ax, 2
    deathAnim:
        mov si, [bx]
        call drawPac
        waitDeathAnim:
            call waitLoop
            dec byte [waitframedeathanim]
            jnz waitDeathAnim
        mov byte [waitframedeathanim], 4
        add bx, ax
        dec byte [nbdeathanim]
        jnz deathAnim
        mov dx, 50
        waitBeforeContinue:
            call waitLoop
            dec dx
            jnz waitBeforeContinue
        call resetVariables
        call clearFruit
        mov byte [nbdeathanim], 12
        mov byte [enterpressed], 0
        call clearLives
        dec byte [nblives]
        jz gameOver
        jmp initGame

    resetVariables:
        mov word [timefruitspawned], 0
        mov byte [nbeatedghosts], 1
        mov word [ghostIndex], blinkyIndex
        call resetFrightMode
        mov word [ghostIndex], inkyIndex
        call resetFrightMode
        mov word [ghostIndex], pinkyIndex
        call resetFrightMode
        mov word [ghostIndex], clydeIndex
        call resetFrightMode
        mov word [nbgumeated], 0
        mov byte [levelisstarted], 0
        mov byte [goleft], 0 
        mov byte [goright], 0
        mov byte [goup], 0   
        mov byte [godown], 0 
        mov byte [wantgoleft], 0
        mov byte [wantgoright], 0
        mov byte [wantgoup], 0
        mov byte [wantgodown], 0
        ret
    ; END PACMAN DIE ---------------------
; END PACMAN MOVEMENTS -------------------------------------------------
    ghostsEated:
        cmp byte [nbeatedghosts], 1
        je firstGhostsEated
        cmp byte [nbeatedghosts], 2
        je secondGhostsEated
        cmp byte [nbeatedghosts], 3
        je thirdGhostsEated
        cmp byte [nbeatedghosts], 4
        je fourthGhostsEated

    firstGhostsEated:
        add byte [nbeatedghosts], 1
        call resetFrame
        call clearGhost
        call waitWhenGhostEated
        mov bx, infrightmode
        add bx, word [ghostIndex]
        mov word [bx], 0
        add word [scorenb2], 2
        cmp word [scorenb2], 10
        jge nextNb2GhostsEated
        call scoreNumberWriting
        call initGhostAfterEated
        jmp nextGhost

    secondGhostsEated:
        add byte [nbeatedghosts], 1
        call resetFrame
        call clearGhost
        mov bx, ghostInitposition
        add bx, word [ghostIndex]
        mov di, word [bx]
        call waitWhenGhostEated
        mov bx, infrightmode
        add bx, word [ghostIndex]
        mov word [bx], 0
        add word [scorenb2], 4
        cmp word [scorenb2], 10
        jge nextNb2GhostsEated
        call scoreNumberWriting
        call initGhostAfterEated
        jmp nextGhost

    thirdGhostsEated:
        add byte [nbeatedghosts], 1
        call resetFrame
        call clearGhost
        mov bx, ghostInitposition
        add bx, word [ghostIndex]
        mov di, word [bx]
        call waitWhenGhostEated
        mov bx, infrightmode
        add bx, word [ghostIndex]
        mov word [bx], 0
        add word [scorenb2], 8
        cmp word [scorenb2], 10
        jge nextNb2GhostsEated
        call scoreNumberWriting
        call initGhostAfterEated
        jmp nextGhost

    fourthGhostsEated:
        mov byte [nbeatedghosts], 1
        call resetFrame
        call clearGhost
        mov bx, ghostInitposition
        add bx, word [ghostIndex]
        mov di, word [bx]
        call waitWhenGhostEated
        mov bx, infrightmode
        add bx, word [ghostIndex]
        mov word [bx], 0
        add word [scorenb2], 6
        cmp word [scorenb2], 10
        jge nextNb2GhostsEated2
        add word [scorenb2], 1
        cmp word [scorenb2], 10
        call scoreNumberWriting
        call initGhostAfterEated
        jmp nextGhost

    nextNb2GhostsEated:
        sub word [scorenb2], 10
        add word [scorenb3], 1
        cmp word [scorenb3], 10
        jge nextNb3GhostsEated
        call scoreNumberWriting
        call initGhostAfterEated
        jmp nextGhost
    
    nextNb3GhostsEated:
        sub word [scorenb2], 10
        add word [scorenb3], 1
        cmp word [scorenb3], 10
        jge nextNb4GhostsEated
        call scoreNumberWriting
        call initGhostAfterEated
        jmp nextGhost

    nextNb4GhostsEated:
        sub word [scorenb2], 10
        add word [scorenb3], 1
        cmp word [scorenb3], 10
        jge nextNb5GhostsEated
        call scoreNumberWriting
        call initGhostAfterEated
        jmp nextGhost

    nextNb5GhostsEated:
        sub word [scorenb2], 10
        add word [scorenb3], 1
        cmp word [scorenb3], 10
        jge end
        call scoreNumberWriting
        call initGhostAfterEated
        jmp nextGhost

    nextNb2GhostsEated2:
        sub word [scorenb2], 10
        add word [scorenb3], 2
        cmp word [scorenb3], 10
        jge nextNb3GhostsEated
        call scoreNumberWriting
        call initGhostAfterEated
        jmp nextGhost

    waitWhenGhostEated:
        mov dx, 25
        .waitGhostEated:
            mov cx, 50000
            call waitLoop
            dec dx
            jnz .waitGhostEated
        ret
; EAT GUM --------------------------------------------------------------
    verifyEatGumLeft:
        mov ax, [position]  
        add ax, 1278
        mov [gumpos], ax
        call collTest 
        cmp al, 0x57
        je eatGum
        jmp continueMoveLeft

    verifyEatGumRight:
        mov ax, [position]
        add ax, 1291
        mov [gumpos], ax
        call collTest
        cmp al, 0x57
        je eatGum
        jmp continueMoveRight

    verifyEatGumUp:
        mov ax, [position]
        sub ax, 635
        mov [gumpos], ax
        call collTest
        cmp al, 0x57
        je eatGum
        jmp continueMoveUp

    verifyEatGumDown:
        mov ax, [position]
        add ax, 3525
        mov [gumpos], ax
        call collTest
        cmp al, 0x57
        je eatGum
        jmp continueMoveDown

    eatGum:
        add word [delayforwaitloop], 120
        add word [nbgumeated], 1
        call resetRegisters
        mov ax, [gumpos]
        mov bx, 320
        div bx
        mov [xPos], dx
        mov [yPos], ax
        call tilePos
        call clearTile
        mov bx, maze
        add bx, [gumtilepos]
        mov al, [bx]
        cmp al, 3
        je superGumEated
        mov bx, [gumtilepos]
        mov byte [maze+bx], 0
        add word [scorenb1], 1
        cmp word [scorenb1], 10
        je nextNb1
        call scoreNumberWriting
        jmp afterGumEated

    superGumEated:
        mov word [ghostIndex], blinkyIndex
        call setFrightMode
        mov word [ghostIndex], inkyIndex
        call setFrightMode
        mov word [ghostIndex], pinkyIndex
        call setFrightMode
        mov word [ghostIndex], clydeIndex
        call setFrightMode
        mov bx, [gumtilepos]
        mov byte [maze+bx], 0
        add word [scorenb1], 5
        cmp word [scorenb1], 10
        jge nextNb1
        call scoreNumberWriting
        jmp afterGumEated

    nextNb1:
        sub word [scorenb1], 10
        add word [scorenb2], 1
        cmp word [scorenb2], 10
        jge nextNb2
        call scoreNumberWriting
        jmp afterGumEated

    nextNb2:
        sub word [scorenb2], 10
        add word [scorenb3], 1
        cmp word [scorenb3], 10
        jge nextNb3
        call scoreNumberWriting
        jmp afterGumEated

    nextNb3:
        sub word [scorenb3], 10
        add word [scorenb4], 1
        cmp byte [gotlife], 0
        je gainlife
        cmp word [scorenb4], 10
        jge nextNb4
        call scoreNumberWriting
        jmp afterGumEated

    nextNb4:
        sub word [scorenb4], 10
        add word [scorenb5], 1
        cmp word [scorenb5], 10
        jge nextNb5
        call scoreNumberWriting
        jmp afterGumEated

    nextNb5:
        sub word [scorenb5], 10
        add word [scorenb6], 1
        cmp word [scorenb6], 10
        jge end
        call scoreNumberWriting
        jmp afterGumEated

    afterGumEated:
        cmp word [nbgumeated], 70
        je fruitIsNotEated
        cmp word [nbgumeated], 170
        je fruitIsNotEated
        jmp actualDirection

    fruitIsNotEated:
        mov byte [isfruiteated], 0
        jmp spawnFruit

    tilePos:
        xor dx, dx
        mov ax, [xPos]
        sub ax, 76
        mov bx, 6
        div bx
        mov [xTilePos], ax
        call resetRegisters
        mov ax, [yPos]
        mov bx, 6
        div bx
        mov [yTilePos], ax
        call resetRegisters
        mov ax, [yTilePos]
        mov bx, 28
        mul bx
        mov bx, [xTilePos]
        add ax, bx
        mov [gumtilepos], ax
        ret

    clearTile:
        call resetRegisters
        mov ax, [yTilePos]
        mov bx, 6
        mul bx
        mov bx, 320
        mul bx
        mov [yPos], ax
        call resetRegisters
        mov ax, [xTilePos]
        mov bx, 6
        mul bx
        add ax, 76
        mov [xPos], ax
        call resetRegisters
        mov ax, [yPos]
        mov bx, [xPos]
        add ax, bx
        xor bx, bx
        mov di, ax
        mov si, empty
        mov dx, 6
        .eachLineClearTile:
            mov cx, 6
            rep movsb
            add di, 320-6
            dec dx
            jnz .eachLineClearTile
        ret
;END EAT GUM -----------------------------------------------------------
    fruitEated:
        mov word [timefruitspawned], 0
        mov byte [isfruiteated], 1
        call chooseFruit
        cmp word [selectfruit], 1
        je eatCherry
        cmp word [selectfruit], 2
        je eatStrawberry
        cmp word [selectfruit], 4
        jle eatOrange
        cmp word [selectfruit], 6
        jle eatApple
        cmp word [selectfruit], 8
        jle eatMelon
        cmp word [selectfruit], 10
        jle eatGalaxian
        cmp word [selectfruit], 12
        jle eatBell
        cmp word [selectfruit], 13
        jge eatKey

    eatCherry:
        call clearFruit
        add word [scorenb2], 1
        cmp word [scorenb2], 10
        jge nextNb2
        call scoreNumberWriting
        jmp actualDirection

    eatStrawberry:
        call clearFruit
        add word [scorenb2], 3
        cmp word [scorenb2], 10
        jge nextNb2
        call scoreNumberWriting
        jmp actualDirection

    eatOrange:
        call clearFruit
        add word [scorenb2], 5
        cmp word [scorenb2], 10
        jge nextNb2
        call scoreNumberWriting
        jmp actualDirection

    eatApple:
        call clearFruit
        add word [scorenb2], 7
        cmp word [scorenb2], 10
        jge nextNb2
        call scoreNumberWriting
        jmp actualDirection
    
    eatMelon:
        call clearFruit
        add word [scorenb3], 1
        cmp word [scorenb3], 10
        jge nextNb3
        call scoreNumberWriting
        jmp actualDirection

    eatGalaxian:
        call clearFruit
        add word [scorenb3], 2
        cmp word [scorenb3], 10
        jge nextNb3
        call scoreNumberWriting
        jmp actualDirection

    eatBell:
        call clearFruit
        add word [scorenb3], 3
        cmp word [scorenb3], 10
        jge nextNb3
        call scoreNumberWriting
        jmp actualDirection

    eatKey:
        call clearFruit
        add word [scorenb3], 5
        cmp word [scorenb3], 10
        jge nextNb3
        call scoreNumberWriting
        jmp actualDirection

    clearFruit:
        mov di, 31836
        mov si, clearfruit
        mov dx, 10
        .eachLineClearFruit:
            mov cx, 11
            rep movsb
            add di, 320-11
            dec dx
            jnz .eachLineClearFruit
        ret
; PACMAN ANIMATIONS ----------------------------------------------------
    ; CHOICE ------------------------------
    animLeft:                   ; choose the right sprite to make the animation
        sub word [position], 1 
        inc byte [frame]
        cmp byte [frame], 3
        jl pacSphere
        cmp byte [frame], 6
        jl pacLeft1
        cmp byte [frame], 9
        jl pacLeft2
        cmp byte [frame], 12
        jl pacLeft1
        mov byte [frame], 1
        jmp pacSphere

    animRight:
        add word [position], 1
        inc byte [frame]
        cmp byte [frame], 2
        jl pacSphere
        cmp byte [frame], 6
        jl pacRight1
        cmp byte [frame], 9
        jl pacRight2
        cmp byte [frame], 12
        jl pacRight1
        mov byte [frame], 1
        jmp pacSphere

    animUp:
        sub word [position], 320
        inc byte [frame]
        cmp byte [frame], 3
        jl pacSphere
        cmp byte [frame], 6
        jl pacUp1
        cmp byte [frame], 9
        jl pacUp2
        cmp byte [frame], 12
        jl pacUp1
        mov byte [frame], 1
        jmp pacSphere

    animDown:
        add word [position], 320
        inc byte [frame]
        cmp byte [frame], 3
        jl pacSphere
        cmp byte [frame], 6
        jl pacDown1
        cmp byte [frame], 9
        jl pacDown2
        cmp byte [frame], 12
        jl pacDown1
        mov byte [frame], 1
        jmp pacSphere
    ; END CHOICE --------------------------
    ; SET ANIMATIONS ----------------------
    pacSphere:
        mov si, pacManStart
        call drawPac
        call incFrameFromStart
        jmp Maze

    pacLeft1:
        mov si, pacManWaka1L
        call drawPac
        call incFrameFromStart
        jmp Maze

    pacLeft2:
        mov si, pacManWaka2L
        call drawPac
        call incFrameFromStart
        jmp Maze

    pacRight1:
        mov si, pacManWaka1R
        call drawPac
        call incFrameFromStart
        jmp Maze

    pacRight2:
        mov si, pacManWaka2R
        call drawPac
        call incFrameFromStart
        jmp Maze

    pacUp1:
        mov si, pacManWaka1U
        call drawPac
        call incFrameFromStart
        jmp Maze

    pacUp2:
        mov si, pacManWaka2U
        call drawPac
        call incFrameFromStart
        jmp Maze

    pacDown1:
        mov si, pacManWaka1D
        call drawPac
        call incFrameFromStart
        jmp Maze

    pacDown2:
        mov si, pacManWaka2D
        call drawPac
        call incFrameFromStart
        jmp Maze
    ; END SET ANIMATIONS ------------------
    clearPac:
        mov si, clear
        call drawPac
        ret
; END PACMAN ANIMATIONS ------------------------------------------------

; NEXT LEVEL -----------------------------------------------------------
    nextLevel:
        mov dx, 50
        .waitBeforeNextLevel:
            mov cx, 50000
            call waitLoop
            dec dx
            jnz .waitBeforeNextLevel
        call clearPac
        mov word [ghostIndex], blinkyIndex
        call resetFrame
        call clearGhost
        call resetFrightMode
        mov word [ghostIndex], inkyIndex
        call resetFrame
        call clearGhost
        call resetFrightMode
        mov word [ghostIndex], pinkyIndex
        call resetFrame
        call clearGhost
        call resetFrightMode
        mov word [ghostIndex], clydeIndex
        call resetFrame
        call clearGhost
        call resetFrightMode
        mov word [timefruitspawned], 0
        mov byte [isfruiteated], 1
        mov byte [nbeatedghosts], 1
        mov word [delayforwaitloop], 1
        mov byte [levelstarted], 0
        mov byte [levelisstarted], 0
        mov word [nbgumeated], 0
        mov byte [goleft], 0 
        mov byte [goright], 0
        mov byte [goup], 0   
        mov byte [godown], 0 
        mov byte [wantgoleft], 0
        mov byte [wantgoright], 0
        mov byte [wantgoup], 0
        mov byte [wantgodown], 0
        mov byte [enterpressed], 0
    nextLevelNb1:
        add word [levelnb1], 1
        cmp word [levelnb1], 10
        je nextLevelNb2
        jmp initGame
    nextLevelNb2:
        sub word [levelnb1], 10
        add word [levelnb2], 1
        cmp word [levelnb2], 10
        je nextLevelNb3
        jmp initGame
    nextLevelNb3:
        sub word [levelnb2], 10
        add word [levelnb3], 1
        cmp word [levelnb3], 10
        je end
        jmp initGame
; END NEXT LEVEL -------------------------------------------------------