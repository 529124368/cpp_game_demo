#ifndef GAME_H
#define GAME_H
#include "raylib.h"

class Game
{
private:
    Texture2D imagebox[1];
    Texture2D uibox[1];
    Texture2D map;
    Vector2 postion;
    float move_speed;
    int screenWidth;
    int screenHeight;
    int FPS;
    int count;
    int framesCounter;
    int framesSpeed;
    RenderTexture2D target;
    void unloadTexture(void);
    void controller(void);

public:
    void run(void);
    void load(void);
    Game();
    ~Game();
};
#endif
