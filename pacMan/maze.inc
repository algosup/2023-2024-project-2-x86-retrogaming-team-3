section .data
%define WALL_SIZE 6
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
         db 42, 0, 0, 0, 0, 0, 2, 0, 0, 0,24, 0, 0, 0, 0, 0, 0,25, 0, 0, 0, 2, 0, 0, 0, 0, 0,43
         db 23,23,23,23,23,15, 2,14,15, 0,24, 0, 0, 0, 0, 0, 0,25, 0,14,15, 2,14,23,23,23,23,23
         db  0, 0, 0, 0, 0,25, 2,13,12, 0,41,22,22,22,22,22,22,40, 0,13,12, 2,24, 0, 0, 0, 0, 0
         db  0, 0, 0, 0, 0,25, 2,13,12, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,13,12, 2,24, 0, 0, 0, 0, 0
         db  0, 0, 0, 0, 0,25, 2,13,12, 0,14,10,10,10,10,10,10,15, 0,13,12, 2,24, 0, 0, 0, 0, 0
         db 26,22,22,22,22,16, 2,17,16, 0,17,11,11,19,18,11,11,16, 0,17,16, 2,17,22,22,22,22,27
         db 25, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,13,12, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,24
         db 25, 2,14,10,10,15, 2,14,10,10,10,15, 2,13,12, 2,14,10,10,10,15, 2,14,10,10,15, 2,24
         db 25, 2,17,11,19,12, 2,17,11,11,11,16, 2,17,16, 2,17,11,11,11,16, 2,13,18,11,16, 2,24
         db 25, 3, 2, 2,13,12, 2, 2, 2, 2, 2, 2, 2, 0, 0, 2, 2, 2, 2, 2, 2, 2,13,12, 2, 2, 3,24
         db 33,10,15, 2,13,12, 2,14,15, 2,14,10,10,10,10,10,10,15, 2,14,15, 2,13,12, 2,14,10,34
         db 32,11,16, 2,17,16, 2,13,12, 2,17,11,11,19,18,11,11,16, 2,13,12, 2,17,16, 2,17,11,35
         db 25, 2, 2, 2, 2, 2, 2,13,12, 2, 2, 2, 2,13,12, 2, 2, 2, 2,13,12, 2, 2, 2, 2, 2, 2,24
         db 25, 2,14,10,10,10,10,20,21,10,10,15, 2,13,12, 2,14,10,10,20,21,10,10,10,10,15, 2,24
         db 25, 2,17,11,11,11,11,11,11,11,11,16, 2,17,16, 2,17,11,11,11,11,11,11,11,11,16, 2,24
         db 25, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,24
         db 29,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,28

    mazesave db 26,22,22,22,22,22,22,22,22,22,22,22,22,30,31,22,22,22,22,22,22,22,22,22,22,22,22,27
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
             db 42, 0, 0, 0, 0, 0, 2, 0, 0, 0,24, 0, 0, 0, 0, 0, 0,25, 0, 0, 0, 2, 0, 0, 0, 0, 0,43
             db 23,23,23,23,23,15, 2,14,15, 0,24, 0, 0, 0, 0, 0, 0,25, 0,14,15, 2,14,23,23,23,23,23
             db  0, 0, 0, 0, 0,25, 2,13,12, 0,41,22,22,22,22,22,22,40, 0,13,12, 2,24, 0, 0, 0, 0, 0
             db  0, 0, 0, 0, 0,25, 2,13,12, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,13,12, 2,24, 0, 0, 0, 0, 0
             db  0, 0, 0, 0, 0,25, 2,13,12, 0,14,10,10,10,10,10,10,15, 0,13,12, 2,24, 0, 0, 0, 0, 0
             db 26,22,22,22,22,16, 2,17,16, 0,17,11,11,19,18,11,11,16, 0,17,16, 2,17,22,22,22,22,27
             db 25, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,13,12, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,24
             db 25, 2,14,10,10,15, 2,14,10,10,10,15, 2,13,12, 2,14,10,10,10,15, 2,14,10,10,15, 2,24
             db 25, 2,17,11,19,12, 2,17,11,11,11,16, 2,17,16, 2,17,11,11,11,16, 2,13,18,11,16, 2,24
             db 25, 3, 2, 2,13,12, 2, 2, 2, 2, 2, 2, 2, 0, 0, 2, 2, 2, 2, 2, 2, 2,13,12, 2, 2, 3,24
             db 33,10,15, 2,13,12, 2,14,15, 2,14,10,10,10,10,10,10,15, 2,14,15, 2,13,12, 2,14,10,34
             db 32,11,16, 2,17,16, 2,13,12, 2,17,11,11,19,18,11,11,16, 2,13,12, 2,17,16, 2,17,11,35
             db 25, 2, 2, 2, 2, 2, 2,13,12, 2, 2, 2, 2,13,12, 2, 2, 2, 2,13,12, 2, 2, 2, 2, 2, 2,24
             db 25, 2,14,10,10,10,10,20,21,10,10,15, 2,13,12, 2,14,10,10,20,21,10,10,10,10,15, 2,24
             db 25, 2,17,11,11,11,11,11,11,11,11,16, 2,17,16, 2,17,11,11,11,11,11,11,11,11,16, 2,24
             db 25, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,24
             db 29,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,28
    ; ---------------------------------------------------------------------
    initColumn dw 28    ; number of columns
    Column dw 28
    initRow dw 31       ; number of rows
    Row dw 31
    initnbpixel dw 1996 ; number of pixels in a row of tile
    nbpixel dw 1996

    levelstarted db 0
    levelisstarted db 0

    totalnbtile dw 0

