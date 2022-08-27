#include "raylib.h"
#pragma comment(lib, "winmm")
#include <iostream>
#include <string>
using namespace std;
// 函数声明
void move();
void unloadTexture();
//全局变量asd
Texture2D imagebox[6];
int sprite_position[2] = {400, 250};
// main
int main(void)
{
    //配置信息
    const int screenWidth = 800;
    const int screenHeight = 450;
    const int FPS = 60;
    int count = 0;
    int framesCounter = 0;
    int framesSpeed = 8;

    string titile;
    titile = "games";
    InitWindow(screenWidth, screenHeight, titile.c_str());
    // Set FPS 60
    SetTargetFPS(FPS);
    //加载资源
    for (size_t i = 0; i < 6; i++)
    {
        Image man = LoadImage(("asset/man" + to_string(i) + ".png").c_str());
        imagebox[i] = LoadTextureFromImage(man);
        UnloadImage(man);
    }
    while (!WindowShouldClose())
    {
        framesCounter++;

        if (framesCounter >= (FPS / framesSpeed))
        {
            count++;
            framesCounter = 0;
        }
        move();
        BeginDrawing();
        ClearBackground(WHITE);
        DrawTexture(imagebox[count % 6], sprite_position[0], sprite_position[1], WHITE);
        DrawText("c++ games demo!", 0, 0, 50, BLACK);
        EndDrawing();
    }

    unloadTexture();
    CloseWindow();

    return 0;
}

void move()
{
    if (IsKeyDown(KEY_LEFT))
    {
        int x = sprite_position[0] - 1;
        sprite_position[0] = x;
    }
    if (IsKeyDown(KEY_RIGHT))
    {
        int x = sprite_position[0] + 1;
        sprite_position[0] = x;
    }
    if (IsKeyDown(KEY_UP))
    {
        int y = sprite_position[1] - 1;
        sprite_position[1] = y;
    }
    if (IsKeyDown(KEY_DOWN))
    {
        int y = sprite_position[1] + 1;
        sprite_position[1] = y;
    }
}

void unloadTexture()
{
    //卸载资源
    for (size_t i = 0; i < 6; i++)
    {
        UnloadTexture(imagebox[i]);
    }
}