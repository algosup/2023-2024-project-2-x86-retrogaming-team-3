section .data
    ;All Ghost Data
        ghostInitposition dw 20635
                          dw 26715
                          dw 26704
                          dw 26726

        ghostPosition dw 0
                      dw 0
                      dw 0
                      dw 0

        ghostFrame db 1
                   db 1
                   db 1
                   db 1

            ghostWantGoLeft db 0
                            db 0
                            db 0
                            db 0

            ghostWantGoRight db 0
                            db 0
                            db 0
                            db 0

            ghostWantGoUp db 0
                        db 0
                        db 0
                        db 0

            ghostWantGoDown db 0
                            db 0
                            db 0
                            db 0

            ghostGoLeft db 0
                        db 0
                        db 0
                        db 0

            ghostGoRight db 0
                        db 0
                        db 0
                        db 0

            ghostGoUp db 0
                    db 0
                    db 0
                    db 0

            ghostGoDown db 0
                        db 0
                        db 0
                        db 0

        ghostPosTestColl dw 0
                         dw 0
                         dw 0
                         dw 0

    ;Animation data
        ghostIndex dw 0

        ghost1L dw blinky1L
                dw pinky1L
                dw inky1L
                dw clyde1L

        ghost2L dw blinky2L
                dw pinky2L
                dw inky2L
                dw clyde2L

        ghost1R dw blinky1R
                dw pinky1R
                dw inky1R
                dw clyde1R

        ghost2R dw blinky2R
                dw pinky2R
                dw inky2R
                dw clyde2R

        ghost1U dw blinky1U
                dw pinky1U
                dw inky1U
                dw clyde1U

        ghost2U dw blinky2U
                dw pinky2U
                dw inky2U
                dw clyde2U

        ghost1D dw blinky1D
                dw pinky1D
                dw inky1D
                dw clyde1D

        ghost2D dw blinky2D
                dw pinky2D
                dw inky2D
                dw clyde2D

section .text
    blinkyMovement:
        mov ax, 0
        mov [ghostIndex], ax

        je ghostBeforeUp 
        jmp ghostWantGoDirection
            
; INITIALISATION PACMAN ------------------------------------------------
    initGhost:
        mov cx, [ghostIndex]
        mov bx, ghostInitposition
        add bx, word [ghostIndex]
        mov ax, [bx]
        mov bx, ghostIndex
        mov bx, ghostPosition
        add bx, word [ghostIndex]
        mov word [bx], ax
        mov bx, ghostIndex
        mov bx, ghostPosition
        add bx, word [ghostIndex]
        mov di, [bx]
        mov bx, ghost1U
        add bx, word [ghostIndex]
        mov si, [bx]
        call drawGhosts
        ret

    
; END INITIALISATION PACMAN --------------------------------------------

