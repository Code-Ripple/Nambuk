#include "button.hpp"
#include "iostream"


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
    colour = RED;
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
       if(GetMouseX() >= rect.x - 5 && GetMouseX() <= rect.x + 5 && GetMouseY() >= rect.y - 5 && GetMouseY() <= rect.y + 5)
       {
           press();
       }
    }
}


