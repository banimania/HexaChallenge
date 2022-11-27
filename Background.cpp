#include "Background.hpp"

#include <gl/glut.h>

using namespace std;

Background::Background(int x, int y, int width, int height) {
	this->x = x;
	this->y = y;
	this->width = width;
	this->height = height;
}

void Background::render() {
	glBegin(GL_QUADS);
	glColor3f(0.4f, 0.55f, 1.0f);
	glVertex2f(x, y);
	glVertex2f(x, y + height);
	glVertex2f(x + width, y + height);
	glVertex2f(x + width, y);
	glEnd();
}