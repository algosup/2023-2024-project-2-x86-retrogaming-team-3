org 100h

%include "sprite.asm"

section .data
    pixpos dw 322
; pacman
    ; initialisation
    position dw 43751
    ; end initialisation
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

    nbtestcoll db 4
    postestcoll dw 0
    ; end mouvement related
; end pacman

; maze
    ; maze array
    maze db 26,22,22,22,22,22,22,22,22,22,22,22,22,30,31,22,22,22,22,22,22,22,22,22,22,22,22,27
         db 25, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,13,12, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,24
         db 25, 0,14,10,10,15, 0,14,10,10,10,15, 0,13,12, 0,14,10,10,10,15, 0,14,10,10,15, 0,24
         db 25, 0,13, 0, 0,12, 0,13, 0, 0, 0,12, 0,13,12, 0,13, 0, 0, 0,12, 0,13, 0, 0,12, 0,24
         db 25, 0,17,11,11,16, 0,17,11,11,11,16, 0,17,16, 0,17,11,11,11,16, 0,17,11,11,16, 0,24
         db 25, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,24
         db 25, 0,14,10,10,15, 0,14,15, 0,14,10,10,10,10,10,10,15, 0,14,15, 0,14,10,10,15, 0,24
         db 25, 0,17,11,11,16, 0,13,12, 0,17,11,11,19,18,11,11,16, 0,13,12, 0,17,11,11,16, 0,24
         db 25, 0, 0, 0, 0, 0, 0,13,12, 0, 0, 0, 0,13,12, 0, 0, 0, 0,13,12, 0, 0, 0, 0, 0, 0,24
         db 29,23,23,23,23,15, 0,13,21,10,10,15, 0,13,12, 0,14,10,10,20,12, 0,14,23,23,23,23,28
         db  0, 0, 0, 0, 0,25, 0,13,18,11,11,16, 0,17,16, 0,17,11,11,19,12, 0,24, 0, 0, 0, 0, 0
         db  0, 0, 0, 0, 0,25, 0,13,12, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,13,12, 0,24, 0, 0, 0, 0, 0
         db  0, 0, 0, 0, 0,25, 0,13,12, 0,38,23,36, 1, 1,37,23,39, 0,13,12, 0,24, 0, 0, 0, 0, 0
         db 22,22,22,22,22,16, 0,17,16, 0,24, 0, 0, 0, 0, 0, 0,25, 0,17,16, 0,17,22,22,22,22,22
         db  0, 0, 0, 0, 0, 0, 0, 0, 0, 0,24, 0, 0, 0, 0, 0, 0,25, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
         db 23,23,23,23,23,15, 0,14,15, 0,24, 0, 0, 0, 0, 0, 0,25, 0,14,15, 0,14,23,23,23,23,23
         db  0, 0, 0, 0, 0,25, 0,13,12, 0,41,22,22,22,22,22,22,40, 0,13,12, 0,24, 0, 0, 0, 0, 0
         db  0, 0, 0, 0, 0,25, 0,13,12, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,13,12, 0,24, 0, 0, 0, 0, 0
         db  0, 0, 0, 0, 0,25, 0,13,12, 0,14,10,10,10,10,10,10,15, 0,13,12, 0,24, 0, 0, 0, 0, 0
         db 26,22,22,22,22,16, 0,17,16, 0,17,11,11,19,18,11,11,16, 0,17,16, 0,17,22,22,22,22,27
         db 25, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,13,12, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,24
         db 25, 0,14,10,10,15, 0,14,10,10,10,15, 0,13,12, 0,14,10,10,10,15, 0,14,10,10,15, 0,24
         db 25, 0,17,11,19,12, 0,17,11,11,11,16, 0,17,16, 0,17,11,11,11,16, 0,13,18,11,16, 0,24
         db 25, 0, 0, 0,13,12, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,13,12, 0, 0, 0,24
         db 33,10,15, 0,13,12, 0,14,15, 0,14,10,10,10,10,10,10,15, 0,14,15, 0,13,12, 0,14,10,34
         db 32,11,16, 0,17,16, 0,13,12, 0,17,11,11,19,18,11,11,16, 0,13,12, 0,17,16, 0,17,11,35
         db 25, 0, 0, 0, 0, 0, 0,13,12, 0, 0, 0, 0,13,12, 0, 0, 0, 0,13,12, 0, 0, 0, 0, 0, 0,24
         db 25, 0,14,10,10,10,10,20,21,10,10,15, 0,13,12, 0,14,10,10,20,21,10,10,10,10,15, 0,24
         db 25, 0,17,11,11,11,11,11,11,11,11,16, 0,17,16, 0,17,11,11,11,11,11,11,11,11,16, 0,24
         db 25, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,24
         db 29,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,28
    ; ---------------------------------------------------------------------
    Column dw 28    ; number of columns
    Row dw 31       ; number of rows
    nbpixel dw 2072 ; number of pixels in a row of tile
