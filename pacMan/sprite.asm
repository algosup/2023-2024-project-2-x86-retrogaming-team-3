org 100h

section .data
        pix db 0x2F
; ready sprites
        ready db 0x00,0x2C,0x2C,0x2C,0x2C,0x2C,0x2C,0x00,0x00,0x00,0x2C,0x2C,0x2C,0x2C,0x2C,0x2C,0x00,0x00,0x00,0x2C,0x2C,0x2C,0x00,0x00,0x00,0x2C,0x2C,0x2C,0x2C,0x2C,0x00,0x00,0x00,0x00,0x2C,0x2C,0x00,0x00,0x2C,0x2C,0x00,0x00,0x00,0x00,0x2C,0x2C,0x2C,0x00
              db 0x00,0x2C,0x2C,0x00,0x00,0x00,0x2C,0x2C,0x00,0x00,0x2C,0x2C,0x00,0x00,0x00,0x00,0x00,0x00,0x2C,0x2C,0x00,0x2C,0x2C,0x00,0x00,0x2C,0x2C,0x00,0x00,0x2C,0x2C,0x00,0x00,0x00,0x2C,0x2C,0x00,0x00,0x2C,0x2C,0x00,0x00,0x00,0x00,0x2C,0x2C,0x2C,0x00
              db 0x00,0x2C,0x2C,0x00,0x00,0x00,0x2C,0x2C,0x00,0x00,0x2C,0x2C,0x00,0x00,0x00,0x00,0x00,0x2C,0x2C,0x00,0x00,0x00,0x2C,0x2C,0x00,0x2C,0x2C,0x00,0x00,0x00,0x2C,0x2C,0x00,0x00,0x2C,0x2C,0x00,0x00,0x2C,0x2C,0x00,0x00,0x00,0x2C,0x2C,0x2C,0x00,0x00
              db 0x00,0x2C,0x2C,0x00,0x00,0x2C,0x2C,0x2C,0x00,0x00,0x2C,0x2C,0x2C,0x2C,0x2C,0x00,0x00,0x2C,0x2C,0x00,0x00,0x00,0x2C,0x2C,0x00,0x2C,0x2C,0x00,0x00,0x00,0x2C,0x2C,0x00,0x00,0x00,0x2C,0x2C,0x2C,0x2C,0x00,0x00,0x00,0x00,0x2C,0x2C,0x00,0x00,0x00
              db 0x00,0x2C,0x2C,0x2C,0x2C,0x2C,0x00,0x00,0x00,0x00,0x2C,0x2C,0x00,0x00,0x00,0x00,0x00,0x2C,0x2C,0x2C,0x2C,0x2C,0x2C,0x2C,0x00,0x2C,0x2C,0x00,0x00,0x00,0x2C,0x2C,0x00,0x00,0x00,0x00,0x2C,0x2C,0x00,0x00,0x00,0x00,0x00,0x2C,0x00,0x00,0x00,0x00
              db 0x00,0x2C,0x2C,0x00,0x2C,0x2C,0x2C,0x00,0x00,0x00,0x2C,0x2C,0x00,0x00,0x00,0x00,0x00,0x2C,0x2C,0x00,0x00,0x00,0x2C,0x2C,0x00,0x2C,0x2C,0x00,0x00,0x2C,0x2C,0x00,0x00,0x00,0x00,0x00,0x2C,0x2C,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
              db 0x00,0x2C,0x2C,0x00,0x00,0x2C,0x2C,0x2C,0x00,0x00,0x2C,0x2C,0x2C,0x2C,0x2C,0x2C,0x00,0x2C,0x2C,0x00,0x00,0x00,0x2C,0x2C,0x00,0x2C,0x2C,0x2C,0x2C,0x2C,0x00,0x00,0x00,0x00,0x00,0x00,0x2C,0x2C,0x00,0x00,0x00,0x00,0x2C,0x00,0x00,0x00,0x00,0x00

        clearready db 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
                   db 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
                   db 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
                   db 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
                   db 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
                   db 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
                   db 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
; end ready sprites
; clear pacman/ghosts
        clear db 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
              db 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
              db 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
              db 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
              db 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
              db 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
              db 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
              db 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
              db 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
              db 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
              db 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
              db 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
              
