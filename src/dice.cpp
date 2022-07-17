#include <raylib.h>
#include "dice.hpp"

int dice::getDiceValue() {
    return value;
}

void dice::roll() {
    value = GetRandomValue(6, 6);
}