; COLLISIONS -----------------------------------------------------------
    ; SIMPLE --------------------------
    ghostWCollLeft:                  ; collision for straight direction to stop when seing a wall
         
        mov bx, ghostIndex
        mov bx, ghostPosition
        add bx, word [ghostIndex]
        mov ax, [bx]  
        add ax, 1279 
        call collTest 
        cmp al, 0x10            ; test if the color is the same as the maze
        je ghostLeft1
        cmp al, 0x11
        je ghostTpRight
        jmp ghostContinueMoveLeft
        
    ghostWCollRight:
         
        mov bx, ghostIndex
        mov bx, ghostPosition
        add bx, word [ghostIndex]
        mov ax, [bx]
        add ax, 1290
        call collTest
        cmp al, 0x10        
        je ghostRight1
        cmp al, 0x11
        je ghostTpLeft
        jmp ghostContinueMoveRight
        
    ghostWCollUp:
     
        mov bx, ghostIndex
        mov bx, ghostPosition
        add bx, word [ghostIndex]
        mov ax, [bx]
        sub ax, 315
        call collTest
        cmp al, 0x10        
        je ghostUp1
        jmp ghostContinueMoveUp

    ghostWCollDown:
         
        mov bx, ghostIndex
        mov bx, ghostPosition
        add bx, word [ghostIndex]
        mov ax, [bx]
        add ax, 3205
        call collTest
        cmp al, 0x10        
        je ghostDown1
        jmp ghostContinueMovedown
    ; END SIMPLE -----------------------
    ; COMPLEX --------------------------
    ghostBeforeLeft:             ; collision test before turning, if collision is detected, save the direction for when he can turn
         
        mov bx, ghostIndex
        mov bx, ghostWantGoLeft
        add bx, word [ghostIndex]
        mov byte [bx], 1
        mov bx, ghostIndex
        mov bx, ghostWantGoRight
        add bx, word [ghostIndex]
        mov byte [bx], 0
        mov bx, ghostIndex
        mov bx, ghostWantGoUp
        add bx, word [ghostIndex]
        mov byte [bx], 0
        mov bx, ghostIndex
        mov bx, ghostWantGoDown
        add bx, word [ghostIndex]
        mov byte [bx], 0
        mov bx, ghostIndex
        mov bx, ghostPosition
        add bx, word [ghostIndex]
        mov ax, [bx]
        sub ax, 1
        mov bx, ghostIndex
        mov bx, ghostPosTestColl
        add bx, word [ghostIndex]
        mov [bx], ax

         
        call collTest     
        cmp al, 0x10                ; test if the color is the same as the maze
        je ghostActualDirection  
        mov bx, ghostIndex
        mov bx, ghostPosTestColl
        add bx, word [ghostIndex]
        mov ax, [bx]
        add ax, 2880
        mov bx, ghostIndex
        mov bx, ghostPosTestColl
        add bx, word [ghostIndex]
        mov [bx], ax
        
        call collTest 
        cmp al, 0x10            
        je ghostActualDirection 
        mov bx, ghostIndex
        mov bx, ghostPosTestColl
        add bx, word [ghostIndex]
        mov ax, [bx]
        sub ax, 960
        mov bx, ghostIndex
        mov bx, ghostPosTestColl
        add bx, word [ghostIndex]
        mov [bx], ax

         
        call collTest 
        cmp al, 0x10            
        je ghostActualDirection
        jmp ghostMoveLeft

    ghostBeforeRight:
        mov bx, ghostIndex
        mov bx, ghostWantGoLeft
        add bx, word [ghostIndex]
        mov byte [bx], 0
        mov bx, ghostIndex
        mov bx, ghostWantGoRight
        add bx, word [ghostIndex]
        mov byte [bx], 1
        mov bx, ghostIndex
        mov bx, ghostWantGoUp
        add bx, word [ghostIndex]
        mov byte [bx], 0
        mov bx, ghostIndex
        mov bx, ghostWantGoDown
        add bx, word [ghostIndex]
        mov byte [bx], 0
        mov bx, ghostIndex
        mov bx, ghostPosition
        add bx, word [ghostIndex]
        mov ax, [bx]
        add ax, 10
        mov bx, ghostIndex
        mov bx, ghostPosTestColl
        add bx, word [ghostIndex]
        mov [bx], ax
        call collTest 
        cmp al, 0x10            
        je ghostActualDirection  
        mov bx, ghostIndex
        mov bx, ghostPosTestColl
        add bx, word [ghostIndex]
        mov ax, [bx]
        add ax, 2880
        mov bx, ghostIndex
        mov bx, ghostPosTestColl
        add bx, word [ghostIndex]
        mov [bx], ax
        call collTest 
        cmp al, 0x10            
        je ghostActualDirection 
        mov bx, ghostIndex
        mov bx, ghostPosTestColl
        add bx, word [ghostIndex]
        mov ax, [bx]
        sub ax, 960
        mov bx, ghostIndex
        mov bx, ghostPosTestColl
        add bx, word [ghostIndex]
        mov [bx], ax
        call collTest 
        cmp al, 0x10            
        je ghostActualDirection  
        jmp ghostMoveRight

    ghostBeforeUp:
        mov bx, ghostIndex
        mov bx, ghostWantGoLeft
        add bx, word [ghostIndex]
        mov byte [bx], 0
        mov bx, ghostIndex
        mov bx, ghostWantGoRight
        add bx, word [ghostIndex]
        mov byte [bx], 0
        mov bx, ghostIndex
        mov bx, ghostWantGoUp
        add bx, word [ghostIndex]
        mov byte [bx], 1
        mov bx, ghostIndex
        mov bx, ghostWantGoDown
        add bx, word [ghostIndex]
        mov byte [bx], 0
        mov bx, ghostIndex
        mov bx, ghostPosition
        add bx, word [ghostIndex]
        mov ax, [bx]
        sub ax, 320
        mov bx, ghostIndex
        mov bx, ghostPosTestColl
        add bx, word [ghostIndex]
        mov [bx], ax
        call collTest 
        cmp al, 0x10            
        je ghostActualDirection 
        mov bx, ghostIndex
        mov bx, ghostPosTestColl
        add bx, word [ghostIndex]
        mov ax, [bx]
        add ax, 9
        mov bx, ghostIndex
        mov bx, ghostPosTestColl
        add bx, word [ghostIndex]
        mov [bx], ax
        call collTest 
        cmp al, 0x10            
        je ghostActualDirection
        mov bx, ghostIndex
        mov bx, ghostPosTestColl
        add bx, word [ghostIndex]
        mov ax, [bx]
        sub ax, 3
        mov bx, ghostIndex
        mov bx, ghostPosTestColl
        add bx, word [ghostIndex]
        mov [bx], ax
        call collTest
        cmp al, 0x10            
        je ghostActualDirection
        jmp ghostMoveUp

    ghostBeforeDown:
        mov bx, ghostIndex
        mov bx, ghostWantGoLeft
        add bx, word [ghostIndex]
        mov byte [bx], 0
        mov bx, ghostIndex
        mov bx, ghostWantGoRight
        add bx, word [ghostIndex]
        mov byte [bx], 0
        mov bx, ghostIndex
        mov bx, ghostWantGoUp
        add bx, word [ghostIndex]
        mov byte [bx], 0
        mov bx, ghostIndex
        mov bx, ghostWantGoDown
        add bx, word [ghostIndex]
        mov byte [bx], 1
        mov bx, ghostIndex
        mov bx, ghostPosition
        add bx, word [ghostIndex]
        mov ax, [bx]
        add ax, 3200
        mov bx, ghostIndex
        mov bx, ghostPosTestColl
        add bx, word [ghostIndex]
        mov [bx], ax
        call collTest
        cmp al, 0x10            
        je ghostActualDirection  
        mov bx, ghostIndex
        mov bx, ghostPosTestColl
        add bx, word [ghostIndex]
        mov ax, [bx]
        add ax, 9
        mov bx, ghostIndex
        mov bx, ghostPosTestColl
        add bx, word [ghostIndex]
        mov [bx], ax
        call collTest 
        cmp al, 0x10            
        je ghostActualDirection 
        mov bx, ghostIndex
        mov bx, ghostPosTestColl
        add bx, word [ghostIndex]
        mov ax, [bx]
        sub ax, 3
        mov bx, ghostIndex
        mov bx, ghostPosTestColl
        add bx, word [ghostIndex]
        mov [bx], ax
        call collTest
        cmp al, 0x10            
        je ghostActualDirection
        jmp ghostMoveDown
    ; END COMPLEX -----------------------
