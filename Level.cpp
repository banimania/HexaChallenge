#include "Level.hpp"
#include "main.hpp"

#include <gl/glut.h>

using namespace std;

Level::Level(int index, int startX, int startY, vector<Enemy> enemies, vector<Goal> goals, vector<Wall> walls, vector<Background> backgrounds, vector<Coin> coins) {
    this->index = index;
	this->startX = startX;
	this->startY = startY;
	this->enemies = enemies;
    this->goals = goals;
    this->walls = walls;
    this->backgrounds = backgrounds;
    this->coins = coins;
}

void Level::start(Player& player) {
	player.x = startX;
	player.y = startY;
    for (Coin& coin : coins) {
        coin.obtained = false;
    }
}

void Level::logic(Player player) {

    bool allCoins = true;
    for (Coin& coin : coins) {
        if (!coin.obtained) {
            allCoins = false;
        }
        coin.logicCoin(player);
        coin.render();
    }

    for (Goal& goal : goals) {
        goal.logicGoal(player, allCoins);
        goal.render();
    }

    for (Enemy& enemy : enemies) {
        enemy.logic();
        if (player.isCollidingWithEnemy(enemy.x, enemy.y, enemy.radius)) {
            game.restartFromLevel(index, true);
        }
        enemy.renderEnemy();
    }

    for (Wall wall : walls) {
        wall.render();
    }

}

void Level::renderBackground() {
    int sq_size = 10;
    int count = 0;
    for (int i = -100; i < 230; i += sq_size) {
        for (int j = -100; j < 230; j += sq_size) {

            glBegin(GL_QUADS);
            glColor3f(0.9f, 0.9f, 0.9f);
            glVertex2f(i - (sq_size / 2), (j * 2) + i + (sq_size / 2));
            glVertex2f(i - (sq_size / 2), (j * 2) + i - (sq_size / 2));
            glVertex2f(i + (sq_size / 2), (j * 2) + i - (sq_size / 2));
            glVertex2f(i + (sq_size / 2), (j * 2) + i + (sq_size / 2));
            glEnd();

        }
    }

    //render backgrounds
    for (Background background : backgrounds) {
        background.render();
    }
}