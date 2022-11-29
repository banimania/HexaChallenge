#pragma once

#include "Wall.hpp"

#include <vector>

using namespace std;

#ifndef PLAYER_H
#define PLAYER_H

class Player {
	public:
		float x, y, speed, size;
		int deathcount;
		void renderPlayer();
		void handleMovement(float dt, vector<Wall> walls);
		bool isCollidingWithEnemy(float ex, float ey, int radius);

		Player(float x, float y, float speed, float size);
};

#endif