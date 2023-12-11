org 100h

%include "sprite.asm"

section .data
    cPos db 0

    position dw 43751

    blinkyPos dw 20711

    inkyPos dw 26780

    pinkyPos dw 26791

    clydePos dw 26802

    nbtestcoll db 4
    postestcoll dw 0

    frame db 1
    ; maze array
    maze db 26,22,22,22,22,22,22,22,22,22,22,22,22,30,31,22,22,22,22,22,22,22,22,22,22,22,22,27
         db 25, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,13,12, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,24
         db 25, 2,14,10,10,15, 2,14,10,10,10,15, 2,13,12, 2,14,10,10,10,15, 2,14,10,10,15, 2,24
         db 25, 3,13, 0, 0,12, 2,13, 0, 0, 0,12, 2,13,12, 2,13, 0, 0, 0,12, 2,13, 0, 0,12, 3,24
         db 25, 2,17,11,11,16, 2,17,11,11,11,16, 2,17,16, 2,17,11,11,11,16, 2,17,11,11,16, 2,24
         db 25, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,24
         db 25, 2,14,10,10,15, 2,14,15, 2,14,10,10,10,10,10,10,15, 2,14,15, 2,14,10,10,15, 2,24
         db 25, 2,17,11,11,16, 2,13,12, 2,17,11,11,19,18,11,11,16, 2,13,12, 2,17,11,11,16, 2,24
         db 25, 2, 2, 2, 2, 2, 2,13,12, 2, 2, 2, 2,13,12, 2, 2, 2, 2,13,12, 2, 2, 2, 2, 2, 2,24
         db 29,23,23,23,23,15, 2,13,21,10,10,15, 2,13,12, 2,14,10,10,20,12, 2,14,23,23,23,23,28
         db  0, 0, 0, 0, 0,25, 2,13,18,11,11,16, 0,17,16, 0,17,11,11,19,12, 2,24, 0, 0, 0, 0, 0
         db  0, 0, 0, 0, 0,25, 2,13,12, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,13,12, 2,24, 0, 0, 0, 0, 0
         db  0, 0, 0, 0, 0,25, 2,13,12, 0,38,23,36, 1, 1,37,23,39, 0,13,12, 2,24, 0, 0, 0, 0, 0
         db 22,22,22,22,22,16, 2,17,16, 0,24, 0, 0, 0, 0, 0, 0,25, 0,17,16, 2,17,22,22,22,22,22
         db  0, 0, 0, 0, 0, 0, 2, 0, 0, 0,24, 0, 0, 0, 0, 0, 0,25, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0
         db 23,23,23,23,23,15, 2,14,15, 0,24, 0, 0, 0, 0, 0, 0,25, 0,14,15, 2,14,23,23,23,23,23
         db  0, 0, 0, 0, 0,25, 2,13,12, 0,41,22,22,22,22,22,22,40, 0,13,12, 2,24, 0, 0, 0, 0, 0
         db  0, 0, 0, 0, 0,25, 2,13,12, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,13,12, 2,24, 0, 0, 0, 0, 0
         db  0, 0, 0, 0, 0,25, 2,13,12, 0,14,10,10,10,10,10,10,15, 0,13,12, 2,24, 0, 0, 0, 0, 0
         db 26,22,22,22,22,16, 2,17,16, 0,17,11,11,19,18,11,11,16, 0,17,16, 2,17,22,22,22,22,27
         db 25, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,13,12, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,24
         db 25, 2,14,10,10,15, 2,14,10,10,10,15, 2,13,12, 2,14,10,10,10,15, 2,14,10,10,15, 2,24
         db 25, 2,17,11,19,12, 2,17,11,11,11,16, 2,17,16, 2,17,11,11,11,16, 2,13,18,11,16, 2,24
         db 25, 3, 2, 2,13,12, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,13,12, 2, 2, 3,24
         db 33,10,15, 2,13,12, 2,14,15, 2,14,10,10,10,10,10,10,15, 2,14,15, 2,13,12, 2,14,10,34
         db 32,11,16, 2,17,16, 2,13,12, 2,17,11,11,19,18,11,11,16, 2,13,12, 2,17,16, 2,17,11,35
         db 25, 2, 2, 2, 2, 2, 2,13,12, 2, 2, 2, 2,13,12, 2, 2, 2, 2,13,12, 2, 2, 2, 2, 2, 2,24
         db 25, 2,14,10,10,10,10,20,21,10,10,15, 2,13,12, 2,14,10,10,20,21,10,10,10,10,15, 2,24
         db 25, 2,17,11,11,11,11,11,11,11,11,16, 2,17,16, 2,17,11,11,11,11,11,11,11,11,16, 2,24
         db 25, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,24
         db 29,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,28
    ; ---------------------------------------------------------------------
    Column dw 28    ; number of columns
    Row dw 31       ; number of rows
    nbpixel dw 2072 ; number of pixels in a row of tile

