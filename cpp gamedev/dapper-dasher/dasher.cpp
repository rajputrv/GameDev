#include "raylib.h"

int main()
{
    // window dimensions
    const int windowWidth{512};
    const int windowHeight{380};

    // rectangle dimensions
    const int width{50};
    const int height{80};

    int posY{windowHeight - height};
    int velocity{-10};

    // initialize the window
    InitWindow(windowWidth, windowHeight, "Damper-Dasher!");
    SetTargetFPS(60);
    while (!WindowShouldClose())
    {
        BeginDrawing(); // start drawing
        ClearBackground(WHITE);

        posY += velocity;

        DrawRectangle(windowWidth / 2, posY, width, height, BLUE);

        EndDrawing(); // STOP WINDOW
    }
    CloseWindow();
}

// velocity in game is the no. of pixel travelled per frame ie pixels/frames
// we declared fps=60, if velocity is 10p/f then in one second (10p/f * 60f/s = 600p/s ), 600 pixels are travelled