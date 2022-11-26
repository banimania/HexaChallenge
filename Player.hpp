#pragma once

#include "Wall.hpp"

#include <vector>

using namespace std;

#ifndef PLAYER_H
#define PLAYER_H

class Player {
	public:
		int x, y, speed, size, deathcount;
		void renderPlayer();
		void handleMovement(vector<Wall> walls);
		bool isCollidingWithEnemy(int x, int y, int radius);

		Player(int x, int y, int speed, int size);
};

#endif