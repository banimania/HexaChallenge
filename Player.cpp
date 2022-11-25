
#include "Player.hpp"

#include <gl/glut.h>
#include <math.h>
#include <windows.h>

Player::Player(int x, int y, int speed, int size) {
	this->x = x;
	this->y = y;
	this->speed = speed;
	this->size = size;
}

void Player::renderPlayer() {

	//Lines
	glBegin(GL_QUADS);
	glColor3f(0, 0, 0);
	glVertex2f((x - size) - (size / 4), (y + size) + (size / 4));
	glVertex2f((x - size) - (size / 4), (y - size) - (size / 4));
	glVertex2f((x + size) + (size / 4), (y - size) - (size / 4));
	glVertex2f((x + size) + (size / 4), (y + size) + (size / 4));
	glEnd();

	//Square
	glBegin(GL_QUADS);
	glColor3f(0, 1, 0);
	glVertex2f(x - size, y + size);
	glVertex2f(x - size, y - size);
	glVertex2f(x + size, y - size);
	glVertex2f(x + size, y + size);
	glEnd();
	
}

void Player::handleMovement() {

	/*cout << GetCurrentProcessId() << endl;
	cout << "T: " << GetWindowThreadProcessId(GetForegroundWindow(), NULL) << endl;*/
	if (GetAsyncKeyState('W')) {
		y -= speed;
	}

	if (GetAsyncKeyState('S')) {
		y += speed;
	}

	if (GetAsyncKeyState('A')) {
		x -= speed;
	}

	if (GetAsyncKeyState('D')) {
		x += speed;
	}
}

bool Player::isCollidingWithEnemy(int ex, int ey, int radius) {

	float d = sqrt(pow(ex - x, 2) + pow(ey - y, 2));

	if (d - radius < size) {
		return true;
	}

	return false;
}