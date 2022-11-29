
#include "Player.hpp"

#include <gl/glut.h>
#include <math.h>
#include <windows.h>
#include <iostream>

Player::Player(float x, float y, float speed, float size) {
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
	glVertex2f((x - size) - 1, (y + size) + 1);
	glVertex2f((x - size) - 1, (y - size) - 1);
	glVertex2f((x + size) + 1, (y - size) - 1);
	glVertex2f((x + size) + 1, (y + size) + 1);
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

void Player::handleMovement(float dt, vector<Wall> walls) {
	bool isGonnaCollideOnX = false;
	bool isGonnaCollideOnY = false;
	float xchange = 0;
	float ychange = 0;
	if (GetAsyncKeyState('W')) {
		ychange -= speed * dt;
	}

	if (GetAsyncKeyState('S')) {
		ychange += speed * dt;
	}

	if (GetAsyncKeyState('A')) {
		xchange -= speed * dt;
	}

	if (GetAsyncKeyState('D')) {
		xchange += speed * dt;
	}

	for (Wall wall : walls) {
		float newx = x + xchange;
		float newy = y + ychange;

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

bool Player::isCollidingWithEnemy(float ex, float ey, int radius) {

	float d = sqrt(pow(int(ex) - x, 2) + pow(int(ey) - y, 2));

	if (d - radius + 1 < size) {
		return true;
	}

	return false;
}