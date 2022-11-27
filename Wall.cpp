#include "Wall.hpp"

#include <gl/glut.h>

using namespace std;

Wall::Wall(int x, int y, int length, int direction) {
	this->x = x;
	this->y = y;
	this->length = length;
	this->direction = direction;

	switch (direction) {
		case 1: //DOWN
			this->x2 = this->x + 1;
			this->y2 = this->y + this->length;
			break;
		case 2: //RIGHT
			this->x2 = this->x + this->length;
			this->y2 = this->y + 1;
			break;
	}
}

void Wall::render() {
	//glLineWidth(5.0f);
	//glBegin(GL_LINES);
	//glColor3f(0.0f, 0.0f, 0.0f);
	//glVertex2f(x, y);
	//switch (direction) {
	//	case 1: //DOWN
	//		glVertex2f(x, y + length);
	//		break;
	//	case 2: //RIGHT
	//		glVertex2f(x + length, y);
	//		break;
	//}
	//glEnd();
	//glLineWidth(1.0f);
	glBegin(GL_QUADS);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex2f(x, y);
	glVertex2f(x, y2);
	glVertex2f(x2, y2);
	glVertex2f(x2, y);
}