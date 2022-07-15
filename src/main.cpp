#include <raylib.h>
#include <string>
#include "dice.hpp"
#include "button.hpp"
#include <iostream>

using std::string;

const int SCREEN_WIDTH  = 1280;
const int SCREEN_HEIGHT = 720;

dice mainDice;

button buttons[20];

void SetupButtons()
{
    for(int i = 0; i < 16; i++)
    {
        if(i < 9)
        {
            buttons[i].setColour(BLUE);
        }
        else
        {
            buttons[i].setColour(RED);
        }

    }

    buttons[0].setPosX((SCREEN_WIDTH/2)-30);
    buttons[0].setPosY((SCREEN_HEIGHT/2)+40);
    buttons[1].setPosX((SCREEN_WIDTH/2)+50);
    buttons[1].setPosY((SCREEN_HEIGHT/2)+25);
    buttons[2].setPosX((SCREEN_WIDTH/2)-35);
    buttons[2].setPosY((SCREEN_HEIGHT/2)+100);
}

void Update()
{
    for(int i = 0; i < 16; i++)
    {
        buttons[i].Update();
    }
}

int main(void)
{
    SetupButtons();

    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Nambuk");
    SetTargetFPS(60);
    Texture2D background = LoadTexture("D:/CPP Projects/Nambuk/assets/background.png");
    Texture2D map = LoadTexture("D:/CPP Projects/Nambuk/assets/Map.png");




    while (!WindowShouldClose())
    {
        Update();

        DrawTexture(background, 0, 0, WHITE);
        DrawTexture(map, (SCREEN_WIDTH/2)-(312/2), (SCREEN_HEIGHT/2)-(495/2), WHITE);
        BeginDrawing();
        ClearBackground(RAYWHITE);


        if(IsMouseButtonPressed(0))
        {
            mainDice.roll();
        }

        //Drawing buttons
        for(int i = 0; i < 16; i++)
        {
            DrawCircle(buttons[i].getPosX(), buttons[i].getPosY(), 10, buttons[i].getColour());
        }

        EndDrawing();
    }



    UnloadTexture(background);
    CloseWindow();

    return 0;
}
