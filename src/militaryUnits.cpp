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

void militaryUnit::actionOfMoving(button location) {
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

void militaryUnit::moveUnit(button location) {
    if(getProvinceNumber() == 1)
    {
        if(location.getProvinceNumber() == 2 || location.getProvinceNumber() == 3 || location.getProvinceNumber() == 4 || location.getProvinceNumber() == 9 || location.getProvinceNumber() == 10)
        {
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
            //actionOfMoving(location);
        }
    }

    if(getProvinceNumber() == 2)
    {
        if(location.getProvinceNumber() == 1 || location.getProvinceNumber() == 5 || location.getProvinceNumber() == 4 || location.getProvinceNumber() == 9 || location.getProvinceNumber() == 10)
        {
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
            //actionOfMoving(location);
        }
    }

    if(getProvinceNumber() == 3)
    {
        if(location.getProvinceNumber() == 1 || location.getProvinceNumber() == 4 || location.getProvinceNumber() == 6)
        {
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
    }

    if(getProvinceNumber() == 4)
    {
        if(location.getProvinceNumber() == 1 || location.getProvinceNumber() == 2 || location.getProvinceNumber() == 3 || location.getProvinceNumber() == 5 || location.getProvinceNumber() == 6)
        {
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
    }

    if(getProvinceNumber() == 5)
    {
        if(location.getProvinceNumber() == 2 || location.getProvinceNumber() == 4 || location.getProvinceNumber() == 6 || location.getProvinceNumber() == 7)
        {
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
    }

    if(getProvinceNumber() == 8)
    {
        if(location.getProvinceNumber() == 3 || location.getProvinceNumber() == 4 || location.getProvinceNumber() == 5 || location.getProvinceNumber() == 15 || location.getProvinceNumber() == 8)
        {
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
    }

    if(getProvinceNumber() == 15)
    {
        if(location.getProvinceNumber() == 6 || location.getProvinceNumber() == 5 || location.getProvinceNumber() == 8)
        {
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
    }

    if(getProvinceNumber() == 8)
    {
        if(location.getProvinceNumber() == 6 || location.getProvinceNumber() == 7 || location.getProvinceNumber() == 8)
        {

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
    }

    if(getProvinceNumber() == 9)
    {
        if(location.getProvinceNumber() == 1 || location.getProvinceNumber() == 2 || location.getProvinceNumber() == 10  || location.getProvinceNumber() == 11)
        {



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
    }

    if(getProvinceNumber() == 10)
    {
        if(location.getProvinceNumber() == 1 || location.getProvinceNumber() == 2 || location.getProvinceNumber() == 9 || location.getProvinceNumber() == 11 || location.getProvinceNumber() == 12)
        {
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
    }

    if(getProvinceNumber() == 11)
    {
        if(location.getProvinceNumber() == 9 || location.getProvinceNumber() == 10 || location.getProvinceNumber() == 12 || location.getProvinceNumber() == 13 || location.getProvinceNumber() == 14)
        {
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
    }

    if(getProvinceNumber() == 12)
    {
        if(location.getProvinceNumber() == 10 || location.getProvinceNumber() == 11 || location.getProvinceNumber() == 14 || location.getProvinceNumber() == 15 || location.getProvinceNumber() == 16)
        {
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
    }

    if(getProvinceNumber() == 13)
    {
        if(location.getProvinceNumber() == 14 || location.getProvinceNumber() == 11)
        {
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
    }

    if(getProvinceNumber() == 14)
    {
        if(location.getProvinceNumber() == 13 || location.getProvinceNumber() == 11 || location.getProvinceNumber() == 12 || location.getProvinceNumber() == 15)
        {
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
    }

    if(getProvinceNumber() == 15)
    {
        if(location.getProvinceNumber() == 12 || location.getProvinceNumber() == 14 || location.getProvinceNumber() == 16)
        {
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
    }

    if(getProvinceNumber() == 16)
    {
        if(location.getProvinceNumber() == 12 || location.getProvinceNumber() == 15)
        {
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
    }





    else
    {
        selected = false;
        location.setPressed(false);
    }



}

void militaryUnit::setSelected(bool newValue) {
    selected = newValue;
}

void militaryUnit::Update() {
    std::cout << getProvinceNumber() << std::endl;

    if(IsMouseButtonPressed(0))
    {
        if(GetMouseX() >= getPosX() - 7 && GetMouseX() <= getPosX() + 7 && GetMouseY() >= getPosY() - 7 && GetMouseY() <= getPosY() + 7)
        {
            setSelected(true);
        }
    }
}