section .text
    mov ah, 00h     ;--------------------------------
    mov al, 13h     ; set screen 320x200 256colours
    int 10h         ;--------------------------------

    call clearScreen     ; clear the screen before everything

    call Maze   ; display the maze
    call initPac
    call initBlinky
    call initInky
    call initPinky
    call initClyde
    call moveLeft

    gameLoop:
        mov ah, 01h
        int 16h
        jz return ; If no key was pressed, jump back to the top of the loop

        mov ah, 00h
        int 16h     ; Read the key
        cmp ah, 48h ; Up arrow key
        je moveUp
        cmp ah, 4Bh ; Left arrow key
        je moveLeft
        cmp ah, 4Dh ; Right arrow key
        je moveRight
        cmp ah, 50h ; Down arrow key
        je moveDown

    return:
        ret

; MAZE -------------------------------------------------------------------
    ; DRAW WALL ---------------------------
    drawWalls:
        ; draw 1 tile
        mov dx, 6           ; number of row of a sprite
        .eachLine:  
            mov cx, 6       ; number of column of a sprite
            rep movsb       ; draw the sprite
            add di, 320-6   ; go to the next row
            dec dx          ; count the number of rows drawn
            jnz .eachLine   ; if the number of rows drawn is not zero, go to draw the next line
            call nextColumn ; call the function to go to the next tile
        inc bx              ; setup for the next sprite to choose
        ret

    nextColumn:
        mov ax, [Column]    ;------------------------------------------------------
        dec ax              ; decrement Column to count the number of drawn column
        mov [Column], ax    ;------------------------------------------------------
        cmp ax, 0           ; look if he has finished the row
        je nextRow          ; if yes, call the function for the next row of tiles
        sub di, 1914        ; go the the next column
        ret

    nextRow:
        mov ax, [Row]       ;------------------------------------------------
        dec ax              ; decrement Row to count the number of drawn row
        mov [Row], ax       ;------------------------------------------------
        cmp ax, 0           ; look if he has finished the every rows
        je gameLoop              ; if yes, finish
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
        mov di, 152               ; set the position
        mov bx, maze            ; put the maze array to a register to follow the maze pattern
        wallchoice:
            mov al, [bx]        ; look wich sprite he has to put in a tile
            cmp al, 0           ; then he call a function to draw the correct sprite
            je DrawEmpty        ;
            cmp al, 1
            je DrawDoor
            cmp al, 2
            je DrawGum
            cmp al, 3
            je DrawSuperGum
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
    DrawGum:
        mov si, gum
        call drawWalls
        jmp wallchoice
    
    DrawSuperGum:
        mov si, superGum
        call drawWalls
        jmp wallchoice

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
    ret

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

    drawPac:
        mov di, [position]
        mov dx, 10
        eachline:
            mov cx, 10
            rep movsb
            add di, 320-10 ; Move to the next line
            dec dx
            jnz eachline
        ret


drawBlinky:
    mov di, [blinkyPos]
    mov dx, 10
    call eachline
    ret

drawInky:
    mov di, [inkyPos]
    mov dx, 10
    call eachline
    ret

drawPinky:
    mov di, [pinkyPos]
    mov dx, 10
    call eachline
    ret

drawClyde:
    mov di, [clydePos]
    mov dx, 10
    call eachline
    ret



; END INITIALISATION PACMAN --------------------------------------------

; COLLISIONS -----------------------------------------------------------
    
; END COLLISIONS -------------------------------------------------------

