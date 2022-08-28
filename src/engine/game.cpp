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

void Game::load()
{
    //初始坐标
    postion.x = 400;
    postion.y = 250;
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(screenWidth, screenHeight, "games");
    target = LoadRenderTexture(screenWidth, screenHeight);
    SetTextureFilter(target.texture, TEXTURE_FILTER_BILINEAR);
    //  Set FPS 60
    SetTargetFPS(FPS);

    //加载资源
    for (size_t i = 0; i < 6; i++)
    {
        Image man = LoadImage(("asset/man" + to_string(i) + ".png").c_str());
        imagebox[i] = LoadTextureFromImage(man);
        UnloadImage(man);
    }
};

void Game::run()
{
    while (!WindowShouldClose())
    {
        float scale = MIN((float)GetScreenWidth() / screenWidth, (float)GetScreenHeight() / screenHeight);
        framesCounter++;

        if (framesCounter >= (FPS / framesSpeed))
        {
            count++;
            framesCounter = 0;
        }
        controller();
        //
        BeginTextureMode(target);
        ClearBackground(WHITE);
        DrawTexture(imagebox[count % 6], postion.x, postion.y, WHITE);
        DrawTexture(imagebox[0], 0, 200, WHITE);
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

    unloadTexture();
    CloseWindow();
};

void Game::unloadTexture()
{
    //卸载资源
    for (size_t i = 0; i < 6; i++)
    {
        UnloadTexture(imagebox[i]);
    }
}

void Game::controller()
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