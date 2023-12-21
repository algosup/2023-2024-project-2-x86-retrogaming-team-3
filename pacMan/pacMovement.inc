section .data
%define PACMAN_SIZE 10

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

    waitframedeathanim db 4
section .text
    pacmanMovement:
        keyCheck:
            mov cx, 5000
            call waitLoop
            call waitLoop
            mov ah, 01h         ; is a key pressed ?
            int 16h
            jz wantGoDirection   ; if no, skip
            mov ah, 00h 
            int 16h         ; read the key
            cmp ah, 01h
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
        cmp al, 0x28
        je pacDead
        cmp al, 0x3C
        je pacDead
        cmp al, 0x34
        je pacDead
        cmp al, 0x42
        je pacDead
        jmp continueMoveLeft
        
    wCollRight:
        mov ax, [position]
        add ax, 1290
        call collTest
        cmp al, 0x10        
        je pacRight1
        cmp al, 0x11
        je tpLeft
        cmp al, 0x28
        je pacDead
        cmp al, 0x3C
        je pacDead
        cmp al, 0x34
        je pacDead
        cmp al, 0x42
        je pacDead
        jmp continueMoveRight
        
    wCollUp:
        mov ax, [position]
        sub ax, 315
        call collTest
        cmp al, 0x10        
        je pacUp1
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
        je actualDirection  
        mov ax, [postestcoll]
        add ax, 2880
        mov [postestcoll], ax
        call collTest 
        cmp al, 0x10            
        je actualDirection 
        mov ax, [postestcoll]
        sub ax, 960
        mov [postestcoll], ax
        call collTest 
        cmp al, 0x10            
        je actualDirection
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
        je actualDirection  
        mov ax, [postestcoll]
        add ax, 2880
        mov [postestcoll], ax
        call collTest 
        cmp al, 0x10            
        je actualDirection 
        mov ax, [postestcoll]
        sub ax, 960
        mov [postestcoll], ax
        call collTest 
        cmp al, 0x10            
        je actualDirection  
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
        je actualDirection 
        mov ax, [postestcoll]
        add ax, 9
        mov [postestcoll], ax
        call collTest 
        cmp al, 0x10            
        je actualDirection
        mov ax, [postestcoll]
        sub ax, 3
        mov [postestcoll], ax
        call collTest
        cmp al, 0x10            
        je actualDirection
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
        je actualDirection  
        mov ax, [postestcoll]
        add ax, 9
        mov [postestcoll], ax
        call collTest 
        cmp al, 0x10            
        je actualDirection 
        mov ax, [postestcoll]
        sub ax, 3
        mov [postestcoll], ax
        call collTest
        cmp al, 0x10            
        je actualDirection
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
        jmp actualDirection
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
        mov byte [goleft], 1        ; use to save wich direction he is going
        mov byte [goright], 0       ;
        mov byte [goup], 0          ;
        mov byte [godown], 0        ;
        jmp wCollLeft
    continueMoveLeft:
        call clearPac
        jmp animLeft

    moveRight:
        mov byte [goleft], 0 
        mov byte [goright], 1
        mov byte [goup], 0   
        mov byte [godown], 0       
        jmp wCollRight
    continueMoveRight:
        call clearPac
        jmp animRight
    
    moveUp:
        mov byte [goleft], 0 
        mov byte [goright], 0
        mov byte [goup], 1   
        mov byte [godown], 0         
        jmp wCollUp
    continueMoveUp:
        call clearPac
        jmp animUp

    moveDown:
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
        call resetDirection
        mov byte [nbdeathanim], 12
        mov byte [enterpressed], 0
        call clearLives
        dec byte [nblives]
        jz end
        jmp initGame

    resetDirection:
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

; PACMAN ANIMATIONS ----------------------------------------------------
    ; CHOICE ------------------------------
    animLeft:               ; choose the right sprite to make the animation
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
        jmp blinkyMovement

    pacLeft1:
        mov si, pacManWaka1L
        call drawPac
        call incFrameFromStart
        jmp blinkyMovement

    pacLeft2:
        mov si, pacManWaka2L
        call drawPac
        call incFrameFromStart
        jmp blinkyMovement

    pacRight1:
        mov si, pacManWaka1R
        call drawPac
        call incFrameFromStart
        jmp blinkyMovement

    pacRight2:
        mov si, pacManWaka2R
        call drawPac
        call incFrameFromStart
        jmp blinkyMovement

    pacUp1:
        mov si, pacManWaka1U
        call drawPac
        call incFrameFromStart
        jmp blinkyMovement

    pacUp2:
        mov si, pacManWaka2U
        call drawPac
        call incFrameFromStart
        jmp blinkyMovement

    pacDown1:
        mov si, pacManWaka1D
        call drawPac
        call incFrameFromStart
        jmp blinkyMovement

    pacDown2:
        mov si, pacManWaka2D
        call drawPac
        call incFrameFromStart
        jmp blinkyMovement
    ; END SET ANIMATIONS ------------------
    clearPac:
        mov si, clear
        call drawPac
        ret
; END PACMAN ANIMATIONS ------------------------------------------------
