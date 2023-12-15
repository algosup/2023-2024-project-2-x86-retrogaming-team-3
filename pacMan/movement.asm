org 100h

section .data
    pixpos dw 322

    ; pacman initialisation
    position dw 43751

    ; mouvement related
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

section .text
    pacmanMovement:
        jmp wantGoDirection
        ;jmp actualDirection
        keyCheck:
            mov ah, 01h
            int 16h
            jz gameLoop
            mov ah, 00h 
            int 16h         ; read the key
            cmp ah, 4Bh     ; left arrow key 
            je beforeLeft
            cmp ah, 4Dh     ; right arrow key 
            je beforeRight
            cmp ah, 48h     ; up arrow key    
            je beforeUp 
            cmp ah, 50h     ; down arrow key
            je beforeDown
            jmp gameLoop
            


    ; READY -------------------------
    readyDraw:
        mov di, 32852
        mov si, ready
        call drawReady
        jmp start

    readyClear:
        mov di, 32852
        mov si, clearready
        call drawReady
        jmp moveLeft

    drawReady:
        mov dx, 7
        eachlineReady:
            mov cx, 48
            rep movsb
            add di, 320-48
            dec dx
            jnz eachlineReady
        ret
    ; END READY ---------------------
; END MAZE ------------------------------------------------------------

; INITIALISATION PACMAN ------------------------------------------------
    initPac:
       mov si, pacManWaka1L
       call drawPac
       jmp readyDraw

    drawPac:
        mov di, [position]
        mov dx, 10
        eachLinePac:
            mov cx, 10
            rep movsb
            add di, 320-10 ; Move to the next line
            dec dx
            jnz eachLinePac
        ret
; END INITIALISATION PACMAN --------------------------------------------

; COLLISIONS -----------------------------------------------------------
    ; SIMPLE --------------------------
    wCollLeft:              ; collision for straight direction to stop when seing a wall
        mov dx, 1
        mov ax, [position]
        add ax, 959
        mov bx, 320         ; nb of pixels in a row
        div bx              ; division to calculate the x and y position of the pixel where we test the collision
        mov bx, ax          ; save the quotient
        mov ah, 0Dh         ; int to read the pixel color
        mov cx, dx          ; remainder goes to x position
        mov dx, bx          ; quotient goes to y position
        int 10h
        cmp al, 0x10        ; test if the color is the same as the maze
        je pacLeft1
        jmp continueMoveLeft
        
    wCollRight:
        mov dx, 1
        mov ax, [position]
        add ax, 970
        mov bx, 320         
        div bx              
        mov bx, ax          
        mov ah, 0Dh         
        mov cx, dx          
        mov dx, bx          
        int 10h
        cmp al, 0x10        
        je pacRight1
        jmp continueMoveRight
        
    wCollUp:
        mov dx, 1
        mov ax, [position]
        sub ax, 315
        mov bx, 320         
        div bx              
        mov bx, ax          
        mov ah, 0Dh         
        mov cx, dx          
        mov dx, bx          
        int 10h
        cmp al, 0x10        
        je pacUp1
        jmp continueMoveUp

    wCollDown:
        mov dx, 1
        mov ax, [position]
        add ax, 3205
        mov bx, 320         
        div bx              
        mov bx, ax          
        mov ah, 0Dh         
        mov cx, dx          
        mov dx, bx          
        int 10h
        cmp al, 0x10        
        je pacDown1
        jmp continueMoveDown
    ; END SIMPLE -----------------------
    ; COMPLEX --------------------------
    beforeLeft:             ; collision test before turning, if collision is detected, save the direction for when he can turn
        mov ax, 1
        mov bx, 0
        mov [wantgoleft], ax
        mov [wantgoright], bx
        mov [wantgoup], bx
        mov [wantgodown], bx
        mov ax, [position]
        sub ax, 1
        mov [postestcoll], ax
        mov dx, 1
        mov cx, 320             ; nb of pixels in a row
        div cx                  ; division to calculate the x and y position of the pixel where we test the collision
        mov bx, ax              ; save the quotient
        mov ah, 0Dh             ; int to read the pixel color
        mov cx, dx              ; remainder goes to x position
        mov dx, bx              ; quotient goes to y position
        int 10h 
        cmp al, 0x10            ; test if the color is the same as the maze
        je actualDirection
        mov dx, 1
        mov ax, [postestcoll]
        add ax, 2880
        mov [postestcoll], ax
        mov cx, 320             
        div cx                  
        mov bx, ax              
        mov ah, 0Dh             
        mov cx, dx              
        mov dx, bx              
        int 10h 
        cmp al, 0x10            
        je actualDirection 
        mov dx, 1
        mov ax, [postestcoll]
        sub ax, 960
        mov [postestcoll], ax
        mov cx, 320             
        div cx                  
        mov bx, ax              
        mov ah, 0Dh             
        mov cx, dx              
        mov dx, bx              
        int 10h 
        cmp al, 0x10            
        je actualDirection

        jmp moveLeft
