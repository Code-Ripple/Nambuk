#include "button.hpp"
#include "iostream"

#define BlueColour (Color){ 0, 121, 241, 255 }
#define RedColour (Color){ 230, 41, 55, 255 }

Rectangle button::getRect()
{
    return rect;
}

int button::getPosX() const {

    return rect.x;
}

int button::getPosY() const
{
    return rect.y;
}

void button::setPosX(int value)
{
    rect.x = value;
}

void button::setPosY(int value)
{
    rect.y = value;
}

void button::press()
{
    hasPressedButton = true;
}

void button::setColour(Color newColour)
{
    colour = newColour;
}

Color button::getColour()
{
    return colour;
}

void button::Update()
{

    if(IsMouseButtonPressed(0))
    {
       if(GetMouseX() >= rect.x - 6 && GetMouseX() <= rect.x + 6 && GetMouseY() >= rect.y - 6 && GetMouseY() <= rect.y + 6)
       {
           press();
       }
    }

   if(colourValue == "RED")
    {
        colour = RedColour;
    }

    if(colourValue == "BLUE")
    {
        colour = BlueColour;
    }

}

bool button::getInteractible() {
    return isInteractible;
}

void button::setInteractible(bool value) {
    isInteractible = value;
}

bool button::pressedButton() {
    return hasPressedButton;
}

void button::setPressed(bool newValue) {
    hasPressedButton = newValue;
}

std::string button::getColorValue() {
    return colourValue;
}

void button::setColourValue(std::string newValue) {
    colourValue = newValue;
}

int button::getProvinceNumber() {
    return provinceNumber;
}

void button::setProvinceNumber(int newProvinceNumber) {
    provinceNumber = newProvinceNumber;
}


