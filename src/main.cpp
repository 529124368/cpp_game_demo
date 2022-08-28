#include "raylib.h"
#include "raymath.h"
#pragma comment(lib, "winmm")
#include <iostream>
#include <string>
#include "main.h"
using namespace std;
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
//全局变量asd
Texture2D imagebox[6];
int sprite_position[2] = {400, 250};
// main
int main(void)
{
    //配置信息
    const int screenWidth = 800;
    const int screenHeight = 600;
    const int FPS = 60;
    int count = 0;
    int framesCounter = 0;
    int framesSpeed = 8;

    string titile;
    titile = "games";
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(screenWidth, screenHeight, titile.c_str());
    RenderTexture2D target = LoadRenderTexture(screenWidth, screenHeight);
    SetTextureFilter(target.texture, TEXTURE_FILTER_BILINEAR);
    // ToggleFullscreen();
    //  Set FPS 60
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
        DrawTexture(imagebox[count % 6], sprite_position[0], sprite_position[1], WHITE);
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

    return 0;
}

void controller()
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
