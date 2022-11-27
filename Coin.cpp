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
	float d = sqrt(pow(player.x - x, 2) + pow(player.y - y, 2));
	if (d - 4 < player.size) {
		obtained = true;
	}
}