#include "Goal.hpp"

#include <gl/glut.h>
#include <math.h>
#include <iostream>

using namespace std;

Goal::Goal(int x, int y, int width, int height, bool isGoal) {
	this->x = x;
	this->y = y;
	this->width = width;
	this->height = height;
	this->isGoal = isGoal;
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

void Goal::logicGoal(Player player) {
	//Collision checks
	if (player.x + player.size > x && player.x - player.size < x + width
		&& player.y + player.size > y && player.y - player.size < y + height) {
		cout << "COLLISION" << endl;
	}
}