section .text
; MAZE -------------------------------------------------------------------
    ; DRAW WALL ---------------------------
    drawWalls:     ; draw 1 tile
        mov dx, WALL_SIZE               ; number of row of a sprite
        .eachLineMaze:   
            mov cx, WALL_SIZE           ; number of column of a sprite
            .eachPixel:
                lodsb                       ; load the next pixel into AL
                cmp al, 0      ; check if the color is the excluded one
                je .skipDraw                ; if yes, skip drawing this pixel
                stosb                       ; draw the pixel
                jmp .nextPixel               ; jump to the next pixel
            .skipDraw:
                add di, 1                   ; skip drawing the pixel but still move to the next destination
                .nextPixel:
                loop .eachPixel             ; process the next pixel           ; draw the sprite
            add di, 320-WALL_SIZE       ; go to the next row
            dec dx              ; count the number of rows drawn
            jnz .eachLineMaze    ; if the number of rows drawn is not zero, go to draw the next line
        jmp nextColumn          ; call the function to go to the next tile

    nextColumn:
        inc bx              ; setup for the next sprite to choose
        sub di, 1914        ; go the the next column
        mov ax, [Column]    ;------------------------------------------------------
        dec ax              ; decrement Column to count the number of drawn column
        mov [Column], ax    ;------------------------------------------------------
        cmp ax, 0           ; look if it has finished the row
        je nextRow          ; if yes, call the function for the next row of tiles
        cmp byte [levelisstarted], 1
        je drawOnlyGums
        jmp wallchoice

    nextRow:
        mov ax, [Row]       ;------------------------------------------------
        dec ax              ; decrement Row to count the number of drawn row
        mov [Row], ax       ;------------------------------------------------
        cmp ax, 0           ; look if it has finished the every rows
        je levelStarted          ; if yes, finish
        mov ax, 28          ;  
        mov [Column], ax    ; setup the number of columns for the next row
        mov ax, [nbpixel] 
        mov di, ax          ; go to the next row of tile
        add ax, 1920        ; save the number of pixel to go to the next line
        mov [nbpixel], ax   ;
        cmp byte [levelisstarted], 1
        je drawOnlyGums
        jmp wallchoice 
    ; END DRAW WALL ----------------------
    ; WALL CHOICE ------------------------
    initMaze:
        call initTileVariables
        cmp byte [levelstarted], 1
        je Maze
        mov word [totalnbtile], 0
        eachTile:
            mov bx, mazesave            ; put the maze array to a register to follow the maze pattern
            add bx, [totalnbtile]
            mov al, [bx]
            cmp al, 2
            je setGum
            cmp al, 3
            je setSuperGum
            inc word [totalnbtile]
            cmp word [totalnbtile], 867
            jne eachTile
        ;mov byte [levelstarted], 1
        mov bx, mazesave
        mov di, 76
        jmp wallchoice
    Maze:
        call initTileVariables
        mov di, 76             ; set the position
        mov bx, maze
        cmp byte [levelisstarted], 1
        je drawOnlyGums
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
            cmp al, 42
            je DrawTunnelRight
            cmp al, 43
            je DrawTunnelLeft

        drawOnlyGums:
            mov al, [bx]
            cmp al, 2
            je DrawGum
            cmp al, 3
            je DrawSuperGum
            add di, 1920
            jmp nextColumn
    ; END WALL CHOICE -----------------
    ; SET WALL ------------------------
    DrawGum:
        inc word [nbgumeated]
        mov si, gum
        jmp drawWalls
    
    DrawSuperGum:
        inc word [nbgumeated]
        mov si, superGum
        jmp drawWalls

    DrawEmpty:                 
        mov si, empty           ; tell which sprite he want to draw 
        jmp drawWalls           ; call the function to draw the tile

    DrawDoor:
        mov si, door
        jmp drawWalls

    DrawSmplwall1:              
        mov si, smplwall1
        jmp drawWalls

    DrawSmplwall2:
        mov si, smplwall2
        jmp drawWalls

    DrawSmplwall3:
        mov si, smplwall3
        jmp drawWalls

    DrawSmplwall4:
        mov si, smplwall4
        jmp drawWalls

    DrawSmplangle11:
        mov si, smplangle11
        jmp drawWalls

    DrawSmplangle12:
        mov si, smplangle12
        jmp drawWalls

    DrawSmplangle13:
        mov si, smplangle13
        jmp drawWalls

    DrawSmplangle14:
        mov si, smplangle14
        jmp drawWalls

    DrawSmplangle21:
        mov si, smplangle21
        jmp drawWalls

    DrawSmplangle22:
        mov si, smplangle22
        jmp drawWalls

    DrawSmplangle23:
        mov si, smplangle23
        jmp drawWalls

    DrawSmplangle24:
        mov si, smplangle24
        jmp drawWalls

    DrawDblwall1:
        mov si, dblwall1
        jmp drawWalls

    DrawDblwall2:
        mov si, dblwall2
        jmp drawWalls

    DrawDblwall3:
        mov si, dblwall3
        jmp drawWalls

    DrawDblwall4:
        mov si, dblwall4
        jmp drawWalls

    DrawDblangle1:
        mov si, dblangle1
        jmp drawWalls

    DrawDblangle2:
        mov si, dblangle2
        jmp drawWalls

    DrawDblangle3:
        mov si, dblangle3
        jmp drawWalls

    DrawDblangle4:
        mov si, dblangle4
        jmp drawWalls

    DrawDblwallangle1:
        mov si, dblwallangle1
        jmp drawWalls

    DrawDblwallangle2:
        mov si, dblwallangle2
        jmp drawWalls

    DrawDblwallangle3:
        mov si, dblwallangle3
        jmp drawWalls

    DrawDblwallangle4:
        mov si, dblwallangle4
        jmp drawWalls

    DrawDblwallangle5:
        mov si, dblwallangle5
        jmp drawWalls

    DrawDblwallangle6:
        mov si, dblwallangle6
        jmp drawWalls

    DrawDblstrgwall1:
        mov si, dblstrgwall1
        jmp drawWalls

    DrawDblstrgwall2:
        mov si, dblstrgwall2
        jmp drawWalls

    DrawDblstrgangle1:
        mov si, dblstrgangle1
        jmp drawWalls
    
    DrawDblstrgangle2:
        mov si, dblstrgangle2
        jmp drawWalls

    DrawDblstrgangle3:
        mov si, dblstrgangle3
        jmp drawWalls

    DrawDblstrgangle4:
        mov si, dblstrgangle4
        jmp drawWalls

    DrawTunnelRight:
        mov si, tunnelright
        jmp drawWalls

    DrawTunnelLeft:
        mov si, tunnelleft
        jmp drawWalls
    ; END SET WALL ------------------
    setGum:
        mov bx, [totalnbtile]
        mov byte [maze+bx], 2
        inc word [totalnbtile]
        jmp eachTile

    setSuperGum:
        mov bx, [totalnbtile]
        mov byte [maze+bx], 3
        inc word [totalnbtile]
        jmp eachTile

    initTileVariables: 
        mov word [nbgumeated], 0
        mov ax, [initColumn]
        mov word [Column], ax
        mov ax, [initRow]
        mov word [Row], ax
        mov ax, [initnbpixel]
        mov word [nbpixel], ax
        ret

    levelStarted:
        cmp word [nbgumeated], 0
        je nextLevel
        cmp byte [levelisstarted], 1
        je blinkyMovement
        mov byte [levelisstarted], 1
        mov byte [levelstarted], 1
        jmp initAll
; END MAZE ------------------------------------------------------------