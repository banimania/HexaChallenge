#include "Level.hpp"
#include "main.hpp"

#include <gl/glut.h>
//#include <gl/freeglut.h>

using namespace std;

Level::Level(int index, int startX, int startY, vector<Enemy> enemies, vector<Goal> goals) {
    this->index = index;
	this->startX = startX;
	this->startY = startY;
	this->enemies = enemies;
    this->goals = goals;
}

void Level::start(Player& player) {
	player.x = startX;
	player.y = startY;
}

void Level::logic(Player player) {
    for (Enemy& enemy : enemies) {
        enemy.logic();
        if (player.isCollidingWithEnemy(enemy.x, enemy.y, enemy.radius)) {
            game.restartFromLevel(index);
            //glFlush();
            //exit(0);
        }
        enemy.renderEnemy();
    }

    for (Goal goal : goals) {
        goal.logicGoal(player);
        goal.render();
    }
}

void Level::finish() {

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