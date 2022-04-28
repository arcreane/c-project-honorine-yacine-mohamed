#include "raylib.h"
#include <iostream>
#include "Hero.h"
#include "Antagoniste.h"

#define NOMBRE_ANTAGONIST 4

using namespace std;

void onKeyDown(Texture2D* myHeroRun, Texture2D* myHeroAttack, Vector2* position, Rectangle* frameRec, Rectangle* frameRecAttack);

Hero player = Hero("Name", 0, 0, 0, 100);  // run=false, attack = false et idle= true 


Antagoniste man[NOMBRE_ANTAGONIST] = {
    Antagoniste("ANTAGONISTE 1", 1, 1),
    Antagoniste("ANTAGONISTE 2", 1, 1),
    Antagoniste("ANTAGONISTE 3", 1, 1),
    Antagoniste("ANTAGONISTE 4", 1, 1)
};

int currentFrame = 0;
int framesCounter = 0;;
float frameSpeed = 60;
int moveX = 7;
const int screenWidth = 1270;
const int screenHeight = 800;
int playerPosX;
int playerPosY;
int enemyLeft = 1;
int manFrame = 0;
int enemySpawn[] = { 0, 1250 };


int main(void)
{

    // Au lancement je lui donne 10 pieces
    player.initCoinsList();
        
    player.setPosY(600);

    int playerPosX = player.getPosX();
    int playerPosY = player.getPosY();

    InitWindow(screenWidth, screenHeight, "JEU");

    Image image = LoadImage("resources/bg.png");
    Image btn = LoadImage("resources/playbutton.png");
    Image hero_running = LoadImage("resources/hero_run.png");
    Image hero_attack = LoadImage("resources/hero_attack.png");
    Image hero_idle = LoadImage("resources/hero_idle.png");
    Image health = LoadImage("resources/health.png");
    Image coin = LoadImage("resources/coin.png");
    Image man_run = LoadImage("resources/Man_walk.png");

    Texture2D texture = LoadTextureFromImage(image);
    Texture2D button = LoadTextureFromImage(btn);
    Texture2D myHeroRun = LoadTextureFromImage(hero_running);
    Texture2D myHeroAttack = LoadTextureFromImage(hero_attack);
    Texture2D myHeroIdle = LoadTextureFromImage(hero_idle);
    Texture2D healthIcon = LoadTextureFromImage(health);
    Texture2D coinIcon = LoadTextureFromImage(coin);
    Texture2D manRun = LoadTextureFromImage(man_run);

    Rectangle btnBounds = { (screenWidth / 2) - 75, (screenHeight / 2) - 75, 150, 150 };
    Vector2 mousePoint = { 0.0f, 0.0f };
    Vector2 position = { playerPosX, playerPosY };
    Rectangle frameRec = { 0.0f, 0.0f, (float)myHeroRun.width / 8, (float)myHeroRun.height };
    Rectangle frameRecAttack = { 0.0f, 0.0f, (float)myHeroAttack.width / 6, (float)myHeroAttack.height };

    texture.height = screenHeight;
    texture.width = screenWidth;
    button.height = 150;
    button.width = 150;
    healthIcon.width = 40;
    healthIcon.height = 40;
    coinIcon.width = 40;
    coinIcon.height = 40;
    int btnState = 0;
    bool btnAction = false;
    bool gameStart = false;

    UnloadImage(image);
    UnloadImage(btn);
    UnloadImage(hero_running);
    UnloadImage(hero_attack);
    UnloadImage(hero_idle);
    UnloadImage(health);
    UnloadImage(coin);
    UnloadImage(man_run);

    SetTargetFPS(60);

    for (int i = 0; i < NOMBRE_ANTAGONIST; i++) {
        man[i].setActive(true);
        man[i].setRect({ 0.0f, 0.0f, (float)manRun.width / 6, (float)manRun.height });
        man[i].setPos({2, position.y + 32 });  //mettre une fonction random pour position les ennemis.
        man[i].setSide(1);
    }

    while (!WindowShouldClose()) {
        framesCounter++;
        mousePoint = GetMousePosition();
        btnAction = false;

        onKeyDown(&myHeroRun, &myHeroAttack, &position, &frameRec, &frameRecAttack);

        for (int i = 0; i < NOMBRE_ANTAGONIST; i++) {
            if (man[i].getActive() && gameStart) {
                Vector2 pos = man[i].getPos();
                if (position.x > pos.x) {
                    man[i].setPos({ pos.x + 1, pos.y });
                    man[i].setSide(1);
                }
                if (position.x + 50 < pos.x) {
                    man[i].setPos({ pos.x - 1, pos.y });
                    man[i].setSide(-1);
                }
            }
        }

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
        else {

            for (int i = 0; i < NOMBRE_ANTAGONIST; i++) {
                if (man[i].getActive()) {
                    DrawTextureRec(manRun, { manFrame * (float)manRun.width / 6, man[i].getRect().y, man[i].getRect().width * man[i].getSide(), man[i].getRect().height }, man[i].getPos(), WHITE);

                    if (framesCounter % 10 == 0) {
                        manFrame++;
                        if (manFrame >= 6)
                            manFrame = 0;
                    }
                }
            }
            for (int i = 0; i < player.getStrength() / 20; i++) {
                DrawTexture(healthIcon, 40 + (i * 35), 50, WHITE);
            }
            DrawTexture(coinIcon, 40, 100, WHITE);
            DrawText(std::to_string(player.getnbCoins()).c_str(), 85, 105, 35, YELLOW);
            if (player.getrun() == true)
                DrawTextureRec(myHeroRun, frameRec, position, WHITE);
            if (player.getidle() == true)
                DrawTextureRec(myHeroIdle, frameRec, position, WHITE);
            else if (player.getattack() == true)
                DrawTextureRec(myHeroAttack, frameRecAttack, position, WHITE);
        }
        EndDrawing();
    }

    UnloadTexture(texture);
    UnloadTexture(myHeroAttack);
    UnloadTexture(myHeroRun);
    UnloadTexture(myHeroIdle);
    UnloadTexture(healthIcon);
    UnloadTexture(coinIcon);

    CloseWindow();

    return 0;
}

