#include "Level.hpp"

#include <gl/glut.h>

using namespace std;

Level::Level(int startX, int startY, vector<Enemy> enemies) {
	this->startX = startX;
	this->startY = startY;
	this->enemies = enemies;
}

void Level::start(Player& player) {
	player.x = startX;
	player.y = startY;
}

void Level::logic(Player player) {
    for (Enemy& enemy : enemies) {
        enemy.logic(0, 40);
        if (player.isCollidingWithEnemy(enemy.x, enemy.y, enemy.radius)) {
            glFlush();
            exit(0);
        }
        enemy.renderEnemy();
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
}