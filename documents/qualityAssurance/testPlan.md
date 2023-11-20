# Test plan document

|Author|Robin DEBRY and Quentin CLÉMENT|
|---|---|
|Created|11/09/2023|
|Last Modified|20/09/2023|

## Table of Contents

- [Test plan document](#test-plan-document)
  - [Table of Contents](#table-of-contents)
  - [1. Analyse the product](#1-analyse-the-product)
    - [a. Who will use this pac-man game?](#a-who-will-use-this-pac-man-game)
      - [Former players](#former-players)
      - [New players](#new-players)
      - [Competitive players](#competitive-players)
    - [b. What is it used for?](#b-what-is-it-used-for)
    - [c. How will it work?](#c-how-will-it-work)
    - [d. What are software/ hardware the game uses?](#d-what-are-software-hardware-the-game-uses)
      - [Asssembly](#asssembly)
      - [DosBox](#dosbox)
  - [2. Test strategy](#2-test-strategy)
    - [a. Quality assurance team](#a-quality-assurance-team)
    - [b. Testing scope](#b-testing-scope)
    - [c. Testing type](#c-testing-type)
    - [d. Testing tools](#d-testing-tools)
    - [Test cases](#test-cases)
    - [Bug data reports](#bug-data-reports)
  - [3. Test criteria](#3-test-criteria)
    - [a. Suspension criteria](#a-suspension-criteria)
    - [b. Exit criteria](#b-exit-criteria)
  - [4. Resource planning](#4-resource-planning)
    - [a. Human resource](#a-human-resource)
    - [b. System resource](#b-system-resource)
    - [c. Test tool](#c-test-tool)
  - [5. Plan test environment](#5-plan-test-environment)
    - [a. Test environment for Mac](#a-test-environment-for-mac)
    - [b. Test environment for Windows](#b-test-environment-for-windows)
  - [Schedule estimation](#schedule-estimation)
  - [7. Test deliverables](#7-test-deliverables)

## 1. Analyse the product

### a. Who will use this pac-man game?

As testers, we will have to put ourselves in the shoes of the users. For this reason, we will have to determine all the possible different user types. By doing that, we will be able to test the product from different perspectives and make sure that it is suitable for all types of users.

#### Former players

The principal targetted audience is nostalgic gamers who have a fondness for classic arcade experiences. It's for those who remember the iconic Pac-Man of 1980 and want to relive the excitement of crunching pellets and escaping ghosts.

#### New players

The second targetted audience Pac-Man was really popular during the 80's and the 90's, afterwards it became less played and a lot of people never played the original Pac-Man game. This is why, newbies are also a targetted audience. They will be able to discover the game and the retro gaming world.

#### Competitive players

Competitive Pac-Man players are a tiny part of the target audience, but they do exist. These players will be aiming to beat their records, whether in terms of speed, score. But also to achieve the various challenges that are popular in this community.

<!-- This Pac-Man game is designed for nostalgic gamers who have a fondness for classic arcade experiences. It caters to those who remember the iconic Pac-Man of 1980 and want to relive the excitement of chomping pellets and evading ghosts. Whether you're a seasoned gamer who grew up with the original or a newcomer curious about gaming history, this clone appeals to a broad audience of all ages. -->

### b. What is it used for?

The Pac-Man game serves as a delightful escape into the past, offering a virtual time machine to the golden era of arcade gaming. It's a source of entertainment and nostalgia, allowing players to immerse themselves in the simple yet addictive gameplay that made Pac-Man a timeless classic. Additionally, it can be a great way to introduce younger generations to the joy of retro gaming, fostering a sense of appreciation for the roots of the gaming industry. Overall, it's a fun and engaging experience that transcends generations.

### c. How will it work?

Given that this is an exact clone of the 1980 Pac-Man, the gameplay mechanics will faithfully replicate the original experience. Players will navigate through a maze, controlling the iconic yellow character to consume pellets while avoiding colorful ghosts. The controls will mimic the simplicity of the arcade joystick, ensuring an authentic feel for players. Here's a [link](https://www.nintendo.co.jp/clv/manuals/en/pdf/CLV-P-NABME.pdf) to the official instruction manual we'll be referring to.

The graphics and audio will stay true to the retro charm, maintaining the pixelated aesthetic and classic sound effects that defined the original Pac-Man. The game will be designed to run smoothly on modern platforms while preserving the nostalgic elements that make Pac-Man a timeless favorite.

### d. What are software/ hardware the game uses?

The development of this Pac-Man clone involves a combination of software and hardware elements.

#### Asssembly

We will use Assembly to develop the game. Assembly is a low-level programming language that is used to write programs that are directly executable by the computer's hardware.

#### DosBox

DosBox is a DOS-emulator that uses the SDL-library which makes DosBox very easy to port to different platforms. DosBox has already been ported to many different platforms, such as Windows, BeOS, Linux, MacOS X...

## 2. Test strategy

### a. Quality assurance team

The testing team will be divided into 2 parts. The first half will be composed of team 4's QA's:
- Robin DEBRY (Mac OS)
- Quentin CLÉMENT (Mac OS)

The second half will be composed of team 5's QA's:
- Thomas PLANCHARD (Mac OS)
- Maxime CARON (Windows)

Sparing the testing team in 2 parts will allow us to test the game on 2 different OS (Windows and MAC) to be sure that the game works in each of them. As Thomas and Maxime are not part of our team and of the developpment of the project, they point of view will be completely different from ours and will allow us to have a more objective point of view on the quality of our product.

### b. Testing scope

The 2 main things to test during this project will be the documents and the game itself. <br>
About the documents, it's paramount to ensure their quality, so that communication with the client is clear and the whole team can work on the same basis. Not only will we check the documents for grammatical and typographical errors, but also the content itself, to ensure that no crucial points have been overlooked or erroneous elements introduced into the document. <br>
As far as the game is concerned, we'll be testing all the features listed in the functional specifications to check that they correspond to what was originally intended. We will also be testing the game on different operating systems (Windows and MAC) to ensure that it works on all of them.

<!-- All the documents and features listed in the functional specifications will be sorted by priority and product areas. If 2 features are ready for testing at the same, the one with the highest priority will be tested first. Documents will be tested first so when they are fully completed, the whole will be able to focus on the product. -->

### c. Testing type

We're going to use an agile testing strategy so that as new features are released by the development team, and previous bugs are fixed, team 4 QA's will have to be reactive and test them as soon as possible (according to their priorities if 2 things are ready to be tested at the same time, priorities will be set in the test cases on the linear). <br>

### d. Testing tools

Linear:

GitHub Issues:

### Test cases

To be sure that all features and all possible bugs have been tested, we will create multiple test cases on Linear/GitHub Issues. We will use a template to be sure that each test case is clear and concise. This template will be used for each test case and will be filled with the following information:

```
Ticket ID:

Test title [MM/DD/YYYY]:

Priority:

Labels: Test Case, ...

Test description:

Steps:

Expected result:

Actual result:

Status:

Comments:
```

### Bug data reports

When a bug is found, we will create a ticket on Linear/GitHub issues with the label "bug" so the developpers can see it by sorting the tickets with this particular label, and fix it as soon as possible. The ticket will be filled with the following information:

```
Ticket ID:

Bug title [MM/DD/YYYY]:

Priority:

Labels: Bug, ...

Bug description:

Steps to reproduce the bug:

Expected result:

Actual result:

Potential solution:

Comments:
```

<!-- ### d. Document testing

Documents are milestones in this project. They are an important way of communication within the team and between the team and the external world. Their quality and their pertinance is paramount so the whole way of thinking of the team can be transmitted. Moreover, each point has to be clear and precise so the final product is as close as possible to the specifications and ALGOSUP's requirements.
As the functional and technical specifications are the most important documents, they will be tested as a priority and published as soon as possible so that the teams can base their production work on them.

### e. Game testing

About the product in itself, all the features listed in the functional specifications will be tested to verify if they are corresponding to what was planned in the specifications. -->


## 3. Test criteria

### a. Suspension criteria

The active test cycle will be suspended until the criteria are resolved.

![suspensionCriteria](../pictures/qa/suspensionCriteria.png)

We will use this test criteria for tests with critical priority, because if a test is with critical priority, it means we absolutely need it on our game, also we will need these features for the MVP.

### b. Exit criteria

We will use this test criteria for tests with a priority between low and high for each development phases.
For that we need to target a run rate and a pass rate.

**run rate** will be the ratio between the number test cases executed/total test cases.
**pass rate** will be the ratio between number test cases passed/test cases executed.

Run rate is mandatory to be 100%.
Achieving high pass rate is a goal.

A weekly report will be make each friday to confirm the exit criteria with the report of the test results

## 4. Resource planning

### a. Human resource

The Quality Assurance of this team will take all QA roles together like Test manager,Tester, developer in test, test administrator and software quality assurance(SQA).

|No|Member|Tasks|
|---|---|---|
|1|Tester|Execute the tests, Log results and report the defects|
|2|Developer in test|Implement the test cases, the test units|
|3|Test Administrator|Builds up and ensure the test environment to be use by the test|
|4|SQA|Take in charge the quality assurance. Check to confirm the testing process is meeting specified requirements of the customers|

### b. System resource

|No|Resources|Description|
|---|---|---|
|1|Test tools|Builds up and ensure the test environment to be use by the test.|
|2|Computer|We will use 2 different OS (Windows and MAC to be sure that the game works in each of them|

### c. Test tool

For this project we will use Linear(https://linear.app). It will be useful for all issues make each weeks for each features needs for the game. After that we will convert the issue into github.

![Linear_overview](../pictures/QA/linearOverview.png)

We can see that we can add a description, a priority, a label, a milestone, a project, a assignee, a due date and a estimate time.
The only difference with github is that we can add a estimate time and a due date. Also is better to understand in which part of the project the issue is and to see if a issue it's already in progress or not. Finally each members of the team can see is own issues and the issues of the team.

## 5. Plan test environment

### a. Test environment for Mac

To test the game we will use NASM to compile the game and DosBox to run the game.

To compile the game we will use a file bash to compile the game

```bash
 nasm pacman.asm -f bin -o "pacman.com"
```

after that we will create a file bash to open DosBox and run the game

We will use this command to open DosBox

```bash
DOSBOX_BIN="/Applications/dosbox.app/Contents/MacOS/DOSBox"
```

and this command to run the game directly when DosBox is open

```bash
dosbox -c "mount c ${BIN_DIR}" -c "pacman.com" -c "exit"
```

### b. Test environment for Windows

## Schedule estimation

## 7. Test deliverables
