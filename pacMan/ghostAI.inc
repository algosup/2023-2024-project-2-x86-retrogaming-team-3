section .data
    frameAI dw 0
            dw 0
            dw 0
            dw 0

    seed dw 12345 

section .text
    blinkyRandomAI:
        ;mov ax, [seed]
;
        ;mov cx, 25173
        ;mov dx, 13849
        ;imul ax, cx
        ;add ax, dx
        ;mov [seed], ax
;
;
        ;jmp collisionLeft
        jmp ghostBeforeLeft
    
    pinkyRandomAI:
        jmp ghostBeforeLeft
    
    inkyRandomAI:
        jmp ghostBeforeLeft
    
    clydeRandomAI:
        jmp ghostBeforeLeft


    collisionLeft:
        mov bx, ghostPosition
        add bx, word [ghostIndex]
        mov ax, [bx]  
        add ax, 1279 
        call collTest 
        cmp al, 0x10
        je blinkyRandomAI
        jmp ghostBeforeLeft

    collisionRight:
        mov bx, ghostPosition
        add bx, word [ghostIndex]
        mov ax, [bx]
        add ax, 1290
        call collTest
        cmp al, 0x10        
        je blinkyRandomAI
        jmp ghostBeforeRight

    collisionUp:
        mov bx, ghostPosition
        add bx, word [ghostIndex]
        mov ax, [bx]
        sub ax, 315
        call collTest
        cmp al, 0x10        
        je blinkyRandomAI
        jmp ghostBeforeUp

    collisionDown:
        mov bx, ghostPosition
        add bx, word [ghostIndex]
        mov ax, [bx]
        add ax, 3205
        call collTest
        cmp al, 0x10        
        je blinkyRandomAI
        jmp ghostBeforeDown

    