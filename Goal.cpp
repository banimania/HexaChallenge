#include "Goal.hpp"
#include "main.hpp"

#include <gl/glut.h>
#include <math.h>

using namespace std;

Goal::Goal(int x, int y, int width, int height, bool isGoal, int lIndex) {
	this->x = x;
	this->y = y;
	this->width = width;
	this->height = height;
	this->isGoal = isGoal;
	this->lIndex = lIndex;
}

void Goal::render() {
	glBegin(GL_QUADS);
	glColor3f(0.6f, 1.0f, 0.4f);
	glVertex2f(x, y);
	glVertex2f(x, y + height);
	glVertex2f(x + width, y + height);
	glVertex2f(x + width, y);
	glEnd();
}

void Goal::logicGoal(Player player, bool allCoins) {
	//Collision checks
	if (player.x + player.size > x && player.x - player.size < x + width
		&& player.y + player.size > y && player.y - player.size < y + height
		&& allCoins) {
		game.restartFromLevel(lIndex + 1, false);
	}
}