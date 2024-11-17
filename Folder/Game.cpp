#include "Game.h"

Game::Game() : health(INITIAL_HEALTH), bossHealth(BOSS_HEALTH), hasGun(false), hasMapPiece1(false), hasMapPiece2(false) {
    srand(time(0));  // Seed the random number generator
}

int Game::getRandomDamage(int min, int max) {
    return rand() % (max - min + 1) + min;
}

void Game::bossFight() {
    cout << "You enter Cave 3. Boss fight!" << endl;

    if (hasGun) {
        while (bossHealth > 0 && health > 0) {
            int hit = rand() % 10;  // 90% chance to hit
            if (hit < 9) {
                bossHealth -= 3;
                cout << "You hit the boss! Boss health: " << bossHealth << endl;
            }
            else {
                cout << "You missed!" << endl;
            }

            if (bossHealth > 0) {
                int damage = getRandomDamage(2, 4);
                health -= damage;
                cout << "The boss hit you! Your health: " << health << endl;
            }
        }

        if (health > 0) {
            cout << "You defeated the boss!" << endl;
            hasMapPiece2 = true;
            if (hasMapPiece1) {
                cout << "You win!" << endl;
            }
            else {
                cout << "You found the second map piece." << endl;
            }
        }
    }
    else {
        cout << "You don't have a gun! The boss defeats you." << endl;
        health = 0;
    }
}

void Game::cave1() {
    cout << "You enter Cave 1." << endl;
    int damage = getRandomDamage(1, 3);
    health -= damage;
    cout << "You took " << damage << " damage. Health: " << health << endl;

    if (health > 0) {
        hasMapPiece1 = true;
        cout << "You found the first map piece." << endl;
    }
}

void Game::cave2() {
    cout << "You enter Cave 2." << endl;
    int item = rand() % 2;  // Random item: health or weapon
    if (item == 0) {
        health = INITIAL_HEALTH;
        cout << "You found a health item. Health restored to " << health << "." << endl;
    }
    else {
        hasGun = true;
        cout << "You found a gun." << endl;
    }

    int damage = getRandomDamage(1, 5);
    health -= damage;
    cout << "You took " << damage << " damage. Health: " << health << endl;
}

void Game::cave3() {
    if (health <= 0) {
        cout << "You can't proceed, you're dead!" << endl;
        return;
    }
    bossFight();
}

void Game::lobby() {
    cout << "Choose a cave (1, 2, 3) or return to lobby (4): ";
    int choice;
    cin >> choice;

    switch (choice) {
    case 1:
        cave1();
        break;
    case 2:
        cave2();
        break;
    case 3:
        cave3();
        break;
    case 4:
        cout << "Returning to lobby.\n";
        break;
    default:
        cout << "Invalid choice. Try again.\n";
        break;
    }
}

void Game::start() {
    while (health > 0 && !hasMapPiece2) {
        lobby();
    }

    if (health <= 0) {
        cout << "Game Over! You have been defeated." << endl;
    }
    else {
        cout << "Congratulations! You won the game." << endl;
    }
}