;PacMan's movement animations.
        ;Starting pacman
        pacManStart  db 0x00, 0x00, 0x00, 0x2C, 0x2C, 0x2C, 0x2C, 0x00, 0x00, 0x00
                     db 0x00, 0x2C, 0x2C, 0x2C, 0x2C, 0x2C, 0x2C, 0x2C, 0x2C, 0x00
                     db 0x00, 0x2C, 0x2C, 0x2C, 0x2C, 0x2C, 0x2C, 0x2C, 0x2C, 0x00
                     db 0x2C, 0x2C, 0x2C, 0x2C, 0x2C, 0x2C, 0x2C, 0x2C, 0x2C, 0x2C
                     db 0x2C, 0x2C, 0x2C, 0x2C, 0x2C, 0x2C, 0x2C, 0x2C, 0x2C, 0x2C
                     db 0x2C, 0x2C, 0x2C, 0x2C, 0x2C, 0x2C, 0x2C, 0x2C, 0x2C, 0x2C
                     db 0x2C, 0x2C, 0x2C, 0x2C, 0x2C, 0x2C, 0x2C, 0x2C, 0x2C, 0x2C
                     db 0x00, 0x2C, 0x2C, 0x2C, 0x2C, 0x2C, 0x2C, 0x2C, 0x2C, 0x00
                     db 0x00, 0x2C, 0x2C, 0x2C, 0x2C, 0x2C, 0x2C, 0x2C, 0x2C, 0x00
                     db 0x00, 0x00, 0x00, 0x2C, 0x2C, 0x2C, 0x2C, 0x00, 0x00, 0x00

        ;Move Down
        pacManWaka1D  db 0x00, 0x00, 0x00, 0x2C, 0x2C, 0x2C, 0x2C, 0x00, 0x00, 0x00
                      db 0x00, 0x2C, 0x2C, 0x2C, 0x2C, 0x2C, 0x2C, 0x2C, 0x2C, 0x00
                      db 0x00, 0x2C, 0x2C, 0x2C, 0x2C, 0x2C, 0x2C, 0x2C, 0x2C, 0x00
                      db 0x2C, 0x2C, 0x2C, 0x2C, 0x2C, 0x2C, 0x2C, 0x2C, 0x2C, 0x2C
                      db 0x2C, 0x2C, 0x2C, 0x2C, 0x00, 0x00, 0x2C, 0x2C, 0x2C, 0x2C
                      db 0x2C, 0x2C, 0x2C, 0x2C, 0x00, 0x00, 0x2C, 0x2C, 0x2C, 0x2C
                      db 0x2C, 0x2C, 0x2C, 0x2C, 0x00, 0x00, 0x2C, 0x2C, 0x2C, 0x2C
                      db 0x00, 0x2C, 0x2C, 0x00, 0x00, 0x00, 0x00, 0x2C, 0x2C, 0x00
                      db 0x00, 0x2C, 0x2C, 0x00, 0x00, 0x00, 0x00, 0x2C, 0x2C, 0x00
                      db 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00

        pacManWaka2D  db 0x00, 0x00, 0x00, 0x2C, 0x2C, 0x2C, 0x2C, 0x00, 0x00, 0x00
                      db 0x00, 0x2C, 0x2C, 0x2C, 0x2C, 0x2C, 0x2C, 0x2C, 0x2C, 0x00
                      db 0x00, 0x2C, 0x2C, 0x2C, 0x2C, 0x2C, 0x2C, 0x2C, 0x2C, 0x00
                      db 0x2C, 0x2C, 0x2C, 0x2C, 0x2C, 0x2C, 0x2C, 0x2C, 0x2C, 0x2C
                      db 0x2C, 0x2C, 0x2C, 0x2C, 0x00, 0x00, 0x2C, 0x2C, 0x2C, 0x2C
                      db 0x2C, 0x2C, 0x2C, 0x00, 0x00, 0x00, 0x00, 0x2C, 0x2C, 0x2C
                      db 0x2C, 0x2C, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x2C, 0x2C
                      db 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
                      db 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
                      db 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00

        ;Move Up
        pacManWaka1U  db 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
                      db 0x00, 0x2C, 0x2C, 0x00, 0x00, 0x00, 0x00, 0x2C, 0x2C, 0x00
                      db 0x00, 0x2C, 0x2C, 0x00, 0x00, 0x00, 0x00, 0x2C, 0x2C, 0x00
                      db 0x2C, 0x2C, 0x2C, 0x2C, 0x00, 0x00, 0x2C, 0x2C, 0x2C, 0x2C
                      db 0x2C, 0x2C, 0x2C, 0x2C, 0x00, 0x00, 0x2C, 0x2C, 0x2C, 0x2C
                      db 0x2C, 0x2C, 0x2C, 0x2C, 0x00, 0x00, 0x2C, 0x2C, 0x2C, 0x2C
                      db 0x2C, 0x2C, 0x2C, 0x2C, 0x2C, 0x2C, 0x2C, 0x2C, 0x2C, 0x2C
                      db 0x00, 0x2C, 0x2C, 0x2C, 0x2C, 0x2C, 0x2C, 0x2C, 0x2C, 0x00
                      db 0x00, 0x2C, 0x2C, 0x2C, 0x2C, 0x2C, 0x2C, 0x2C, 0x2C, 0x00
                      db 0x00, 0x00, 0x00, 0x2C, 0x2C, 0x2C, 0x2C, 0x00, 0x00, 0x00

        pacManWaka2U  db 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
                      db 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
                      db 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
                      db 0x2C, 0x2C, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x2C, 0x2C
                      db 0x2C, 0x2C, 0x2C, 0x00, 0x00, 0x00, 0x00, 0x2C, 0x2C, 0x2C
                      db 0x2C, 0x2C, 0x2C, 0x2C, 0x00, 0x00, 0x2C, 0x2C, 0x2C, 0x2C
                      db 0x2C, 0x2C, 0x2C, 0x2C, 0x2C, 0x2C, 0x2C, 0x2C, 0x2C, 0x2C
                      db 0x00, 0x2C, 0x2C, 0x2C, 0x2C, 0x2C, 0x2C, 0x2C, 0x2C, 0x00
                      db 0x00, 0x2C, 0x2C, 0x2C, 0x2C, 0x2C, 0x2C, 0x2C, 0x2C, 0x00
                      db 0x00, 0x00, 0x00, 0x2C, 0x2C, 0x2C, 0x2C, 0x00, 0x00, 0x00

        ;Move Left                
        pacManWaka1L db 0x00, 0x00, 0x00, 0x2C, 0x2C, 0x2C, 0x2C, 0x00, 0x00, 0x00
                     db 0x00, 0x2C, 0x2C, 0x2C, 0x2C, 0x2C, 0x2C, 0x2C, 0x2C, 0x00
                     db 0x00, 0x2C, 0x2C, 0x2C, 0x2C, 0x2C, 0x2C, 0x2C, 0x2C, 0x00
                     db 0x00, 0x00, 0x00, 0x2C, 0x2C, 0x2C, 0x2C, 0x2C, 0x2C, 0x2C
                     db 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x2C, 0x2C, 0x2C, 0x2C
                     db 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x2C, 0x2C, 0x2C, 0x2C
                     db 0x00, 0x00, 0x00, 0x2C, 0x2C, 0x2C, 0x2C, 0x2C, 0x2C, 0x2C
                     db 0x00, 0x2C, 0x2C, 0x2C, 0x2C, 0x2C, 0x2C, 0x2C, 0x2C, 0x00
                     db 0x00, 0x2C, 0x2C, 0x2C, 0x2C, 0x2C, 0x2C, 0x2C, 0x2C, 0x00
                     db 0x00, 0x00, 0x00, 0x2C, 0x2C, 0x2C, 0x2C, 0x00, 0x00, 0x00

        pacManWaka2L db 0x00, 0x00, 0x00, 0x2C, 0x2C, 0x2C, 0x2C, 0x00, 0x00, 0x00
                     db 0x00, 0x00, 0x00, 0x2C, 0x2C, 0x2C, 0x2C, 0x2C, 0x2C, 0x00
                     db 0x00, 0x00, 0x00, 0x00, 0x2C, 0x2C, 0x2C, 0x2C, 0x2C, 0x00
                     db 0x00, 0x00, 0x00, 0x00, 0x00, 0x2C, 0x2C, 0x2C, 0x2C, 0x2C
                     db 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x2C, 0x2C, 0x2C, 0x2C
                     db 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x2C, 0x2C, 0x2C, 0x2C
                     db 0x00, 0x00, 0x00, 0x00, 0x00, 0x2C, 0x2C, 0x2C, 0x2C, 0x2C
                     db 0x00, 0x00, 0x00, 0x00, 0x2C, 0x2C, 0x2C, 0x2C, 0x2C, 0x00
                     db 0x00, 0x00, 0x00, 0x2C, 0x2C, 0x2C, 0x2C, 0x2C, 0x2C, 0x00
                     db 0x00, 0x00, 0x00, 0x2C, 0x2C, 0x2C, 0x2C, 0x00, 0x00, 0x00

        ;Move Right
        pacManWaka1R db 0x00, 0x00, 0x00, 0x2C, 0x2C, 0x2C, 0x2C, 0x00, 0x00, 0x00
                     db 0x00, 0x2C, 0x2C, 0x2C, 0x2C, 0x2C, 0x2C, 0x2C, 0x2C, 0x00
                     db 0x00, 0x2C, 0x2C, 0x2C, 0x2C, 0x2C, 0x2C, 0x2C, 0x2C, 0x00
                     db 0x2C, 0x2C, 0x2C, 0x2C, 0x2C, 0x2C, 0x2C, 0x00, 0x00, 0x00
                     db 0x2C, 0x2C, 0x2C, 0x2C, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
                     db 0x2C, 0x2C, 0x2C, 0x2C, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
                     db 0x2C, 0x2C, 0x2C, 0x2C, 0x2C, 0x2C, 0x2C, 0x00, 0x00, 0x00
                     db 0x00, 0x2C, 0x2C, 0x2C, 0x2C, 0x2C, 0x2C, 0x2C, 0x2C, 0x00
                     db 0x00, 0x2C, 0x2C, 0x2C, 0x2C, 0x2C, 0x2C, 0x2C, 0x2C, 0x00
                     db 0x00, 0x00, 0x00, 0x2C, 0x2C, 0x2C, 0x2C, 0x00, 0x00, 0x00


        pacManWaka2R db 0x00, 0x00, 0x00, 0x2C, 0x2C, 0x2C, 0x2C, 0x00, 0x00, 0x00
                     db 0x00, 0x2C, 0x2C, 0x2C, 0x2C, 0x2C, 0x2C, 0x00, 0x00, 0x00
                     db 0x00, 0x2C, 0x2C, 0x2C, 0x2C, 0x2C, 0x00, 0x00, 0x00, 0x00
                     db 0x2C, 0x2C, 0x2C, 0x2C, 0x2C, 0x00, 0x00, 0x00, 0x00, 0x00
                     db 0x2C, 0x2C, 0x2C, 0x2C, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
                     db 0x2C, 0x2C, 0x2C, 0x2C, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
                     db 0x2C, 0x2C, 0x2C, 0x2C, 0x2C, 0x00, 0x00, 0x00, 0x00, 0x00
                     db 0x00, 0x2C, 0x2C, 0x2C, 0x2C, 0x2C, 0x00, 0x00, 0x00, 0x00
                     db 0x00, 0x2C, 0x2C, 0x2C, 0x2C, 0x2C, 0x2C, 0x00, 0x00, 0x00
                     db 0x00, 0x00, 0x00, 0x2C, 0x2C, 0x2C, 0x2C, 0x00, 0x00, 0x00

