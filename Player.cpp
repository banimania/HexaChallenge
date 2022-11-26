
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
		int xlength, ylength;
		switch (wall.direction) {
			case 1:
				xlength = 5;
				ylength = wall.length;
				break;
			case 2:
				xlength = wall.length;
				ylength = 5;
		}
		if (x + newx >= wall.x and newx <= wall.x + size + xlength) {
			if (x + newy >= wall.y and newy <= wall.y + size + ylength) {
				cout << "test" << endl;
			}
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