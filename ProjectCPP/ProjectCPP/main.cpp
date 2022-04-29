#include "raylib.h"
#include <iostream>
#include "Hero.h"
#include "Antagoniste.h"
#include "Piece.h"

#define NOMBRE_ANTAGONIST 4

using namespace std;

void onKeyDown(Texture2D* myHeroRun, Texture2D* myHeroAttack, Vector2* position, Rectangle* frameRec, Rectangle* frameRecAttack);

Hero player = Hero("Name", 100, 0, 0, 0);  // run=false, attack = false et idle= true 


Antagoniste tabantagoniste[NOMBRE_ANTAGONIST] = {
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
int enemySpawn[][2] = { {-100, 0},{screenWidth - 50,screenWidth + 50} };

std::vector< Texture2D > listModelantagonistes;

int main(void)
{

    // Au lancement je lui donne 10 pieces au joueur
    player.initCoinsList();

    player.setPosY(600);

    int playerPosX = player.getPosX();
    int playerPosY = player.getPosY();

    InitWindow(screenWidth, screenHeight, "JEU");

    Image image = LoadImage("resources/bg.png");
    Image btn = LoadImage("resources/playbutton.png");
    Image health = LoadImage("resources/health.png");
    Image coin = LoadImage("resources/coin.png");

    //ANTAGONISTES 
    Image man_run = LoadImage("resources/Man_walk.png");
    Image woman_run = LoadImage("resources/Woman_walk.png");

    // PIECE DANS L'ENVIRONNEMENT
    Image coin_environnement = LoadImage("resources/coin1.png");

    Texture2D texture = LoadTextureFromImage(image);
    Texture2D button = LoadTextureFromImage(btn);


    Texture2D myHeroRun = player.getTexture2DRun();  
    Texture2D myHeroAttack = player.getTexture2DAttack();
    Texture2D myHeroIdle = player.getTexture2DIdle();

    Texture2D healthIcon = LoadTextureFromImage(health);

    Texture2D coinIcon = LoadTextureFromImage(coin);

    Texture2D manRun = LoadTextureFromImage(man_run);
    Texture2D womanRun = LoadTextureFromImage(woman_run);

    Texture2D coinEnvironnement = LoadTextureFromImage(coin_environnement);

    listModelantagonistes.push_back(manRun);
    listModelantagonistes.push_back(womanRun);


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
    UnloadImage(health);
    UnloadImage(coin);
    UnloadImage(man_run);
    UnloadImage(woman_run);
    UnloadImage(coin_environnement);

    SetTargetFPS(60);

    for (int i = 0; i < NOMBRE_ANTAGONIST; i++) {
        tabantagoniste[i].setActive(true);
        tabantagoniste[i].setRect({ 0.0f, 0.0f, (float)manRun.width / 6, (float)manRun.height });
        tabantagoniste[i].setPos({(float)GetRandomValue(enemySpawn[i % 2][0], enemySpawn[i % 2][1]), position.y + 32 });
        tabantagoniste[i].setSide(1);
        tabantagoniste[i].setModel(listModelantagonistes[rand() % listModelantagonistes.size()]);
        tabantagoniste[i].setDamage(5);
        tabantagoniste[i].setRecompense(1);
    }

    while (!WindowShouldClose()) {
        framesCounter++;
        mousePoint = GetMousePosition();
        btnAction = false;

        if (gameStart == true) {
            if (IsKeyDown(KEY_ENTER)) {
                player.setVie(100);
                player.setScore(0);
                position = { 0.0f, (float)player.getPosY() };
                for (int i = 0; i < NOMBRE_ANTAGONIST; i++) {
                    tabantagoniste[i].setPos({ (float)GetRandomValue(enemySpawn[i % 2][0], enemySpawn[i % 2][1]), position.y + 32 });
                    tabantagoniste[i].setSide(1);
                }
            }
        }

        if (player.getVie() > 0 && gameStart == true) {
            onKeyDown(&myHeroRun, &myHeroAttack, &position, &frameRec, &frameRecAttack);

            for (int i = 0; i < NOMBRE_ANTAGONIST; i++) {
                if (tabantagoniste[i].getActive() && gameStart) {
                    Vector2 pos = tabantagoniste[i].getPos();
                    if (position.x > pos.x) {
                        tabantagoniste[i].setPos({ pos.x + 1, pos.y });
                        tabantagoniste[i].setSide(1);
                    }
                    if (position.x + 50 < pos.x) {
                        tabantagoniste[i].setPos({ pos.x - 1, pos.y });
                        tabantagoniste[i].setSide(-1);
                    }
                    if (CheckCollisionPointRec(pos, player.getRect())) {
                        if (player.getattack()) {
                            tabantagoniste[i].setPos({(float)GetRandomValue(enemySpawn[i % 2][0], enemySpawn[i % 2][1]), position.y + 32 });
                            tabantagoniste[i].setModel(listModelantagonistes[rand() % listModelantagonistes.size()]);
                            player.setScore(tabantagoniste[i].getRecompense() + player.getScore());
                        }
                        if (!player.getattack() && framesCounter % 30 == 0) {
                            int health = player.getVie();
                            player.setVie(health - tabantagoniste[i].getDamage());
                        }
                    }
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
            DrawText("JOUER !", (screenWidth / 2) - 75, (screenHeight / 2) + 75, 45, WHITE);
        }
        else {
            if (player.getVie() <= 0) {
                DrawText(TextFormat("SCORE: %i", player.getScore()), 500, 320, 50, MAROON);   //ecrire dans le fichier
                DrawText(TextFormat(" BEST-SCORE: %i", player.getScore()), 420, 400, 45, BLACK);  //recuperer depuis le fichier
                DrawText("GAME OVER", 470, 230, 50, BLACK);
                DrawText("APPUYER SUR ENTRER POUR REJOUER", 280, 500, 40, LIGHTGRAY);
            }
            else {
                for (int i = 0; i < NOMBRE_ANTAGONIST; i++) {
                    if (tabantagoniste[i].getActive()) {
                        tabantagoniste[i].setDamageRect({ manFrame * (float)tabantagoniste[i].getModel().width / 6, tabantagoniste[i].getRect().y, tabantagoniste[i].getRect().width * tabantagoniste[i].getSide(), tabantagoniste[i].getRect().height });
                        DrawTextureRec(tabantagoniste[i].getModel(), tabantagoniste[i].getDamageRect(), tabantagoniste[i].getPos(), WHITE);
                        if (framesCounter % 10 == 0) {
                            manFrame++;
                            if (manFrame >= 6)
                                manFrame = 0;
                        }
                    }
                }
                for (int i = 1; i <= player.getVie() / 20; i++) {
                    DrawTexture(healthIcon, 40 + ((i - 1) * 35), 50, WHITE);
                }
                DrawTexture(coinIcon, 40, 100, WHITE);
                DrawText(std::to_string(player.getScore()).c_str(), 1120, 50, 30, WHITE);
                DrawText(std::to_string(player.getnbCoins()).c_str(), 85, 105, 35, YELLOW);
                if (player.getrun() == true)
                    DrawTextureRec(myHeroRun, frameRec, position, WHITE);
                if (player.getidle() == true)
                    DrawTextureRec(myHeroIdle, frameRec, position, WHITE);
                else if (player.getattack() == true)
                    DrawTextureRec(myHeroAttack, frameRecAttack, position, WHITE);
                player.setRect({ position.x,position.y,abs(frameRec.width) / 2,frameRec.height });
            }
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
            frameRec->width = abs((float)myHeroRun->width / 10) * player.getSide();
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
            frameRec->width = abs((float)myHeroRun->width / 10) * player.getSide();
        }
    }

    if (IsKeyDown(KEY_SPACE)) {
        if (framesCounter % 3 == 0) {
            player.attaque();

            currentFrame++;

            if (currentFrame > 10)
                currentFrame = 0;
            frameRecAttack->x = (float)currentFrame * (float)myHeroAttack->width / 6;
            frameRecAttack->width = abs((float)myHeroAttack->width / 6) * player.getSide();
        }
    }

    if (IsKeyReleased(KEY_SPACE)) {
        player.notmove();
    }
}

