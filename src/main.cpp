#include <raylib.h>
#include "game.h"
int main()
{
    const int screenWidth = 288;
    const int screenHeight = 512;
    Color background = {78, 192, 202};

    InitWindow(screenWidth, screenHeight, "Flappy Bird");
    InitAudioDevice();
    SetTargetFPS(60);

    Game game;

    while (!WindowShouldClose())
    {

        game.Update();
        BeginDrawing();
        ClearBackground(background);
        game.Draw();
        EndDrawing();
    }

    CloseWindow();
    return 0;
}