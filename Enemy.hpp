#pragma once

#ifndef ENEMY_H
#define ENEMY_H

class Enemy {
	public:
		int x, y, speed, radius;
		int ox, oy, od;
		int direction, distance;
		bool reachedEndPoint;
		void renderEnemy();
		void logic();

		Enemy(int x, int y, int speed, int radius, int direction, int distance);
};

#endif