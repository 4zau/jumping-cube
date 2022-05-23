#include "include/player.h"
#include <raylib.h>
#include "include/platform.h"

const int screenWidth = 800;
const int screenHeight = 450;

Player::Player(float x, float y,float h, float w, Color color, Sound sound) : Entity(x,y,h,w,color) {
    jumpSound = sound;
}

void Player::draw() {
    DrawRectangle(getX(), getY(), getW(), getH(), getColor());
    if (IsMouseButtonDown(0) && onGround && mouseDownX && mouseDownY)
    {
        DrawLineEx(Vector2{mouseDownX, mouseDownY},
                   Vector2{(float)GetMouseX(), (float)GetMouseY()},
                   3.f, YELLOW);
    }
}

void Player::update(Platform *platforms) {

    onGround = checkCollision(platforms);

    // TODO: MAKE DEATH
    if (getY() + velocityY > screenHeight - getH()) {
        velocityY = 0;
        velocityX = 0;
        onGround = true;
    }

    // gravity
    if (!onGround){
        velocityY += gravity;
    }

    // remember mouse position when clicked
    if (IsMouseButtonPressed(0)) {
        mouseDownX = GetMouseX();
        mouseDownY = GetMouseY();
    }

    // released, jump.wav!
    if (IsMouseButtonReleased(0) && onGround)
    {
        // uncomment if too much stucking
        // setY(getY() - 1);

        float _velX = GetMouseX() - mouseDownX;
        float _velY = GetMouseY() - mouseDownY;

        velocityX += _velX * .05;
        velocityY += _velY * .05;

        onGround = false;
        mouseDownY = 0;
        mouseDownX = 0;

        PlaySound(jumpSound);
    }

    if (getX() < 0 || getX() > screenWidth - getW())
        velocityX *= -1;


    setX(getX() + velocityX);
    setY(getY() + velocityY);
}

bool Player::checkCollision(Platform *platforms) {
    for (int i = 0; i < 4; i++)
    {
        if (
            getX()           < platforms[i].getX() + platforms[i].getW() &&
            getX() + getW()  > platforms[i].getX() &&
            getY() + getH() >= platforms[i].getY() &&
            getY()           < platforms[i].getY() + platforms[i].getH())
        {
            if (getY() > platforms[i].getY() + platforms[i].getH() / 2 - 10) {
                velocityY = 2;
                return false;
            } else if (getY() + getH() < platforms[i].getY() + platforms[i].getH()) {
                velocityX = 0;
                setY(platforms[i].getY() - getH() + 0.8);
                velocityY = 0;
                return true;
            }
            velocityX *= -1;
        }
    }
    return false;
}
