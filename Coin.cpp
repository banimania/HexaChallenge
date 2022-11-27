#include "Coin.hpp"

#include <gl/glut.h>
#include <math.h>

using namespace std;

Coin::Coin(int x, int y) {
	this->x = x;
	this->y = y;
	this->obtained = obtained;
}

void Coin::render() {
	//Outline
	if (obtained) {
		return;
	}

	for (double i = 0; i < 360; i++) {
		glBegin(GL_LINES);
		glColor3f(0.0f, 0.0f, 0.0f);

		float xc = x + (4 * cos(i));
		float yc = y + (4 * sin(i));

		glVertex2f(xc, yc);
		glVertex2f(x, y);

		glEnd();
	}

	//Circle
	for (double i = 0; i < 360; i++) {
		glBegin(GL_LINES);
		glColor3f(1.0f, 1.0f, 0.0f);

		float xc = x + (3 * cos(i));
		float yc = y + (3 * sin(i));

		glVertex2f(xc, yc);
		glVertex2f(x, y);

		glEnd();
	}
}

void Coin::logicCoin(Player player) {
	//Collision checks
	if (player.x + player.size > x && player.x - player.size < x + 8
		&& player.y + player.size > y && player.y - player.size < y + 8) {
		obtained = true;
	}
}