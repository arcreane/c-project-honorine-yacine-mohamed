#include "raylib.h"
#include <iostream>
#include <fstream>
#include "Hero.h"
#include "Antagoniste.h"
#include "Piece.h"
#include "Sorciere.h"
#include "Monstre.h"
#include "Potion.h"

#define NOMBRE_ANTAGONIST 4

using namespace std;

void onKeyDown(Texture2D* myHeroRun, Texture2D* myHeroAttack, Rectangle* frameRec, Rectangle* frameRecAttack);

Hero player = Hero("Name", 100, 0);  // run=false, attack = false et idle= true 
Piece piece = Piece();
Potion hp = Potion("potion_vie", 10);

template<typename Base, typename T>
inline bool instanceof(const T*) {
    return std::is_base_of<Base, T>::value;
}

Antagoniste tabantagoniste[NOMBRE_ANTAGONIST] = {
    Antagoniste("ANTAGONISTE 1", 1, 1),
    Antagoniste("ANTAGONISTE 2", 1, 1),
    Antagoniste("ANTAGONISTE 3", 1, 1),
    Antagoniste("ANTAGONISTE 4", 1, 1)
};

Sorciere sorciere = Sorciere("Sorciere", 1, 2);
Monstre monstre = Monstre("MONSTRE", 1, 2);

int currentFrame = 0;
int framesCounter = 0;;
float frameSpeed = 60;
int moveX = 7;
const int screenWidth = 1270;
const int screenHeight = 800;
int manFrame = 0;
int manAtkFrame = 0;
int coinFrame = 0;
int witchFrame = 0;
int witchAtkFrame = 0;
int monsterFrame = 0;
int monstAtkFrame = 0;
int highScore = 0;

int enemySpawn[][2] = { {-100, 0},{screenWidth - 50,screenWidth + 50} };

bool showScore = false;

std::vector< Texture2D > listModelantagonistes;
std::vector< Texture2D > listModelantagonistesAttack;

