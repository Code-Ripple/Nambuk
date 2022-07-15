#pragma once
#include "raylib.h"
#include "string"

class button
{
public:
    Rectangle getRect();
    void setPosX(int value);
    void setPosY(int value);
    int getPosX() const;
    int getPosY() const;
    void press();
    void setColour(Color newColour);
    Color getColour();
    void Update();

private:
    Rectangle rect;
    Color colour;
};

