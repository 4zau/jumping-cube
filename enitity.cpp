#include "include/entity.h"

Entity::Entity(float _x, float _y, float _h, float _w, Color _c) {
    x = _x;
    y = _y;
    h = _h;
    w = _w;
    color = _c;
}

float Entity::getX() {
    return x;
}

float Entity::getY() {
    return y;
}

void Entity::setX(float _x) {
    x = _x;
}

void Entity::setY(float _y) {
    y = _y;
}

float Entity::getW() {
    return w;
}

float Entity::getH() {
    return h;
}

void Entity::setH(float _x) {
    h = _x;
}

void Entity::setW(float _y) {
    w = _y;
}

Color Entity::getColor() {
    return color;
}

void Entity::setColor(Color _c) {
    color = _c;
}
