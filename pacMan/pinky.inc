section .data
    blinkyInitposition dw 20635
    blinkyPosition dw 0

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
section .text
    blinkyMovement:
        je blinkyBeforeUp 
        jmp blinkyWantGoDirection
            
; INITIALISATION PACMAN ------------------------------------------------
    initBlinky:
        mov ax, [blinkyInitposition]
        mov word [blinkyPosition], ax
        mov di, [blinkyPosition]
        call drawGhosts
        ret
    
; END INITIALISATION PACMAN --------------------------------------------

; COLLISIONS -----------------------------------------------------------
    ; SIMPLE --------------------------
    BlinkyWCollLeft:                  ; collision for straight direction to stop when seing a wall 
        mov ax, [blinkyPosition]  
        add ax, 1279 
        call collTest 
        cmp al, 0x10            ; test if the color is the same as the maze
        je blinkyLeft1
        cmp al, 0x11
        je blinkyTpRight
        jmp blinkyContinueMoveLeft
        
    BlinkyWCollRight:
        mov ax, [blinkyPosition]
        add ax, 1290
        call collTest
        cmp al, 0x10        
        je blinkyRight1
        cmp al, 0x11
        je blinkyTpLeft
        jmp blinkyContinueMoveRight
        
    BlinkyWCollUp:
        mov ax, [blinkyPosition]
        sub ax, 315
        call collTest
        cmp al, 0x10        
        je blinkyUp1
        jmp blinkyContinueMoveUp

    BlinkyWCollDown:
        mov ax, [blinkyPosition]
        add ax, 3205
        call collTest
        cmp al, 0x10        
        je blinkyDown1
        jmp blinkyContinueMovedown
    ; END SIMPLE -----------------------
    ; COMPLEX --------------------------
    blinkyBeforeLeft:             ; collision test before turning, if collision is detected, save the direction for when he can turn
        mov byte [blinkyWantGoLeft], 1
        mov byte [blinkyWantGoRight], 0
        mov byte [blinkyWantGoUp], 0
        mov byte [blinkyWantGoDown], 0
        mov ax, [blinkyPosition]
        sub ax, 1
        mov [blinkyPosTestColl], ax
        call collTest     
        cmp al, 0x10                ; test if the color is the same as the maze
        je blinkyActualDirection  
        mov ax, [blinkyPosTestColl]
        add ax, 2880
        mov [blinkyPosTestColl], ax
        call collTest 
        cmp al, 0x10            
        je blinkyActualDirection 
        mov ax, [blinkyPosTestColl]
        sub ax, 960
        mov [blinkyPosTestColl], ax
        call collTest 
        cmp al, 0x10            
        je blinkyActualDirection
        jmp blinkyMoveLeft

    blinkyBeforeRight:
        mov byte [blinkyWantGoLeft], 0
        mov byte [blinkyWantGoRight], 1
        mov byte [blinkyWantGoUp], 0
        mov byte [blinkyWantGoDown], 0
        mov ax, [blinkyPosition]
        add ax, 10
        mov [blinkyPosTestColl], ax
        call collTest 
        cmp al, 0x10            
        je blinkyActualDirection  
        mov ax, [blinkyPosTestColl]
        add ax, 2880
        mov [blinkyPosTestColl], ax
        call collTest 
        cmp al, 0x10            
        je blinkyActualDirection 
        mov ax, [blinkyPosTestColl]
        sub ax, 960
        mov [blinkyPosTestColl], ax
        call collTest 
        cmp al, 0x10            
        je blinkyActualDirection  
        jmp blinkyMoveRight

    blinkyBeforeUp:
        mov byte [blinkyWantGoLeft], 0
        mov byte [blinkyWantGoRight], 0
        mov byte [blinkyWantGoUp], 1
        mov byte [blinkyWantGoDown], 0
        mov ax, [blinkyPosition]
        sub ax, 320
        mov [blinkyPosTestColl], ax
        call collTest 
        cmp al, 0x10            
        je blinkyActualDirection 
        mov ax, [blinkyPosTestColl]
        add ax, 9
        mov [blinkyPosTestColl], ax
        call collTest 
        cmp al, 0x10            
        je blinkyActualDirection
        mov ax, [blinkyPosTestColl]
        sub ax, 3
        mov [blinkyPosTestColl], ax
        call collTest
        cmp al, 0x10            
        je blinkyActualDirection
        jmp blinkyMoveUp

    blinkyBeforeDown:
        mov byte [blinkyWantGoLeft], 0
        mov byte [blinkyWantGoRight], 0
        mov byte [blinkyWantGoUp], 0
        mov byte [blinkyWantGoDown], 1
        mov ax, [blinkyPosition]
        add ax, 3200
        mov [blinkyPosTestColl], ax
        call collTest
        cmp al, 0x10            
        je blinkyActualDirection  
        mov ax, [blinkyPosTestColl]
        add ax, 9
        mov [blinkyPosTestColl], ax
        call collTest 
        cmp al, 0x10            
        je blinkyActualDirection 
        mov ax, [blinkyPosTestColl]
        sub ax, 3
        mov [blinkyPosTestColl], ax
        call collTest
        cmp al, 0x10            
        je blinkyActualDirection
        jmp blinkyMoveDown
    ; END COMPLEX -----------------------
; END COLLISIONS -------------------------------------------------------

