section .data
    ;All Ghost Data
        frameFromStart dw 0

        %define penDoor 20635

        ghostInitposition dw 20635
                          dw 26715
                          dw 26704
                          dw 26726

        ghostInitpositionaftereated dw 20635

        ghostMoveTime dw 0 ;the time after which the ghost are moved out of the ghost pen
                      dw 20
                      dw 40
                      dw 60

        ghostPosition dw 0
                      dw 0
                      dw 0
                      dw 0

        ghostFrame dw 1
                   dw 1
                   dw 1
                   dw 1

            ghostWantGoLeft dw 0
                            dw 0
                            dw 0
                            dw 0

            ghostWantGoRight dw 0
                            dw 0
                            dw 0
                            dw 0

            ghostWantGoUp dw 0
                        dw 0
                        dw 0
                        dw 0

            ghostWantGoDown dw 0
                            dw 0
                            dw 0
                            dw 0

            ghostGoLeft dw 0
                        dw 0
                        dw 0
                        dw 0

            ghostGoRight dw 0
                        dw 0
                        dw 0
                        dw 0

            ghostGoUp dw 0
                    dw 0
                    dw 0
                    dw 0

            ghostGoDown dw 0
                        dw 0
                        dw 0
                        dw 0

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

        infrightmode dw 0
                     dw 0
                     dw 0
                     dw 0

        frightmodetime dw 0
                       dw 0
                       dw 0
                       dw 0

        nbeatedghosts db 1

        posTest dw 0
                dw 0
                dw 0
                dw 0

section .text
    blinkyMovement:
        mov word [ghostIndex], blinkyIndex

        mov bx, ghostMoveTime
        add bx, word [ghostIndex]
        
        mov ax, [frameFromStart]
        cmp ax, 0
        je exitPen1
        jg Patern1
        jl nextGhost

    pinkyMovement:
        mov word [ghostIndex], pinkyIndex

        mov bx, ghostMoveTime
        add bx, word [ghostIndex]

        mov ax, [frameFromStart]
        cmp ax, 40
        je exitPen2
        jg Patern2
        jl nextGhost

    inkyMovement:
        mov word [ghostIndex], inkyIndex

        mov bx, ghostMoveTime
        add bx, word [ghostIndex]

        mov ax, [frameFromStart]
        cmp ax, 80
        je exitPen3
        jg Patern3
        jl nextGhost

    clydeMovement:
        mov word [ghostIndex], clydeIndex

        mov bx, ghostMoveTime
        add bx, word [ghostIndex]

        mov ax, [frameFromStart]
        cmp ax, 120
        je exitPen4
        jg Patern4
        jl nextGhost


    nextGhost:
        cmp word [ghostIndex], 0
        je pinkyMovement

        cmp word [ghostIndex], 2
        je inkyMovement

        cmp word [ghostIndex], 4
        je clydeMovement

        cmp word [ghostIndex], 6
        je keyCheck

    exitPen1:
        call clearGhost
        mov bx, ghostPosition
        add bx, word [ghostIndex]
        mov word [bx], penDoor
        jmp Patern1

    exitPen2:
        call clearGhost
        mov bx, ghostPosition
        add bx, word [ghostIndex]
        mov word [bx], penDoor
        jmp Patern2

    exitPen3:
        call clearGhost
        mov bx, ghostPosition
        add bx, word [ghostIndex]
        mov word [bx], penDoor
        jmp Patern3

    exitPen4:
        call clearGhost
        mov bx, ghostPosition
        add bx, word [ghostIndex]
        mov word [bx], penDoor
        jmp Patern4


    incFrameFromStart:
        mov ax, [frameFromStart]
        cmp ax, 100
        jl .incUp
        .incUp :
            inc ax
        mov [frameFromStart], ax
        ret
            
