org 100h

section .data
    inkyPos dw 26780

    pinkyPos dw 26791

    clydePos dw 26802

    blinkyPixPos dw 322

    blinkyPos dw 20711
    ; mouvement Blinky
        blinkyFrame db 1

        blinkyWantGoLeft db 0
        blinkyWantGoRight db 0
        blinkyWantGoUp db 0
        blinkyWantGoDown db 0

        blinkyGoLeft db 0
        blinkyGoRight db 0
        blinkyGoUp db 0
        blinkyGoDown db 0

        blinkyPosTestColl dw 0

    ghostCmpPos db 0
    pacCmpPos db 0

section .text
    initBlinky:
        mov si, blinky1L
        mov di, [blinkyPos]
        mov dx, 10
        call drawBlinky
        
        ret

    initInky:
        mov si, inky1U
        mov di, [inkyPos]
        mov dx, 10
        call drawInky

        ret

    initPinky:
        mov si, pinky1D
        mov di, [pinkyPos]
        mov dx, 10
        call drawPinky

        ret

    initClyde:
        mov si, clyde1U
        mov di, [clydePos]
        mov dx, 10
        call drawClyde

        ret

    drawBlinky:
        mov di, [blinkyPos]
        mov dx, 10
        call eachLine10
        ret

    drawInky:
        mov di, [inkyPos]
        mov dx, 10
        call eachLine10
        ret

    drawPinky:
        mov di, [pinkyPos]
        mov dx, 10
        call eachLine10
        ret

    drawClyde:
        mov di, [clydePos]
        mov dx, 10
        call eachLine10
        ret

    eachLine10:
        mov cx, 10
        rep movsb
        add di, 320-10 ; Move to the next line
        dec dx
        jnz eachLine10
        ret

    blinkyDirection:
        jmp blinkyPickDirection
        jmp blinkyWantGoDirection
            ;jmp blinkyMovement
        ;keyCheck:
        ;    mov ah, 01h
        ;    int 16h
        ;    jz pacmanMovement
        ;    mov ah, 00h 
        ;    int 16h         ; read the key
        ;    cmp ah, 4Bh     ; left arrow key 
        ;    je beforeLeft
        ;    cmp ah, 4Dh     ; right arrow key 
        ;    je beforeRight
        ;    cmp ah, 48h     ; up arrow key    
        ;    je beforeUp 
        ;    cmp ah, 50h     ; down arrow key
        ;    je beforeDown
        ;    jmp pacmanMovement

    blinkyPickDirection:
        ;mov dx, 1
        ;mov ax, position
        ;mov bx, 200
        ;div bx
        ;mov [pacCmpPos], dx
;
        ;mov dx, 1
        ;mov ax, blinkyPos
        ;mov bx, 200
        ;div bx
        ;mov [ghostCmpPos], dx
;
        ;mov bx, [ghostCmpPos]
        ;mov ax, [pacCmpPos] 
        ;cmp ax, bx
        ;jl blkBeforeLeft
        ;jmp blkBeforeRight

        ;mov cx, blinkyFrame
        ;cmp cx, 5
        ;jg blkBeforeRight
        jmp blkBeforeUp

