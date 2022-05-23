#include <raylib.h>
#include "include/player.h"
#include "include/platform.h"
#include <math.h>
#include <ctime>

enum State {
    Maingame,
    Titlescreen,
    Deathscreen
};

const int screenWidth = 800;
const int screenHeight = 450;
bool boot = true;
State state = Titlescreen;
Sound deathSound;
Sound titleSound;

void mainGame(Player *player, Platform *platforms);

void titleScreen();

void deathScreen();

int main() {

    srand(time(NULL));

    Platform platforms[4] = {
            Platform(rand() % (screenWidth-100), 0, 30, 100, BLACK),
            Platform(rand() % (screenWidth-100), -200, 30, 100, BLACK),
            Platform(rand() % (screenWidth-100), -400, 30, 100, BLACK),
            Platform(rand() % (screenWidth-100), -600, 30, 100, BLACK),
    };

    InitWindow(screenWidth, screenHeight, "endless... something");
    InitAudioDevice();

    SetTargetFPS(60);

    deathSound = LoadSound("res/death.wav");
    titleSound = LoadSound("res/title.wav");

    Player player(screenWidth/2 - 15,screenHeight/2 - 15, 30, 30, RED, LoadSound("res/jump.wav"));

    PlaySound(titleSound);

    while (!WindowShouldClose()) {
        switch (state) {
            case Titlescreen:
                titleScreen();
                break;
            case Maingame:
                mainGame(&player, platforms);
                break;
            case Deathscreen:
                deathScreen();
                break;
        }
    }

    CloseWindow();

    return 0;
}

void deathScreen() {
    if (IsMouseButtonReleased(0) || IsMouseButtonReleased(1)) {
        state = Maingame;
    }
    BeginDrawing();
    ClearBackground(RAYWHITE);

    DrawText("  You've just died!", screenWidth/2- 250, screenHeight/2  - 80, 50, GRAY);

    DrawText("press mouse button to begin", screenWidth/2- 175, screenHeight/2  + 30, 25, (Color){130,130,130,100});

    EndDrawing();
}

void titleScreen() {
    if (IsMouseButtonReleased(0) || IsMouseButtonReleased(1)) {
        state = Maingame;
    }

    BeginDrawing();
    ClearBackground(RAYWHITE);

    DrawText("Endless... something...", screenWidth/2- 255, screenHeight/2  - 80, 50, GRAY);

    DrawText("press mouse button to begin", screenWidth/2- 175, screenHeight/2  + 30, 25, (Color){130,130,130,100});

    EndDrawing();
}

void mainGame(Player *player, Platform *platforms) {
    if (boot) {
        player->setX(platforms[0].getX() + platforms[0].getW() / 2 - player->getW() / 2);
        player->setY(platforms[0].getY() - player->getH());
        boot = false;
    }

    // check if player is in lava and reset all values
    if(player->getY() + player->getH() > screenHeight - 50 + sin(GetTime()) * 10) {
        boot = true;
        platforms[0] = Platform(rand() % (screenWidth-100), 0, 30, 100, BLACK);
        platforms[1] = Platform(rand() % (screenWidth-100), -200, 30, 100, BLACK);
        platforms[2] = Platform(rand() % (screenWidth-100), -400, 30, 100, BLACK);
        platforms[3] = Platform(rand() % (screenWidth-100), -600, 30, 100, BLACK);
        PlaySound(deathSound);
        state = Deathscreen;
    }

    player->update(platforms);

    for(int i = 0; i < 4; i++) {
        platforms[i].update();
    }

    BeginDrawing();

    ClearBackground(RAYWHITE);

    for(int i = 0; i < 4; i++) {
        platforms[i].draw();
    }

    player->draw();

    DrawRectangle(0, screenHeight - 50 + sin(GetTime()) * 10, screenWidth, 70, ORANGE);

    EndDrawing();
}
