org 100h

%include "sprite.asm"

section .data


    ; maze array
    maze db 17,13,13,13,13,13,13,13,13,13,13,13,13,21,22,13,13,13,13,13,13,13,13,13,13,13,13,18
         db 16, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,15
         db 16, 0, 5,33,33, 6, 0, 5,33,33,33, 6, 0, 4, 3, 0, 5,33,33,33, 6, 0, 5,33,33, 6, 0,15
         db 16, 0, 4, 0, 0, 3, 0, 4, 0, 0, 0, 3, 0, 4, 3, 0, 4, 0, 0, 0, 3, 0, 4, 0, 0, 3, 0,15
         db 16, 0, 8, 2, 2, 7, 0, 8, 2, 2, 2, 7, 0, 8, 7, 0, 8, 2, 2, 2, 7, 0, 8, 2, 2, 7, 0,15
         db 16, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,15
         db 16, 0, 5,33,33, 6, 0, 5, 6, 0, 5,33,33,33,33,33,33, 6, 0, 5, 6, 0, 5,33,33, 6, 0,15
         db 16, 0, 8, 2, 2, 7, 0, 4, 3, 0, 8, 2, 2,10, 9, 2, 2, 7, 0, 4, 3, 0, 8, 2, 2, 7, 0,15
         db 16, 0, 0, 0, 0, 0, 0, 4, 3, 0, 0, 0, 0, 4, 3, 0, 0, 0, 0, 4, 3, 0, 0, 0, 0, 0, 0,15
         db 20,14,14,14,14, 6, 0, 4,12,33,33, 6, 0, 4, 3, 0, 5,33,33,11, 3, 0, 5,14,14,14,14,19
         db  0, 0, 0, 0, 0,16, 0, 4, 9, 2, 2, 7, 0, 8, 7, 0, 8, 2, 2,10, 3, 0,15, 0, 0, 0, 0, 0
         db  0, 0, 0, 0, 0,16, 0, 4, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 3, 0,15, 0, 0, 0, 0, 0
         db  0, 0, 0, 0, 0,16, 0, 4, 3, 0,29,14,27, 1, 1,28,14,30, 0, 4, 3, 0,15, 0, 0, 0, 0, 0
         db 13,13,13,13,13, 7, 0, 8, 7, 0,15, 0, 0, 0, 0, 0, 0,16, 0, 8, 7, 0, 8,13,13,13,13,13
         db  0, 0, 0, 0, 0, 0, 0, 0, 0, 0,15, 0, 0, 0, 0, 0, 0,16, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
         db 14,14,14,14,14, 6, 0, 5, 6, 0,15, 0, 0, 0, 0, 0, 0,16, 0, 5, 6, 0, 5,14,14,14,14,14
         db  0, 0, 0, 0, 0,16, 0, 4, 3, 0,32,13,13,13,13,13,13,31, 0, 4, 3, 0,15, 0, 0, 0, 0, 0
         db  0, 0, 0, 0, 0,16, 0, 4, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 3, 0,15, 0, 0, 0, 0, 0
         db  0, 0, 0, 0, 0,16, 0, 4, 3, 0, 5,33,33,33,33,33,33, 6, 0, 4, 3, 0,15, 0, 0, 0, 0, 0
         db 17,13,13,13,13, 7, 0, 8, 7, 0, 8, 2, 2,10, 9, 2, 2, 7, 0, 8, 7, 0, 8,13,13,13,13,18
         db 16, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,15
         db 16, 0, 5,33,33, 6, 0, 5,33,33,33, 6, 0, 4, 3, 0, 5,33,33,33, 6, 0, 5,33,33, 6, 0,15
         db 16, 0, 8, 2,10, 3, 0, 8, 2, 2, 2, 7, 0, 8, 7, 0, 8, 2, 2, 2, 7, 0, 4, 9, 2, 7, 0,15
         db 16, 0, 0, 0, 4, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 3, 0, 0, 0,15
         db 24,33, 6, 0, 4, 3, 0, 5, 6, 0, 5,33,33,33,33,33,33, 6, 0, 5, 6, 0, 4, 3, 0, 5,33,25
         db 23, 2, 7, 0, 8, 7, 0, 4, 3, 0, 8, 2, 2,10, 9, 2, 2, 7, 0, 4, 3, 0, 8, 7, 0, 8, 2,26
         db 16, 0, 0, 0, 0, 0, 0, 4, 3, 0, 0, 0, 0, 4, 3, 0, 0, 0, 0, 4, 3, 0, 0, 0, 0, 0, 0,15
         db 16, 0, 5,33,33,33,33,11,12,33,33, 6, 0, 4, 3, 0, 5,33,33,11,12,33,33,33,33, 6, 0,15
         db 16, 0, 8, 2, 2, 2, 2, 2, 2, 2, 2, 7, 0, 8, 7, 0, 8, 2, 2, 2, 2, 2, 2, 2, 2, 7, 0,15
         db 16, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,15
         db 20,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,19
    ; ---------------------------------------------------------------------
    Column dw 28    ; number of columns
    Row dw 31       ; number of rows
    nbpixel dw 1920 ; number of pixels in a row of tile

section .text
    mov ah, 00h
    mov al, 13h
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
        mov di, 0               ; set the position
        mov bx, maze            ; put the maze array to a register to follow the maze pattern
        wallchoice:
            mov al, [bx]        ; look wich sprite he has to put in a tile
            cmp al, 0           ; then he call a function to draw the correct sprite
            je drawEmpty        ;
            cmp al, 33
            je DrawSmplwall1
            cmp al, 2
            je DrawSmplwall2
            cmp al, 3
            je DrawSmplwall3
            cmp al, 4
            je DrawSmplwall4
            cmp al, 5
            je DrawSmplangle11
            cmp al, 6
            je DrawSmplangle12
            cmp al, 7
            je DrawSmplangle13
            cmp al, 8
            je DrawSmplangle14
            cmp al, 9
            je DrawSmplangle21
            cmp al, 10
            je DrawSmplangle22
            cmp al, 11
            je DrawSmplangle23
            cmp al, 12
            je DrawSmplangle24
            cmp al, 13
            je DrawDblwall1
            cmp al, 14
            je DrawDblwall2
            cmp al, 15
            je DrawDblwall3
            cmp al, 16
            je DrawDblwall4
            cmp al, 17
            je DrawDblangle1
            cmp al, 18
            je DrawDblangle2
            cmp al, 19
            je DrawDblangle3
            cmp al, 20
            je DrawDblangle4
            cmp al, 21
            je DrawDblwallangle1
            cmp al, 22
            je DrawDblwallangle2
            cmp al, 23
            je DrawDblwallangle3
            cmp al, 24
            je DrawDblwallangle4
            cmp al, 25
            je DrawDblwallangle5
            cmp al, 26
            je DrawDblwallangle6
            cmp al, 27
            je DrawDblstrgwall1
            cmp al, 28
            je DrawDblstrgwall2
            cmp al, 29
            je DrawDblstrgangle1
            cmp al, 30
            je DrawDblstrgangle2
            cmp al, 31
            je DrawDblstrgangle3
            cmp al, 32
            je DrawDblstrgangle4
            cmp al, 1
            je DrawDoor
        ret

    drawEmpty:
        mov si, empty           ; tell which sprite he want to draw
        call drawWalls          ; call the function to draw the tile
        jmp wallchoice          ; return to the function where he will look which sprite to use
                                ; does the same in the following functions for each sprite
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

    DrawDoor:
        mov si, door
        call drawWalls
        jmp wallchoice

    end:
        