; end maze

section .text
    mov ah, 00h     ;--------------------------------
    mov al, 13h     ; set screen 320x200 256colours
    int 10h         ;--------------------------------

    initGame:       ; initialise the game
        call clearScreen
        call Maze
        start:
            mov ah, 01h
            int 16h
            jz start
            mov ah, 00h
            int 16h
            cmp ah, 1Ch
            jne start
            jmp readyClear

    gameLoop:

    pacmanMovement:
        jmp wantGoDirection
        ;jmp actualDirection
        keyCheck:
            mov ah, 01h
            int 16h
            jz pacmanMovement
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
            jmp pacmanMovement
            

; MAZE -------------------------------------------------------------------
    ; DRAW WALL ---------------------------
    drawWalls:     ; draw 1 tile
        mov dx, 6               ; number of row of a sprite
        eachLineMaze:   
            mov cx, 6           ; number of column of a sprite
            rep movsb           ; draw the sprite
            add di, 320-6       ; go to the next row
            dec dx              ; count the number of rows drawn
            jnz eachLineMaze    ; if the number of rows drawn is not zero, go to draw the next line
            call nextColumn     ; call the function to go to the next tile
        inc bx                  ; setup for the next sprite to choose
        ret

    nextColumn:
        mov ax, [Column]    ;------------------------------------------------------
        dec ax              ; decrement Column to count the number of drawn column
        mov [Column], ax    ;------------------------------------------------------
        cmp ax, 0           ; look if it has finished the row
        je nextRow          ; if yes, call the function for the next row of tiles
        sub di, 1914        ; go the the next column
        ret

    nextRow:
        mov ax, [Row]       ;------------------------------------------------
        dec ax              ; decrement Row to count the number of drawn row
        mov [Row], ax       ;------------------------------------------------
        cmp ax, 0           ; look if it has finished the every rows
        je initPac          ; if yes, finish
        mov ax, 28          ;  
        mov [Column], ax    ; setup the number of columns for the next row
        mov ax, [nbpixel] 
        mov di, ax          ; go to the next row of tile
        add ax, 1920        ; save the number of pixel to go to the next line
        mov [nbpixel], ax   ;
        ret
    ; END DRAW WALL ----------------------   
    ; WALL CHOICE ------------------------
    Maze:
        mov di, 152             ; set the position
        mov bx, maze            ; put the maze array to a register to follow the maze pattern
        wallchoice:
            mov al, [bx]        ; look wich sprite it has to put in a tile
            cmp al, 0           ; then it call a function to draw the correct sprite
            je DrawEmpty        ;
            cmp al, 1
            je DrawDoor
            cmp al, 10
            je DrawSmplwall1
            cmp al, 11
            je DrawSmplwall2
            cmp al, 12
            je DrawSmplwall3
            cmp al, 13
            je DrawSmplwall4
            cmp al, 14
            je DrawSmplangle11
            cmp al, 15
            je DrawSmplangle12
            cmp al, 16
            je DrawSmplangle13
            cmp al, 17
            je DrawSmplangle14
            cmp al, 18
            je DrawSmplangle21
            cmp al, 19
            je DrawSmplangle22
            cmp al, 20
            je DrawSmplangle23
            cmp al, 21
            je DrawSmplangle24
            cmp al, 22
            je DrawDblwall1
            cmp al, 23
            je DrawDblwall2
            cmp al, 24
            je DrawDblwall3
            cmp al, 25
            je DrawDblwall4
            cmp al, 26
            je DrawDblangle1
            cmp al, 27
            je DrawDblangle2
            cmp al, 28
            je DrawDblangle3
            cmp al, 29
            je DrawDblangle4
            cmp al, 30
            je DrawDblwallangle1
            cmp al, 31
            je DrawDblwallangle2
            cmp al, 32
            je DrawDblwallangle3
            cmp al, 33
            je DrawDblwallangle4
            cmp al, 34
            je DrawDblwallangle5
            cmp al, 35
            je DrawDblwallangle6
            cmp al, 36
            je DrawDblstrgwall1
            cmp al, 37
            je DrawDblstrgwall2
            cmp al, 38
            je DrawDblstrgangle1
            cmp al, 39
            je DrawDblstrgangle2
            cmp al, 40
            je DrawDblstrgangle3
            cmp al, 41
            je DrawDblstrgangle4
        ret
    ; END WALL CHOICE -----------------
    ; SET WALL ------------------------
    DrawEmpty:                  ; tell which sprite he want to draw
        mov si, empty           ; call the function to draw the tile
        call drawWalls          ; return to the function where he will look which sprite to use
        jmp wallchoice          ; does the same in the following functions for each sprite\
                                
    DrawDoor:
        mov si, door
        call drawWalls
        jmp wallchoice

    DrawSmplwall1:              
        mov si, smplwall1
        call drawWalls
        jmp wallchoice

    DrawSmplwall2:
        mov si, smplwall2
        call drawWalls
        jmp wallchoice

    DrawSmplwall3:
        mov si, smplwall3
        call drawWalls
        jmp wallchoice

    DrawSmplwall4:
        mov si, smplwall4
        call drawWalls
        jmp wallchoice

    DrawSmplangle11:
        mov si, smplangle11
        call drawWalls
        jmp wallchoice

    DrawSmplangle12:
        mov si, smplangle12
        call drawWalls
        jmp wallchoice

    DrawSmplangle13:
        mov si, smplangle13
        call drawWalls
        jmp wallchoice

    DrawSmplangle14:
        mov si, smplangle14
        call drawWalls
        jmp wallchoice

    DrawSmplangle21:
        mov si, smplangle21
        call drawWalls
        jmp wallchoice

    DrawSmplangle22:
        mov si, smplangle22
        call drawWalls
        jmp wallchoice

    DrawSmplangle23:
        mov si, smplangle23
        call drawWalls
        jmp wallchoice

    DrawSmplangle24:
        mov si, smplangle24
        call drawWalls
        jmp wallchoice

    DrawDblwall1:
        mov si, dblwall1
        call drawWalls
        jmp wallchoice

    DrawDblwall2:
        mov si, dblwall2
        call drawWalls
        jmp wallchoice

    DrawDblwall3:
        mov si, dblwall3
        call drawWalls
        jmp wallchoice

    DrawDblwall4:
        mov si, dblwall4
        call drawWalls
        jmp wallchoice

    DrawDblangle1:
        mov si, dblangle1
        call drawWalls
        jmp wallchoice

    DrawDblangle2:
        mov si, dblangle2
        call drawWalls
        jmp wallchoice

    DrawDblangle3:
        mov si, dblangle3
        call drawWalls
        jmp wallchoice

    DrawDblangle4:
        mov si, dblangle4
        call drawWalls
        jmp wallchoice

    DrawDblwallangle1:
        mov si, dblwallangle1
        call drawWalls
        jmp wallchoice

    DrawDblwallangle2:
        mov si, dblwallangle2
        call drawWalls
        jmp wallchoice

    DrawDblwallangle3:
        mov si, dblwallangle3
        call drawWalls
        jmp wallchoice

    DrawDblwallangle4:
        mov si, dblwallangle4
        call drawWalls
        jmp wallchoice

    DrawDblwallangle5:
        mov si, dblwallangle5
        call drawWalls
        jmp wallchoice

    DrawDblwallangle6:
        mov si, dblwallangle6
        call drawWalls
        jmp wallchoice

    DrawDblstrgwall1:
        mov si, dblstrgwall1
        call drawWalls
        jmp wallchoice

    DrawDblstrgwall2:
        mov si, dblstrgwall2
        call drawWalls
        jmp wallchoice

    DrawDblstrgangle1:
        mov si, dblstrgangle1
        call drawWalls
        jmp wallchoice
    
    DrawDblstrgangle2:
        mov si, dblstrgangle2
        call drawWalls
        jmp wallchoice

    DrawDblstrgangle3:
        mov si, dblstrgangle3
        call drawWalls
        jmp wallchoice

    DrawDblstrgangle4:
        mov si, dblstrgangle4
        call drawWalls
        jmp wallchoice
    ; END SET WALL ------------------
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

; CLEAR SCREEN ---------------------------------------------------------
    clearScreen:
        mov ax, 0xA000
        mov es, ax
        mov di, 0
        mov cx, 320*200
        rep stosb
        ret
; END CLEAR SCREEN -----------------------------------------------------

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
        mov cx, 35000
        call waitLoop
        call waitLoop
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
        mov cx, 35000
        call waitLoop
        call waitLoop
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
        mov cx, 35000
        call waitLoop
        call waitLoop
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
        mov cx, 35000
        call waitLoop
        call waitLoop
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