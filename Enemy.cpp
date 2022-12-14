#include "Enemy.hpp"

#include <math.h>
#include <gl/glut.h>

using namespace std;

Enemy::Enemy(float x, float y, float speed, int radius, int direction, int distance, float i) {
	this->x = x;
	this->y = y;
	this->speed = speed;
	this->radius = radius;
	
	this->ox = x;
	this->oy = y;
	this->od = direction;
	this->i = i;
	this->oi = i;
	this->direction = direction;
	this->distance = distance;
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

void Enemy::logic(float dt) {

	if (direction == 0) {
		if (ox - distance <= x - speed) {
			x -= speed * dt;
		} else {
			reachedEndPoint = true;
		}
	} else if (direction == 1) {
		if (ox + distance >= x + speed) {
			x += speed * dt;
		} else {
			reachedEndPoint = true;
		}
	} else if (direction == 2) {
		if (oy - distance <= y - speed) {
			y -= speed * dt;
		} else {
			reachedEndPoint = true;
		}
	} else if (direction == 3) {
		if (oy + distance >= y + speed) {
			y += speed * dt;
		} else {
			reachedEndPoint = true;
		}
	} else if (direction == 4) { //CIRCULAR
		if (i > oi+360) {
			i = oi;
		}
		x = ox + distance * cos(i);
		y = oy +  distance * sin(i);
		i += speed * dt;
	} else if (direction == 5) { //CIRCULAR
		if (i < oi-360) {
			i = oi;
		}
		x = ox + distance * cos(i);
		y = oy + distance * sin(i);
		i -= speed * dt;
	}

	if (reachedEndPoint) {
		if (direction == 0 || direction == 1) {
			direction == 1 ? direction = 0 : direction = 1;
		} else if (direction == 2 || direction == 3) {
			direction == 2 ? direction = 3 : direction = 2;
		}
		
		reachedEndPoint = false;
	}
	
}