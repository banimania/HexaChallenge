#pragma once

#ifndef WALL_H
#define WALL_H

class Wall {
public:
	int x, y, length, direction;

	void render();
	Wall(int x, int y, int length, int direction);
};

#endif