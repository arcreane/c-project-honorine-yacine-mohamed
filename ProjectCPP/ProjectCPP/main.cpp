#include "raylib.h"
#include <iostream>
#include "Hero.h"

using namespace std;

void onKeyDown(Texture2D* myHero, Vector2* position, Rectangle* frameRec);
Hero player = Hero("Name", 0, 0, 0, 0, 0);

int currentFrame = 0;
int framesCounter = 0;
float frameSpeed = 15;
int moveX = 7;
const int screenWidth = 1270;
const int screenHeight = 800;
int playerPosX;
int playerPosY;


int main(void)
{

    player.setPosY(600);
    int playerPosX = player.getPosX();
    int playerPosY = player.getPosY();

    InitWindow(screenWidth, screenHeight, "raylib [textures] example - image loading");

    Image image = LoadImage("resources/bg.png");
    Image btn = LoadImage("resources/playbutton.png");
    Image attacker = LoadImage("resources/hero_run.png");
    Texture2D texture = LoadTextureFromImage(image);
    Texture2D button = LoadTextureFromImage(btn);
    Texture2D myHero = LoadTextureFromImage(attacker);
    Rectangle btnBounds = { (screenWidth / 2) - 75, (screenHeight / 2) - 75, 150, 150 };
    Vector2 mousePoint = { 0.0f, 0.0f };

    Vector2 position = { playerPosX, playerPosY };
    Rectangle frameRec = { 0.0f, 0.0f, (float)myHero.width / 8, (float)myHero.height };

    texture.height = screenHeight;
    texture.width = screenWidth;
    button.height = 150;
    button.width = 150;
    int btnState = 0;
    bool btnAction = false;
    bool gameStart = false;

    UnloadImage(image);
    UnloadImage(btn);
    UnloadImage(attacker);

    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        framesCounter++;
        mousePoint = GetMousePosition();
        btnAction = false;

        onKeyDown(&myHero, &position, &frameRec);

        if (CheckCollisionPointRec(mousePoint, btnBounds)) {
            if (IsMouseButtonDown(MOUSE_BUTTON_LEFT))
                btnState = 2;
            else
                btnState = 1;

            if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT))
                btnAction = true;
        }
        else
            btnState = 0;

        if (btnAction) {
            UnloadTexture(button);
            gameStart = true;
        }

        BeginDrawing();

        ClearBackground(RAYWHITE);
        DrawTexture(texture, 0, 0, WHITE);

        if (gameStart == false) {
            DrawTexture(button, (screenWidth / 2) - 75, (screenHeight / 2) - 75, WHITE);
            DrawText("Play!", (screenWidth / 2) - 75, (screenHeight / 2) + 75, 70, WHITE);
        }
        else
            DrawTextureRec(myHero, frameRec, position, WHITE);

        EndDrawing();
    }

    UnloadTexture(texture);

    CloseWindow();

    return 0;
}

void onKeyDown(Texture2D* myHero, Vector2* position, Rectangle* frameRec)
{
    if (IsKeyDown(KEY_RIGHT)) {
        if (framesCounter >= (60 / frameSpeed)) {
            framesCounter = 0;
            position->x += 7;
            currentFrame++;

            if (currentFrame > 10)
                currentFrame = 0;

            frameRec->x = (float)currentFrame * (float)myHero->width / 10;
            frameRec->width = abs(frameRec->width) * 1;
        }
    }

    if (IsKeyDown(KEY_LEFT)) {
        if (framesCounter >= (60 / frameSpeed)) {
            framesCounter = 0;
            position->x -= 7;
            currentFrame++;

            if (currentFrame > 10)
                currentFrame = 0;
            frameRec->x = (float)currentFrame * (float)myHero->width / 10;
            frameRec->width = abs(frameRec->width) * -1;
        }
    }
}
