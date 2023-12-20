section .data
    frameAI dw 0
            dw 0
            dw 0
            dw 0

section .text
    blinkyRandomAI:
        jmp ghostBeforeLeft
    
    pinkyRandomAI:
        jmp ghostBeforeLeft
    
    inkyRandomAI:
        jmp ghostBeforeLeft
    
    clydeRandomAI:
        jmp ghostBeforeLeft
