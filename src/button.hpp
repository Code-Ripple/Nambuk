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
    bool getInteractible();
    void setInteractible(bool value);
    bool pressedButton();
    void setPressed(bool newValue);
    std::string getColorValue();
    void setColourValue(std::string newValue);
    int getProvinceNumber();
    void setProvinceNumber(int newProvinceNumber);
private:
    Rectangle rect;
    Color colour;
    bool isInteractible;
    bool hasPressedButton;
    std::string colourValue;
    int provinceNumber;

};

