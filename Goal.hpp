#pragma once

#include "Player.hpp"

#ifndef GOAL_H
#define GOAL_H

class Goal {
public:
	int x, y, width, height;
	bool isGoal;
	void render();
	void logicGoal(Player player);

	Goal(int x, int y, int width, int height, bool isGoal);
};

#endif