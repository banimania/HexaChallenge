
#include "Player.hpp"

#include <gl/glut.h>
#include <math.h>
#include <windows.h>
#include <iostream>

Player::Player(int x, int y, int speed, int size) {
	this->x = x;
	this->y = y;
	this->speed = speed;
	this->size = size;
	this->deathcount = 0;
}

void Player::renderPlayer() {

	//Lines
	glBegin(GL_QUADS);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex2f((x - size) - (size / 4), (y + size) + (size / 4));
	glVertex2f((x - size) - (size / 4), (y - size) - (size / 4));
	glVertex2f((x + size) + (size / 4), (y - size) - (size / 4));
	glVertex2f((x + size) + (size / 4), (y + size) + (size / 4));
	glEnd();

	//Square
	glBegin(GL_QUADS);
	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex2f(x - size, y + size);
	glVertex2f(x - size, y - size);
	glVertex2f(x + size, y - size);
	glVertex2f(x + size, y + size);
	glEnd();
	
}

void Player::handleMovement(vector<Wall> walls) {
	bool isGonnaCollideOnX = false;
	bool isGonnaCollideOnY = false;
	int xchange = 0;
	int ychange = 0;
	if (GetAsyncKeyState('W')) {
		ychange -= speed;
	}

	if (GetAsyncKeyState('S')) {
		ychange += speed;
	}

	if (GetAsyncKeyState('A')) {
		xchange -= speed;
	}

	if (GetAsyncKeyState('D')) {
		xchange += speed;
	}

	for (Wall wall : walls) {
		int newx = x + xchange;
		int newy = y + ychange;

		if (newx + size >= wall.x &&
			newx <= wall.x + (wall.x2 - wall.x) + size &&
			y + size >= wall.y &&
			y <= wall.y + (wall.y2 - wall.y) + size) {
			isGonnaCollideOnX = true;
		}

		if (x + size >= wall.x &&
			x <= wall.x + (wall.x2 - wall.x) + size &&
			newy + size >= wall.y &&
			newy <= wall.y + (wall.y2 - wall.y) + size) {
			isGonnaCollideOnY = true;
		}
	}

	if (!isGonnaCollideOnX) {
		x += xchange;
	}

	if (!isGonnaCollideOnY) {
		y += ychange;
	}
}

bool Player::isCollidingWithEnemy(int ex, int ey, int radius) {

	float d = sqrt(pow(ex - x, 2) + pow(ey - y, 2));

	if (d - radius < size) {
		return true;
	}

	return false;
}