# Test plan document

|Author|Robin DEBRY and Quentin CLEMENT|
|---|---|
|Created|11/09/2023|
|Last Modified|20/09/2023|

## Table of Contents

- [Test plan document](#test-plan-document)
  - [Table of Contents](#table-of-contents)
  - [Analyse the product](#analyse-the-product)
    - [Who will use this pac-man game?](#who-will-use-this-pac-man-game)
      - [Former players](#former-players)
      - [New players](#new-players)
      - [Competitive players](#competitive-players)
    - [What is it used for?](#what-is-it-used-for)
    - [How will it work?](#how-will-it-work)
    - [What are software/ hardware the game uses?](#what-are-software-hardware-the-game-uses)
      - [Asssembly](#asssembly)
      - [DosBox](#dosbox)
  - [Test strategy](#test-strategy)
    - [Testing scope](#testing-scope)
    - [Testing type](#testing-type)
    - [Document testing](#document-testing)
    - [Game testing](#game-testing)
  - [Test criteria](#test-criteria)
    - [Suspension criteria](#suspension-criteria)
    - [Exit criteria](#exit-criteria)
  - [Resource planning](#resource-planning)
    - [Human resource](#human-resource)
    - [System resource](#system-resource)
    - [Test tool](#test-tool)
  - [Plan test environment](#plan-test-environment)
    - [Test environment for Mac](#test-environment-for-mac)
    - [Test environment for Windows](#test-environment-for-windows)
  - [Schedule estimation](#schedule-estimation)
  - [Test deliverables](#test-deliverables)

## Analyse the product

### Who will use this pac-man game?

As testers, we will have to put ourselves in the shoes of the users. For this reason, we will have to determine all the possible different user types. By doing that, we will be able to test the product from different perspectives and make sure that it is suitable for all types of users.

#### Former players

The principal targetted audience is nostalgic gamers who have a fondness for classic arcade experiences. It’s for those who remember the iconic Pac-Man of 1980 and want to relive the excitement of crunching pellets and escaping ghosts.

#### New players

The second targetted audience Pac-Man was really popular during the 80's and the 90's, afterwards it became less played and a lot of people never played the original Pac-Man game. This is why, newbies are also a targetted audience. They will be able to discover the game and the retro gaming world.

#### Competitive players

Competitive Pac-Man players are a tiny part of the target audience, but they do exist. These players will be aiming to beat their records, whether in terms of speed, score. But also to achieve the various challenges that are popular in this community.

### What is it used for?

The Pac-Man game serves as a delightful escape into the past, offering a virtual time machine to the golden era of arcade gaming. It's a source of entertainment and nostalgia, allowing players to immerse themselves in the simple yet addictive gameplay that made Pac-Man a timeless classic. Additionally, it can be a great way to introduce younger generations to the joy of retro gaming, fostering a sense of appreciation for the roots of the gaming industry. Overall, it's a fun and engaging experience that transcends generations.

### How will it work?

Given that this is an exact clone of the 1980 Pac-Man, the gameplay mechanics will faithfully replicate the original experience. Players will navigate through a maze, controlling the iconic yellow character to consume pellets while avoiding colorful ghosts. The controls will mimic the simplicity of the arcade joystick, ensuring an authentic feel for players.

The graphics and audio will stay true to the retro charm, maintaining the pixelated aesthetic and classic sound effects that defined the original Pac-Man. The game will be designed to run smoothly on modern platforms while preserving the nostalgic elements that make Pac-Man a timeless favorite.

### What are software/ hardware the game uses?

The development of this Pac-Man clone involves a combination of software and hardware elements.

#### Asssembly

We will use Assembly to develop the game. Assembly is a low-level programming language that is used to write programs that are directly executable by the computer's hardware.

#### DosBox

DosBox is a DOS-emulator that uses the SDL-library which makes DosBox very easy to port to different platforms. DosBox has already been ported to many different platforms, such as Windows, BeOS, Linux, MacOS X...

## Test strategy

### Testing scope

All the documents and features listed in the functional specifications will be sorted by priority and product areas. If 2 features are ready for testing at the same, the one with the highest priority will be tested first. Documents will be tested first so when they are fully completed, the whole will be able to focus on the product.

### Testing type

We will use an agile testing type. The goal is to make a overall test set each friday to test eveything that has been done during the week and provide feedbacks quickly so that the concerned team can rework the tested feature.

### Document testing

Documents are milestones in this project. They are an important way of communication within the team and between the team and the external world. Their quality and their pertinance is paramount so the whole way of thinking of the team can be transmitted. Moreover, each point has to be clear and precise so the final product is as close as possible to the specifications and ALGOSUP's requirements.
As the functional and technical specifications are the most important documents, they will be tested as a priority and published as soon as possible so that the teams can base their production work on them.

### Game testing

About the product in itself, all the features listed in the functional specifications will be tested to verify if they are corresponding to what was planned in the specifications.

## Test criteria

### Suspension criteria

The active test cycle will be suspended until the criteria are resolved.

![suspensionCriteria](../pictures/qa/suspensionCriteria.png)

We will use this test criteria for tests with critical priority, because if a test is with critical priority, it means we absolutely need it on our game, also we will need these features for the MVP.

### Exit criteria

We will use this test criteria for tests with a priority between low and high for each development phases.
For that we need to target a run rate and a pass rate.

**run rate** will be the ratio between the number test cases executed/total test cases.
**pass rate** will be the ratio between number test cases passed/test cases executed.

Run rate is mandatory to be 100%.
Achieving high pass rate is a goal.

A weekly report will be make each friday to confirm the exit criteria with the report of the test results

## Resource planning

### Human resource

The Quality Assurance of this team will take all QA roles together like Test manager,Tester, developer in test, test administrator and software quality assurance(SQA).

|No|Member|Tasks|
|---|---|---|
|1|Tester|Execute the tests, Log results and report the defects|
|2|Developer in test|Implement the test cases, the test units|
|3|Test Administrator|Builds up and ensure the test environment to be use by the test|
|4|SQA|Take in charge the quality assurance. Check to confirm the testing process is meeting specified requirements of the customers|

### System resource

|No|Resources|Description|
|---|---|---|
|1|Test tools|Builds up and ensure the test environment to be use by the test.|
|2|Computer|We will use 2 different OS (Windows and MAC to be sure that the game works in each of them|

### Test tool

For this project we will use Linear(https://linear.app). It will be useful for all issues make each weeks for each features needs for the game. After that we will convert the issue into github.

![Linear_overview](../pictures/QA/linearOverview.png)

We can see that we can add a description, a priority, a label, a milestone, a project, a assignee, a due date and a estimate time.
The only difference with github is that we can add a estimate time and a due date. Also is better to understand in which part of the project the issue is and to see if a issue it's already in progress or not. Finally each members of the team can see is own issues and the issues of the team.

## Plan test environment

### Test environment for Mac

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

### Test environment for Windows

## Schedule estimation

## Test deliverables
