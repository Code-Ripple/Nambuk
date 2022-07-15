#include <raylib.h>
#include <string>
#include "dice.hpp"

using std::string;

const int SCREEN_WIDTH  = 1280;
const int SCREEN_HEIGHT = 720;

dice mainDice;

int main(void)
{

    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Window title");
    SetTargetFPS(60);
    Texture2D background = LoadTexture(ASSETS_PATH"Background.png");

    DrawTexture(background, 0, 0, WHITE);


    while (!WindowShouldClose())
    {

        BeginDrawing();

        ClearBackground(RAYWHITE);
        const char* text = "Communism";


        const Vector2 text_size = MeasureTextEx(GetFontDefault(), text, 20, 1);
        DrawText(text, SCREEN_WIDTH / 2 - text_size.x / 2, SCREEN_HEIGHT / 2, 20, BLACK);

        if(IsMouseButtonPressed(0))
        {
            mainDice.roll();
        }
        EndDrawing();
    }



    CloseWindow();
    return 0;
}