; COLLISIONS -----------------------------------------------------------
    ; SIMPLE --------------------------
    blinkyWCollLeft:              ; collision for straight direction to stop when seing a wall
        mov dx, 1
        mov ax, [blinkyPos]
        add ax, 959
        mov bx, 320         ; nb of pixels in a row
        div bx              ; division to calculate the x and y position of the pixel where we test the collision
        mov bx, ax          ; save the quotient
        mov ah, 0Dh         ; int to read the pixel color
        mov cx, dx          ; remainder goes to x position
        mov dx, bx          ; quotient goes to y position
        int 10h
        cmp al, 0x10        ; test if the color is the same as the maze
        je blkLeft1
        jmp blkContinueMoveLeft
        
    blinkyWCollRight:
        mov dx, 1
        mov ax, [blinkyPos]
        add ax, 970
        mov bx, 320         
        div bx              
        mov bx, ax          
        mov ah, 0Dh         
        mov cx, dx          
        mov dx, bx          
        int 10h
        cmp al, 0x10        
        je blkRight1
        jmp blkContinueMoveRight
        
    blinkyWCollUp:
        mov dx, 1
        mov ax, [blinkyPos]
        sub ax, 315
        mov bx, 320         
        div bx              
        mov bx, ax          
        mov ah, 0Dh         
        mov cx, dx          
        mov dx, bx          
        int 10h
        cmp al, 0x10        
        je blkUp1
        jmp blkContinueMoveUp

    blinkyWCollDown:
        mov dx, 1
        mov ax, [blinkyPos]
        add ax, 3205
        mov bx, 320         
        div bx              
        mov bx, ax          
        mov ah, 0Dh         
        mov cx, dx          
        mov dx, bx          
        int 10h
        cmp al, 0x10        
        je blkDown1
        jmp blkContinueMoveDown
    ; END SIMPLE -----------------------
    ; COMPLEX --------------------------
    blkBeforeLeft:             ; collision test before turning, if collision is detected, save the direction for when he can turn
        mov ax, 1
        mov bx, 0
        mov [blinkyWantGoLeft], ax
        mov [blinkyWantGoRight], bx
        mov [blinkyWantGoUp], bx
        mov [blinkyWantGoDown], bx
        mov ax, [blinkyPos]
        sub ax, 1
        mov [blinkyPosTestColl], ax
        mov dx, 1
        mov cx, 320             ; nb of pixels in a row
        div cx                  ; division to calculate the x and y position of the pixel where we test the collision
        mov bx, ax              ; save the quotient
        mov ah, 0Dh             ; int to read the pixel color
        mov cx, dx              ; remainder goes to x position
        mov dx, bx              ; quotient goes to y position
        int 10h 
        cmp al, 0x10            ; test if the color is the same as the maze
        je blkActualDirection  
        mov dx, 1
        mov ax, [blinkyPosTestColl]
        add ax, 2880
        mov [blinkyPosTestColl], ax
        mov cx, 320             
        div cx                  
        mov bx, ax              
        mov ah, 0Dh             
        mov cx, dx              
        mov dx, bx              
        int 10h 
        cmp al, 0x10            
        je blkActualDirection 
        mov dx, 1
        mov ax, [blinkyPosTestColl]
        sub ax, 960
        mov [blinkyPosTestColl], ax
        mov cx, 320             
        div cx                  
        mov bx, ax              
        mov ah, 0Dh             
        mov cx, dx              
        mov dx, bx              
        int 10h 
        cmp al, 0x10            
        je blkActualDirection
        jmp blinkyMoveLeft
;;
    blkBeforeRight:
        mov ax, 1
        mov bx, 0
        mov [blinkyWantGoLeft], bx
        mov [blinkyWantGoRight], ax
        mov [blinkyWantGoUp], bx
        mov [blinkyWantGoDown], bx
        mov ax, [blinkyPos]
        add ax, 10
        mov [blinkyPosTestColl], ax
        mov dx, 1
        mov cx, 320             
        div cx                  
        mov bx, ax              
        mov ah, 0Dh             
        mov cx, dx              
        mov dx, bx              
        int 10h 
        cmp al, 0x10            
        je blkActualDirection  
        mov dx, 1
        mov ax, [blinkyPosTestColl]
        add ax, 2880
        mov [blinkyPosTestColl], ax
        mov cx, 320             
        div cx                  
        mov bx, ax              
        mov ah, 0Dh             
        mov cx, dx              
        mov dx, bx              
        int 10h 
        cmp al, 0x10            
        je blkActualDirection 
        mov dx, 1
        mov ax, [blinkyPosTestColl]
        sub ax, 960
        mov [blinkyPosTestColl], ax
        mov cx, 320             
        div cx                  
        mov bx, ax              
        mov ah, 0Dh             
        mov cx, dx              
        mov dx, bx              
        int 10h 
        cmp al, 0x10            
        je blkActualDirection  
        jmp blinkyMoveRight
