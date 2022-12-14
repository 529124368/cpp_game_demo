#include "raylib.h"
#include "raymath.h"
#include <string>
#include <iostream>
#include <filesystem>
using namespace std;
#pragma comment(lib, "winmm")
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
class Game
{
private:
    Texture2D imagebox[1];
    Texture2D uibox[1];
    Texture2D map;
    Vector2 postion;
    float move_speed;
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
    move_speed = 2.0;
    framesCounter = 0;
    framesSpeed = 8;
    //初始坐标
    postion.x = -1800;
    postion.y = -1800;
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
    // FPS 60
    SetTargetFPS(FPS);

    //加载资源
    // for (size_t i = 0; i < 6; i++)
    // {
    //     Image man = LoadImage(("asset/man" + to_string(i) + ".png").c_str());
    //     imagebox[i] = LoadTextureFromImage(man);
    //     UnloadImage(man);
    // }
    Image man = LoadImage("asset/player.png");
    imagebox[0] = LoadTextureFromImage(man);
    UnloadImage(man);
    //加载UI
    Image ui = LoadImage("asset/menu.png");
    uibox[0] = LoadTextureFromImage(ui);
    UnloadImage(ui);
    //加载地图
    Image map_temp = LoadImage("asset/map.png");
    map = LoadTextureFromImage(map_temp);
    UnloadImage(map_temp);
};

void Game::run(void)
{
    while (!WindowShouldClose())
    {
        float scale = MIN((float)GetScreenWidth() / screenWidth, (float)GetScreenHeight() / screenHeight);
        framesCounter++;

        if (framesCounter >= (FPS / framesSpeed))
        {
            // count++;
            // if (count > 5)
            // {
            //     count = 0;
            // }

            framesCounter = 0;
        }
        //控制器
        controller();
        //绘制东西到画布上
        BeginTextureMode(target);
        ClearBackground(WHITE);
        // map
        DrawTextureEx(map, postion, 1, 1.3, WHITE);
        // player
        // DrawTexture(imagebox[count], screenWidth / 2 - 40, screenHeight / 2 - 40, WHITE);
        DrawTexture(imagebox[0], screenWidth / 2 - 40, screenHeight / 2 - 40, WHITE);
        // ui
        DrawTexture(uibox[0], (screenWidth - uibox[0].width) / 2, screenHeight - 144, WHITE);
        Vector2 mouse = GetMousePosition();
        auto text_mouse = "mouse position :" + to_string(mouse.x) + ":" + to_string(mouse.y);
        DrawText(text_mouse.c_str(), screenWidth / 2, 3, 20, RED);
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
    UnloadTexture(uibox[0]);
    UnloadTexture(map);
}

void Game::controller(void)
{
    if (IsKeyDown(KEY_LEFT))
    {
        postion.x += move_speed;
    }
    if (IsKeyDown(KEY_RIGHT))
    {
        postion.x -= move_speed;
    }
    if (IsKeyDown(KEY_UP))
    {
        postion.y += move_speed;
    }
    if (IsKeyDown(KEY_DOWN))
    {
        postion.y -= move_speed;
    }
}