; INITIALISATION PACMAN ------------------------------------------------
    initGhost:
        mov bx, ghostInitposition
        add bx, word [ghostIndex]
        mov ax, [bx]
        mov bx, ghostPosition
        add bx, word [ghostIndex]
        mov word [bx], ax
        mov bx, ghostPosition
        add bx, word [ghostIndex]
        mov di, [bx]
        mov bx, ghost1U
        add bx, word [ghostIndex]
        mov si, [bx]
        call drawGhosts
        ret

    initGhostAfterEated:
        mov bx, [ghostInitpositionaftereated]
        mov ax, bx
        mov bx, ghostPosition
        add bx, word [ghostIndex]
        mov word [bx], ax
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
        mov bx, ghostPosition
        add bx, word [ghostIndex]
        mov ax, [bx]  
        add ax, 1279 
        call collTest 
        cmp al, 0x10            ; test if the color is the same as the maze
        je ghostLeft1
        cmp al, 0x11
        je ghostTpRight
        cmp al, 0x2C
        je isInFrightModeLeft
        jmp ghostContinueMoveLeft
        
    ghostWCollRight:
        mov bx, ghostPosition
        add bx, word [ghostIndex]
        mov ax, [bx]
        add ax, 1290
        call collTest
        cmp al, 0x10        
        je ghostRight1
        cmp al, 0x11
        je ghostTpLeft
        cmp al, 0x2C
        je isInFrightModeRight
        jmp ghostContinueMoveRight
        
    ghostWCollUp:
        mov bx, ghostPosition
        add bx, word [ghostIndex]
        mov ax, [bx]
        sub ax, 315
        call collTest
        cmp al, 0x10        
        je ghostUp1
        cmp al, 0x2C
        je isInFrightModeUp
        jmp ghostContinueMoveUp

    ghostWCollDown:
        mov bx, ghostPosition
        add bx, word [ghostIndex]
        mov ax, [bx]
        add ax, 3205
        call collTest
        cmp al, 0x10        
        je ghostDown1
        cmp al, 0x2C
        je isInFrightModeDown
        jmp ghostContinueMoveDown
    ; END SIMPLE -----------------------
    ; COMPLEX --------------------------
    ghostBeforeLeft:             ; collision test before turning, if collision is detected, save the direction for when he can turn
        mov bx, ghostWantGoLeft
        add bx, word [ghostIndex]
        mov word [bx], 1
        mov bx, ghostWantGoRight
        add bx, word [ghostIndex]
        mov word [bx], 0
        mov bx, ghostWantGoUp
        add bx, word [ghostIndex]
        mov word [bx], 0
        mov bx, ghostWantGoDown
        add bx, word [ghostIndex]
        mov word [bx], 0
        mov bx, ghostPosition
        add bx, word [ghostIndex]
        mov ax, [bx]
        sub ax, 1
        
        mov bx, ghostPosTestColl
        add bx, word [ghostIndex]
        mov [bx], ax
        call collTest     
        cmp al, 0x10                ; test if the color is the same as the maze
        je ghostActualDirection

        mov bx, ghostPosTestColl
        add bx, word [ghostIndex]
        mov ax, [bx]
        add ax, 2880
        mov bx, ghostPosTestColl
        add bx, word [ghostIndex]
        mov [bx], ax
        call collTest 
        cmp al, 0x10            
        je ghostActualDirection

        mov bx, ghostPosTestColl
        add bx, word [ghostIndex]
        mov ax, [bx]
        sub ax, 960
        mov bx, ghostPosTestColl
        add bx, word [ghostIndex]
        mov [bx], ax
        call collTest 
        cmp al, 0x10            
        je ghostActualDirection

        jmp ghostMoveLeft

    ghostBeforeRight:
        mov bx, ghostWantGoLeft
        add bx, word [ghostIndex]
        mov word [bx], 0
        mov bx, ghostWantGoRight
        add bx, word [ghostIndex]
        mov word [bx], 1
        mov bx, ghostWantGoUp
        add bx, word [ghostIndex]
        mov word [bx], 0
        mov bx, ghostWantGoDown
        add bx, word [ghostIndex]
        mov word [bx], 0
        mov bx, ghostPosition
        add bx, word [ghostIndex]
        mov ax, [bx]
        add ax, 10
        mov bx, ghostPosTestColl
        add bx, word [ghostIndex]
        mov [bx], ax
        call collTest 
        cmp al, 0x10            
        je ghostActualDirection  
        mov bx, ghostPosTestColl
        add bx, word [ghostIndex]
        mov ax, [bx]
        add ax, 2880
        mov bx, ghostPosTestColl
        add bx, word [ghostIndex]
        mov [bx], ax
        call collTest 
        cmp al, 0x10            
        je ghostActualDirection 
        mov bx, ghostPosTestColl
        add bx, word [ghostIndex]
        mov ax, [bx]
        sub ax, 960
        mov bx, ghostPosTestColl
        add bx, word [ghostIndex]
        mov [bx], ax
        call collTest 
        cmp al, 0x10            
        je ghostActualDirection  

        jmp ghostMoveRight

    ghostBeforeUp:
        mov bx, ghostWantGoLeft
        add bx, word [ghostIndex]
        mov word [bx], 0
        mov bx, ghostWantGoRight
        add bx, word [ghostIndex]
        mov word [bx], 0
        mov bx, ghostWantGoUp
        add bx, word [ghostIndex]
        mov word [bx], 1
        mov bx, ghostWantGoDown
        add bx, word [ghostIndex]
        mov word [bx], 0
        mov bx, ghostPosition
        add bx, word [ghostIndex]
        mov ax, [bx]
        sub ax, 320
        mov bx, ghostPosTestColl
        add bx, word [ghostIndex]
        mov [bx], ax
        call collTest 
        cmp al, 0x10            
        je ghostActualDirection 
        mov bx, ghostPosTestColl
        add bx, word [ghostIndex]
        mov ax, [bx]
        add ax, 9
        mov bx, ghostPosTestColl
        add bx, word [ghostIndex]
        mov [bx], ax
        call collTest 
        cmp al, 0x10            
        je ghostActualDirection
        mov bx, ghostPosTestColl
        add bx, word [ghostIndex]
        mov ax, [bx]
        sub ax, 3
        mov bx, ghostPosTestColl
        add bx, word [ghostIndex]
        mov [bx], ax
        call collTest
        cmp al, 0x10            
        je ghostActualDirection

        jmp ghostMoveUp

    ghostBeforeDown:
        mov bx, ghostWantGoLeft
        add bx, word [ghostIndex]
        mov word [bx], 0
        mov bx, ghostWantGoRight
        add bx, word [ghostIndex]
        mov word [bx], 0
        mov bx, ghostWantGoUp
        add bx, word [ghostIndex]
        mov word [bx], 0
        mov bx, ghostWantGoDown
        add bx, word [ghostIndex]
        mov word [bx], 1
        mov bx, ghostPosition
        add bx, word [ghostIndex]
        mov ax, [bx]
        add ax, 3200
        mov bx, ghostPosTestColl
        add bx, word [ghostIndex]
        mov [bx], ax
        call collTest
        cmp al, 0x10            
        je ghostActualDirection  
        mov bx, ghostPosTestColl
        add bx, word [ghostIndex]
        mov ax, [bx]
        add ax, 9
        mov bx, ghostPosTestColl
        add bx, word [ghostIndex]
        mov [bx], ax
        call collTest 
        cmp al, 0x10            
        je ghostActualDirection 
        mov bx, ghostPosTestColl
        add bx, word [ghostIndex]
        mov ax, [bx]
        sub ax, 3
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
        mov bx, ghostWantGoLeft
        add bx, word [ghostIndex]
        cmp word [bx], 1
        je ghostBeforeLeft
        mov bx, ghostWantGoRight
        add bx, word [ghostIndex]
        cmp word [bx], 1
        je ghostBeforeRight
        mov bx, ghostWantGoUp
        add bx, word [ghostIndex]
        cmp word [bx], 1
        je ghostBeforeUp
        mov bx, ghostWantGoDown
        add bx, word [ghostIndex]
        cmp word [bx], 1
        je ghostBeforeDown
        jmp ghostActualDirection
    ; END CHECK WANTED MOVEMENT ----------
    ; ACTUAL DIRECTION --------------------
    ghostActualDirection:        ; test wich direction he is going
        mov bx, ghostGoLeft
        add bx, word [ghostIndex]
        cmp word [bx], 1
        je ghostMoveLeft
        mov bx, ghostGoRight
        add bx, word [ghostIndex]
        cmp word [bx], 1
        je ghostMoveRight
        mov bx, ghostGoUp
        add bx, word [ghostIndex]
        cmp word [bx], 1
        je ghostMoveUp
        mov bx, ghostGoDown
        add bx, word [ghostIndex]
        cmp word [bx], 1
        je ghostMoveDown
        jmp ghostMoveLeft
    ; END ACTUAL DIRECTION ----------------
    ; ACTUAL MOVEMENT ---------------------
    ghostMoveLeft:              
        mov bx, ghostGoLeft
        add bx, word [ghostIndex]
        mov word [bx], 1        ; use to save wich direction he is going
        mov bx, ghostGoRight
        add bx, word [ghostIndex]
        mov word [bx], 0       ;
        mov bx, ghostGoUp
        add bx, word [ghostIndex]
        mov word [bx], 0          ;
        mov bx, ghostGoDown
        add bx, word [ghostIndex]
        mov word [bx], 0        ;
        jmp ghostWCollLeft
    ghostContinueMoveLeft:
        call clearGhost
        jmp ghostAnimLeft

    ghostMoveRight:
        mov bx, ghostGoLeft
        add bx, word [ghostIndex]
        mov word [bx], 0 
        mov bx, ghostGoRight
        add bx, word [ghostIndex]
        mov word [bx], 1
        mov bx, ghostGoUp
        add bx, word [ghostIndex]
        mov word [bx], 0   
        mov bx, ghostGoDown
        add bx, word [ghostIndex]
        mov word [bx], 0       
        jmp ghostWCollRight
    ghostContinueMoveRight:
        call clearGhost
        jmp ghostAnimRight
    
    ghostMoveUp:
        mov bx, ghostGoLeft
        add bx, word [ghostIndex]
        mov word [bx], 0 
        mov bx, ghostGoRight
        add bx, word [ghostIndex]
        mov word [bx], 0
        mov bx, ghostGoUp
        add bx, word [ghostIndex]
        mov word [bx], 1   
        mov bx, ghostGoDown
        add bx, word [ghostIndex]
        mov word [bx], 0         
        jmp ghostWCollUp
    ghostContinueMoveUp:
        call clearGhost
        jmp ghostAnimUp

    ghostMoveDown:
        mov bx, ghostGoLeft
        add bx, word [ghostIndex]
        mov word [bx], 0 
        mov bx, ghostGoRight
        add bx, word [ghostIndex]
        mov word [bx], 0
        mov bx, ghostGoUp
        add bx, word [ghostIndex]
        mov word [bx], 0   
        mov bx, ghostGoDown
        add bx, word [ghostIndex]
        mov word [bx], 1        
        jmp ghostWCollDown
    ghostContinueMoveDown:
        call clearGhost
        jmp ghostAnimDown

    ghostTpRight:
        call clearGhost
        mov bx, ghostPosition
        add bx, word [ghostIndex]
        mov word [bx], 26473
        jmp ghostMoveLeft

    ghostTpLeft:
        call clearGhost
        mov bx, ghostPosition
        add bx, word [ghostIndex]
        mov word [bx], 26317
        jmp ghostMoveRight
    ; END ACTUAL MOVEMENT ----------------
