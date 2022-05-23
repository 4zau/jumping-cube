#include "include/platform.h"
#include <raylib.h>
#include <math.h>

const int screenWidth = 800;
const int screenHeight = 450;

void Platform::draw() {
    DrawRectangleRounded(rect, roundness, segments, getColor());
}

void Platform::update() {
    setY(getY() + speed);
    if (getY()>screenHeight) {
        setY(0 - getH());
        setX(rand() % (screenWidth-100));
        rect.x = getX();
    }
    rect.y = getY();
}

Platform::Platform(float x, float y, float h, float w, Color c) : Entity(x, y, h, w, c) {
    rect = Rectangle {x,y,w,h};
}
