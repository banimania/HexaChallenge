#include "Wall.hpp"

#include <gl/glut.h>

using namespace std;

Wall::Wall(int x, int y, int length, int direction) {
	this->x = x;
	this->y = y;
	this->length = length;
	this->direction = direction;
}

void Wall::render() {
	glLineWidth(5.0f);
	glBegin(GL_LINES);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex2f(x, y);
	switch (direction) {
		case 1: //DOWN
			glVertex2f(x, y + length);
			break;
		case 2: //RIGHT
			glVertex2f(x + length, y);
			break;
	}
	glEnd();
	glLineWidth(1.0f);
}