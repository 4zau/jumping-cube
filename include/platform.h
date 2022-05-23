#ifndef UNTITLED_PLATFORM_H
#define UNTITLED_PLATFORM_H
#include <raylib.h>
#include "entity.h"

class Platform : public Entity {
private:
    float speed = 0.8;
    Color color = BLACK;
    Rectangle rect;
    float roundness = 0.5;
    int segments = 5;
public:
    void init(float x, float y, float h, float w);
    void update();
    void draw();
    Platform(float x, float y, float h, float w, Color c);
};

#endif //UNTITLED_PLATFORM_H
