#include "LevelManager.hpp"
#include "main.hpp"

#include <vector>
#include <iostream>

using namespace std;

Level LevelManager::getLevelFromId(int id) {
	for (Level level : levelList) {
		if (level.index == id) {
			return level;
		}
	}

	//cout << game.levelManager.levelList.size();
	return Level(420, 100, 100, {}, {});
}

void LevelManager::initLevelManager() {
	Level level1 = Level(1, 100, 30,
		{ Enemy(100, 50, 2, 5, 1, 40) , Enemy(100, 60, 2, 5, 0, 40) , Enemy(100, 70, 2, 5, 1, 40) , Enemy(100, 80, 2, 5, 0, 40) },
		{ Goal(85, 85, 30, 30, true, 1) });

	Level level2 = Level(2, 180, 90,
		{ Enemy(100, 50, 2, 5, 1, 40) , Enemy(100, 60, 2, 5, 0, 40) , Enemy(100, 70, 2, 5, 1, 40) , Enemy(100, 80, 2, 5, 0, 40) },
		{ Goal(85, 85, 30, 30, true, 1) });

	levelList.push_back(level1);
	levelList.push_back(level2);
}