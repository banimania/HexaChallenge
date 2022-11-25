#pragma once

#ifndef ENEMY_H
#define ENEMY_H

class Enemy {
	public:
		int x, y, speed, radius;
		int ox, oy, od, pdir;
		bool reachedEndPoint;
		void renderEnemy();
		void logic(int direction, int distance);

		Enemy(int x, int y, int speed, int radius);
};

#endif