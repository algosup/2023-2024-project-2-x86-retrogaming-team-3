# Functional Specifications
<!-- TABLE OF CONTENTS -->
<h2 id="table-of-contents"> 📖 Table of Contents</h2>

<details>
    <summary><em>click to expand...</em></summary>
    Hello There !
</details>

## A) Document Control

- ### ➤ 1) Document Information

| Document ID | Document # 01 |
|---|---|
| Document Owner | Max BERNARD |
| Issue date |  |
| Last Issue Date | |
| Document Name | |

- ### ➤ 2) Document History

| Version n° | Edits completed by | Date | Description of edit |
|---|---|---|---|
|01|Max BERNARD, Mathis KAKAL| 11/08/2023 | Initial Release (V.01) |

- ### ➤ 3) Document Approval

| Role | Name | Signature | Date |
|---|---|---|---|
| Project Manager | Arthur LEMOINE | | |
| Tech Lead | Mathis KAKAL | | |
| Software Developer | Pierre GORIN | | |
| Software Developer | Evan UHRLING | | |
| Quality Assurance | Quentin CLEMENT | | |
| Quality Assurance | Robin DEBRY | | |

## B) Introduction

- ### ➤ 1) Glossary

| Term used | Definition |
|---|---|
| "team" | ALGOSUP team 3 (2023-2024 - Project 2) |
| "player" | A person playing the game |

- ### ➤ 2) Project Overview

<!--- Explain what we have to do -->
Our team was tasked with creating a Pac-Man clone, with the added restriction that it had to be coded in assembly and run on an x86 CPU architecture 16-bit system.

