# 👾 MONSTER SHOOTER

**Monster Shooter** is a very simple 2D game built using the **iGraphics** library in **C language**.  
This was developed as the **term project for 1st year, 1st semester (1-1)**.

---

## 🎮 How to Play

- Detailed instructions for playing the game can be found in the **Instruction** section within the game.
- To play the game:
  1. **Download** the full project folder  
  2. Run the `Monster_Shooter.exe` file  
  3. Enjoy the game! 🎉

---

## 🧑‍💻 Source Code

- The entire source code is available in the `Monster_Shooter.cpp` file.
- The project is developed using the **iGraphics** library, a simple graphics library for C.

---

## 📚 iGraphics Library Info

For your convenience, the **official README** of the iGraphics library is included in this repository.  
It contains installation instructions, function descriptions, and usage guidelines.

---

## 📦 Folder Contents

- `Monster_Shooter.cpp` – main source code  
- `Monster_Shooter.exe` – executable file to run the game  
- Additional assets (images, sounds, etc. if any)

---

## 🎯 Goal

The goal of this game is simple: **shoot the monsters, survive, and have fun!**

---

Let me know if you’d like to add a screenshot, gameplay GIF, or instructions for compiling the C code manually.


# IGraphics
This is the repository for IGraphics library. IGraphics is a thin wrapper on top of OpenGL. This can be used for simple 2D graphics demonstrations, project work for C programming language course

Command line compiling:
-----------------------
g++ -IOpenGL\include -w -c BallDemo.cpp -o BallDemo.o

Command line linking:
---------------------
g++ -LOpenGL\lib BallDemo.o -o BallDemo.exe -lGlaux -lGLU32 -lglui32 -lglut32 -lOPENGL32 -lgdi32

Command line running:
---------------------
Make sure glut32.dll is present in the same folder
Run BallDemo.exe

Animation Related API:
----------------------
int iSetTimer(int msec, void (*f)(void))
void iPauseTimer(int index)
void iResumeTimer(int index)

Shape drawing:
--------------
void iSetColor(double r, double g, double b)
void iPoint(double x, double y, int size=0)
void iLine(double x1, double y1, double x2, double y2)
void iFilledPolygon(double x[], double y[], int n)
void iPolygon(double x[], double y[], int n)
void iRectangle(double left, double bottom, double dx, double dy)
void iFilledRectangle(double left, double bottom, double dx, double dy)
void iFilledCircle(double x, double y, double r, int slices=100)
void iCircle(double x, double y, double r, int slices=100)
void iEllipse(double x, double y, double a, double b, int slices=100)
void iFilledEllipse(double x, double y, double a, double b, int slices=100)

Text output:
------------
void iText(double x, double y, char *str, void* font=GLUT_BITMAP_8_BY_13)

Rendering:
----------
void iDraw();
void iClear();
void iShowBMP(int x, int y, char filename[])

Initialization:
---------------
void iInitialize(int width=500, int height=500, char *title="iGraphics")

I/O event handling:
-------------------
void iKeyboard(unsigned char);
void iSpecialKeyboard(unsigned char);
void iMouseMove(int, int);
void iMouse(int button, int state, int x, int y);

