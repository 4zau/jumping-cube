#ifndef UNTITLED_ENTITY_H
#define UNTITLED_ENTITY_H
#include <raylib.h>
class Entity {
private:
    float x;
    float y;
    float w;
    float h;
    Color color;
public:
    Entity(float x, float y, float h, float w, Color c);
    void setX(float _x);
    float getX();
    void setY(float _y);
    float getY();
    void setW(float _x);
    float getW();
    void setH(float _y);
    float getH();
    void setColor(Color _c);
    Color getColor();
    void update();
    void draw();
};
#endif
