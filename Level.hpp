#pragma once

#include "Enemy.hpp"
#include "Player.hpp"

#include <vector>

using namespace std;

#ifndef LEVEL_H
#define LEVEL_H

class Level {
	public:
		int startX, startY;
		vector<Enemy> enemies;
		void start(Player& player);
		void logic(Player player);
		void renderBackground();
		void finish();

		Level(int startX, int startY, vector<Enemy> enemies);
};

#endif