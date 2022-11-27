#pragma once

#ifndef ENEMY_H
#define ENEMY_H

class Enemy {
	public:
		float x, y;
		int radius;
		int ox, oy, od;
		float speed, i;
		int direction, distance;
		bool reachedEndPoint;
		void renderEnemy();
		void logic();

		Enemy(float x, float y, float speed, int radius, int direction, int distance);
};

#endif