;;
    blkBeforeUp:
        mov ax, 1
        mov bx, 0
        mov [blinkyWantGoLeft], bx
        mov [blinkyWantGoRight], bx
        mov [blinkyWantGoUp], ax
        mov [blinkyWantGoDown], bx
        mov ax, [blinkyPos]
        sub ax, 320
        mov [blinkyPosTestColl], ax
        mov dx, 1
        mov cx, 320             
        div cx                  
        mov bx, ax              
        mov ah, 0Dh             
        mov cx, dx              
        mov dx, bx              
        int 10h 
        cmp al, 0x10            
        je blkActualDirection 
        mov dx, 1
        mov ax, [blinkyPosTestColl]
        add ax, 9
        mov [blinkyPosTestColl], ax
        mov cx, 320             
        div cx                  
        mov bx, ax              
        mov ah, 0Dh             
        mov cx, dx              
        mov dx, bx              
        int 10h 
        cmp al, 0x10            
        je blkActualDirection
        mov dx, 1
        mov ax, [blinkyPosTestColl]
        sub ax, 3
        mov [blinkyPosTestColl], ax
        mov cx, 320             
        div cx                  
        mov bx, ax              
        mov ah, 0Dh             
        mov cx, dx              
        mov dx, bx              
        int 10h 
        cmp al, 0x10            
        je blkActualDirection
        jmp blinkyMoveUp
;
    blkBeforeDown:
        mov ax, 1
        mov bx, 0
        mov [blinkyWantGoLeft], bx
        mov [blinkyWantGoRight], bx
        mov [blinkyWantGoUp], bx
        mov [blinkyWantGoDown], ax
        mov ax, [blinkyPos]
        add ax, 3200
        mov [blinkyPosTestColl], ax
        mov dx, 1
        mov cx, 320             ; nb of pixels in a row
        div cx                  ; division to calculate the x and y position of the pixel where we test the collision
        mov bx, ax              ; save the quotient
        mov ah, 0Dh             ; int to read the pixel color
        mov cx, dx              ; remainder goes to x position
        mov dx, bx              ; quotient goes to y position
        int 10h 
        cmp al, 0x10            ; test if the color is the same as the maze
        je blkActualDirection  
        mov dx, 1
        mov ax, [blinkyPosTestColl]
        add ax, 9
        mov [blinkyPosTestColl], ax
        mov cx, 320             
        div cx                  
        mov bx, ax              
        mov ah, 0Dh             
        mov cx, dx              
        mov dx, bx              
        int 10h 
        cmp al, 0x10            
        je blkActualDirection 
        mov dx, 1
        mov ax, [blinkyPosTestColl]
        sub ax, 3
        mov [blinkyPosTestColl], ax
        mov cx, 320             
        div cx                  
        mov bx, ax              
        mov ah, 0Dh             
        mov cx, dx              
        mov dx, bx              
        int 10h 
        cmp al, 0x10            
        je blkActualDirection
        jmp blinkyMoveDown

    ;END COMPLEX -----------------------
; END COLLISIONS -------------------------------------------------------

; ANIMATIONS -----------------------------------------------------------
    ; CHOICE ------------------------------
    blkAnimLeft:               ; choose the right sprite to make the animation
        sub word [blinkyPos], 1
        mov al, [blinkyFrame]
        inc al
        mov [blinkyFrame], al
        cmp al, 4
        jl blkLeft1
        cmp al, 8
        jl blkLeft2
        mov al, 1
        mov [blinkyFrame], al
        jmp blkLeft1

    blkAnimRight:
        add word [blinkyPos], 1
        mov al, [blinkyFrame]
        inc al
        mov [blinkyFrame], al
        cmp al, 4
        jl blkRight1
        cmp al, 8
        jl blkRight2
        mov al, 1
        mov [blinkyFrame], al
        jmp blkRight1

    blkAnimUp:
        sub word [blinkyPos], 320
        mov al, [blinkyFrame]
        inc al
        mov [blinkyFrame], al
        cmp al, 4
        jl blkUp1
        cmp al, 8
        jl blkUp2
        mov al, 1
        mov [blinkyFrame], al
        jmp blkUp1

    blkAnimDown:
        add word [blinkyPos], 320
        mov al, [blinkyFrame]
        inc al
        mov [blinkyFrame], al
        cmp al, 4
        jl blkDown1
        cmp al, 8
        jl blkDown2
        mov al, 1
        mov [blinkyFrame], al
        jmp blkDown1
    ; END CHOICE --------------------------
    ; SET ANIMATIONS ----------------------
    blkLeft1:
        mov si, blinky1L
        call drawBlinky
        jmp pacmanMovement

    blkLeft2:
        mov si, blinky2L
        call drawBlinky
        jmp pacmanMovement

    blkRight1:
        mov si, blinky1R
        call drawBlinky
        jmp pacmanMovement

    blkRight2:
        mov si, blinky2R
        call drawBlinky
        jmp pacmanMovement

    blkUp1:
        mov si, blinky1U
        call drawBlinky
        jmp pacmanMovement

    blkUp2:
        mov si, blinky2U
        call drawBlinky
        jmp pacmanMovement

    blkDown1:
        mov si, blinky1D
        call drawBlinky
        jmp pacmanMovement

    blkDown2:
        mov si, blinky2D
        call drawBlinky
        jmp pacmanMovement
    ; END SET ANIMATIONS ------------------
