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

bool southWon = false;
bool northWon = false;

dice mainDice;

bool turn; //False is south korea (0). True is north korea (1). Definitely not political in any way

button buttons[20];
militaryUnit units[4];

string text1 = "DDDDD";

char redTurnText[] = "North Korea's Turn";
char blueTurnText[] = "South Korea's Turn";
char turnText[] = "_____ Korea's Turn";

void nextTurn()
{
    if(turn)
        turn = 0;
    if(!turn)
        turn = 1;
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
        buttons[i].setInteractible(true);
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

void Update() {
    int blueCounter = 0, redCounter = 0;

    for (int i = 0; i < 16; i++) {
        if (buttons[i].getColorValue() == "RED") {
            redCounter++;
        }

        if (buttons[i].getColorValue() == "BLUE") {
            blueCounter++;
        }
    }

    if (redCounter == 16) {
        northWon = true;
    }

    if (blueCounter == 16) {
        southWon = true;
    }

    int numberActiveBlue = 2, numberActiveRed = 2;

    //std::cout << mainDice.getDiceValue() << std::endl;

    if (turn) {
        for (int i = 0; i < 19; i++) {
            turnText[i] = redTurnText[i];
        }
    } else {
        for (int i = 0; i < 19; i++) {
            turnText[i] = blueTurnText[i];
        }
    }

    if (numberActiveRed <= 0) {
        turn = false;
    }


    if (numberActiveBlue <= 0) {
        turn = true;
    }


    for (int i = 0; i < 4; i++) {
        if (!units[i].getInteractible()) {
            if (units[i].getSide() == "RED") {
                numberActiveRed -= 1;
            }

            if (units[i].getSide() == "BLUE") {
                numberActiveBlue -= 1;
            }

        }

        for (int j = 0; j < 16; j++) {

            if (units[i].getPosX() == buttons[j].getPosX()) {
                units[i].setProvinceNumber(buttons[j].getProvinceNumber());
            }
        }
    }


    for (int i = 0; i < 16; i++) {
        for (int j = 0; j < 4; j++) {
            if (units[j].getPosX() == buttons[i].getPosX() && units[j].getPosY() == buttons[i].getPosY() + 10) {
                buttons[i].setColourValue(units[j].getSide());
            }
        }

        buttons[i].Update();

        //std::cout << "Button selected: " << buttons[i].pressedButton() << std::endl;

        if (buttons[i].getColorValue() == "RED")
            buttons[i].setColour(RED);
        if (buttons[i].getColorValue() == "BLUE)")
            buttons[i].setColour(BLUE);


    }






    /*for(int l = 0; l < 4; l++)
    {
        for(int ii = 0; ii < 16; ii++) {
            if (buttons[ii].pressedButton() && !units[l].unitSelected()) {
                buttons[ii].setPressed(false);
            }
        }
    }*/




    for (int i = 0; i < 4; i++) {
        units[i].Update();
        //std::cout << "Unit selected: " << units[i].unitSelected() << std::endl;

        if (units[i].unitSelected() == 1) {


            for (int j = 0; j < 16; j++) {
                if (buttons[j].pressedButton()) {


                    if (units[i].getSide() == "RED" && turn == 1 && buttons[j].getPosX() != units[i].getPosX()) {
                        int curPosX = units[i].getPosX(), curPosY = units[i].getPosY();
                        for (int l = 0; l < 4; l++) {
                            int curPosXl = units[l].getPosX(), curPosYl = units[l].getPosY();

                            if (buttons[j].getPosX() == units[l].getPosX()) {
                                mainDice.roll();

                                if (mainDice.getDiceValue() == 1 || mainDice.getDiceValue() == 6) {
                                    std::cout << mainDice.getDiceValue();
                                    units[i].moveUnit(buttons[j]);
                                    units[i].setSelected(false);
                                    buttons[j].setPressed(false);

                                    if (numberActiveBlue >= 0)
                                        turn = false;

                                    if (units[l].getPosX() == buttons[0].getPosX()) {
                                        if (buttons[1].getColorValue() == "RED" && buttons[8].getColorValue() == "RED" && buttons[9].getColorValue() == "RED" && buttons[2].getColorValue() == "RED" && buttons[3].getColorValue() == "RED") {
                                                std::cout << "DDD" << buttons[1].getColorValue();
                                                units[l].setInteractible(false);
                                                units[l].setPosX(43432);
                                                units[l].setPosY(32323);
                                                numberActiveBlue -= 1;
                                            }
                                        else {


                                                units[l].setPosX(buttons[7].getPosX());
                                                units[l].setPosY(buttons[7].getPosY() + 10);

                                        }
                                    }

                                    if (units[l].getPosX() == buttons[1].getPosX()) {
                                        if (buttons[0].getColorValue() == "RED" &&
                                            buttons[3].getColorValue() == "RED" &&
                                            buttons[4].getColorValue() == "RED" &&
                                            buttons[9].getColorValue() == "RED" &&
                                            buttons[8].getColorValue() == "RED") {
                                            units[l].setInteractible(false);
                                            units[l].setPosX(43432);
                                            units[l].setPosY(32323);
                                            numberActiveBlue -= 1;
                                        } else {
                                            if (units[l].getPosX() != buttons[0].getPosX()) {
                                                units[l].setPosX(buttons[l - 1].getPosX());
                                                units[l].setPosY(buttons[l - 1].getPosY() + 10);
                                            } else {
                                                units[l].setPosX(buttons[l + 1].getPosX());
                                                units[l].setPosY(buttons[l + 1].getPosY() + 10);
                                            }

                                        }


                                    }

                                    if (units[l].getPosX() == buttons[2].getPosX()) {
                                        if (buttons[0].getColorValue() == "RED" &&
                                            buttons[3].getColorValue() == "RED" &&
                                            buttons[5].getColorValue() == "RED")
                                        {
                                            units[l].setInteractible(false);
                                            units[l].setPosX(43432);
                                            units[l].setPosY(32323);
                                            numberActiveBlue -= 1;
                                        }
                                        else {
                                            if (units[l].getPosX() != buttons[0].getPosX()) {
                                                units[l].setPosX(buttons[l - 1].getPosX());
                                                units[l].setPosY(buttons[l - 1].getPosY() + 10);
                                            } else {
                                                units[l].setPosX(buttons[l + 1].getPosX());
                                                units[l].setPosY(buttons[l + 1].getPosY() + 10);
                                            }

                                        }
                                    }

                                    if (units[l].getPosX() == buttons[3].getPosX()) {
                                        if (buttons[0].getColorValue() == "RED" &&
                                            buttons[1].getColorValue() == "RED" &&
                                            buttons[2].getColorValue() == "RED" &&
                                            buttons[4].getColorValue() == "RED" &&
                                            buttons[5].getColorValue() == "RED")
                                        {
                                            units[l].setInteractible(false);
                                            units[l].setPosX(43432);
                                            units[l].setPosY(32323);
                                            numberActiveBlue -= 1;
                                        }
                                        else {
                                            if (units[l].getPosX() != buttons[0].getPosX()) {
                                                units[l].setPosX(buttons[l - 1].getPosX());
                                                units[l].setPosY(buttons[l - 1].getPosY() + 10);
                                            } else {
                                                units[l].setPosX(buttons[l + 1].getPosX());
                                                units[l].setPosY(buttons[l + 1].getPosY() + 10);
                                            }

                                        }
                                    }

                                    if (units[l].getPosX() == buttons[4].getPosX()) {
                                        if (buttons[1].getColorValue() == "RED" &&
                                            buttons[3].getColorValue() == "RED" &&
                                            buttons[5].getColorValue() == "RED" &&
                                            buttons[6].getColorValue() == "RED") {
                                            units[l].setInteractible(false);
                                            units[l].setPosX(43432);
                                            units[l].setPosY(32323);
                                            numberActiveBlue -= 1;
                                        } else {
                                            if (units[l].getPosX() != buttons[0].getPosX()) {
                                                units[l].setPosX(buttons[l - 1].getPosX());
                                                units[l].setPosY(buttons[l - 1].getPosY() + 10);
                                            } else {
                                                units[l].setPosX(buttons[l + 1].getPosX());
                                                units[l].setPosY(buttons[l + 1].getPosY() + 10);
                                            }

                                        }
                                    }

                                    if (units[l].getPosX() == buttons[5].getPosX()) {
                                        if (buttons[2].getColorValue() == "RED" &&
                                            buttons[3].getColorValue() == "RED" &&
                                            buttons[6].getColorValue() == "RED" &&
                                            buttons[7].getColorValue() == "RED" &&
                                            buttons[4].getColorValue() == "RED") {
                                            units[l].setInteractible(false);
                                            units[l].setPosX(43432);
                                            units[l].setPosY(32323);
                                            numberActiveBlue -= 1;
                                        } else {
                                            if (units[l].getPosX() != buttons[0].getPosX()) {
                                                units[l].setPosX(buttons[l - 1].getPosX());
                                                units[l].setPosY(buttons[l - 1].getPosY() + 10);
                                            } else {
                                                units[l].setPosX(buttons[l + 1].getPosX());
                                                units[l].setPosY(buttons[l + 1].getPosY() + 10);
                                            }

                                        }
                                    }

                                    if (units[l].getPosX() == buttons[6].getPosX()) {
                                        if (buttons[5].getColorValue() == "RED" &&
                                            buttons[4].getColorValue() == "RED" &&
                                            buttons[7].getColorValue() == "RED") {
                                            units[l].setInteractible(false);
                                            units[l].setPosX(43432);
                                            units[l].setPosY(32323);
                                            numberActiveBlue -= 1;
                                        } else {
                                            if (units[l].getPosX() != buttons[0].getPosX()) {
                                                units[l].setPosX(buttons[l - 1].getPosX());
                                                units[l].setPosY(buttons[l - 1].getPosY() + 10);
                                            } else {
                                                units[l].setPosX(buttons[l + 1].getPosX());
                                                units[l].setPosY(buttons[l + 1].getPosY() + 10);
                                            }

                                        }
                                    }
                                    if (units[l].getPosX() == buttons[7].getPosX()) {
                                        if (buttons[5].getColorValue() == "RED" &&
                                            buttons[6].getColorValue() == "RED") {
                                            units[l].setInteractible(false);
                                            units[l].setPosX(43432);
                                            units[l].setPosY(32323);
                                            numberActiveBlue -= 1;
                                        } else {
                                            if (units[l].getPosX() != buttons[0].getPosX()) {
                                                units[l].setPosX(buttons[l - 1].getPosX());
                                                units[l].setPosY(buttons[l - 1].getPosY() + 10);
                                            } else {
                                                units[l].setPosX(buttons[l + 1].getPosX());
                                                units[l].setPosY(buttons[l + 1].getPosY() + 10);
                                            }

                                        }

                                    }

                                    if (units[l].getPosX() == buttons[8].getPosX()) {
                                        if (buttons[0].getColorValue() == "RED" &&
                                            buttons[1].getColorValue() == "RED" &&
                                            buttons[9].getColorValue() == "RED" &&
                                            buttons[10].getColorValue() == "RED") {
                                            units[l].setInteractible(false);
                                            units[l].setPosX(43432);
                                            units[l].setPosY(32323);
                                            numberActiveBlue -= 1;
                                        } else {
                                            if (units[l].getPosX() != buttons[0].getPosX()) {
                                                units[l].setPosX(buttons[l - 1].getPosX());
                                                units[l].setPosY(buttons[l - 1].getPosY() + 10);
                                            } else {
                                                units[l].setPosX(buttons[l + 1].getPosX());
                                                units[l].setPosY(buttons[l + 1].getPosY() + 10);
                                            }

                                        }
                                    }

                                    if (units[l].getPosX() == buttons[9].getPosX()) {
                                        if (buttons[0].getColorValue() == "RED" &&
                                            buttons[1].getColorValue() == "RED" &&
                                            buttons[8].getColorValue() == "RED" &&
                                            buttons[10].getColorValue() == "RED" &&
                                            buttons[11].getColorValue() == "RED") {
                                            units[l].setInteractible(false);
                                            units[l].setPosX(43432);
                                            units[l].setPosY(32323);
                                            numberActiveBlue -= 1;
                                        } else {
                                            if (units[l].getPosX() != buttons[0].getPosX()) {
                                                units[l].setPosX(buttons[l - 1].getPosX());
                                                units[l].setPosY(buttons[l - 1].getPosY() + 10);
                                            } else {
                                                units[l].setPosX(buttons[l + 1].getPosX());
                                                units[l].setPosY(buttons[l + 1].getPosY() + 10);
                                            }

                                        }
                                    }

                                    if (units[l].getPosX() == buttons[10].getPosX()) {
                                        if (buttons[8].getColorValue() == "RED" &&
                                            buttons[9].getColorValue() == "RED" &&
                                            buttons[12].getColorValue() == "RED" &&
                                            buttons[13].getColorValue() == "RED" &&
                                            buttons[11].getColorValue() == "RED") {
                                            units[l].setInteractible(false);
                                            units[l].setPosX(43432);
                                            units[l].setPosY(32323);
                                            numberActiveBlue -= 1;
                                        } else {
                                            if (units[l].getPosX() != buttons[0].getPosX()) {
                                                units[l].setPosX(buttons[l - 1].getPosX());
                                                units[l].setPosY(buttons[l - 1].getPosY() + 10);
                                            } else {
                                                units[l].setPosX(buttons[l + 1].getPosX());
                                                units[l].setPosY(buttons[l + 1].getPosY() + 10);
                                            }

                                        }
                                    }

                                    if (units[l].getPosX() == buttons[11].getPosX()) {
                                        if (buttons[10].getColorValue() == "RED" &&
                                            buttons[13].getColorValue() == "RED" &&
                                            buttons[9].getColorValue() == "RED" &&
                                            buttons[14].getColorValue() == "RED" &&
                                            buttons[15].getColorValue() == "RED") {
                                            units[l].setInteractible(false);
                                            units[l].setPosX(43432);
                                            units[l].setPosY(32323);
                                            numberActiveBlue -= 1;
                                        } else {
                                            if (units[l].getPosX() != buttons[0].getPosX()) {
                                                units[l].setPosX(buttons[l - 1].getPosX());
                                                units[l].setPosY(buttons[l - 1].getPosY() + 10);
                                            } else {
                                                units[l].setPosX(buttons[l + 1].getPosX());
                                                units[l].setPosY(buttons[l + 1].getPosY() + 10);
                                            }

                                        }
                                    }

                                    if (units[l].getPosX() == buttons[12].getPosX()) {
                                        if (buttons[10].getColorValue() == "RED" &&
                                            buttons[13].getColorValue() == "RED") {
                                            units[l].setInteractible(false);
                                            units[l].setPosX(43432);
                                            units[l].setPosY(32323);
                                            numberActiveBlue -= 1;
                                        } else {
                                            if (units[l].getPosX() != buttons[0].getPosX()) {
                                                units[l].setPosX(buttons[l - 1].getPosX());
                                                units[l].setPosY(buttons[l - 1].getPosY() + 10);
                                            } else {
                                                units[l].setPosX(buttons[l + 1].getPosX());
                                                units[l].setPosY(buttons[l + 1].getPosY() + 10);
                                            }

                                        }
                                    }

                                    if (units[l].getPosX() == buttons[13].getPosX()) {
                                        if (buttons[12].getColorValue() == "RED" &&
                                            buttons[10].getColorValue() == "RED" &&
                                            buttons[11].getColorValue() == "RED" &&
                                            buttons[14].getColorValue() == "RED") {
                                            units[l].setInteractible(false);
                                            units[l].setPosX(43432);
                                            units[l].setPosY(32323);
                                            numberActiveBlue -= 1;
                                        } else {
                                            if (units[l].getPosX() != buttons[0].getPosX()) {
                                                units[l].setPosX(buttons[l - 1].getPosX());
                                                units[l].setPosY(buttons[l - 1].getPosY() + 10);
                                            } else {
                                                units[l].setPosX(buttons[l + 1].getPosX());
                                                units[l].setPosY(buttons[l + 1].getPosY() + 10);
                                            }

                                        }
                                    }

                                    if (units[l].getPosX() == buttons[14].getPosX()) {
                                        if (buttons[11].getColorValue() == "RED" &&
                                            buttons[13].getColorValue() == "RED" &&
                                            buttons[15].getColorValue() == "RED") {
                                            units[l].setInteractible(false);
                                            units[l].setPosX(43432);
                                            units[l].setPosY(32323);
                                            numberActiveBlue -= 1;
                                        } else {
                                            if (units[l].getPosX() != buttons[0].getPosX()) {
                                                units[l].setPosX(buttons[l - 1].getPosX());
                                                units[l].setPosY(buttons[l - 1].getPosY() + 10);
                                            } else {
                                                units[l].setPosX(buttons[l + 1].getPosX());
                                                units[l].setPosY(buttons[l + 1].getPosY() + 10);
                                            }

                                        }
                                    }

                                    if (units[l].getPosX() == buttons[15].getPosX()) {
                                        if (buttons[14].getColorValue() == "RED" &&
                                            buttons[11].getColorValue() == "RED") {
                                            units[l].setInteractible(false);
                                            units[l].setPosX(43432);
                                            units[l].setPosY(32323);
                                            numberActiveBlue -= 1;
                                        } else {
                                            if (units[l].getPosX() != buttons[0].getPosX()) {
                                                units[l].setPosX(buttons[l - 1].getPosX());
                                                units[l].setPosY(buttons[l - 1].getPosY() + 10);
                                            } else {
                                                units[l].setPosX(buttons[l + 1].getPosX());
                                                units[l].setPosY(buttons[l + 1].getPosY() + 10);
                                            }

                                        }
                                    }



                                    /*else if(buttons[7].getColorValue() == "BLUE")
                                    {


                                        units[l].setPosX(buttons[7].getPosX());
                                        units[l].setPosY(buttons[7].getPosY()+10);

                                    }*/








                                    break;
                                }

                                if (mainDice.getDiceValue() != 6 || mainDice.getDiceValue() != 1) {


                                    std::cout << "LOST";
                                    units[i].setPosX(curPosX);
                                    units[i].setPosY(curPosY);
                                    turn = false;
                                    units[i].setSelected(false);
                                    buttons[j].setPressed(false);

                                }



                                /*if(units[i].battle(units[l], mainDice))
                                {
                                    std::cout << mainDice.getDiceValue();
                                    units[i].moveUnit(buttons[j]);
                                    units[i].setSelected(false);
                                    buttons[j].setPressed(false);
                                    turn = false;
                                }*/
                            }
                        }

                        if (turn) {
                            units[i].moveUnit(buttons[j]);
                            units[i].setSelected(false);
                            buttons[j].setPressed(false);
                            if (numberActiveBlue >= 0)
                                turn = false;
                        }


                    }

                    if (units[i].getSide() == "BLUE" && turn == 0 && buttons[j].getPosX() != units[i].getPosX()) {
                        int curPosX = units[i].getPosX(), curPosY = units[i].getPosY();
                        for (int l = 0; l < 4; l++) {
                            if (buttons[j].getPosX() == units[l].getPosX()) {
                                mainDice.roll();

                                if (mainDice.getDiceValue() == 1 || mainDice.getDiceValue() == 6) {
                                    std::cout << mainDice.getDiceValue();
                                    units[i].moveUnit(buttons[j]);
                                    units[i].setSelected(false);
                                    buttons[j].setPressed(false);
                                    turn = true;


                                    if (units[l].getPosX() == buttons[0].getPosX()) {
                                        if (buttons[1].getColorValue() == "BLUE" &&
                                            buttons[8].getColorValue() == "BLUE" &&
                                            buttons[9].getColorValue() == "BLUE",
                                                buttons[2].getColorValue() == "BLUE" &&
                                                buttons[3].getColorValue() == "BLUE") {
                                            units[l].setInteractible(false);
                                            units[l].setPosX(43432);
                                            units[l].setPosY(32323);
                                        }
                                    }

                                    if (units[l].getPosX() == buttons[1].getPosX()) {
                                        if (buttons[0].getColorValue() == "RED" &&
                                            buttons[3].getColorValue() == "RED" &&
                                            buttons[4].getColorValue() == "RED" &&
                                            buttons[9].getColorValue() == "RED" &&
                                            buttons[8].getColorValue() == "RED") {
                                            units[l].setInteractible(false);
                                            units[l].setPosX(43432);
                                            units[l].setPosY(32323);
                                        }
                                    }

                                    /*if(units[i].battle(units[l], mainDice))
                                    {
                                        std::cout << mainDice.getDiceValue();
                                        units[i].moveUnit(buttons[j]);
                                        units[i].setSelected(false);
                                        buttons[j].setPressed(false);
                                        turn = true;
                                    }*/
                                }
                            }

                            if (!turn) {
                                units[i].moveUnit(buttons[j]);
                                units[i].setSelected(false);
                                buttons[j].setPressed(false);
                                turn = true;
                            }

                        }



                        /*else
                        {
                            units[i].setSelected(false);
                            buttons[j].setPressed(false);
                        }*/



                    } else {
                        //units[i].setSelected(false);
                        buttons[j].setPressed(false);
                    }


                }
            }


        }
    }
}

int main(void)
{
    SetupButtons();


    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Nambuk");
    SetTargetFPS(60);
    Texture2D background = LoadTexture("D:/CPP Projects/Nambuk/assets/background.png");
    Texture2D map = LoadTexture("D:/CPP Projects/Nambuk/assets/Map.png");
    Texture2D dice[6] = {LoadTexture("D:/CPP Projects/Nambuk/assets/Dice1.png"),
                         LoadTexture("D:/CPP Projects/Nambuk/assets/Dice2.png"),
                         LoadTexture("D:/CPP Projects/Nambuk/assets/Dice3.png"),
                         LoadTexture("D:/CPP Projects/Nambuk/assets/Dice4.png"),
                         LoadTexture("D:/CPP Projects/Nambuk/assets/Dice5.png"),
                         LoadTexture("D:/CPP Projects/Nambuk/assets/Dice6.png")};


    while (!WindowShouldClose()) {
        Update();

        DrawTexture(background, 0, 0, WHITE);
        DrawTexture(map, (SCREEN_WIDTH / 2) - (312 / 2), (SCREEN_HEIGHT / 2) - (495 / 2), WHITE);
        DrawTexture(dice[mainDice.getDiceValue() - 1], 50, 580, WHITE);
        BeginDrawing();
        ClearBackground(RAYWHITE);

        DrawText(turnText, (SCREEN_WIDTH / 2) - 220, 50, 50, BLACK);


        //Drawing buttons
        for (int i = 0; i < 16; i++) {

            DrawCircle(buttons[i].getPosX(), buttons[i].getPosY(), 10, buttons[i].getColour());

        }

        for (int i = 0; i < 4; i++) {
            DrawCircle(units[i].getPosX(), units[i].getPosY(), 11, units[i].getColour());

        }

        EndDrawing();
    }


    UnloadTexture(background);
    CloseWindow();

    return 0;
}






