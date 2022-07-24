#include <raylib.h>
#include "dice.hpp"

int dice::getDiceValue() {
    return value;
}

void dice::roll() {
    value = GetRandomValue(6, 6); //supposed to be 1 and 6, I am just doing this for testing purposes
}