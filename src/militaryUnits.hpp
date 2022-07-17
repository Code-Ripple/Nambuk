#pragma once
#include "raylib.h"
#include "button.hpp"
#include "string"
#include "dice.hpp"

using std::string;

class militaryUnit : public button
{
public:
    string getSide();
    void setSide(string newSide);
    void moveUnit(button location);
    bool unitSelected();
    void setSelected(bool newValue);
    void Update();
    void actionOfMoving(button location);
    bool battle(militaryUnit otherUnit, dice Dice);
private:
    string side;
    bool selected;
};