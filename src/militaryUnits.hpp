#pragma once
#include "raylib.h"
#include "button.hpp"
#include "string"

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
private:
    string side;
    bool selected;
};