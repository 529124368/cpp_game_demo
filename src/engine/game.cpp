#include "raylib.h"
#include "raymath.h"
#include <string>
#include <iostream>
using namespace std;
#pragma comment(lib, "winmm")
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
class Game
{
private:
    Texture2D imagebox[6];
    Texture2D uibox[1];
    Vector2 postion;
    //配置信息
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

Game::Game(void)
{
    screenWidth = 800;
    screenHeight = 600;
    FPS = 60;
    count = 0;
    framesCounter = 0;
    framesSpeed = 8;
    //初始坐标
    postion.x = 400;
    postion.y = 250;
}
Game::~Game(void)
{
    UnloadRenderTexture(target);
    unloadTexture();
    CloseWindow();
}
void Game::load(void)
{

    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(screenWidth, screenHeight, "games");
    target = LoadRenderTexture(screenWidth, screenHeight);
    SetTextureFilter(target.texture, TEXTURE_FILTER_BILINEAR);
    // Set FPS 60
    SetTargetFPS(FPS);

    //加载资源
    for (size_t i = 0; i < 6; i++)
    {
        Image man = LoadImage(("asset/man" + to_string(i) + ".png").c_str());
        imagebox[i] = LoadTextureFromImage(man);
        UnloadImage(man);
    }
    //加载UI
    Image ui = LoadImage("asset/menu.png");
    uibox[0] = LoadTextureFromImage(ui);
    UnloadImage(ui);
};

void Game::run(void)
{
    while (!WindowShouldClose())
    {
        float scale = MIN((float)GetScreenWidth() / screenWidth, (float)GetScreenHeight() / screenHeight);
        framesCounter++;

        if (framesCounter >= (FPS / framesSpeed))
        {
            count++;
            if (count > 5)
            {
                count = 0;
            }

            framesCounter = 0;
        }
        //控制器
        controller();
        //绘制东西到画布上
        BeginTextureMode(target);
        ClearBackground(WHITE);
        DrawTexture(imagebox[count], postion.x, postion.y, WHITE);
        DrawTexture(imagebox[0], 0, 200, WHITE);
        // ui
        DrawTexture(uibox[0], 0, 0, WHITE);
        DrawFPS(1, 1);
        EndTextureMode();
        //开始绘制
        BeginDrawing();
        ClearBackground(BLACK);
        DrawTexturePro(target.texture, Rectangle{0.0, 0.0, (float)target.texture.width, -((float)target.texture.height)},
                       Rectangle{(GetScreenWidth() - ((float)screenWidth * scale)) * 0.5f, (GetScreenHeight() - ((float)screenHeight * scale)) * 0.5f,
                                 (float)screenWidth * scale, float(screenHeight * scale)},
                       Vector2{0, 0}, 0.0f, WHITE);
        EndDrawing();
    }
};

void Game::unloadTexture(void)
{
    //卸载资源
    for (size_t i = 0; i < 6; i++)
    {
        UnloadTexture(imagebox[i]);
    }
}

void Game::controller(void)
{
    if (IsKeyDown(KEY_LEFT))
    {
        postion.x -= 1;
    }
    if (IsKeyDown(KEY_RIGHT))
    {
        postion.x += 1;
    }
    if (IsKeyDown(KEY_UP))
    {
        postion.y -= 1;
    }
    if (IsKeyDown(KEY_DOWN))
    {
        postion.y += 1;
    }
}
