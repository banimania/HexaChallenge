#pragma once

#ifndef PLAYER_H
#define PLAYER_H

class Player {
	public:
		int x, y, speed, size;
		void renderPlayer();
		void handleMovement();
		bool isCollidingWithEnemy(int x, int y, int radius);

		Player(int x, int y, int speed, int size);
};

#endif