;;
    beforeRight:
        mov ax, 1
        mov bx, 0
        mov [wantgoleft], bx
        mov [wantgoright], ax
        mov [wantgoup], bx
        mov [wantgodown], bx
        mov ax, [position]
        add ax, 10
        mov [postestcoll], ax
        mov dx, 1
        mov cx, 320             
        div cx                  
        mov bx, ax              
        mov ah, 0Dh             
        mov cx, dx              
        mov dx, bx              
        int 10h 
        cmp al, 0x10            
        je actualDirection  
        mov dx, 1
        mov ax, [postestcoll]
        add ax, 2880
        mov [postestcoll], ax
        mov cx, 320             
        div cx                  
        mov bx, ax              
        mov ah, 0Dh             
        mov cx, dx              
        mov dx, bx              
        int 10h 
        cmp al, 0x10            
        je actualDirection 
        mov dx, 1
        mov ax, [postestcoll]
        sub ax, 960
        mov [postestcoll], ax
        mov cx, 320             
        div cx                  
        mov bx, ax              
        mov ah, 0Dh             
        mov cx, dx              
        mov dx, bx              
        int 10h 
        cmp al, 0x10            
        je actualDirection  
        jmp moveRight
;;
    beforeUp:
        mov ax, 1
        mov bx, 0
        mov [wantgoleft], bx
        mov [wantgoright], bx
        mov [wantgoup], ax
        mov [wantgodown], bx
        mov ax, [position]
        sub ax, 320
        mov [postestcoll], ax
        mov dx, 1
        mov cx, 320             
        div cx                  
        mov bx, ax              
        mov ah, 0Dh             
        mov cx, dx              
        mov dx, bx              
        int 10h 
        cmp al, 0x10            
        je actualDirection 
        mov dx, 1
        mov ax, [postestcoll]
        add ax, 9
        mov [postestcoll], ax
        mov cx, 320             
        div cx                  
        mov bx, ax              
        mov ah, 0Dh             
        mov cx, dx              
        mov dx, bx              
        int 10h 
        cmp al, 0x10            
        je actualDirection
        mov dx, 1
        mov ax, [postestcoll]
        sub ax, 3
        mov [postestcoll], ax
        mov cx, 320             
        div cx                  
        mov bx, ax              
        mov ah, 0Dh             
        mov cx, dx              
        mov dx, bx              
        int 10h 
        cmp al, 0x10            
        je actualDirection
        jmp moveUp
;
    beforeDown:
        mov ax, 1
        mov bx, 0
        mov [wantgoleft], bx
        mov [wantgoright], bx
        mov [wantgoup], bx
        mov [wantgodown], ax
        mov ax, [position]
        add ax, 3200
        mov [postestcoll], ax
        mov dx, 1
        mov cx, 320             ; nb of pixels in a row
        div cx                  ; division to calculate the x and y position of the pixel where we test the collision
        mov bx, ax              ; save the quotient
        mov ah, 0Dh             ; int to read the pixel color
        mov cx, dx              ; remainder goes to x position
        mov dx, bx              ; quotient goes to y position
        int 10h 
        cmp al, 0x10            ; test if the color is the same as the maze
        je actualDirection  
        mov dx, 1
        mov ax, [postestcoll]
        add ax, 9
        mov [postestcoll], ax
        mov cx, 320             
        div cx                  
        mov bx, ax              
        mov ah, 0Dh             
        mov cx, dx              
        mov dx, bx              
        int 10h 
        cmp al, 0x10            
        je actualDirection 
        mov dx, 1
        mov ax, [postestcoll]
        sub ax, 3
        mov [postestcoll], ax
        mov cx, 320             
        div cx                  
        mov bx, ax              
        mov ah, 0Dh             
        mov cx, dx              
        mov dx, bx              
        int 10h 
        cmp al, 0x10            
        je actualDirection
        jmp moveDown

    ;END COMPLEX -----------------------
; END COLLISIONS -------------------------------------------------------