;PacMan's Death
        death0  db 0x00, 0x00, 0x00, 0x00, 0x2C, 0x2C, 0x2C, 0x2C, 0x00, 0x00, 0x00, 0x00
                db 0x00, 0x00, 0x2C, 0x2C, 0x2C, 0x2C, 0x2C, 0x2C, 0x2C, 0x2C, 0x00, 0x00
                db 0x00, 0x00, 0x2C, 0x2C, 0x2C, 0x2C, 0x2C, 0x2C, 0x2C, 0x2C, 0x00, 0x00
                db 0x00, 0x2C, 0x2C, 0x2C, 0x2C, 0x2C, 0x2C, 0x2C, 0x2C, 0x2C, 0x2C, 0x00
                db 0x00, 0x2C, 0x2C, 0x2C, 0x2C, 0x2C, 0x2C, 0x2C, 0x2C, 0x2C, 0x2C, 0x00
                db 0x00, 0x2C, 0x2C, 0x2C, 0x2C, 0x2C, 0x2C, 0x2C, 0x2C, 0x2C, 0x2C, 0x00
                db 0x00, 0x2C, 0x2C, 0x2C, 0x2C, 0x2C, 0x2C, 0x2C, 0x2C, 0x2C, 0x2C, 0x00
                db 0x00, 0x00, 0x2C, 0x2C, 0x2C, 0x2C, 0x2C, 0x2C, 0x2C, 0x2C, 0x00, 0x00
                db 0x00, 0x00, 0x2C, 0x2C, 0x2C, 0x2C, 0x2C, 0x2C, 0x2C, 0x2C, 0x00, 0x00
                db 0x00, 0x00, 0x00, 0x00, 0x2C, 0x2C, 0x2C, 0x2C, 0x00, 0x00, 0x00, 0x00
                db 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00

        death1  db 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
                db 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
                db 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
                db 0x00, 0x2C, 0x2C, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x2C, 0x2C, 0x00
                db 0x00, 0x2C, 0x2C, 0x2C, 0x00, 0x00, 0x00, 0x00, 0x2C, 0x2C, 0x2C, 0x00
                db 0x00, 0x2C, 0x2C, 0x2C, 0x2C, 0x00, 0x00, 0x2C, 0x2C, 0x2C, 0x2C, 0x00
                db 0x00, 0x2C, 0x2C, 0x2C, 0x2C, 0x2C, 0x2C, 0x2C, 0x2C, 0x2C, 0x2C, 0x00
                db 0x00, 0x00, 0x2C, 0x2C, 0x2C, 0x2C, 0x2C, 0x2C, 0x2C, 0x2C, 0x00, 0x00
                db 0x00, 0x00, 0x2C, 0x2C, 0x2C, 0x2C, 0x2C, 0x2C, 0x2C, 0x2C, 0x00, 0x00
                db 0x00, 0x00, 0x00, 0x00, 0x2C, 0x2C, 0x2C, 0x2C, 0x00, 0x00, 0x00, 0x00
                db 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00

        death2  db 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
                db 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
                db 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
                db 0x00, 0x2C, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x2C, 0x00
                db 0x2C, 0x2C, 0x2C, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x2C, 0x2C, 0x2C
                db 0x2C, 0x2C, 0x2C, 0x2C, 0x2C, 0x00, 0x00, 0x2C, 0x2C, 0x2C, 0x2C, 0x2C
                db 0x2C, 0x2C, 0x2C, 0x2C, 0x2C, 0x2C, 0x2C, 0x2C, 0x2C, 0x2C, 0x2C, 0x2C
                db 0x00, 0x2C, 0x2C, 0x2C, 0x2C, 0x2C, 0x2C, 0x2C, 0x2C, 0x2C, 0x2C, 0x00
                db 0x00, 0x00, 0x2C, 0x2C, 0x2C, 0x2C, 0x2C, 0x2C, 0x2C, 0x2C, 0x00, 0x00
                db 0x00, 0x00, 0x00, 0x00, 0x2C, 0x2C, 0x2C, 0x2C, 0x00, 0x00, 0x00, 0x00
                db 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00

        death3  db 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
                db 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
                db 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
                db 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
                db 0x2C, 0x2C, 0x2C, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x2C, 0x2C, 0x2C
                db 0x2C, 0x2C, 0x2C, 0x2C, 0x2C, 0x00, 0x00, 0x2C, 0x2C, 0x2C, 0x2C, 0x2C
                db 0x2C, 0x2C, 0x2C, 0x2C, 0x2C, 0x2C, 0x2C, 0x2C, 0x2C, 0x2C, 0x2C, 0x2C
                db 0x00, 0x2C, 0x2C, 0x2C, 0x2C, 0x2C, 0x2C, 0x2C, 0x2C, 0x2C, 0x2C, 0x00
                db 0x00, 0x00, 0x2C, 0x2C, 0x2C, 0x2C, 0x2C, 0x2C, 0x2C, 0x2C, 0x00, 0x00
                db 0x00, 0x00, 0x00, 0x2C, 0x2C, 0x00, 0x00, 0x2C, 0x2C, 0x00, 0x00, 0x00
                db 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00

        death4  db 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
                db 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
                db 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
                db 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
                db 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
                db 0x2C, 0x2C, 0x2C, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x2C, 0x2C, 0x2C
                db 0x2C, 0x2C, 0x2C, 0x2C, 0x2C, 0x2C, 0x2C, 0x2C, 0x2C, 0x2C, 0x2C, 0x2C
                db 0x2C, 0x2C, 0x2C, 0x2C, 0x2C, 0x2C, 0x2C, 0x2C, 0x2C, 0x2C, 0x2C, 0x2C
                db 0x00, 0x2C, 0x2C, 0x2C, 0x2C, 0x2C, 0x2C, 0x2C, 0x2C, 0x2C, 0x2C, 0x00
                db 0x00, 0x00, 0x00, 0x2C, 0x2C, 0x00, 0x00, 0x2C, 0x2C, 0x00, 0x00, 0x00
                db 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00

        death5  db 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
                db 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
                db 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
                db 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
                db 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
                db 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
                db 0x00, 0x00, 0x2C, 0x2C, 0x2C, 0x2C, 0x2C, 0x2C, 0x2C, 0x2C, 0x00, 0x00
                db 0x2C, 0x2C, 0x2C, 0x2C, 0x2C, 0x2C, 0x2C, 0x2C, 0x2C, 0x2C, 0x2C, 0x2C
                db 0x00, 0x2C, 0x2C, 0x2C, 0x2C, 0x2C, 0x2C, 0x2C, 0x2C, 0x2C, 0x2C, 0x00
                db 0x00, 0x00, 0x00, 0x2C, 0x2C, 0x00, 0x00, 0x2C, 0x2C, 0x00, 0x00, 0x00
                db 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00

        death6  db 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
                db 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
                db 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
                db 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
                db 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
                db 0x00, 0x00, 0x00, 0x00, 0x00, 0x2C, 0x2C, 0x00, 0x00, 0x00, 0x00, 0x00
                db 0x00, 0x00, 0x00, 0x2C, 0x2C, 0x2C, 0x2C, 0x2C, 0x2C, 0x00, 0x00, 0x00
                db 0x00, 0x2C, 0x2C, 0x2C, 0x2C, 0x2C, 0x2C, 0x2C, 0x2C, 0x2C, 0x2C, 0x00
                db 0x2C, 0x2C, 0x2C, 0x2C, 0x2C, 0x00, 0x00, 0x2C, 0x2C, 0x2C, 0x2C, 0x2C
                db 0x00, 0x00, 0x2C, 0x2C, 0x00, 0x00, 0x00, 0x00, 0x2C, 0x2C, 0x00, 0x00
                db 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00

        death7  db 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
                db 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
                db 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
                db 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
                db 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
                db 0x00, 0x00, 0x00, 0x00, 0x00, 0x2C, 0x2C, 0x00, 0x00, 0x00, 0x00, 0x00
                db 0x00, 0x00, 0x00, 0x2C, 0x2C, 0x2C, 0x2C, 0x2C, 0x2C, 0x00, 0x00, 0x00
                db 0x00, 0x00, 0x2C, 0x2C, 0x2C, 0x2C, 0x2C, 0x2C, 0x2C, 0x2C, 0x00, 0x00
                db 0x2C, 0x2C, 0x2C, 0x2C, 0x2C, 0x00, 0x00, 0x2C, 0x2C, 0x2C, 0x2C, 0x2C
                db 0x00, 0x2C, 0x2C, 0x2C, 0x00, 0x00, 0x00, 0x00, 0x2C, 0x2C, 0x2C, 0x00
                db 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00

        death8  db 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
                db 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
                db 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
                db 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
                db 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x2C, 0x00, 0x00, 0x00, 0x00, 0x00
                db 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x2C, 0x00, 0x00, 0x00, 0x00, 0x00
                db 0x00, 0x00, 0x00, 0x00, 0x00, 0x2C, 0x2C, 0x2C, 0x00, 0x00, 0x00, 0x00
                db 0x00, 0x00, 0x00, 0x00, 0x00, 0x2C, 0x2C, 0x2C, 0x00, 0x00, 0x00, 0x00
                db 0x00, 0x00, 0x00, 0x00, 0x2C, 0x2C, 0x2C, 0x2C, 0x2C, 0x00, 0x00, 0x00
                db 0x00, 0x00, 0x00, 0x00, 0x00, 0x2C, 0x00, 0x2C, 0x00, 0x00, 0x00, 0x00
                db 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00

        death9  db 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
                db 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
                db 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
                db 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
                db 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x2C, 0x00, 0x00, 0x00, 0x00, 0x00
                db 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x2C, 0x00, 0x00, 0x00, 0x00, 0x00
                db 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x2C, 0x00, 0x00, 0x00, 0x00, 0x00
                db 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x2C, 0x00, 0x00, 0x00, 0x00, 0x00
                db 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x2C, 0x00, 0x00, 0x00, 0x00, 0x00
                db 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
                db 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00

        death10 db 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
                db 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
                db 0x00, 0x00, 0x00, 0x00, 0x2C, 0x00, 0x00, 0x00, 0x2C, 0x00, 0x00, 0x00
                db 0x00, 0x00, 0x00, 0x00, 0x00, 0x2C, 0x00, 0x2C, 0x00, 0x00, 0x00, 0x00
                db 0x00, 0x00, 0x00, 0x2C, 0x00, 0x00, 0x00, 0x00, 0x00, 0x2C, 0x00, 0x00
                db 0x00, 0x00, 0x00, 0x00, 0x2C, 0x00, 0x00, 0x00, 0x2C, 0x00, 0x00, 0x00
                db 0x00, 0x00, 0x2C, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x2C, 0x00
                db 0x00, 0x00, 0x00, 0x00, 0x2C, 0x00, 0x00, 0x00, 0x2C, 0x00, 0x00, 0x00
                db 0x00, 0x00, 0x00, 0x2C, 0x00, 0x00, 0x00, 0x00, 0x00, 0x2C, 0x00, 0x00
                db 0x00, 0x00, 0x00, 0x00, 0x00, 0x2C, 0x00, 0x2C, 0x00, 0x00, 0x00, 0x00
                db 0x00, 0x00, 0x00, 0x00, 0x2C, 0x00, 0x00, 0x00, 0x2C, 0x00, 0x00, 0x00

