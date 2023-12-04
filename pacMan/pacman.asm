org 100h

%include "sprite.asm"

section .data


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

section .text
    mov ah, 00h     ;--------------------------------
    mov al, 13h     ; set screen 320x200 256colours
    int 10h         ;--------------------------------

    mov ax, 0xA000  ; clear the screen
    mov es, ax      ;

    gameLoop:
        call Maze   ; display the maze

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
        ; go to the next column
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
        je end              ; if yes, finish
        mov ax, 28          ;  
        mov [Column], ax    ; setup the number of columns for the next row
        mov ax, [nbpixel] 
        mov di, ax          ; go to the next row of tile
        add ax, 1920        ; save the number of pixel to go to the next line
        mov [nbpixel], ax   ;
        ret
       
    Maze:
        mov di, 152               ; set the position
        mov bx, maze            ; put the maze array to a register to follow the maze pattern
        wallchoice:
            mov al, [bx]        ; look wich sprite he has to put in a tile
            cmp al, 0           ; then he call a function to draw the correct sprite
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

    end:
        