#pragma once

#include "Enemy.hpp"
#include "Player.hpp"
#include "Goal.hpp"
#include "Background.hpp"
#include "Coin.hpp"

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
		vector<Background> backgrounds;
		vector<Coin> coins;
		void start(Player& player);
		void logic(float dt, Player player);
		void renderBackground();
		void renderSquaredBg();

		Level(int index, int startX, int startY, vector<Enemy> enemies, vector<Goal> goals, vector<Wall> walls, vector<Background> backgrounds, vector<Coin> coins);
};

#endif