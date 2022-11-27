#pragma once

#ifndef ENEMY_H
#define ENEMY_H

class Enemy {
	public:
		int x, y, radius;
		int ox, oy, od;
		float speed, i;
		int direction, distance;
		bool reachedEndPoint;
		void renderEnemy();
		void logic();

		Enemy(int x, int y, float speed, int radius, int direction, int distance);
};

#endif