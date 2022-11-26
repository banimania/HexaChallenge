#pragma once

#include <string>

#include "Player.hpp"

static const int DELAY = 17;
static const int W_WIDTH = 800;
static const int W_HEIGHT = 800;
static const int MAX_FPS = 60;

static const int WIDTH = 200;
static const int HEIGHT = 200;

void render();
void idle();
void renderInfo();

#ifndef GAME_H
#define GAME_H

class Game {
	public:
		bool init(int argc, char** argv);
		void restartFromLevel(int levelIndex);
};

#endif