; ANIMATIONS -----------------------------------------------------------
    ; CHOICE ------------------------------
    animLeft:               ; choose the right sprite to make the animation
        sub word [position], 1
        mov al, [frame]
        inc al
        mov [frame], al
        cmp al, 4
        jl pacLeft1
        cmp al, 8
        jl pacLeft2
        mov al, 1
        mov [frame], al
        jmp pacLeft1

    animRight:
        add word [position], 1
        mov al, [frame]
        inc al
        mov [frame], al
        cmp al, 4
        jl pacRight1
        cmp al, 8
        jl pacRight2
        mov al, 1
        mov [frame], al
        jmp pacRight1

    animUp:
        sub word [position], 320
        mov al, [frame]
        inc al
        mov [frame], al
        cmp al, 4
        jl pacUp1
        cmp al, 8
        jl pacUp2
        mov al, 1
        mov [frame], al
        jmp pacUp1

    animDown:
        add word [position], 320
        mov al, [frame]
        inc al
        mov [frame], al
        cmp al, 4
        jl pacDown1
        cmp al, 8
        jl pacDown2
        mov al, 1
        mov [frame], al
        jmp pacDown1
    ; END CHOICE --------------------------
    ; SET ANIMATIONS ----------------------
    pacLeft1:
        mov si, pacManWaka1L
        call drawPac
        jmp keyCheck

    pacLeft2:
        mov si, pacManWaka2L
        call drawPac
        jmp keyCheck

    pacRight1:
        mov si, pacManWaka1R
        call drawPac
        jmp keyCheck

    pacRight2:
        mov si, pacManWaka2R
        call drawPac
        jmp keyCheck

    pacUp1:
        mov si, pacManWaka1U
        call drawPac
        jmp keyCheck

    pacUp2:
        mov si, pacManWaka2U
        call drawPac
        jmp keyCheck

    pacDown1:
        mov si, pacManWaka1D
        call drawPac
        jmp keyCheck

    pacDown2:
        mov si, pacManWaka2D
        call drawPac
        jmp keyCheck
    ; END SET ANIMATIONS ------------------
; END ANIMATIONS -------------------------------------------------------

; PACMAN MOVEMENTS -----------------------------------------------------
    ; ACTUAL DIRECTION --------------------
    actualDirection:        ; test wich direction he is going
        mov ax, [goleft]
        cmp ax, 1
        je moveLeft
        mov ax, [goright]
        cmp ax, 1
        je moveRight
        mov ax, [goup]
        cmp ax, 1
        je moveUp
        mov ax, [godown]
        cmp ax, 1
        je moveDown
    ; END ACTUAL DIRECTION ----------------
    ; ACTUAL MOVEMENT ---------------------
    moveLeft:
        mov ax, 1
        mov dx, 0               
        mov [goleft], ax        ; use to save wich direction he is going
        mov [goright], dx       ;
        mov [goup], dx          ;
        mov [godown], dx        ;
        jmp wCollLeft
    continueMoveLeft:
        call clearPac
        jmp animLeft

    moveRight:
        mov ax, 1
        mov dx, 0               
        mov [goleft], dx        ; use to save wich direction he is going
        mov [goright], ax       ;
        mov [goup], dx          ;
        mov [godown], dx        ;
        jmp wCollRight
    continueMoveRight:
        call clearPac
        jmp animRight
    
    moveUp:
        mov ax, 1
        mov dx, 0               
        mov [goleft], dx        ; use to save wich direction he is going
        mov [goright], dx       ;
        mov [goup], ax          ;
        mov [godown], dx        ;
        jmp wCollUp
    continueMoveUp:
        call clearPac
        jmp animUp

    moveDown:
        mov ax, 1
        mov dx, 0               
        mov [goleft], dx        ; use to save wich direction he is going
        mov [goright], dx       ;
        mov [goup], dx          ;
        mov [godown], ax        ;
        jmp wCollDown
    continueMoveDown:
        call clearPac
        jmp animDown
    ; END ACTUAL MOVEMENT ----------------
    ;  CHECK WANTED MOVEMENT -------------
    wantGoDirection:            ; test wich direction he wants to go
        mov cx, [wantgoleft]
        cmp cx, 1
        je beforeLeft
        mov cx, [wantgoright]
        cmp cx, 1
        je beforeRight
        mov cx, [wantgoup]
        cmp cx, 1
        je beforeUp
        mov cx, [wantgodown]
        cmp cx, 1
        je beforeDown
        jmp actualDirection
    ; END CHECK WANTED MOVEMENT ----------
    clearPac:
        mov si, clear
        call drawPac
        ret
; END PACMAN MOVEMENTS -----------------------------------------------
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

    pixLeft:
        call drawPixel
        jmp pacLeft1

    pixRight:
        call drawPixel
        jmp pacRight1

    pixUp:
        call drawPixel
        jmp pacUp1

    pixDown:
        call drawPixel
        jmp pacDown1

    drawPixel:
        mov ax, [pixpos]
        mov di, ax
        mov si, pix
        mov dx, 1
        mov cx, 1
        rep movsb
        add ax, 2
        mov [pixpos], ax
        ret
            
    end:
        int 21h