; END COLLISIONS -------------------------------------------------------

; PACMAN MOVEMENTS -----------------------------------------------------
    ; CHECK WANTED MOVEMENT --------------
    ghostWantGoDirection:            ; test wich direction he wants to go
        mov bx, ghostIndex
        mov bx, ghostWantGoLeft
        add bx, word [ghostIndex]
        cmp byte [bx], 1
        je ghostBeforeLeft
        mov bx, ghostIndex
        mov bx, ghostWantGoRight
        add bx, word [ghostIndex]
        cmp byte [bx], 1
        je ghostBeforeRight
        mov bx, ghostIndex
        mov bx, ghostWantGoUp
        add bx, word [ghostIndex]
        cmp byte [bx], 1
        je ghostBeforeUp
        mov bx, ghostIndex
        mov bx, ghostWantGoDown
        add bx, word [ghostIndex]
        cmp byte [bx], 1
        je ghostBeforeDown
        jmp ghostActualDirection
    ; END CHECK WANTED MOVEMENT ----------
    ; ACTUAL DIRECTION --------------------
    ghostActualDirection:        ; test wich direction he is going
        mov bx, ghostIndex
        mov bx, ghostGoLeft
        add bx, word [ghostIndex]
        cmp byte [bx], 1
        je ghostMoveLeft
        mov bx, ghostIndex
        mov bx, ghostGoRight
        add bx, word [ghostIndex]
        cmp byte [bx], 1
        je ghostMoveRight
        mov bx, ghostIndex
        mov bx, ghostGoUp
        add bx, word [ghostIndex]
        cmp byte [bx], 1
        je ghostMoveUp
        mov bx, ghostIndex
        mov bx, ghostGoDown
        add bx, word [ghostIndex]
        cmp byte [bx], 1
        je ghostMoveDown
        jmp ghostMoveLeft
    ; END ACTUAL DIRECTION ----------------
    ; ACTUAL MOVEMENT ---------------------
    ghostMoveLeft:              
        mov bx, ghostIndex
        mov bx, ghostGoLeft
        add bx, word [ghostIndex]
        mov byte [bx], 1        ; use to save wich direction he is going
        mov bx, ghostIndex
        mov bx, ghostGoRight
        add bx, word [ghostIndex]
        mov byte [bx], 0       ;
        mov bx, ghostIndex
        mov bx, ghostGoUp
        add bx, word [ghostIndex]
        mov byte [bx], 0          ;
        mov bx, ghostIndex
        mov bx, ghostGoDown
        add bx, word [ghostIndex]
        mov byte [bx], 0        ;
        jmp ghostWCollLeft
    ghostContinueMoveLeft:
        call clearGhost
        jmp ghostAnimLeft

    ghostMoveRight:
        mov bx, ghostIndex
        mov bx, ghostGoLeft
        add bx, word [ghostIndex]
        mov byte [bx], 0 
        mov bx, ghostIndex
        mov bx, ghostGoRight
        add bx, word [ghostIndex]
        mov byte [bx], 1
        mov bx, ghostIndex
        mov bx, ghostGoUp
        add bx, word [ghostIndex]
        mov byte [bx], 0   
        mov bx, ghostIndex
        mov bx, ghostGoDown
        add bx, word [ghostIndex]
        mov byte [bx], 0       
        jmp ghostWCollRight
    ghostContinueMoveRight:
        call clearGhost
        jmp ghostAnimRight
    
    ghostMoveUp:
        mov bx, ghostIndex
        mov bx, ghostGoLeft
        add bx, word [ghostIndex]
        mov byte [bx], 0 
        mov bx, ghostIndex
        mov bx, ghostGoRight
        add bx, word [ghostIndex]
        mov byte [bx], 0
        mov bx, ghostIndex
        mov bx, ghostGoUp
        add bx, word [ghostIndex]
        mov byte [bx], 1   
        mov bx, ghostIndex
        mov bx, ghostGoDown
        add bx, word [ghostIndex]
        mov byte [bx], 0         
        jmp ghostWCollUp
    ghostContinueMoveUp:
        call clearGhost
        jmp ghostAnimUp

    ghostMoveDown:
        mov bx, ghostIndex
        mov bx, ghostGoLeft
        add bx, word [ghostIndex]
        mov byte [bx], 0 
        mov bx, ghostIndex
        mov bx, ghostGoRight
        add bx, word [ghostIndex]
        mov byte [bx], 0
        mov bx, ghostIndex
        mov bx, ghostGoUp
        add bx, word [ghostIndex]
        mov byte [bx], 0   
        mov bx, ghostIndex
        mov bx, ghostGoDown
        add bx, word [ghostIndex]
        mov byte [bx], 1        
        jmp ghostWCollDown
    ghostContinueMovedown:
        call clearGhost
        jmp ghostAnimDown

    ghostTpRight:
        call clearGhost
        mov bx, ghostIndex
        mov bx, ghostPosition
        add bx, word [ghostIndex]
        mov word [bx], 26473
        jmp ghostMoveLeft

    ghostTpLeft:
        call clearGhost
        mov bx, ghostIndex
        mov bx, ghostPosition
        add bx, word [ghostIndex]
        mov word [bx], 26317
        jmp ghostMoveRight
    ; END ACTUAL MOVEMENT ----------------
