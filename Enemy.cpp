#include "Enemy.hpp"

#include <math.h>
#include <gl/glut.h>

Enemy::Enemy(int x, int y, int speed, int radius) {
	this->x = x;
	this->y = y;
	this->speed = speed;
	this->radius = radius;
	
	this->ox = x;
	this->oy = y;
	this->od = -1;
	this->pdir = -1;
	this->reachedEndPoint = false;
}

void Enemy::renderEnemy() {

	//Outline
	for (double i = 0; i < 360; i++) {
		glBegin(GL_LINES);
		glColor3f(0.0f, 0.0f, 0.0f);

		float xc = x + radius * cos(i);
		float yc = y + radius * sin(i);

		glVertex2f(xc, yc);
		glVertex2f(x, y);

		glEnd();
	}

	//Circle
	for (double i = 0; i < 360; i++) {
		glBegin(GL_LINES);
		glColor3f(1.0f, 0.0f, 0.0f);

		float xc = x + (radius - (radius / 4)) * cos(i);
		float yc = y + (radius - (radius / 4)) * sin(i);

		glVertex2f(xc, yc);
		glVertex2f(x, y);

		glEnd();
	}


	/*
	glBegin(GL_QUADS);
	glColor3f(1, 0, 0);
	glVertex2f(x - radius, y + radius);
	glVertex2f(x - radius, y - radius);
	glVertex2f(x + radius, y - radius);
	glVertex2f(x + radius, y + radius);
	glEnd();*/
}

void Enemy::logic(int direction, int distance) {
	if (od == -1) {
		od = direction;
		pdir = direction;
	}

	if (pdir == 0) {
		if (ox - distance <= x - speed) {
			x -= speed;
		} else {
			reachedEndPoint = true;
		}
	} else if (pdir == 1) {
		if (ox + distance >= x + speed) {
			x += speed;
		} else {
			reachedEndPoint = true;
		}
	}

	if (reachedEndPoint) {
		pdir == 1 ? pdir = 0 : pdir = 1;
		reachedEndPoint = false;
	}
	
}