- ### ➤ 3) Project Definition

    - #### ➭ <ins>Vision</ins>

    <!-- our end goal with this project -->
    We are making a perfect Pac-Man clone. We will use the Original assets and copy exactly the game mechanics. 

    - #### ➭ <ins>Objectives</ins>

    > Tell the objectives given by the customer and the objectives we gave ourselves (in simple bullet points)

    - #### ➭ <ins>Scope</ins>

    | In Scope |
    |---|
    | Delivering the project |
    | Delivering an open source clone of pacman |

    | Out of Scope |
    |---|
    | Delivering the actual DOS binaries of pacman |

    - #### ➭ <ins>Deliverables</ins>

    | Name | Type | Deadline | Goal | Link |
    |---|---|---|---|---|
    | Functional Specifications Document | Document (markdown) | | | |
    | Technical Specifications Document | Document (markdown) | | | |
    | Weekly Reports | Document ( | | | |
    | Test Plan | Document (markdown) | | | |
    | Test Cases | Spreadsheet (Google Sheets) | | | |

- ### ➤ 4) Project Organisation

    - #### ➭ <ins>Project Representatives</ins>

    |Project Owner|Represented by...|
    |---|---|
    |**Franck JEANNIN**|Represented by himself|
    |Arthur LEMOINE|Represented by Max BERNARD (Program Manager)|
    
    The project sponsors (highlighted in **bold**) are expected to be in charge of:

    - Defining the vision and high level objectives for the project
    - Approving the requirements, timetable, resources and budget (if necessary).
    - Authorising the provision of funds/resources (internal or external) (if necessary).
    - Approving the functional and technical specifications written by the team.
    - Ensuring that major business risks are identified and managed by the team
    - Approving any major changes in scope
    - Receiving Project Weekly Reports and taking action accordingly resolving issues escalated by the Project Manager.
    - Ensuring business/operational support arrangements are put in place
    - Ensuring the participation of a business resource (if required)
    - Providing final acceptance of the solution upon project completion.

    - #### ➭ <ins>Stakeholders</ins>

    | Stakeholder | Might have/find an interest in... |
    |---|---|
    | Franck JEANNIN | |
    | ALGOSUP Students | |
    | B3 ?? | |

    - #### ➭ <ins>Project Roles</ins>

    As defined by the project owner (ALGOSUP), the team is arranged in the following manner:

    | Role | Description | Name |
    |---|---|---|
    | Project Manager | | Arthur LEMOINE |
    | Program Manager | | Max BERNARD |
    | Tech Lead | | Mathis KAKAL |
    | Software Developer | | Pierre GORIN |
    | Software Developer | | Evan UHRLING |
    | Quality Assurance | | Quentin CLEMENT |
    | Quality Assurance | | Robin DEBRY |

    - #### ➭ <ins>Project Reviewers</ins>

    External project reviewers have been appointed by the project owner to review our specifications and provide us with feedback.

- ### ➤ 5) Project Plan

    - #### ➭ <ins>Retroplanning</ins>

    ![image.png](./pictures/retroplan.png)
    (do agile instead of waterfall) => use scrum methodology

    - #### ➭ <ins>Milestones</ins>

    | Milestone | Deadline |
    |---|---|
    | Functional Specifications V1 | Friday, November 10th 2023 |
    | Technical Specifications V1 | |
    | POC (pre MVP) | |
    | MVP (Alpha realease) | |
    | Oral Presentation (Beta Release) | |
    | ?? | |

    - #### ➭ <ins>Dependencies</ins>

    The POC requires some prior understanding of the target technologies before being developed, meaning that its development will probably start on week 2.

    The MVP requires the POC to be made first to estimate difficulty of tasks and viability of set objectives.

    The rest of the project depends on the first version of the functional specifications to be released and approved first.

    - #### ➭ <ins>Resources/Financial plan</ins>

    We have an estimated 55 hours total to complete this project
    => We have the team

    => Teachers

    => School's resources

    - #### ➭ <ins>Assumptions/Constraints</ins>

    | Assumptions |
    |---|
    | We assume that reality is real |
    |We assume to be alive in such reality|

    | Constraints |
    |---|
    | We only live once |

## C) Functional Requirements

- ### ➤ 1) Pac-Man's features

    - #### ➭ <ins>Brief History...</ins>

    <!-- Explain what is pacman + image to be pretty -->
    Pac-Man is a maze arcade game created in 1980 in Japan. In the game, you play Pac-Man, who looks like: <img src="./pictures/pac-man1.png" alt="a yellow ball with a mouth" width="15">, and need to eat all the Gums in a maze to end the level.
    <p align="center"><img src="./pictures/PAC-MAN-game1.png" alt="Pac-Man game" width="400"/></p> 

    In this picture, the smallest dots in the maze are Gums. To navigate the level, you can go up, down, left, or right, with no other input required.

    Multi-coloured ghosts <img src="./pictures/pink-ghost.png" alt="pink ghost" width="15"/> are chasing Pac-Man through the level, and if one touches Pac-Man, he loses a life.
    Pac-Man can eat a Super Gum (the slightly bigger dots). 
    
    They give Pac-Man the ability to eat the ghosts for a period of time. When you complete a level, the ghosts get faster, and the Super Gum bonus gets shorter.
    After a set amount of time, fruits appear in a level. Eating the fruits gives bonus points.

    - #### ➭ <ins>Environment</ins>

        - ##### ➤ <ins>Unit of Measurement</ins>

        We are using Pac-Man diameter as a unit of Reference through this section as we needed a constant that would not change. In the original Game Pac-Man has a 12px diameter but we can't assume that this will be the case for us.

        - ##### ➤ <ins>Level</ins>

        We will use the original 1980 Pac-Man level layout. The picture bellow can be used as a reference to recreate the layout. Neither Pac-Man nor the ghosts can cross the blue lines.
        <p align="center"><img src="./pictures/PAC-MAN-game1.png" alt="pac-man game" width="500"/></p>
        The Gum and Super-Gum should be placed on the exact same location. as in the picture.<br>
        The levels walls have a blue border and a transparent fill. They should be 83.3% as wide as the Pac-Man. When wall are next to one an other, the iner border should be removed so that is looks like there is no empty space.<br>
        The outer wall of the level are as wide as 41.6% of Pac-Man.
        There should be a 30% rounded of effect to every corner similar to the border radius efect in CSS.<br>
        The exeption to those rules is the Ghost spawning box at the center of the level who as the same wall as the outer wall of the level.<br>
        Every coridor in which the player and ghosts can move should be 116.6% wider than the player.

        - ##### ➤ <ins>User Interface</ins>

        At the UI should be at the top of the screen. "HIGH SCORE" should be aligned at the center of the screen.<br> The Number should be displayed bellow the text with a 8.3% Pac-Man high gap between the top and bottom lines. The right most number in the high score should be under the "O" of "SCORE<br><br> The current Score should be displayed as "1UP", horizontaly aligned with "HIGH SCORE". the "P" of "1UP" should be 4 characters left of the "H" of "HIGH SCORE".<br>The number should be displayed, horizontaly aligned with the numbers under "HIGH SCORE" 
        <p align="center"><img src="./pictures/UI.png" alt="pac-man UI" width="500"/></p>
        The Font is a monospace and should be all Upercase. The characters are white to create a contrast against the black background. Every character is 58.3% Pac-Man high and and wide. There should be a 8.3% Pac-Man wide gap between characters.

    - #### ➭ <ins>Player</ins>

    Explain the player movement
    Talk about eating pac-Gum talk about super pac-gum
    Score 
    Fruits ( cherry level 1, Strawberry level 2 , orange lv 3 and 4, Apple lv5 and lv6 , Melon lv7 et 8, Galaxian lv 9 et 10 , bell lv 11 et 12 key lv 13 and more)

    Point reward fruit: 

    |Fruit|Score|
    |---|---|
    |Cherry|100|
    |Strawberry|300|
    |Orange|500|
    |Apple|700|
    |Melon|1000|
    |Galaxian|2000|
    |Bell|3000|
    |Key|5000|

    Lives(4) + what happens on death
    Live + 1 if you kill all ghost

    - #### <ins>Ghosts</ins>

    Ghost kill the player
    Ghost scramble at game start
    Frightened, Normal and Chase
    Personality
    ghost can’t leave base if you eat super pac-gum
    
    - #### <ins>Increasing Difficulty</ins>

    the game gets faster and faster when you finish a level

- ### ➤ 2) Personas Definition

<img src="./pictures/personas/etienne.png" alt="Etienne-Persona" width="95%" align="center"/> 

<img src="./pictures/personas/isabelle.PNG" alt="Isabelle-Persona" width="95%" align="center"/> 

<img src="./pictures/personas/antoine.PNG" alt="Antoine-Persona" width="95%" align="center"/>

- ### ➤ 3) Use Cases Analysis

| Use Case Number | Name | Description | Actor(s) | Pre-Conditions | Flow of Events | Post-Conditions | Exit Criteria | Notes & Issues |
|---|---|---|---|---|---|---|---|---|
| text | text | The player launches the game | the player | text | text | text | text | text |
| text | text | The player pauses the game | the player | text | text | text | text | text |

- ### ➤ 4) Functional Analysis

Functional Diagrams each function addresses a use case

## D) Non-Functional Requirements
	  *Add or remove sections as relevant*  
- ### ➤ Costs
    - #### <ins>I - Capital Expenditures</ins>
        - ##### <ins>Material</ins>
        - ##### <ins>Production Line</ins>
        - ##### <ins>Tools</ins>
        - ##### <ins>Software</ins>
        - ##### <ins>Time Spent/Wages</ins>
    - #### <ins>II - Operational Expenditures</ins>
        - ##### <ins>Server Costs</ins>
        - ##### <ins>Maintenance</ins>
        - ##### <ins>Salaries</ins>
        - ##### <ins>Energies</ins>
- ### ➤ Reliability
- ### ➤ Response/Performance
- ### ➤ Operability
- ### ➤ Recovery
- ### ➤ Delivery
- ### ➤ Maintainability
- ### ➤ Scalability
- ### ➤ Availability
- ### ➤ Security
- ### ➤ Transition Requirements

## E) Conclusion??