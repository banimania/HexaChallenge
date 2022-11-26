#pragma once

#include "Enemy.hpp"
#include "Player.hpp"
#include "Goal.hpp"

#include <vector>

using namespace std;

#ifndef LEVEL_H
#define LEVEL_H

class Level {
	public:
		int index;
		int startX, startY;
		vector<Enemy> enemies;
		vector<Goal> goals;
		vector<Wall> walls;
		void start(Player& player);
		void logic(Player player);
		void renderBackground();

		Level(int index, int startX, int startY, vector<Enemy> enemies, vector<Goal> goals, vector<Wall> walls);
};

#endif