int main(void)
{

    //pour enregistrer les scores dans le fichiers scores.txt
    // et lire le best-score
    std::ofstream WriteFile;
    WriteFile.open("scores.txt", std::ios_base::app);
    ifstream ReadFile("scores.txt");
    string score;


    //on donne une position au joueur
    player.setPos({ 0.0f,600 });
    player.initCoinsList();  // Au lancement je lui donne 10 pieces au joueur


    InitWindow(screenWidth, screenHeight, "JEU");

    //IMAGES POUR LA FENETRE D'ACCUEIL ET POUR LA PAGE EN HAUT VIE + PIECES
    Image image = LoadImage("resources/bg.png");
    Image btn = LoadImage("resources/playbutton.png");
    Image health = LoadImage("resources/health.png");
    Image coin = LoadImage("resources/coin.png");

    //ANTAGONISTES 
    Image man_run = LoadImage("resources/Man_walk.png");
    Image woman_run = LoadImage("resources/Woman_walk.png");
    Image man_attack = LoadImage("resources/Man_attack.png");
    Image woman_attack = LoadImage("resources/woman_attack.png");


    Texture2D texture = LoadTextureFromImage(image);
    Texture2D button = LoadTextureFromImage(btn);

    Texture2D myHeroRun = player.getTexture2DRun();
    Texture2D myHeroAttack = player.getTexture2DAttack();
    Texture2D myHeroIdle = player.getTexture2DIdle();

    Texture2D healthIcon = LoadTextureFromImage(health);
    Texture2D coinIcon = LoadTextureFromImage(coin);

    Texture2D manRun = LoadTextureFromImage(man_run);
    Texture2D womanRun = LoadTextureFromImage(woman_run);
    Texture2D manAttack = LoadTextureFromImage(man_attack);
    Texture2D womanAttack = LoadTextureFromImage(woman_attack);

    Texture2D coinEnvironnement = piece.getModel();
    Texture2D healthPotion = hp.getModel();

    Texture2D sorciereRun = sorciere.getTexture2DRun();
    Texture2D sorciereAttack = sorciere.getTexture2DAttack();

    Texture2D monsterRun = monstre.getTexture2DRun();
    Texture2D monsterAttack = monstre.getTexture2DAttack();

    monsterRun.width += monsterRun.width / 2;
    monsterRun.height += monsterRun.height / 2;

    monsterAttack.width += monsterAttack.width / 2;
    monsterAttack.height += monsterAttack.height / 2;

    listModelantagonistes.push_back(manRun);
    listModelantagonistes.push_back(womanRun);

    listModelantagonistesAttack.push_back(manAttack);
    listModelantagonistesAttack.push_back(womanAttack);

    Rectangle btnBounds = { (screenWidth / 2) - 75, (screenHeight / 2) - 75, 150, 150 };
    Vector2 mousePoint = { 0.0f, 0.0f };
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
    UnloadImage(man_attack);
    UnloadImage(woman_attack);

    SetTargetFPS(60);

    for (int i = 0; i < NOMBRE_ANTAGONIST; i++) {  
        int rands = rand() % listModelantagonistes.size();
        tabantagoniste[i].setActive(true);
        tabantagoniste[i].setRect({ 0.0f, 0.0f, (float)manRun.width / 6, (float)manRun.height });
        tabantagoniste[i].setPos({ (float)GetRandomValue(enemySpawn[i % 2][0], enemySpawn[i % 2][1]), player.getPos().y + 32 });
        tabantagoniste[i].setSide(1);
        tabantagoniste[i].setModel(listModelantagonistes[rands]);
        tabantagoniste[i].setAttackModel(listModelantagonistesAttack[rands]);
        tabantagoniste[i].setDamage(5);
        tabantagoniste[i].setRecompense(1);
    }

    sorciere.setActive(false);  //la sorciere pas visible au début.
    sorciere.setSide(1);
    sorciere.setPos({ 0,610 });  // sa position

    monstre.setActive(false);  //monstre pas visible au début.
    monstre.setSide(1);
    monstre.setPos({ 1300,630 }); // sa position

    while (!WindowShouldClose()) {
        framesCounter++;
        mousePoint = GetMousePosition();
        btnAction = false;

        if (gameStart == true) {  
            if (IsKeyDown(KEY_ENTER)) {
                player.setVie(100);  // je donne une 100 points de vie au joueur
                player.setScore(0);   // et un score de 0
                player.setPos({ 0.0f,600 }); // on le positionne

                for (int i = 0; i < NOMBRE_ANTAGONIST; i++)  // positionner les 4 antagonistes 
                {
                    tabantagoniste[i].setPos({ (float)GetRandomValue(enemySpawn[i % 2][0], enemySpawn[i % 2][1]), player.getPos().y + 32 });
                    tabantagoniste[i].setSide(1);
                }
                sorciere.setPos({ 0, 610 }); //positionner la sorciere
                sorciere.setActive(false); // pas visible 
                sorciere.setattack(false);  // dans aucune position
                sorciere.setrun(false);
            }
        }

        if (player.getVie() > 0 && gameStart == true) { // si le jeu est lancé et que le joueur a de la vie

            onKeyDown(&myHeroRun, &myHeroAttack, &frameRec, &frameRecAttack);

            if (player.getScore() > 0) {  // si son score est supérieur à  0 
                if (player.getScore() % 10 == 0) sorciere.setActive(true); // toutes les 10 points de score la sorcière apparait. => active à true
                if (player.getScore() % 15 == 0) monstre.setActive(true); // toutes les 15 points de score le monstre apparait.
            }

            if (sorciere.getActive()) {   // si la sorcière est active <=> getActtive == true
                Vector2 pos = sorciere.getPos(); // on récupère sa position
                if (player.getPos().x > pos.x) // si d'un cote du joueur
                {
                    sorciere.setPos({ (float)(pos.x + 1.2), pos.y }); // on la repositionne
                    sorciere.setSide(1);
                    sorciere.setrun(true); // elle en position de marche seulement
                    sorciere.setattack(false); 
                    if (CheckCollisionPointRec({ sorciere.getPos().x + 5,sorciere.getPos().y + 5 }, player.getRect())) {  // si elle touche le joueur
                        if (player.getattack()) // et que le joeur est en position d'attaque
                        {
                            player.attaque(sorciere);
                            sorciere.setActive(false); // la sorciere disparait.
                            sorciere.giveRecompense(player);
                            //player.setScore(sorciere.getRecompense() + player.getScore()); //le joeueur  récupère le récompense donnée par la sorcière
                            sorciere.setSide(1);
                            sorciere.setPos({ 0, 610 }); // on la repositionne
                            if (GetRandomValue(0, 1) == 0) // une fois sur 2 elle donne une piece
                            {
                                piece.setPos({ pos.x, 670 });
                                piece.setActive(true);
                            }
                            else  // une fois sur deux elle donne une potion
                            {
                                hp.setPos({ pos.x + 2, 665 });
                                hp.setActive(true);
                            }
                        }
                        else
                        {
                            sorciere.setattack(true);  // si le joeur n'est pas en position d'attaque alors c'est la 
                            sorciere.setrun(false);   // sorciere qui se met en position d'attaque
                        }
                    }
                }
                if (player.getPos().x + 65 < pos.x) //pour l'autre cote.
                {
                    sorciere.setPos({ (float)(pos.x - 1.2), pos.y });
                    sorciere.setSide(-1);
                    sorciere.setrun(true);
                    sorciere.setattack(false);
                    if (CheckCollisionPointRec({ sorciere.getPos().x - 20,sorciere.getPos().y + 5 }, player.getRect())) {
                        if (player.getattack())
                        {
                            player.attaque(sorciere);
                            sorciere.setActive(false);
                            sorciere.giveRecompense(player);
                            //player.setScore(sorciere.getRecompense() + player.getScore());
                            sorciere.setSide(1);
                            sorciere.setPos({ 0, 610 });
                            if (GetRandomValue(0, 1) == 0)
                            {
                                piece.setPos({ pos.x, 670 });
                                piece.setActive(true);
                            }
                            else
                            {
                                hp.setPos({ pos.x + 2, 665 });
                                hp.setActive(true);
                            }
                        }
                        else
                        {
                            sorciere.setattack(true);
                            sorciere.setrun(false);
                        }
                    }
                }
            }

            if (monstre.getActive()) {  // même chose que pour la sorcière pour le monstre
                Vector2 pos = monstre.getPos();
                if (player.getPos().x > pos.x)
                {
                    monstre.setPos({ (float)(pos.x + 1.2), pos.y });
                    monstre.setSide(1);
                    monstre.setrun(true);
                    monstre.setattack(false);
                    if (CheckCollisionPointRec({ monstre.getPos().x + 5,monstre.getPos().y }, player.getRect())) {
                        if (player.getattack())
                        {
                            player.attaque(monstre);
                            monstre.setActive(false);
                            monstre.giveRecompense(player);

                            //player.setScore(monstre.getRecompense() + player.getScore());  
                            monstre.setSide(1);
                            monstre.setPos({ 1300,630 });
                            if (GetRandomValue(0, 1) == 0)
                            {
                                piece.setPos({ pos.x, 670 });
                                piece.setActive(true);
                            }
                            else
                            {
                                hp.setPos({ pos.x + 2, 665 });
                                hp.setActive(true);
                            }
                        }
                        else
                        {
                            monstre.setattack(true);
                            monstre.setrun(false);
                        }
                    }
                }
                if (player.getPos().x + 65 < pos.x)
                {
                    monstre.setPos({ (float)(pos.x - 1.2), pos.y });
                    monstre.setSide(-1);
                    monstre.setrun(true);
                    monstre.setattack(false);
                    if (CheckCollisionPointRec({ monstre.getPos().x - 20,monstre.getPos().y }, player.getRect())) {
                        if (player.getattack())
                        {
                            player.attaque(monstre);
                            monstre.setActive(false);
                            monstre.giveRecompense(player);
                            //player.setScore(monstre.getRecompense() + player.getScore());
                            monstre.setSide(1);
                            monstre.setPos({ 1300,630 });
                            if (GetRandomValue(0, 1) == 0)
                            {
                                piece.setPos({ pos.x, 670 });
                                piece.setActive(true);
                            }
                            else
                            {
                                hp.setPos({ pos.x + 2, 665 });
                                hp.setActive(true);
                            }
                        }
                        else
                        {
                            monstre.setattack(true);
                            monstre.setrun(false);
                        }
                    }
                }
            }

            for (int i = 0; i < NOMBRE_ANTAGONIST; i++) {  //pour les antagonistes simples
                if (tabantagoniste[i].getActive() && gameStart) {
                    Vector2 pos = tabantagoniste[i].getPos();
                    if (player.getPos().x + 20 > pos.x) {
                        tabantagoniste[i].setPos({ pos.x + 1, pos.y });
                        tabantagoniste[i].setSide(1);
                        tabantagoniste[i].setattack(false);
                        tabantagoniste[i].setrun(true);
                    }
                    if (player.getPos().x + 50 < pos.x) {
                        tabantagoniste[i].setPos({ pos.x - 1, pos.y });
                        tabantagoniste[i].setSide(-1);
                        tabantagoniste[i].setattack(false);
                        tabantagoniste[i].setrun(true);

                    }
                    if (CheckCollisionPointRec({ pos.x,pos.y }, player.getRect())) {
                        if (player.getattack()) {
                            tabantagoniste[i].setPos({ (float)GetRandomValue(enemySpawn[i % 2][0], enemySpawn[i % 2][1]), player.getPos().y + 32 });
                            player.setScore(tabantagoniste[i].getRecompense() + player.getScore());
                        }
                        else
                        {
                            tabantagoniste[i].setattack(true);
                            tabantagoniste[i].setrun(false);
                        }
                    }
                }
            }
        }

        if (piece.getActive() && CheckCollisionPointRec({ piece.getPos().x - 20,piece.getPos().y }, player.getRect())) {// s'il y a une collision avec une piece 
            piece.setActive(false); //la piece disparait
            player.getCoin(piece);  // le joueur récupère la pièce
        }

        if (hp.getActive() && CheckCollisionPointRec({ hp.getPos().x - 20,hp.getPos().y - 20 }, player.getRect())) {  // si colision avec une potion
            hp.setActive(false); //la potion disparait.
            player.getPotion(hp); // le joueur autant de vie que la potion lui en donne
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
            if (player.getVie() <= 0) {  // si le joueur n'a plus de vie
                if (showScore == false) {  
                    if (player.getScore() > 0) // et qu'il a un score supérieur à 0
                        WriteFile << player.getScore() + player.getnbCoins() << endl; // on écrit dans le fichier des scores
                    while (getline(ReadFile, score)) { //recupere le meilleur score 
                        if (stoi(score) > highScore)
                            highScore = stoi(score);
                    }
                    showScore = true;
                }
                DrawText(TextFormat("SCORE: %i", player.getScore() + player.getnbCoins()), 500, 320, 50, MAROON);
                DrawText(TextFormat("BEST-SCORE: %i", highScore), 420, 400, 45, BLACK);
                DrawText("GAME OVER", 470, 230, 50, BLACK);
                DrawText("APPUYER SUR ENTRER POUR REJOUER", 280, 500, 40, LIGHTGRAY);
            }
            else { //si le joueur a de la vie
                for (int i = 0; i < NOMBRE_ANTAGONIST; i++) { // pour chaque antagonsites simples: 
                    if (tabantagoniste[i].getActive()) {
                        if (tabantagoniste[i].getrun()) { // si en position de marche 
                            tabantagoniste[i].setDamageRect({ manFrame * (float)tabantagoniste[i].getModel().width / 6, tabantagoniste[i].getRect().y, tabantagoniste[i].getRect().width * tabantagoniste[i].getSide(), tabantagoniste[i].getRect().height });
                            DrawTextureRec(tabantagoniste[i].getModel(), tabantagoniste[i].getDamageRect(), tabantagoniste[i].getPos(), WHITE);
                            if (framesCounter % 10 == 0) {
                                manFrame++;
                                if (manFrame >= 6)
                                    manFrame = 0;
                            }
                        }
                        else if (tabantagoniste[i].getattack()) {  // si en positon d'attaque
                            DrawTextureRec(tabantagoniste[i].getAttackModel(), { manAtkFrame * (float)tabantagoniste[i].getAttackModel().width / 4, 0.0f, (float)tabantagoniste[i].getAttackModel().width / 4 * tabantagoniste[i].getSide(), (float)tabantagoniste[i].getAttackModel().height }, tabantagoniste[i].getPos(), WHITE);
                            if (framesCounter % 10 == 0) {
                                manAtkFrame++;
                                if (manAtkFrame >= 4) {
                                    manAtkFrame = 0;
                                    tabantagoniste[i].attaque(player);  // attaque le joueur
                                    tabantagoniste[i].setattack(false);  // il se remette en position de marche
                                    tabantagoniste[i].setrun(true);
                                }
                            }
                        }
                    }
                }
                if (sorciere.getActive()) {  // si la sorciere est active
                    if (sorciere.getrun()) //si elle est en positon de marche
                    {
                        DrawTextureRec(sorciereRun, { 0.0f, witchFrame * (float)sorciereRun.height / 8, (float)sorciere.getSide() * sorciereRun.width, (float)sorciereRun.height / 8 }, sorciere.getPos(), WHITE);

                        if (framesCounter % 5 == 0)
                        {
                            witchFrame++;
                            if (witchFrame >= 8)
                            {
                                witchFrame = 0;
                            }
                        }
                    }
                    if (sorciere.getattack()) // si elle est en position d'attaque 
                    {
                        DrawTextureRec(sorciereAttack, { 0.0f, witchAtkFrame * (float)sorciereAttack.height / 9, (float)sorciere.getSide() * sorciereAttack.width, (float)sorciereAttack.height / 9 }, sorciere.getPos(), WHITE);

                        if (framesCounter % 5 == 0)
                        {
                            witchAtkFrame++;
                            if (witchAtkFrame >= 9)
                            {
                                witchAtkFrame = 0;
                                sorciere.voler(player);  // elle vole (fait perdre) une pièce au joueur.
                            }
                        }
                    }
                }

                if (monstre.getActive()) {  // si le monstre est actif
                    if (monstre.getrun())  // si il est en position de marche
                    {
                        DrawTextureRec(monsterRun, { monsterFrame * (float)monsterRun.width / 13, 0.0f,   (float)monstre.getSide() * monsterRun.width / 13, (float)monsterRun.height }, monstre.getPos(), WHITE);

                        if (framesCounter % 3 == 0)
                        {
                            monsterFrame++;
                            if (monsterFrame >= 13)
                            {
                                monsterFrame = 0;
                            }
                        }
                    }
                    if (monstre.getattack()) //si le monstre est en position d'attaque
                    {
                        DrawTextureRec(monsterAttack, { monstAtkFrame * (float)monsterAttack.width / 18 , 0.0f,  (float)monstre.getSide() * monsterAttack.width / 18, (float)monsterAttack.height }, monstre.getPos(), WHITE);

                        if (framesCounter % 3 == 0)
                        {
                            monstAtkFrame++;
                            if (monstAtkFrame >= 18)
                            {
                                monstAtkFrame = 0;
                                monstre.oneshot(player);  // il one shot le joueur
                            }
                        }
                    }
                }
                for (int i = 1; i <= (player.getVie() + 20) / 20; i++) {  //pour afficher le nombre de vie du joueur
                    DrawTexture(healthIcon, 40 + ((i - 1) * 35), 50, WHITE);
                }
                DrawTexture(coinIcon, 40, 100, WHITE);
                DrawText(std::to_string(player.getScore()).c_str(), 1120, 50, 30, WHITE);  //son score
                DrawText(std::to_string(player.getnbCoins()).c_str(), 85, 105, 35, YELLOW); // son nombre de pieces
                
                if (piece.getActive()) {  //si la piece est active : 
                    DrawTextureRec(coinEnvironnement, { coinFrame * (float)coinEnvironnement.width / 4, 0.0f, (float)coinEnvironnement.width / 4, (float)coinEnvironnement.height }, piece.getPos(), WHITE);
                    if (framesCounter % 10 == 0) {
                        coinFrame++;
                        if (coinFrame >= 4) {
                            coinFrame = 0;
                        }
                    }
                }
                if (hp.getActive()) {  // si la potion est active
                    DrawTextureRec(healthPotion, { (float)healthPotion.width / 3, (float)healthPotion.height / 3, (float)healthPotion.width / 3, (float)healthPotion.height / 3 }, hp.getPos(), WHITE);
                }

                if (player.getrun() == true)  // si le joueur est en position de marche/run
                    DrawTextureRec(myHeroRun, frameRec, player.getPos(), WHITE);

                if (player.getidle() == true) //si le joueur est en postion immobile
                    DrawTextureRec(myHeroIdle, frameRec, player.getPos(), WHITE);

                else if (player.getattack() == true) //si le joueur est en position d'attaque
                    DrawTextureRec(myHeroAttack, frameRecAttack, player.getPos(), WHITE);
                
                player.setRect({ player.getPos().x,player.getPos().y,abs(frameRec.width) / 2,frameRec.height });
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

    WriteFile.close(); 
    ReadFile.close();

    return 0;
}

void onKeyDown(Texture2D* myHeroRun, Texture2D* myHeroAttack, Rectangle* frameRec, Rectangle* frameRecAttack)
{
    if (IsKeyDown(KEY_RIGHT)) {  //si click sur la flèche aller à droite
        if (IsKeyDown(KEY_SPACE)) {  // et cick sur la touche espace
            player.attaque();  // le joueur est en position d'attaque
        }
        else if (framesCounter % 3 == 0) { 
            player.runright(); // le joueur court à droite 
            if (player.getPos().x <= 1200)
                player.setPos({ player.getPos().x + 7, player.getPos().y });
            currentFrame++;
            if (currentFrame > 10)
                currentFrame = 0;
            frameRec->x = (float)currentFrame * (float)myHeroRun->width / 10;
            frameRec->width = abs((float)myHeroRun->width / 10) * player.getSide();
        }
    }

    if (IsKeyReleased(KEY_RIGHT) || IsKeyReleased(KEY_LEFT) || IsKeyReleased(KEY_SPACE)) {
        player.notmove(); // si aucun des trois boutons n'est clické alors position immobile
    }

    if (IsKeyDown(KEY_LEFT)) { // si click flèche de gauche
        if (IsKeyDown(KEY_SPACE)) {  // si clique touche espaces
            player.attaque();  // le joueur attaque
        }
        else if (framesCounter % 3 == 0) { // sinon il court à gauche
            player.runleft(); 
            if (player.getPos().x >= -60)
                player.setPos({ player.getPos().x - 7, player.getPos().y });
            currentFrame++;

            if (currentFrame > 10)
                currentFrame = 0;
            frameRec->x = (float)currentFrame * (float)myHeroRun->width / 10;
            frameRec->width = abs((float)myHeroRun->width / 10) * player.getSide();
        }
    }

    if (IsKeyDown(KEY_SPACE)) {  // si il clique que sur le bouton espace 
        if (framesCounter % 3 == 0) {
            player.attaque(); // il attaque

            currentFrame++;

            if (currentFrame > 10)
                currentFrame = 0;
            frameRecAttack->x = (float)currentFrame * (float)myHeroAttack->width / 6;
            frameRecAttack->width = abs((float)myHeroAttack->width / 6) * player.getSide();
        }
    }

    if (IsKeyReleased(KEY_SPACE)) {  // si pas de click sur la touche espace il reste immobile.
        player.notmove();
    }
}