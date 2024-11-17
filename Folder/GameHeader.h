#pragma #ifndef GAME_H
#define GAME_H

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

const int INITIAL_HEALTH = 100;
const int BOSS_HEALTH = 50;

class Game {
private:
    int health;
    int bossHealth;
    bool hasGun;
    bool hasMapPiece1;
    bool hasMapPiece2;

    int getRandomDamage(int min, int max);
    void bossFight();
    void cave1();
    void cave2();
    void cave3();
    void lobby();

public:
    Game();
    void start();
};

#endifonce