; END PACMAN MOVEMENTS -------------------------------------------------

; PACMAN ANIMATIONS ----------------------------------------------------
    ; CHOICE ------------------------------
    ghostAnimLeft:               ; choose the right sprite to make the animation
         
        mov bx, ghostIndex
        mov bx, ghostPosition
        add bx, word [ghostIndex]
        sub word [bx], 1
        mov bx, ghostIndex
        inc byte [ghostFrame + ecx*2]

        mov bx, ghostIndex
        mov bx, ghostFrame
        add bx, word [ghostIndex]
        cmp byte [bx], 4
        jl ghostLeft2
        mov bx, ghostIndex
        mov bx, ghostFrame
        add bx, word [ghostIndex]
        cmp byte [bx], 8
        jl ghostLeft1
        mov bx, ghostIndex
        mov bx, ghostFrame
        add bx, word [ghostIndex]
        mov byte [bx], 0
        jmp ghostLeft2

    ghostAnimRight:
         
        mov bx, ghostIndex
        mov bx, ghostPosition
        add bx, word [ghostIndex]
        add word [bx], 1
        mov bx, ghostIndex
        inc byte [ghostFrame + ecx*2]

        mov bx, ghostIndex
        mov bx, ghostFrame
        add bx, word [ghostIndex]
        cmp byte [bx], 4
        jl ghostRight2
        mov bx, ghostIndex
        mov bx, ghostFrame
        add bx, word [ghostIndex]
        cmp byte [bx], 8
        jl ghostRight1
        mov bx, ghostIndex
        mov bx, ghostFrame
        add bx, word [ghostIndex]
        mov byte [bx], 0
        jmp ghostRight2

    ghostAnimUp:
         
        mov bx, ghostIndex
        mov bx, ghostPosition
        add bx, word [ghostIndex]
        sub word [bx], 320
        mov bx, ghostIndex
        inc byte [ghostFrame + ecx*2]

        mov bx, ghostIndex
        mov bx, ghostFrame
        add bx, word [ghostIndex]
        cmp byte [bx], 4
        jl ghostUp2
        mov bx, ghostIndex
        mov bx, ghostFrame
        add bx, word [ghostIndex]
        cmp byte [bx], 8
        jl ghostUp1
        mov bx, ghostIndex
        mov bx, ghostFrame
        add bx, word [ghostIndex]
        mov byte [bx], 0
        jmp ghostUp2

    ghostAnimDown:
         
        mov bx, ghostIndex
        mov bx, ghostPosition
        add bx, word [ghostIndex]
        add word [bx], 320
        mov bx, ghostIndex
        inc byte [ghostFrame + ecx*2]

        mov bx, ghostIndex
        mov bx, ghostFrame
        add bx, word [ghostIndex]
        cmp byte [bx], 4
        jl ghostDown2
        mov bx, ghostIndex
        mov bx, ghostFrame
        add bx, word [ghostIndex]
        cmp byte [bx], 8
        jl ghostDown1
        mov bx, ghostIndex
        mov bx, ghostFrame
        add bx, word [ghostIndex]
        mov byte [bx], 0
        jmp ghostDown2

    ; END CHOICE --------------------------
    ; SET ANIMATIONS ----------------------

    ghostLeft1:
        mov bx, ghost1L
        mov ax, [ghostIndex]
        add bx, ax
        mov si, [bx]
        mov bx, ghostIndex
        mov bx, ghostPosition
        add bx, word [ghostIndex]
        mov di, [bx]
        call drawGhosts
        jmp keyCheck

    ghostLeft2:
        mov bx, ghost2L
        mov ax, [ghostIndex]
        add bx, ax
        mov si, [bx]
        mov bx, ghostIndex
        mov bx, ghostPosition
        add bx, word [ghostIndex]
        mov di, [bx]
        call drawGhosts
        jmp keyCheck

    ghostRight1:
        mov bx, ghost1R
        mov ax, [ghostIndex]
        add bx, ax
        mov si, [bx]
        mov bx, ghostIndex
        mov bx, ghostPosition
        add bx, word [ghostIndex]
        mov di, [bx]
        call drawGhosts
        jmp keyCheck

    ghostRight2:
        mov bx, ghost2R
        mov ax, [ghostIndex]
        add bx, ax
        mov si, [bx]
        mov bx, ghostIndex
        mov bx, ghostPosition
        add bx, word [ghostIndex]
        mov di, [bx]
        call drawGhosts
        jmp keyCheck

    ghostUp1:
        mov bx, ghost1U
        mov ax, [ghostIndex]
        add bx, ax
        mov si, [bx]
        mov bx, ghostIndex
        mov bx, ghostPosition
        add bx, word [ghostIndex]
        mov di, [bx]
        call drawGhosts
        jmp keyCheck

    ghostUp2:
        mov bx, ghost2U
        mov ax, [ghostIndex]
        add bx, ax
        mov si, [bx]
        mov bx, ghostIndex
        mov bx, ghostPosition
        add bx, word [ghostIndex]
        mov di, [bx]
        call drawGhosts
        jmp keyCheck

    ghostDown1:
        mov bx, ghost1D
        mov ax, [ghostIndex]
        add bx, ax
        mov si, [bx]
        mov bx, ghostIndex
        mov bx, ghostPosition
        add bx, word [ghostIndex]
        mov di, [bx]
        call drawGhosts
        jmp keyCheck

    ghostDown2:
        mov bx, ghost2D
        add bx, word [ghostIndex]
        mov si, [bx]

        mov bx, ghostIndex
        mov bx, ghostPosition
        add bx, word [ghostIndex]
        mov di, [bx]

        call drawGhosts
        jmp keyCheck
    ; END SET ANIMATIONS ------------------
    clearGhost:
        mov si, clear
        mov bx, ghostIndex
        mov bx, ghostPosition
        add bx, word [ghostIndex]
        mov di, [bx]
        call drawGhosts
         
        ret
; END PACMAN ANIMATIONS ------------------------------------------------

    drawGhosts:
    mov dx, 10
        eachLineGhosts:
            mov cx, 10
            rep movsb
            add di, 320-10 
            dec dx
            jnz eachLineGhosts
        ret

;(\w+ \w+), \[(\w+) \+ ecx\*2\]
;
;mov bx, $2
;        add bx, word [ghostIndex]
;        $1, [bx]

;(\w+(?: \w+)?) \[(\w+) \+ ecx\*2\], (\w+)
;
;mov bx, $2
;add bx, word [ghostIndex]
;$1 [bx], $3
