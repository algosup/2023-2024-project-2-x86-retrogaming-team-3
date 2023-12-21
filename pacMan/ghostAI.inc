section .data
    frameAI dw 0
            dw 0
            dw 0
            dw 0

    rand dw 0

section .text

Patern4:
    mov bx, frameAI
    add bx, word [ghostIndex]
    mov ax, [bx]
    inc word [bx]

    cmp word [bx], 10
    jl ghostBeforeRight

    cmp word [bx], 40
    jl ghostBeforeDown

    cmp word [bx], 60
    jl ghostBeforeRight

    cmp word [bx], 90
    jl ghostBeforeUp

    cmp word [bx], 190
    jl ghostBeforeLeft

    cmp word [bx], 200
    jl ghostBeforeDown

    cmp word [bx], 220
    jl ghostBeforeRight

    cmp word [bx], 240
    jl ghostBeforeDown

    cmp word [bx], 260
    jl ghostBeforeLeft

    cmp word [bx], 265
    jl ghostBeforeDown

    cmp word [bx], 360
    jl ghostBeforeLeft

    cmp word [bx], 390
    jl ghostBeforeUp

    cmp word [bx], 420
    jl ghostBeforeRight

    cmp word [bx], 470
    jl ghostBeforeUp

    cmp word [bx], 490
    jl ghostBeforeLeft

    cmp word [bx], 560
    jl ghostBeforeDown

    cmp word [bx], 620
    jl ghostBeforeRight

    cmp word [bx], 670
    jl ghostBeforeDown

    cmp word [bx], 690
    jl ghostBeforeRight

    cmp word [bx], 750
    jl ghostBeforeUp

    cmp word [bx], 781
    jl ghostBeforeRight

    mov word [bx], 0
    jmp Patern4

    Patern3:
        mov bx, frameAI
        add bx, word [ghostIndex]
        mov ax, [bx]
        inc word [bx]

        cmp word [bx], 5
        jl ghostBeforeLeft

        cmp word [bx], 25
        jl ghostBeforeUp

        cmp word [bx], 40
        jl ghostBeforeLeft

        cmp word [bx], 60
        jl ghostBeforeUp

        cmp word [bx], 90
        jl ghostBeforeLeft

        cmp word [bx], 130
        jl ghostBeforeDown

        cmp word [bx], 150
        jl ghostBeforeRight

        cmp word [bx], 230
        jl ghostBeforeDown

        cmp word [bx], 250
        jl ghostBeforeLeft

        cmp word [bx], 270
        jl ghostBeforeDown

        cmp word [bx], 290
        jl ghostBeforeRight

        cmp word [bx], 300
        jl ghostBeforeDown

        cmp word [bx], 320
        jl ghostBeforeLeft

        cmp word [bx], 330
        jl ghostBeforeDown

        cmp word [bx], 480
        jl ghostBeforeRight

        cmp word [bx], 500
        jl ghostBeforeUp

        cmp word [bx], 510
        jl ghostBeforeLeft

        cmp word [bx], 530
        jl ghostBeforeUp

        cmp word [bx], 540
        jl ghostBeforeRight

        cmp word [bx], 560
        jl ghostBeforeUp

        cmp word [bx], 580
        jl ghostBeforeLeft

        cmp word [bx], 620
        jl ghostBeforeUp

        cmp word [bx], 640
        jl ghostBeforeLeft

        cmp word [bx], 660
        jl ghostBeforeDown

        cmp word [bx], 720
        jl ghostBeforeLeft

        cmp word [bx], 730
        jl ghostBeforeUp

        cmp word [bx], 840
        jl ghostBeforeLeft

        cmp word [bx], 850
        jl ghostBeforeUp

        cmp word [bx], 889
        jl ghostBeforeLeft

        mov word [bx], 0
        jmp Patern3

    Patern2:
        mov bx, frameAI
        add bx, word [ghostIndex]
        mov ax, [bx]
        inc word [bx]
        cmp word [bx], 20
        jl ghostBeforeLeft
        cmp word [bx], 40
        jl ghostBeforeDown
        cmp word [bx], 80
        jl ghostBeforeRight
        cmp word [bx], 130
        jl ghostBeforeDown
        cmp word [bx], 145
        jl ghostBeforeLeft
        cmp word [bx], 160
        jl ghostBeforeDown
        cmp word [bx], 180
        jl ghostBeforeLeft
        cmp word [bx], 200
        jl ghostBeforeUp
        cmp word [bx], 240
        jl ghostBeforeLeft
        cmp word [bx], 270
        jl ghostBeforeUp
        cmp word [bx], 330
        jl ghostBeforeLeft
        cmp word [bx], 380
        jl ghostBeforeUp
        cmp word [bx], 400
        jl ghostBeforeRight
        cmp word [bx], 440
        jl ghostBeforeUp
        cmp word [bx], 510
        jl ghostBeforeLeft
        cmp word [bx], 530
        jl ghostBeforeDown
        cmp word [bx], 555
        jl ghostBeforeRight
        cmp word [bx], 570
        jl ghostBeforeDown
        cmp word [bx], 590
        jl ghostBeforeLeft
        cmp word [bx], 610
        jl ghostBeforeDown
        cmp word [bx], 640
        jl ghostBeforeLeft
        cmp word [bx], 700
        jl ghostBeforeDown
        cmp word [bx], 720
        jl ghostBeforeRight
        cmp word [bx], 730
        jl ghostBeforeDown
        cmp word [bx], 780
        jl ghostBeforeRight
        cmp word [bx], 810
        jl ghostBeforeDown
        cmp word [bx], 830
        jl ghostBeforeRight
        cmp word [bx], 840
        jl ghostBeforeUp
        cmp word [bx], 860
        jl ghostBeforeRight
        cmp word [bx], 870
        jl ghostBeforeUp
        cmp word [bx], 890
        jl ghostBeforeLeft
        cmp word [bx], 920
        jl ghostBeforeUp
        cmp word [bx], 960
        jl ghostBeforeLeft
        cmp word [bx], 980
        jl ghostBeforeUp
        cmp word [bx], 1009
        jl ghostBeforeLeft
        mov word [bx], 0
        jmp Patern2

    Patern1:
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
        cmp word [bx], 730
        jl ghostBeforeRight
        cmp word [bx], 750
        jl ghostBeforeUp
        cmp word [bx], 770
        jl ghostBeforeRight
        cmp word [bx], 785
        jl ghostBeforeUp
        cmp word [bx], 820
        jl ghostBeforeLeft
        cmp word [bx], 850
        jl ghostBeforeUp
        cmp word [bx], 920
        jl ghostBeforeLeft
        cmp word [bx], 940
        jl ghostBeforeDown
        cmp word [bx], 960
        jl ghostBeforeRight
        cmp word [bx], 1020
        jl ghostBeforeDown
        cmp word [bx], 1040
        jl ghostBeforeRight
        cmp word [bx], 1060
        jl ghostBeforeUp
        cmp word [bx], 1093
        jl ghostBeforeRight
        mov word [bx], 0
        jmp Patern1

    resetFrame:
        mov bx, frameAI
        add bx, word [ghostIndex]
        mov word [bx], 0
        ret
    
    setFrightMode:
        mov bx, infrightmode
        add bx, word [ghostIndex]
        mov word [bx], 1
        mov bx, frightmodetime
        add bx, word [ghostIndex]
        mov word [bx], 1
        ret

    resetFrightMode:
        mov bx, infrightmode
        add bx, word [ghostIndex]
        mov word [bx], 0
        mov bx, frightmodetime
        add bx, word [ghostIndex]
        mov word [bx], 1
        ret