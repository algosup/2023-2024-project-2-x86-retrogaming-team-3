org 100h

section .data
    position dw 43675

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
        keyCheck:
            mov cx, 15000
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
        mov si, pacManWaka1L
        call drawPac
        ret

    drawPac:
        mov di, [position]
        mov dx, 10
        eachLinePac:
            mov cx, 10
            rep movsb
            add di, 320-10 
            dec dx
            jnz eachLinePac
        ret
; END INITIALISATION PACMAN --------------------------------------------

; COLLISIONS -----------------------------------------------------------
    ; SIMPLE --------------------------
    wCollLeft:                  ; collision for straight direction to stop when seing a wall
        mov dx, 1   
        mov ax, [position]  
        add ax, 959 
        mov bx, 320             ; nb of pixels in a row
        div bx                  ; division to calculate the x and y position of the pixel where we test the collision
        mov bx, ax              ; save the quotient
        mov ah, 0Dh             ; int to read the pixel color
        mov cx, dx              ; remainder goes to x position
        mov dx, bx              ; quotient goes to y position
        int 10h 
        cmp al, 0x10            ; test if the color is the same as the maze
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
        mov byte [wantgoleft], 1
        mov byte [wantgoright], 0
        mov byte [wantgoup], 0
        mov byte [wantgodown], 0
        mov ax, [position]
        sub ax, 1
        mov [postestcoll], ax
        mov dx, 1
        mov cx, 320                 ; nb of pixels in a row
        div cx                      ; division to calculate the x and y position of the pixel where we test the collision
        mov bx, ax                  ; save the quotient
        mov ah, 0Dh                 ; int to read the pixel color
        mov cx, dx                  ; remainder goes to x position
        mov dx, bx                  ; quotient goes to y position
        int 10h     
        cmp al, 0x10                ; test if the color is the same as the maze
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

    beforeRight:
        mov byte [wantgoleft], 0
        mov byte [wantgoright], 1
        mov byte [wantgoup], 0
        mov byte [wantgodown], 0
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

    beforeUp:
        mov byte [wantgoleft], 0
        mov byte [wantgoright], 0
        mov byte [wantgoup], 1
        mov byte [wantgodown], 0
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

    beforeDown:
        mov byte [wantgoleft], 0
        mov byte [wantgoright], 0
        mov byte [wantgoup], 0
        mov byte [wantgodown], 1
        mov ax, [position]
        add ax, 3200
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
        jmp moveDown
    ;END COMPLEX -----------------------
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
    ; END ACTUAL MOVEMENT ----------------
; END PACMAN MOVEMENTS -------------------------------------------------

; PACMAN ANIMATIONS ----------------------------------------------------
    ; CHOICE ------------------------------
    animLeft:               ; choose the right sprite to make the animation
        sub word [position], 1
        mov al, [frame]
        inc al
        mov [frame], al
        cmp al, 3
        jl pacSphere
        cmp al, 6
        jl pacLeft1
        cmp al, 9
        jl pacLeft2
        cmp al, 12
        jl pacLeft1
        mov al, 1
        mov [frame], al
        jmp pacSphere

    animRight:
        add word [position], 1
        mov al, [frame]
        inc al
        mov [frame], al
        cmp al, 2
        jl pacSphere
        cmp al, 6
        jl pacRight1
        cmp al, 9
        jl pacRight2
        cmp al, 12
        jl pacRight1
        mov al, 1
        mov [frame], al
        jmp pacSphere

    animUp:
        sub word [position], 320
        mov al, [frame]
        inc al
        mov [frame], al
        cmp al, 3
        jl pacSphere
        cmp al, 6
        jl pacUp1
        cmp al, 9
        jl pacUp2
        cmp al, 12
        jl pacUp1
        mov al, 1
        mov [frame], al
        jmp pacSphere

    animDown:
        add word [position], 320
        mov al, [frame]
        inc al
        mov [frame], al
        cmp al, 3
        jl pacSphere
        cmp al, 6
        jl pacDown1
        cmp al, 9
        jl pacDown2
        cmp al, 12
        jl pacDown1
        mov al, 1
        mov [frame], al
        jmp pacSphere
    ; END CHOICE --------------------------
    ; SET ANIMATIONS ----------------------
    pacSphere:
        mov si, pacManStart
        call drawPac
        jmp keyCheck

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
    clearPac:
        mov si, clear
        call drawPac
        ret
; END PACMAN ANIMATIONS ------------------------------------------------