;Fruits
        ;Cherry
        cherry16 db 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x06, 0x06
                 db 0x00, 0x00, 0x00, 0x00, 0x00, 0x06, 0x06, 0x06, 0x06
                 db 0x00, 0x00, 0x00, 0x00, 0x06, 0x00, 0x06, 0x00, 0x00
                 db 0x00, 0x00, 0x00, 0x06, 0x00, 0x00, 0x06, 0x00, 0x00
                 db 0x00, 0x28, 0x06, 0x28, 0x00, 0x28, 0x06, 0x28, 0x00
                 db 0x28, 0x28, 0x28, 0x28, 0x28, 0x28, 0x28, 0x28, 0x28
                 db 0x28, 0x0F, 0x28, 0x28, 0x28, 0x28, 0x28, 0x28, 0x28
                 db 0x00, 0x28, 0x28, 0x00, 0x28, 0x0F, 0x0F, 0x28, 0x28
                 db 0x00, 0x00, 0x00, 0x00, 0x00, 0x28, 0x28, 0x28, 0x00

; Gums sprites
        ;superGum
        superGum db 0x00, 0x57, 0x57, 0x57, 0x57, 0x00
                 db 0x57, 0x57, 0x57, 0x57, 0x57, 0x57
                 db 0x57, 0x57, 0x57, 0x57, 0x57, 0x57
                 db 0x57, 0x57, 0x57, 0x57, 0x57, 0x57
                 db 0x57, 0x57, 0x57, 0x57, 0x57, 0x57
                 db 0x00, 0x57, 0x57, 0x57, 0x57, 0x00

        ;gum
        gum db 0x57, 0x57
            db 0x57, 0x57

   ; maze patterns sprite ------------------------------------------------
    ; simple wall
    smplwall1 db 0x00,0x00,0x00,0x00,0x00,0x00 ; 10
              db 0x00,0x00,0x00,0x00,0x00,0x00
              db 0x10,0x10,0x10,0x10,0x10,0x10
              db 0x20,0x20,0x20,0x20,0x20,0x20
              db 0x00,0x00,0x00,0x00,0x00,0x00
              db 0x00,0x00,0x00,0x00,0x00,0x00

    smplwall2 db 0x00,0x00,0x00,0x00,0x00,0x00 ; 11
              db 0x00,0x00,0x00,0x00,0x00,0x00
              db 0x20,0x20,0x20,0x20,0x20,0x20
              db 0x10,0x10,0x10,0x10,0x10,0x10
              db 0x00,0x00,0x00,0x00,0x00,0x00
              db 0x00,0x00,0x00,0x00,0x00,0x00
             
    smplwall3 db 0x00,0x00,0x20,0x10,0x00,0x00 ; 12
              db 0x00,0x00,0x20,0x10,0x00,0x00
              db 0x00,0x00,0x20,0x10,0x00,0x00
              db 0x00,0x00,0x20,0x10,0x00,0x00
              db 0x00,0x00,0x20,0x10,0x00,0x00
              db 0x00,0x00,0x20,0x10,0x00,0x00

    smplwall4 db 0x00,0x00,0x10,0x20,0x00,0x00 ; 13
              db 0x00,0x00,0x10,0x20,0x00,0x00
              db 0x00,0x00,0x10,0x20,0x00,0x00
              db 0x00,0x00,0x10,0x20,0x00,0x00
              db 0x00,0x00,0x10,0x20,0x00,0x00
              db 0x00,0x00,0x10,0x20,0x00,0x00
    
    ; simple angle backward
    smplangle11 db 0x00,0x00,0x00,0x00,0x00,0x00 ; 14
                db 0x00,0x00,0x00,0x00,0x00,0x00
                db 0x00,0x00,0x10,0x10,0x10,0x10
                db 0x00,0x00,0x10,0x00,0x00,0x20
                db 0x00,0x00,0x10,0x00,0x20,0x00
                db 0x00,0x00,0x10,0x20,0x00,0x00

    smplangle12 db 0x00,0x00,0x00,0x00,0x00,0x00 ; 15
                db 0x00,0x00,0x00,0x00,0x00,0x00 
                db 0x10,0x10,0x10,0x10,0x00,0x00 
                db 0x20,0x00,0x00,0x10,0x00,0x00 
                db 0x00,0x20,0x00,0x10,0x00,0x00 
                db 0x00,0x00,0x20,0x10,0x00,0x00 

    smplangle13 db 0x00,0x00,0x20,0x10,0x00,0x00 ; 16
                db 0x00,0x20,0x00,0x10,0x00,0x00
                db 0x20,0x00,0x00,0x10,0x00,0x00
                db 0x10,0x10,0x10,0x10,0x00,0x00
                db 0x00,0x00,0x00,0x00,0x00,0x00
                db 0x00,0x00,0x00,0x00,0x00,0x00

    smplangle14 db 0x00,0x00,0x10,0x20,0x00,0x00; 17
                db 0x00,0x00,0x10,0x00,0x20,0x00
                db 0x00,0x00,0x10,0x00,0x00,0x20
                db 0x00,0x00,0x10,0x10,0x10,0x10
                db 0x00,0x00,0x00,0x00,0x00,0x00
                db 0x00,0x00,0x00,0x00,0x00,0x00

    ; simple angle forward
    smplangle21 db 0x00,0x00,0x00,0x00,0x00,0x00; 18
                db 0x00,0x00,0x00,0x00,0x00,0x00
                db 0x00,0x00,0x00,0x00,0x20,0x20
                db 0x00,0x00,0x00,0x20,0x10,0x10
                db 0x00,0x00,0x20,0x10,0x00,0x00
                db 0x00,0x00,0x20,0x10,0x00,0x00

    smplangle22 db 0x00,0x00,0x00,0x00,0x00,0x00; 19
                db 0x00,0x00,0x00,0x00,0x00,0x00
                db 0x20,0x20,0x00,0x00,0x00,0x00
                db 0x10,0x10,0x20,0x00,0x00,0x00
                db 0x00,0x00,0x10,0x20,0x00,0x00
                db 0x00,0x00,0x10,0x20,0x00,0x00

    smplangle23 db 0x00,0x00,0x10,0x20,0x00,0x00 ; 20
                db 0x00,0x00,0x10,0x20,0x00,0x00
                db 0x10,0x10,0x20,0x00,0x00,0x00
                db 0x20,0x20,0x00,0x00,0x00,0x00
                db 0x00,0x00,0x00,0x00,0x00,0x00
                db 0x00,0x00,0x00,0x00,0x00,0x00

    smplangle24 db 0x00,0x00,0x20,0x10,0x00,0x00; 21
                db 0x00,0x00,0x20,0x10,0x00,0x00
                db 0x00,0x00,0x00,0x20,0x10,0x10
                db 0x00,0x00,0x00,0x00,0x20,0x20
                db 0x00,0x00,0x00,0x00,0x00,0x00
                db 0x00,0x00,0x00,0x00,0x00,0x00
    
    ; double wall
    dblwall1 db 0x20,0x20,0x20,0x20,0x20,0x20 ; 22
             db 0x00,0x00,0x00,0x00,0x00,0x00
             db 0x20,0x20,0x20,0x20,0x20,0x20
             db 0x10,0x10,0x10,0x10,0x10,0x10
             db 0x00,0x00,0x00,0x00,0x00,0x00
             db 0x00,0x00,0x00,0x00,0x00,0x00

    dblwall2 db 0x00,0x00,0x00,0x00,0x00,0x00 ; 23
             db 0x00,0x00,0x00,0x00,0x00,0x00
             db 0x10,0x10,0x10,0x10,0x10,0x10
             db 0x20,0x20,0x20,0x20,0x20,0x20
             db 0x00,0x00,0x00,0x00,0x00,0x00
             db 0x20,0x20,0x20,0x20,0x20,0x20

    dblwall3 db 0x00,0x00,0x10,0x20,0x00,0x20 ; 24
             db 0x00,0x00,0x10,0x20,0x00,0x20
             db 0x00,0x00,0x10,0x20,0x00,0x20
             db 0x00,0x00,0x10,0x20,0x00,0x20
             db 0x00,0x00,0x10,0x20,0x00,0x20
             db 0x00,0x00,0x10,0x20,0x00,0x20

    dblwall4 db 0x20,0x00,0x20,0x10,0x00,0x00 ; 25
             db 0x20,0x00,0x20,0x10,0x00,0x00
             db 0x20,0x00,0x20,0x10,0x00,0x00
             db 0x20,0x00,0x20,0x10,0x00,0x00
             db 0x20,0x00,0x20,0x10,0x00,0x00
             db 0x20,0x00,0x20,0x10,0x00,0x00
    
    ; double angle wall
    dblangle1 db 0x00,0x00,0x00,0x20,0x20,0x20 ; 26
              db 0x00,0x00,0x20,0x00,0x00,0x00 
              db 0x00,0x20,0x00,0x00,0x20,0x20 
              db 0x20,0x00,0x00,0x20,0x10,0x10 
              db 0x20,0x00,0x20,0x10,0x00,0x00 
              db 0x20,0x00,0x20,0x10,0x00,0x00 

    dblangle2 db 0x20,0x20,0x20,0x00,0x00,0x00 ; 27
              db 0x00,0x00,0x00,0x20,0x00,0x00
              db 0x20,0x20,0x00,0x00,0x20,0x00
              db 0x10,0x10,0x20,0x00,0x00,0x20
              db 0x00,0x00,0x10,0x20,0x00,0x20
              db 0x00,0x00,0x10,0x20,0x00,0x20

    dblangle3 db 0x00,0x00,0x10,0x20,0x00,0x20 ; 28
              db 0x00,0x00,0x10,0x20,0x00,0x20
              db 0x10,0x10,0x20,0x00,0x00,0x20
              db 0x20,0x20,0x00,0x00,0x20,0x00
              db 0x00,0x00,0x00,0x20,0x00,0x00
              db 0x20,0x20,0x20,0x00,0x00,0x00

    dblangle4 db 0x20,0x00,0x20,0x10,0x00,0x00 ; 29
              db 0x20,0x00,0x20,0x10,0x00,0x00
              db 0x20,0x00,0x00,0x20,0x10,0x10
              db 0x00,0x20,0x00,0x00,0x20,0x20
              db 0x00,0x00,0x20,0x00,0x00,0x00
              db 0x00,0x00,0x00,0x20,0x20,0x20
    
    ; double wall with angle
    dblwallangle1 db 0x20,0x20,0x20,0x20,0x20,0x20 ; 30
                  db 0x00,0x00,0x00,0x00,0x00,0x00 
                  db 0x20,0x20,0x00,0x00,0x00,0x00 
                  db 0x10,0x10,0x20,0x00,0x00,0x00 
                  db 0x00,0x00,0x10,0x20,0x00,0x00 
                  db 0x00,0x00,0x10,0x20,0x00,0x00 
    
    dblwallangle2 db 0x20,0x20,0x20,0x20,0x20,0x20 ; 31
                  db 0x00,0x00,0x00,0x00,0x00,0x00
                  db 0x00,0x00,0x00,0x00,0x20,0x20
                  db 0x00,0x00,0x00,0x20,0x10,0x10
                  db 0x00,0x00,0x20,0x10,0x00,0x00
                  db 0x00,0x00,0x20,0x10,0x00,0x00

    dblwallangle3 db 0x20,0x00,0x00,0x00,0x00,0x00 ; 32
                  db 0x20,0x00,0x00,0x00,0x00,0x00
                  db 0x20,0x00,0x00,0x00,0x20,0x20
                  db 0x20,0x00,0x00,0x20,0x10,0x10
                  db 0x20,0x00,0x20,0x10,0x00,0x00
                  db 0x20,0x00,0x20,0x10,0x00,0x00

    dblwallangle4 db 0x20,0x00,0x20,0x10,0x00,0x00 ; 33
                  db 0x20,0x00,0x20,0x10,0x00,0x00
                  db 0x20,0x00,0x00,0x20,0x10,0x10
                  db 0x20,0x00,0x00,0x00,0x20,0x20
                  db 0x20,0x00,0x00,0x00,0x00,0x00
                  db 0x20,0x00,0x00,0x00,0x00,0x00

    dblwallangle5 db 0x00,0x00,0x10,0x20,0x00,0x20 ; 34
                  db 0x00,0x00,0x10,0x20,0x00,0x20
                  db 0x10,0x10,0x20,0x00,0x00,0x20
                  db 0x20,0x20,0x00,0x00,0x00,0x20
                  db 0x00,0x00,0x00,0x00,0x00,0x20
                  db 0x00,0x00,0x00,0x00,0x00,0x20

    dblwallangle6 db 0x00,0x00,0x00,0x00,0x00,0x20 ; 35
                  db 0x00,0x00,0x00,0x00,0x00,0x20
                  db 0x20,0x20,0x00,0x00,0x00,0x20
                  db 0x10,0x10,0x20,0x00,0x00,0x20
                  db 0x00,0x00,0x10,0x20,0x00,0x20
                  db 0x00,0x00,0x10,0x20,0x00,0x20
    
    ; double straight wall door
    dblstrgwall1 db 0x00,0x00,0x00,0x00,0x00,0x00 ; 36
                 db 0x00,0x00,0x00,0x00,0x00,0x00
                 db 0x10,0x10,0x10,0x10,0x10,0x10
                 db 0x20,0x20,0x20,0x20,0x20,0x20
                 db 0x00,0x00,0x00,0x00,0x00,0x20
                 db 0x20,0x20,0x20,0x20,0x20,0x20

    dblstrgwall2 db 0x00,0x00,0x00,0x00,0x00,0x00 ; 37
                 db 0x00,0x00,0x00,0x00,0x00,0x00
                 db 0x10,0x10,0x10,0x10,0x10,0x10
                 db 0x20,0x20,0x20,0x20,0x20,0x20
                 db 0x20,0x00,0x00,0x00,0x00,0x00
                 db 0x20,0x20,0x20,0x20,0x20,0x20
    
    ; double straight angle
    dblstrgangle1 db 0x00,0x00,0x00,0x00,0x00,0x00 ; 38
                  db 0x00,0x00,0x00,0x00,0x00,0x00
                  db 0x00,0x00,0x10,0x10,0x10,0x10
                  db 0x00,0x00,0x10,0x20,0x20,0x20
                  db 0x00,0x00,0x10,0x20,0x00,0x00
                  db 0x00,0x00,0x10,0x20,0x00,0x20

    dblstrgangle2 db 0x00,0x00,0x00,0x00,0x00,0x00 ; 39
                  db 0x00,0x00,0x00,0x00,0x00,0x00 
                  db 0x10,0x10,0x10,0x10,0x00,0x00 
                  db 0x20,0x20,0x20,0x10,0x00,0x00 
                  db 0x00,0x00,0x20,0x10,0x00,0x00 
                  db 0x20,0x00,0x20,0x10,0x00,0x00 

    dblstrgangle3 db 0x20,0x00,0x20,0x10,0x00,0x00; 40
                  db 0x00,0x00,0x20,0x10,0x00,0x00
                  db 0x20,0x20,0x20,0x10,0x00,0x00
                  db 0x10,0x10,0x10,0x10,0x00,0x00
                  db 0x00,0x00,0x00,0x00,0x00,0x00
                  db 0x00,0x00,0x00,0x00,0x00,0x00

    dblstrgangle4 db 0x00,0x00,0x10,0x20,0x00,0x20 ; 41
                  db 0x00,0x00,0x10,0x20,0x00,0x00
                  db 0x00,0x00,0x10,0x20,0x20,0x20
                  db 0x00,0x00,0x10,0x10,0x10,0x10
                  db 0x00,0x00,0x00,0x00,0x00,0x00
                  db 0x00,0x00,0x00,0x00,0x00,0x00
    
    ; door ghost room
    door db 0x00,0x00,0x00,0x00,0x00,0x00 ; 1
         db 0x00,0x00,0x00,0x00,0x00,0x00
         db 0x10,0x10,0x10,0x10,0x10,0x10
         db 0x00,0x00,0x00,0x00,0x00,0x00
         db 0x54,0x54,0x54,0x54,0x54,0x54
         db 0x00,0x00,0x00,0x00,0x00,0x00

    ;empty
    empty db 0,0,0,0,0,0 ; 0
          db 0,0,0,0,0,0
          db 0,0,0,0,0,0
          db 0,0,0,0,0,0
          db 0,0,0,0,0,0
          db 0,0,0,0,0,0
    ; ---------------------------------------------------------------------