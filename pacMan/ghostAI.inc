section .data
    lastTurn dw 1
             dw 1
             dw 1
             dw 1

    rand dw 0

section .text
    RandomAI:
        mov bx, lastTurn
        add bx, word [ghostIndex]
        cmp word [bx], 1
        je .canMakeChoices

        jmp ghostWantGoDirection


        .canMakeChoices:
            rdtsc
            mov [rand], ax

            mov bx, lastTurn
            add bx, word [ghostIndex]
            mov word [bx], 0

            mov bx, ghostGoLeft
            add bx, word [ghostIndex]
            cmp word [bx], 1
            je dontGoRight

            mov bx, ghostGoRight
            add bx, word [ghostIndex]
            cmp word [bx], 1
            je dontGoLeft

            mov bx, ghostGoUp
            add bx, word [ghostIndex]
            cmp word [bx], 1
            je dontGoDown

            mov bx, ghostGoDown
            add bx, word [ghostIndex]
            cmp word [bx], 1
            je dontGoUp

    dontGoRight:
        mov ax, [rand]
        cmp ax, 32767
        jb collisionDown
        jg collisionUp

    dontGoLeft:
        mov ax, [rand]
        cmp ax, 32767
        jb collisionDown
        jg collisionUp

    dontGoDown:
        mov ax, [rand]
        cmp ax, 32767
        jb collisionLeft
        jg collisionRight

    dontGoUp:
        mov ax, [rand]
        cmp ax, 32767
        jb collisionLeft
        jg collisionRight

    collisionLeft:
        mov bx, ghostPosition
        add bx, word [ghostIndex]
        mov ax, [bx]  
        add ax, 1279 
        call collTest 
        cmp al, 0x10
        je setRight
        jmp setLeft

    collisionRight:
        mov bx, ghostPosition
        add bx, word [ghostIndex]
        mov ax, [bx]
        add ax, 1290
        call collTest
        cmp al, 0x10        
        je setLeft
        jmp setRight

    collisionUp:
        mov bx, ghostPosition
        add bx, word [ghostIndex]
        mov ax, [bx]
        sub ax, 315
        call collTest
        cmp al, 0x10        
        je setDown
        jmp setUp

    collisionDown:
        mov bx, ghostPosition
        add bx, word [ghostIndex]
        mov ax, [bx]
        add ax, 3205
        call collTest
        cmp al, 0x10        
        je setUp
        jmp setDown

    setLeft:
        mov bx, ghostWantGoLeft
        add bx, word [ghostIndex]
        mov byte [bx], 1
        mov bx, ghostWantGoRight
        add bx, word [ghostIndex]
        mov byte [bx], 0
        mov bx, ghostWantGoUp
        add bx, word [ghostIndex]
        mov byte [bx], 0
        mov bx, ghostWantGoDown
        add bx, word [ghostIndex]
        mov byte [bx], 0
        jmp ghostWantGoDirection
    
    setRight:
        mov bx, ghostWantGoLeft
        add bx, word [ghostIndex]
        mov byte [bx], 0
        mov bx, ghostWantGoRight
        add bx, word [ghostIndex]
        mov byte [bx], 1
        mov bx, ghostWantGoUp
        add bx, word [ghostIndex]
        mov byte [bx], 0
        mov bx, ghostWantGoDown
        add bx, word [ghostIndex]
        mov byte [bx], 0
        jmp ghostWantGoDirection

    setUp:
        mov bx, ghostWantGoLeft
        add bx, word [ghostIndex]
        mov byte [bx], 0
        mov bx, ghostWantGoRight
        add bx, word [ghostIndex]
        mov byte [bx], 0
        mov bx, ghostWantGoUp
        add bx, word [ghostIndex]
        mov byte [bx], 1
        mov bx, ghostWantGoDown
        add bx, word [ghostIndex]
        mov byte [bx], 0
        jmp ghostWantGoDirection

    setDown:
        mov bx, ghostWantGoLeft
        add bx, word [ghostIndex]
        mov byte [bx], 0
        mov bx, ghostWantGoRight
        add bx, word [ghostIndex]
        mov byte [bx], 0
        mov bx, ghostWantGoUp
        add bx, word [ghostIndex]
        mov byte [bx], 0
        mov bx, ghostWantGoDown
        add bx, word [ghostIndex]
        mov byte [bx], 1
        jmp ghostWantGoDirection