void onKeyDown(Texture2D* myHeroRun, Texture2D* myHeroAttack, Vector2* position, Rectangle* frameRec, Rectangle* frameRecAttack)
{
    if (IsKeyDown(KEY_RIGHT)) {
        if (IsKeyDown(KEY_SPACE)) {
            player.attaque();
        }
        else if (framesCounter % 3 == 0) {
            player.runright();
            if (position->x <= 1200)
                position->x += 7;
            currentFrame++;
            if (currentFrame > 10)
                currentFrame = 0;
            frameRec->x = (float)currentFrame * (float)myHeroRun->width / 10;
            frameRec->width = abs((float)myHeroRun->width / 10) * player.getFacingLeft();
        }
    }

    if (IsKeyReleased(KEY_RIGHT) || IsKeyReleased(KEY_LEFT) || IsKeyReleased(KEY_SPACE)) {
        player.notmove();
    }

    if (IsKeyDown(KEY_LEFT)) {
        if (IsKeyDown(KEY_SPACE)) {
            player.attaque();
        }
        else if (framesCounter % 3 == 0) {
            player.runleft();
            if (position->x >= -60)
                position->x -= 7;
            currentFrame++;

            if (currentFrame > 10)
                currentFrame = 0;
            frameRec->x = (float)currentFrame * (float)myHeroRun->width / 10;
            frameRec->width = abs((float)myHeroRun->width / 10) * player.getFacingLeft();
        }
    }

    if (IsKeyDown(KEY_SPACE)) {
        if (framesCounter % 3 == 0) {
            player.attaque();

            currentFrame++;

            if (currentFrame > 10)
                currentFrame = 0;
            frameRecAttack->x = (float)currentFrame * (float)myHeroAttack->width / 6;
            frameRecAttack->width = abs((float)myHeroAttack->width / 6) * player.getFacingLeft();
        }
    }

    if (IsKeyReleased(KEY_SPACE)) {
        player.notmove();
    }
}

