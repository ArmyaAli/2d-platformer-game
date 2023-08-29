# 2d-platformer-game
## Project setup
#### Prerequisites 
#### Windows
- Install Git [Downloads](https://git-scm.com/downloads)
- Install MinGW toolchain [Downloads](https://www.mingw-w64.org/downloads/](https://github.com/niXman/mingw-builds-binaries/releases)
    ![image](https://github.com/ArmyaAli/2d-platformer-game/assets/11745376/84242f80-c238-46ac-8516-ee2b3d31c2fe)
- Git
- Text editor of your choice
- Shell of your choice 
#### Instructions
```
Directory structure after the setup
C:.
├───build
├───include
│   └───raylib
├───lib
└───src

```
1. Add to $PATH
```
C:\dev\tools\mingw64\bin
```
2. Get Raylib [Download Library & Header files](https://github.com/raysan5/raylib/releases)
3. Clone the repository
```
git clone https://github.com/ArmyaAli/2d-platformer-game.git
cd 2d-platformer-game
```
4. Run make setup
```
mingw32-make setup
```
5. Go to the raylib distribution pkg you downloaded in step 2. 
```
mv raylib.a  2d-platformer-game\lib
mv include\*.h  2d-platformer-game\include\raylib
```
6. Compile and run the program
```
mingw32-make
```
