#include <raylib.h>
#include <string>
#include "dice.hpp"
#include "button.hpp"
#include <iostream>
#include "militaryUnits.hpp"

#define unitColourRed (Color) {100, 66, 66, 255}
#define unitColourBlue (Color) {66, 66, 100, 255}

#define GET_VARIABLE_NAME(Variable) (#Variable)

using std::string;

const int SCREEN_WIDTH  = 1280;
const int SCREEN_HEIGHT = 720;

dice mainDice;

bool turn; //False is south korea (0). True is north korea (1)

button buttons[20];
militaryUnit units[4];

void nextTurn()
{
    turn = !turn;
}

void SetupButtons()
{
    for(int i = 0; i < 16; i++)
    {
        if(i < 8)
        {
            buttons[i].setColour(BLUE);
            buttons[i].setColourValue("BLUE");
        }
        else
        {
            buttons[i].setColour(RED);
            buttons[i].setColourValue("RED");
        }

    }

    for(int i = 0; i < 4; i++)
    {
        buttons[i].setInteractible(false);
        units[i].setInteractible(true);


        if(i >= 2)
        {
            units[i].setSide("RED");
            units[i].setColour(unitColourRed);
        }

        else
        {
            units[i].setSide("BLUE");
            units[i].setColour(unitColourBlue);
        }

    }




    buttons[0].setPosX((SCREEN_WIDTH/2)-30);
    buttons[0].setPosY((SCREEN_HEIGHT/2)+40);
    buttons[1].setPosX((SCREEN_WIDTH/2)+50);
    buttons[1].setPosY((SCREEN_HEIGHT/2)+25);
    buttons[2].setPosX((SCREEN_WIDTH/2)-35);
    buttons[2].setPosY((SCREEN_HEIGHT/2)+100);
    buttons[3].setPosX((SCREEN_WIDTH/2) + 5);
    buttons[3].setPosY((SCREEN_HEIGHT/2)+90);
    buttons[3].setPosY((SCREEN_HEIGHT/2)+90);
    buttons[4].setPosY((SCREEN_HEIGHT/2)+110);
    buttons[4].setPosX((SCREEN_WIDTH/2)+65);
    buttons[5].setPosX((SCREEN_WIDTH/2)-25);
    buttons[5].setPosY((SCREEN_HEIGHT/2)+145);
    buttons[6].setPosX((SCREEN_WIDTH/2)+40);
    buttons[6].setPosY((SCREEN_HEIGHT/2)+170);
    buttons[7].setPosX((SCREEN_WIDTH/2)-25);
    buttons[7].setPosY((SCREEN_HEIGHT/2)+190);
    buttons[8].setPosX((SCREEN_WIDTH/2)-70);
    buttons[8].setPosY((SCREEN_HEIGHT/2)-15);
    buttons[9].setPosX((SCREEN_WIDTH/2)+10);
    buttons[9].setPosY((SCREEN_HEIGHT/2)-35);
    buttons[10].setPosX((SCREEN_WIDTH/2)-60);
    buttons[10].setPosY((SCREEN_HEIGHT/2)-65);
    buttons[11].setPosX((SCREEN_WIDTH/2)+20);
    buttons[11].setPosY((SCREEN_HEIGHT/2)-105);
    buttons[12].setPosX((SCREEN_WIDTH/2)-100);
    buttons[12].setPosY((SCREEN_HEIGHT/2)-100);
    buttons[13].setPosX((SCREEN_WIDTH/2)-40);
    buttons[13].setPosY((SCREEN_HEIGHT/2)-130);
    buttons[14].setPosX((SCREEN_WIDTH/2)+40);
    buttons[14].setPosY((SCREEN_HEIGHT/2)-150);
    buttons[15].setPosX((SCREEN_WIDTH/2)+100);
    buttons[15].setPosY((SCREEN_HEIGHT/2)-180);



    units[0].setPosX(buttons[0].getPosX());
    units[0].setPosY(buttons[0].getPosY()-10);
    units[1].setPosX(buttons[1].getPosX());
    units[1].setPosY(buttons[1].getPosY()-10);
    units[2].setPosX(buttons[8].getPosX());
    units[2].setPosY(buttons[8].getPosY()-10);
    units[3].setPosX(buttons[9].getPosX());
    units[3].setPosY(buttons[9].getPosY()-10);

    buttons[0].setProvinceNumber(1);
    buttons[1].setProvinceNumber(2);
    buttons[2].setProvinceNumber(3);
    buttons[3].setProvinceNumber(4);
    buttons[4].setProvinceNumber(5);
    buttons[5].setProvinceNumber(6);
    buttons[6].setProvinceNumber(7);
    buttons[7].setProvinceNumber(8);
    buttons[8].setProvinceNumber(9);
    buttons[9].setProvinceNumber(10);
    buttons[10].setProvinceNumber(11);
    buttons[11].setProvinceNumber(12);
    buttons[12].setProvinceNumber(13);
    buttons[13].setProvinceNumber(14);
    buttons[14].setProvinceNumber(15);
    buttons[15].setProvinceNumber(16);


}

void Update()
{
    for(int i = 0; i < 16; i++)
    {
        std::cout << buttons[i].getProvinceNumber();
    }
    std::cout << std::endl;

    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 16; j++)
        {
            if(units[i].getPosX() == buttons[7].getPosX())
            {
                //std::cout << "DDD" << std::endl; //this was just testing
            }

            if(units[i].getPosX() == buttons[j].getPosX())
            {
                units[i].setProvinceNumber(buttons[j].getProvinceNumber());
            }
        }
    }


    for(int i = 0; i < 16; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            if(units[j].getPosX() == buttons[i].getPosX() && units[j].getPosY() == buttons[i].getPosY()+10)
            {
                buttons[i].setColourValue(units[j].getSide());
            }
        }

        buttons[i].Update();

        //std::cout << "Button selected: " << buttons[i].pressedButton() << std::endl;

       if(buttons[i].getColorValue() == "RED")
            buttons[i].setColour(RED);
        if(buttons[i].getColorValue() == "BLUE)")
            buttons[i].setColour(BLUE);



    }



    std::cout << std::endl;


        /*for(int l = 0; l < 4; l++)
        {
            for(int ii = 0; ii < 16; ii++) {
                if (buttons[ii].pressedButton() && !units[l].unitSelected()) {
                    buttons[ii].setPressed(false);
                }
            }
        }*/




    for(int i = 0; i < 4; i++)
    {
        units[i].Update();
        //std::cout << "Unit selected: " << units[i].unitSelected() << std::endl;

        if(units[i].unitSelected() == 1)
        {
            for(int j = 0; j < 16; j++)
            {
                if(buttons[j].pressedButton())
                {
                        units[i].moveUnit(buttons[j]);
                        units[i].setSelected(false);
                        buttons[j].setPressed(false);

                }

                else
                {
                    //units[i].setSelected(false);
                    buttons[j].setPressed(false);
                }




            }
        }


    }

    std::cout << std::endl;



}

int main()
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

        for(int i = 0; i < 4; i++)
        {
            DrawCircle(units[i].getPosX(), units[i].getPosY(), 11, units[i].getColour());

        }

        EndDrawing();
    }



    UnloadTexture(background);
    CloseWindow();

    return 0;
}
