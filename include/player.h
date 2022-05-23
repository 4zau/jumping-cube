#ifndef UNTITLED_PLAYER_H
#define UNTITLED_PLAYER_H
#include "entity.h"
#include "platform.h"

class Player: public Entity {
private:
    float velocityX = 0;
    float velocityY = 0;
    float gravity = 0.1;
    bool onGround = false;
    float mouseDownX = 0;
    float mouseDownY = 0;
    Sound jumpSound;
public:
    Player(float x, float y,float h, float w, Color color, Sound sound);
    void update(Platform *platforms);
    void draw();
    bool checkCollision(Platform *platforms);
};

#endif //UNTITLED_PLAYER_H