; END ANIMATIONS -------------------------------------------------------

; PACMAN MOVEMENTS -----------------------------------------------------
    ; ACTUAL DIRECTION --------------------
    blkActualDirection:        ; test wich direction he is going
        mov ax, [blinkyGoLeft]
        cmp ax, 1
        je blinkyMoveLeft
        mov ax, [blinkyGoRight]
        cmp ax, 1
        je blinkyMoveRight
        mov ax, [blinkyGoUp]
        cmp ax, 1
        je blinkyMoveUp
        mov ax, [blinkyGoDown]
        cmp ax, 1
        je blinkyMoveDown
    ; END ACTUAL DIRECTION ----------------
    ; ACTUAL MOVEMENT ---------------------
    blinkyMoveLeft:
        mov ax, 1
        mov dx, 0               
        mov [blinkyGoLeft], ax        ; use to save wich direction he is going
        mov [blinkyGoRight], dx       ;
        mov [blinkyGoUp], dx          ;
        mov [blinkyGoDown], dx        ;
        jmp blinkyWCollLeft
    blkContinueMoveLeft:
        call clearGhost
        jmp blkAnimLeft

    blinkyMoveRight:
        mov ax, 1
        mov dx, 0               
        mov [blinkyGoLeft], dx        ; use to save wich direction he is going
        mov [blinkyGoRight], ax       ;
        mov [blinkyGoUp], dx          ;
        mov [blinkyGoDown], dx        ;
        jmp blinkyWCollRight
    blkContinueMoveRight:
        call clearGhost
        jmp blkAnimRight
    
    blinkyMoveUp:
        mov ax, 1
        mov dx, 0               
        mov [blinkyGoLeft], dx        ; use to save wich direction he is going
        mov [blinkyGoRight], dx       ;
        mov [blinkyGoUp], ax          ;
        mov [blinkyGoDown], dx        ;
        jmp blinkyWCollUp
    blkContinueMoveUp:
        call clearGhost
        jmp blkAnimUp

    blinkyMoveDown:
        mov ax, 1
        mov dx, 0               
        mov [blinkyGoLeft], dx        ; use to save wich direction he is going
        mov [blinkyGoRight], dx       ;
        mov [blinkyGoUp], dx          ;
        mov [blinkyGoDown], ax        ;
        jmp blinkyWCollDown
    blkContinueMoveDown:
        call clearGhost
        jmp blkAnimDown
    ; END ACTUAL MOVEMENT ----------------
    ;  CHECK WANTED MOVEMENT -------------
    blinkyWantGoDirection:            ; test wich direction he wants to go
        mov cx, [blinkyWantGoLeft]
        cmp cx, 1
        je blkBeforeLeft
        mov cx, [blinkyWantGoRight]
        cmp cx, 1
        je beforeRight
        mov cx, [blinkyWantGoUp]
        cmp cx, 1
        je blkBeforeUp
        mov cx, [blinkyWantGoDown]
        cmp cx, 1
        je blkBeforeDown
        jmp blkActualDirection
    ; END CHECK WANTED MOVEMENT ----------
    clearGhost:
        mov si, clear
        call drawBlinky
        ret
; END PACMAN MOVEMENTS -----------------------------------------------