#include <cstring>
#include <iostream>
#include "militaryUnits.hpp"

using std::string;

//#define GET_VARIABLE_NAME(Variable) (#Variable)
#define GET_VARIABLE_NAME(Variable) (void(Variable),#Variable)

string militaryUnit::getSide() {
    return side;
}

void militaryUnit::setSide(string newSide) {
    side = newSide;
}

bool militaryUnit::unitSelected() {
    return selected;
}

void militaryUnit::moveUnit(button location) {
    std::cout << location.getColorValue() << std::endl;
    setPosX(location.getPosX());
    setPosY(location.getPosY() + 10);


    std::cout << "side: " << side << std::endl;
    /*if(std::strcmp(GET_VARIABLE_NAME(location.getColour()), "BLUE") != 0 && std::strcmp(side, "BLUE") == 0)
    {
        location.setColour(BLUE);
    }

    if(std::strcmp(GET_VARIABLE_NAME(location.getColour()), "RED") != 0 && std::strcmp(side, "BLUE") == 0)
    {
        location.setColour(RED);
    }*/

    if(location.getColorValue() == "BLUE" && side == "RED")
    {
        location.setColour(RED);
        location.setColourValue("RED");
    }

    if(location.getColorValue() == "RED" && side == "BLUE")
    {
        location.setColour(BLUE);
        location.setColourValue("BLUE");
    }

    if(location.getColorValue() == "RED" && side == "RED")
    {
        location.setColour(RED);
        location.setColourValue("RED");
    }

    if(location.getColorValue() == "BLUE" && side == "BLUE")
    {
        location.setColour(BLUE);
        location.setColourValue("BLUE");
    }

    location.setPressed(false);
    std::cout << location.getColorValue();
    selected = false;
}

void militaryUnit::setSelected(bool newValue) {
    selected = newValue;
}

void militaryUnit::Update() {
    if(IsMouseButtonPressed(0))
    {
        if(GetMouseX() >= getPosX() - 7 && GetMouseX() <= getPosX() + 7 && GetMouseY() >= getPosY() - 7 && GetMouseY() <= getPosY() + 7)
        {
            setSelected(true);
        }
    }
}