; PACMAN MOVEMENTS -----------------------------------------------------
    ; CHECK WANTED MOVEMENT --------------
    blinkyWantGoDirection:            ; test wich direction he wants to go
        cmp byte [blinkyWantGoLeft], 1
        je blinkyBeforeLeft
        cmp byte [blinkyWantGoRight], 1
        je blinkyBeforeRight
        cmp byte [blinkyWantGoUp], 1
        je blinkyBeforeUp
        cmp byte [blinkyWantGoDown], 1
        je blinkyBeforeDown
        jmp blinkyActualDirection
    ; END CHECK WANTED MOVEMENT ----------
    ; ACTUAL DIRECTION --------------------
    blinkyActualDirection:        ; test wich direction he is going
        cmp byte [blinkyGoLeft], 1
        je blinkyMoveLeft
        cmp byte [blinkyGoRight], 1
        je blinkyMoveRight
        cmp byte [blinkyGoUp], 1
        je blinkyMoveUp
        cmp byte [blinkyGoDown], 1
        je blinkyMoveDown
        jmp blinkyMoveLeft
    ; END ACTUAL DIRECTION ----------------
    ; ACTUAL MOVEMENT ---------------------
    blinkyMoveLeft:              
        mov byte [blinkyGoLeft], 1        ; use to save wich direction he is going
        mov byte [blinkyGoRight], 0       ;
        mov byte [blinkyGoUp], 0          ;
        mov byte [blinkyGoDown], 0        ;
        jmp BlinkyWCollLeft
    blinkyContinueMoveLeft:
        call clearBlinky
        jmp blinkyAnimLeft

    blinkyMoveRight:
        mov byte [blinkyGoLeft], 0 
        mov byte [blinkyGoRight], 1
        mov byte [blinkyGoUp], 0   
        mov byte [blinkyGoDown], 0       
        jmp BlinkyWCollRight
    blinkyContinueMoveRight:
        call clearBlinky
        jmp blinkyAnimRight
    
    blinkyMoveUp:
        mov byte [blinkyGoLeft], 0 
        mov byte [blinkyGoRight], 0
        mov byte [blinkyGoUp], 1   
        mov byte [blinkyGoDown], 0         
        jmp BlinkyWCollUp
    blinkyContinueMoveUp:
        call clearBlinky
        jmp blinkyAnimUp

    blinkyMoveDown:
        mov byte [blinkyGoLeft], 0 
        mov byte [blinkyGoRight], 0
        mov byte [blinkyGoUp], 0   
        mov byte [blinkyGoDown], 1        
        jmp BlinkyWCollDown
    blinkyContinueMovedown:
        call clearBlinky
        jmp blinkyAnimDown

    blinkyTpRight:
        call clearBlinky
        mov word [blinkyPosition], 26473
        jmp blinkyMoveLeft

    blinkyTpLeft:
        call clearBlinky
        mov word [blinkyPosition], 26317
        jmp blinkyMoveRight
    ; END ACTUAL MOVEMENT ----------------
; END PACMAN MOVEMENTS -------------------------------------------------

; PACMAN ANIMATIONS ----------------------------------------------------
    ; CHOICE ------------------------------
    blinkyAnimLeft:               ; choose the right sprite to make the animation
        sub word [blinkyPosition], 1
        inc byte [blinkyFrame]
        cmp byte [blinkyFrame], 4
        jl blinkyLeft2
        cmp byte [blinkyFrame], 8
        jl blinkyLeft1
        mov byte [blinkyFrame], 0
        jmp blinkyLeft2

    blinkyAnimRight:
        add word [blinkyPosition], 1
        inc byte [blinkyFrame]
        cmp byte [blinkyFrame], 4
        jl blinkyRight2
        cmp byte [blinkyFrame], 8
        jl blinkyRight1
        mov byte [blinkyFrame], 0
        jmp blinkyRight2

    blinkyAnimUp:
        sub word [blinkyPosition], 320
        inc byte [blinkyFrame]
        cmp byte [blinkyFrame], 4
        jl blinkyUp2
        cmp byte [blinkyFrame], 8
        jl blinkyUp1
        mov byte [blinkyFrame], 0
        jmp blinkyUp2

    blinkyAnimDown:
        add word [blinkyPosition], 320
        inc byte [blinkyFrame]
        cmp byte [blinkyFrame], 4
        jl blinkyDown2
        cmp byte [blinkyFrame], 8
        jl blinkyDown1
        mov byte [blinkyFrame], 0
        jmp blinkyDown2

    ; END CHOICE --------------------------
    ; SET ANIMATIONS ----------------------

    blinkyLeft1:
        mov si, blinky1L
        mov di, [blinkyPosition]
        call drawGhosts
        jmp keyCheck

    blinkyLeft2:
        mov si, blinky2L
        mov di, [blinkyPosition]
        call drawGhosts
        jmp keyCheck

    blinkyRight1:
        mov si, blinky1R
        mov di, [blinkyPosition]
        call drawGhosts
        jmp keyCheck

    blinkyRight2:
        mov si, blinky2R
        mov di, [blinkyPosition]
        call drawGhosts
        jmp keyCheck

    blinkyUp1:
        mov si, blinky1U
        mov di, [blinkyPosition]
        call drawGhosts
        jmp keyCheck

    blinkyUp2:
        mov si, blinky2U
        mov di, [blinkyPosition]
        call drawGhosts
        jmp keyCheck

    blinkyDown1:
        mov si, blinky1D
        mov di, [blinkyPosition]
        call drawGhosts
        jmp keyCheck

    blinkyDown2:
        mov si, blinky2D
        mov di, [blinkyPosition]
        call drawGhosts
        jmp keyCheck
    ; END SET ANIMATIONS ------------------
    clearBlinky:
        mov si, clear
        mov di, [blinkyPosition]
        call drawGhosts
        ret
; END PACMAN ANIMATIONS ------------------------------------------------