; END PACMAN MOVEMENTS -------------------------------------------------

; PACMAN ANIMATIONS ----------------------------------------------------
    ; CHOICE ------------------------------
    ghostAnimLeft:               ; choose the right sprite to make the animation
         
        mov bx, ghostPosition
        add bx, word [ghostIndex]
        sub word [bx], 1

        mov bx, infrightmode
        add bx, word [ghostIndex]
        cmp word [bx], 1
        je drawFrightenGhost
        
        mov bx, ghostFrame
        add bx, word [ghostIndex]
        inc word [bx]
        cmp word [bx], 4
        jl ghostLeft2
        mov bx, ghostFrame
        add bx, word [ghostIndex]
        cmp word [bx], 8
        jl ghostLeft1
        mov bx, ghostFrame
        add bx, word [ghostIndex]
        mov word [bx], 0
        jmp ghostLeft2

    ghostAnimRight:
         
        mov bx, ghostPosition
        add bx, word [ghostIndex]
        add word [bx], 1
        
        mov bx, infrightmode
        add bx, word [ghostIndex]
        cmp word [bx], 1
        je drawFrightenGhost

        mov bx, ghostFrame
        add bx, word [ghostIndex]
        inc word [bx]
        cmp word [bx], 4
        jl ghostRight2
        mov bx, ghostFrame
        add bx, word [ghostIndex]
        cmp word [bx], 8
        jl ghostRight1
        mov bx, ghostFrame
        add bx, word [ghostIndex]
        mov word [bx], 0
        jmp ghostRight2

    ghostAnimUp:
        mov bx, ghostPosition
        add bx, word [ghostIndex]
        sub word [bx], 320
        
        mov bx, infrightmode
        add bx, word [ghostIndex]
        cmp word [bx], 1
        je drawFrightenGhost

        mov bx, ghostFrame
        add bx, word [ghostIndex]
        inc word [bx]
        cmp word [bx], 4
        jl ghostUp2
        mov bx, ghostFrame
        add bx, word [ghostIndex]
        cmp word [bx], 8
        jl ghostUp1
        mov bx, ghostFrame
        add bx, word [ghostIndex]
        mov word [bx], 0
        jmp ghostUp2

    ghostAnimDown:
        mov bx, ghostPosition
        add bx, word [ghostIndex]
        add word [bx], 320

        mov bx, infrightmode
        add bx, word [ghostIndex]
        cmp word [bx], 1
        je drawFrightenGhost

        mov bx, ghostFrame
        add bx, word [ghostIndex]
        inc word [bx]
        cmp word [bx], 4
        jl ghostDown2
        mov bx, ghostFrame
        add bx, word [ghostIndex]
        cmp word [bx], 8
        jl ghostDown1
        mov bx, ghostFrame
        add bx, word [ghostIndex]
        mov word [bx], 0
        jmp ghostDown2

    ; END CHOICE --------------------------
    ; SET ANIMATIONS ----------------------
    drawFrightenGhost:
        mov bx, frightmodetime
        add bx, word [ghostIndex]
        inc word [bx]
        cmp word [bx], 250
        jge frightModeAlmostFinished
        mov bx, ghostFrame
        add bx, word [ghostIndex]
        inc word [bx]
        cmp word [bx], 4
        jl ghostFrightB2
        mov bx, ghostFrame
        add bx, word [ghostIndex]
        cmp word [bx], 8
        jl ghostFrightB1
        mov bx, ghostFrame
        add bx, word [ghostIndex]
        mov word [bx], 0
        jmp ghostFrightB2

    frightModeAlmostFinished:
        mov bx, frightmodetime
        add bx, word [ghostIndex]
        inc word [bx]
        cmp word [bx], 350
        jge stopFrightMode
        mov bx, ghostFrame
        add bx, word [ghostIndex]
        inc word [bx]
        cmp word [bx], 4
        jl ghostFrightB2
        mov bx, ghostFrame
        add bx, word [ghostIndex]
        cmp word [bx], 8
        jl ghostFrightW1
        mov bx, ghostFrame
        add bx, word [ghostIndex]
        mov word [bx], 0
        jmp ghostFrightB2

    stopFrightMode:
        mov byte [nbeatedghosts], 1
        mov bx, infrightmode
        add bx, word [ghostIndex]
        mov word [bx], 0
        jmp nextGhost

    ghostFrightW1:
        mov si, frightW1
        mov bx, ghostPosition
        add bx, word [ghostIndex]
        mov di, [bx]
        call drawGhosts
        jmp nextGhost

    ghostFrightB1:
        mov si, frightB1
        mov bx, ghostPosition
        add bx, word [ghostIndex]
        mov di, [bx]
        call drawGhosts
        jmp nextGhost

    ghostFrightB2:
        mov si, frightB2
        mov bx, ghostPosition
        add bx, word [ghostIndex]
        mov di, [bx]
        call drawGhosts
        jmp nextGhost

    ghostLeft1:
        mov bx, ghost1L
        mov ax, [ghostIndex]
        add bx, ax
        mov si, [bx]
        mov bx, ghostPosition
        add bx, word [ghostIndex]
        mov di, [bx]
        call drawGhosts
        jmp nextGhost

    ghostLeft2:
        mov bx, ghost2L
        mov ax, [ghostIndex]
        add bx, ax
        mov si, [bx]
        mov bx, ghostPosition
        add bx, word [ghostIndex]
        mov di, [bx]
        call drawGhosts
        jmp nextGhost

    ghostRight1:
        mov bx, ghost1R
        mov ax, [ghostIndex]
        add bx, ax
        mov si, [bx]
        mov bx, ghostPosition
        add bx, word [ghostIndex]
        mov di, [bx]
        call drawGhosts
        jmp nextGhost

    ghostRight2:
        mov bx, ghost2R
        mov ax, [ghostIndex]
        add bx, ax
        mov si, [bx]
        mov bx, ghostPosition
        add bx, word [ghostIndex]
        mov di, [bx]
        call drawGhosts
        jmp nextGhost

    ghostUp1:
        mov bx, ghost1U
        mov ax, [ghostIndex]
        add bx, ax
        mov si, [bx]
        mov bx, ghostPosition
        add bx, word [ghostIndex]
        mov di, [bx]
        call drawGhosts
        jmp nextGhost

    ghostUp2:
        mov bx, ghost2U
        mov ax, [ghostIndex]
        add bx, ax
        mov si, [bx]
        mov bx, ghostPosition
        add bx, word [ghostIndex]
        mov di, [bx]
        call drawGhosts
        jmp nextGhost

    ghostDown1:
        mov bx, ghost1D
        mov ax, [ghostIndex]
        add bx, ax
        mov si, [bx]
        mov bx, ghostPosition
        add bx, word [ghostIndex]
        mov di, [bx]
        call drawGhosts
        jmp nextGhost

    ghostDown2:
        mov bx, ghost2D
        add bx, word [ghostIndex]
        mov si, [bx]

        mov bx, ghostPosition
        add bx, word [ghostIndex]
        mov di, [bx]

        call drawGhosts
        jmp nextGhost
    ; END SET ANIMATIONS ------------------
    clearGhost:
        mov si, clear
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

    isInFrightModeLeft:
        mov bx, infrightmode
        add bx, word [ghostIndex]
        mov ax, [bx]
        cmp ax, 0
        je pacDead
        jmp ghostsEated

    isInFrightModeRight:
        mov bx, infrightmode
        add bx, word [ghostIndex]
        mov ax, [bx]
        cmp ax, 0
        je pacDead
        jmp ghostsEated

    isInFrightModeUp:
        mov bx, infrightmode
        add bx, word [ghostIndex]
        mov ax, [bx]
        cmp ax, 0
        je pacDead
        jmp ghostsEated

    isInFrightModeDown:
        mov bx, infrightmode
        add bx, word [ghostIndex]
        mov ax, [bx]
        cmp ax, 0
        je pacDead
        jmp ghostsEated
; I'm keeping those regex here jsut in case.

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
