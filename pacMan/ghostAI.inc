section .data
    frameAI dw 0
            dw 0
            dw 0
            dw 0

    rand dw 0

section .text
    RandomAI:
        mov bx, frameAI
        add bx, word [ghostIndex]
        mov ax, [bx]
        inc word [bx]

        cmp word [bx], 20
        jl ghostBeforeRight

        cmp word [bx], 40
        jl ghostBeforeDown

        cmp word [bx], 120
        jl ghostBeforeRight

        cmp word [bx], 140
        jl ghostBeforeDown

        cmp word [bx], 180
        jl ghostBeforeRight

        cmp word [bx], 205
        jl ghostBeforeDown

        cmp word [bx], 230
        jl ghostBeforeRight

        cmp word [bx], 260
        jl ghostBeforeDown

        cmp word [bx], 280
        jl ghostBeforeLeft

        cmp word [bx], 300
        jl ghostBeforeDown

        cmp word [bx], 390
        jl ghostBeforeLeft

        cmp word [bx], 410
        jl ghostBeforeUp

        cmp word [bx], 430
        jl ghostBeforeRight

        cmp word [bx], 580
        jl ghostBeforeUp

        cmp word [bx], 600
        jl ghostBeforeRight

        cmp word [bx], 640
        jl ghostBeforeDown

        cmp word [bx], 665
        jl ghostBeforeLeft

        cmp word [bx], 680
        jl ghostBeforeDown

        cmp word [bx], 700
        jl ghostBeforeRight

        cmp word [bx], 720
        jl ghostBeforeDown

        cmp word [bx], 734
        jl ghostBeforeRight

        mov word [bx], 0
        jmp RandomAI

    resetFrame:
        mov bx, frameAI
        add bx, word [ghostIndex]
        mov word [bx], 0
        ret
