# Research Document

|Author|Pierre GORIN|
|---|---|
|Created|11/08/2023|
|Last Modified|11/09/2023|

## Table of Contents

- [Research Document](#research-document)
  - [Table of Contents](#table-of-contents)
  - [Overview](#overview)
  - [x86 Assembly Language](#x86-assembly-language)
    - [Dosbox Quick Start](#dosbox-quick-start)
    - [IDE](#ide)
      - [Windows Installation](#windows-installation)
    - [Exercices](#exercices)
  - [Pacman](#pacman)
  
## Overview

This document is a summary of the research I have done on the **x86 assembly language** and the **Pacman** game. It is a living document that will be updated as I progress in my research.

## x86 Assembly Language

|Topic|Description|Link|
|---|---|---|
|Emulator| To emulate the x86 assembly language, we will use Dosbox. It is a DOS emulator that will allow me to run the game on my computer. | [Dosbox](https://www.dosbox.com/) |
|Assembly Language| The assembly language is a low-level programming language that is specific to a processor. It is a human-readable representation of the machine code. | [Assembly Language](https://en.wikipedia.org/wiki/Assembly_language) |
| IDE | To run the assembly code, we will use SASM. It is an is an open source cross-platform IDE that allows us to write, compile and run assembly code.  | [SASM](https://dman95.github.io/SASM/english.html) |

### Dosbox Quick Start

*⚠️ **Please note:** Dosbox keyboard inputs are Qwerty. ⚠️*

1. Download Dosbox from the [Sourceforge](https://sourceforge.net/projects/dosbox/files/latest/download).
2. Install Dosbox.
3. Create a folder for your assembly code (e.g. `C:\Users\[yourname]\Assembly`).
4. Put a .exe file in the folder (e.g. `C:\Users\[yourname]\Assembly\hello.exe`).
5. Open Dosbox.
6. Type `mount c ~\Assembly` to mount the folder.
7. Type `c:` to go to the folder.
8. Type `hello` to run the program.

### IDE

SASM is an open source cross-platform IDE that allows us to write, compile and run assembly code. It is available for Windows, Linux and Mac OS.

#### Windows Installation



### Exercices

<details>
<summary><h4> 1. Hello World </h4></summary>

Objective: Print "Hello World" on the screen.

Link: [Click Here](https://exercism.org/tracks/x86-64-assembly/exercises/hello-world)

Solution:

```x86asm
default rel
section .rodata
msg: db "Hello, World!", 0
section .text
global hello
hello:
    lea rax, [msg]
    ret
```

Output:

```
Hello, World!
```

</details>

## Pacman

|Topic|Description|Link|
|---|---|---|
|Fruits and Vegetables| The fruits and vegetables are the food that Pacman eats to gain points. | [Fruits and Vegetables](https://pacman.fandom.com/wiki/Fruit) |
|Ghosts| The ghosts are the enemies of Pacman. They are trying to catch him. | [Ghosts](https://villains.fandom.com/wiki/Ghosts_(Pac-Man)) |


