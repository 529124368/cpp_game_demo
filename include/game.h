#include "raylib.h"
class Game
{
private:
    Texture2D imagebox[6];
    Vector2 postion;
    //配置信息
    int screenWidth = 800;
    int screenHeight = 600;
    int FPS = 60;
    int count = 0;
    int framesCounter = 0;
    int framesSpeed = 8;
    RenderTexture2D target;
    void unloadTexture();
    void controller();

public:
    void run();
    void load();
};