; PACMAN MOVEMENTS -----------------------------------------------------
    FlopY:
        mov bl, [frame]
        cmp bl, 4
        jl setblinkyU
        cmp bl, 8
        jl setAltU
        mov bl, 0
        mov [frame], bl
        jmp FlopY
        FlopYret:
            call drawPac
            mov cx, 60000
            call waitLoop
            jmp gameLoop

    noFlopY:
        mov bl, [frame]
        cmp bl, 4
        jl setblinkyD
        cmp bl, 8
        jl setAltD
        mov bl, 0
        mov [frame], bl
        jmp noFlopY
        noFlopYret:
            call drawPac
            mov cx, 60000
            call waitLoop
            jmp gameLoop

    FlopX:
        mov bl, [frame]
        cmp bl, 4
        jl setblinkyR
        cmp bl, 8
        jl setAltR
        mov bl, 0
        mov [frame], bl
        jmp FlopX
        FlopXret:
            call drawPac
            mov cx, 60000
            call waitLoop
            jmp gameLoop

    noFlopX:
        mov bl, [frame]
        cmp bl, 4
        jl setblinkyL
        cmp bl, 8
        jl setAltL
        mov bl, 0
        mov [frame], bl
        jmp noFlopX
        noFlopXret:
            call drawPac
            mov cx, 60000
            call waitLoop
            jmp gameLoop 

    moveLeft:
        wCollisionLeft:
            mov ax, [position]  ; get the position of the sprite
            sub ax, 1           ; where the collision is tested
            mov [postestcoll], ax
            lineLeft:
                mov dx, 1
                mov cx, 320         ; nb of pixels in a row
                div cx              ; division to calculate the x and y position of the pixel where we test the collision
                mov bx, ax          ; save the quotient
                mov ah, 0Dh         ; int to read the pixel color
                mov cx, dx          ; remainder goes to x position
                mov dx, bx          ; quotient goes to y position
                int 10h
                cmp al, 0x10        ; test if the color is the same as the maze
                je stopPacLeft  

                mov dx, 1
                mov ax, [postestcoll]
                add ax, 2880
                mov [postestcoll], ax
                mov cx, 320         ; nb of pixels in a row
                div cx              ; division to calculate the x and y position of the pixel where we test the collision
                mov bx, ax          ; save the quotient
                mov ah, 0Dh         ; int to read the pixel color
                mov cx, dx          ; remainder goes to x position
                mov dx, bx          ; quotient goes to y position
                int 10h
                cmp al, 0x10        ; test if the color is the same as the maze
                je stopPacLeft 

                mov dx, 1
                mov ax, [postestcoll]
                sub ax, 960
                mov [postestcoll], ax
                mov cx, 320         ; nb of pixels in a row
                div cx              ; division to calculate the x and y position of the pixel where we test the collision
                mov bx, ax          ; save the quotient
                mov ah, 0Dh         ; int to read the pixel color
                mov cx, dx          ; remainder goes to x position
                mov dx, bx          ; quotient goes to y position
                int 10h
                cmp al, 0x10        ; test if the color is the same as the maze
                je stopPacLeft 
            ;mov ax, [postestcoll]
            ;add ax, 960
            ;mov [postestcoll], ax
            ;mov bx, [nbtestcoll]
            ;dec bx
            ;mov [nbtestcoll], bx
            ;cmp bx, 0
            ;jg lineLeft
            ;mov bx, 4
            ;mov [nbtestcoll], bx
        call clearPac
        sub word [position], 1
        call noFlopX
        skipLeft:
        call gameLoop
        jmp moveLeft

    moveRight:
        wCollisionRight:
            mov ax, [position] 
            add ax, 10
            mov [postestcoll], ax
            lineRight:
                mov dx, 1
                mov cx, 320         ; nb of pixels in a row
                div cx              ; division to calculate the x and y position of the pixel where we test the collision
                mov bx, ax          ; save the quotient
                mov ah, 0Dh         ; int to read the pixel color
                mov cx, dx          ; remainder goes to x position
                mov dx, bx          ; quotient goes to y position
                int 10h
                cmp al, 0x10        ; test if the color is the same as the maze
                je stopPacRight  

                mov dx, 1
                mov ax, [postestcoll]
                add ax, 2880
                mov [postestcoll], ax
                mov cx, 320         ; nb of pixels in a row
                div cx              ; division to calculate the x and y position of the pixel where we test the collision
                mov bx, ax          ; save the quotient
                mov ah, 0Dh         ; int to read the pixel color
                mov cx, dx          ; remainder goes to x position
                mov dx, bx          ; quotient goes to y position
                int 10h
                cmp al, 0x10        ; test if the color is the same as the maze
                je stopPacRight 

                mov dx, 1
                mov ax, [postestcoll]
                sub ax, 960
                mov [postestcoll], ax
                mov cx, 320         ; nb of pixels in a row
                div cx              ; division to calculate the x and y position of the pixel where we test the collision
                mov bx, ax          ; save the quotient
                mov ah, 0Dh         ; int to read the pixel color
                mov cx, dx          ; remainder goes to x position
                mov dx, bx          ; quotient goes to y position
                int 10h
                cmp al, 0x10        ; test if the color is the same as the maze
                je stopPacRight              
        call clearPac
        add word [position], 1
        call FlopX
        skipRight:
        call gameLoop
        jmp moveRight

    moveUp:
        wCollisionUp:
            mov ax, [position]
            sub ax, 320
            mov [postestcoll], ax
            lineUp:
                mov dx, 1
                mov cx, 320         ; nb of pixels in a row
                div cx              ; division to calculate the x and y position of the pixel where we test the collision
                mov bx, ax          ; save the quotient
                mov ah, 0Dh         ; int to read the pixel color
                mov cx, dx          ; remainder goes to x position
                mov dx, bx          ; quotient goes to y position
                int 10h
                cmp al, 0x10        ; test if the color is the same as the maze
                je stopPacUp  

                mov dx, 1
                mov ax, [postestcoll]
                add ax, 9
                mov [postestcoll], ax
                mov cx, 320         ; nb of pixels in a row
                div cx              ; division to calculate the x and y position of the pixel where we test the collision
                mov bx, ax          ; save the quotient
                mov ah, 0Dh         ; int to read the pixel color
                mov cx, dx          ; remainder goes to x position
                mov dx, bx          ; quotient goes to y position
                int 10h
                cmp al, 0x10        ; test if the color is the same as the maze
                je stopPacUp 

                mov dx, 1
                mov ax, [postestcoll]
                sub ax, 3
                mov [postestcoll], ax
                mov cx, 320         ; nb of pixels in a row
                div cx              ; division to calculate the x and y position of the pixel where we test the collision
                mov bx, ax          ; save the quotient
                mov ah, 0Dh         ; int to read the pixel color
                mov cx, dx          ; remainder goes to x position
                mov dx, bx          ; quotient goes to y position
                int 10h
                cmp al, 0x10        ; test if the color is the same as the maze
                je stopPacUp           
        call clearPac
        sub word [position], 320
        call FlopY
        skipUp:
        call gameLoop
        jmp moveUp

    moveDown:
        wCollisionDown:
            mov ax, [position]  
            add ax, 3200
            mov [postestcoll], ax
            lineDown:
                mov dx, 1
                mov cx, 320         ; nb of pixels in a row
                div cx              ; division to calculate the x and y position of the pixel where we test the collision
                mov bx, ax          ; save the quotient
                mov ah, 0Dh         ; int to read the pixel color
                mov cx, dx          ; remainder goes to x position
                mov dx, bx          ; quotient goes to y position
                int 10h
                cmp al, 0x10        ; test if the color is the same as the maze
                je stopPacDown  

                mov dx, 1
                mov ax, [postestcoll]
                add ax, 9
                mov [postestcoll], ax
                mov cx, 320         ; nb of pixels in a row
                div cx              ; division to calculate the x and y position of the pixel where we test the collision
                mov bx, ax          ; save the quotient
                mov ah, 0Dh         ; int to read the pixel color
                mov cx, dx          ; remainder goes to x position
                mov dx, bx          ; quotient goes to y position
                int 10h
                cmp al, 0x10        ; test if the color is the same as the maze
                je stopPacDown 

                mov dx, 1
                mov ax, [postestcoll]
                sub ax, 3
                mov [postestcoll], ax
                mov cx, 320         ; nb of pixels in a row
                div cx              ; division to calculate the x and y position of the pixel where we test the collision
                mov bx, ax          ; save the quotient
                mov ah, 0Dh         ; int to read the pixel color
                mov cx, dx          ; remainder goes to x position
                mov dx, bx          ; quotient goes to y position
                int 10h
                cmp al, 0x10        ; test if the color is the same as the maze
                je stopPacDown            
        call clearPac
        add word [position], 320
        call noFlopY
        skipDown:
        call gameLoop
        jmp moveDown

    setAltR:
        add bl, 1
        mov [frame], bl
        mov si, pacManWaka1R
        jmp FlopXret

    setAltL:
        add bl, 1
        mov [frame], bl
        mov si, pacManWaka1L
        jmp noFlopXret

    setAltU:
        add bl, 1
        mov [frame], bl
        mov si, pacManWaka1U
        jmp FlopYret

    setAltD:
        add bl, 1
        mov [frame], bl
        mov si, pacManWaka1D
        jmp noFlopYret

    setblinkyR:
        add bl, 1
        mov [frame], bl
        mov si, pacManWaka2R
        jmp FlopXret

    setblinkyL:
        add bl, 1
        mov [frame], bl
        mov si, pacManWaka2L
        jmp noFlopXret

    setblinkyU:
        add bl, 1
        mov [frame], bl
        mov si, pacManWaka2U
        jmp FlopYret

    setblinkyD:
        add bl, 1
        mov [frame], bl
        mov si, pacManWaka2D
        jmp noFlopYret

    clearPac:
        mov di, [position]
        mov si, clear
        call drawPac
        ret

    stopPacLeft:
        mov bx, 4
        mov [nbtestcoll], bx
        mov si, pacManWaka1L
        call drawPac
        jmp skipLeft

    stopPacRight:
        mov si, pacManWaka1R
        call drawPac
        jmp skipRight

    stopPacUp:
        mov si, pacManWaka1U
        call drawPac
        jmp skipUp

    stopPacDown:
        mov si, pacManWaka1D
        call drawPac
        jmp skipDown


    waitLoop:
        loop waitLoop
        ret

    drawPixel:
        mov bx, [postestcoll]
        add bx, 1
        mov di, bx
        mov si, pix
        mov dx, 1
        mov cx, 1
        rep movsb
        ret
    

    end:
        int 21h


