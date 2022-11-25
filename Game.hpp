#pragma once

#include "Player.hpp"

static const int DELAY = 17;
static const int WIDTH = 800;
static const int HEIGHT = 800;
static const int MAX_FPS = 60;

void render();
void timer(int time);
void idle();

#ifndef GAME_H
#define GAME_H

class Game {
	public:
		bool init(int argc, char** argv);
};

#endif