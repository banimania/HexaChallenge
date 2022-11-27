#include "LevelManager.hpp"
#include "main.hpp"

#include <vector>

Level LevelManager::getLevelFromId(int id) {
	for (Level level : levelList) {
		if (level.index == id) {
			return level;
		}
	}

	return Level(420, 100, 100, {}, {}, {});
}

void LevelManager::initLevelManager() {
	Level level1 = Level(1, 100, 40,
		{ Enemy(100, 60, 1, 4.5f, 1, 0) , Enemy(100, 70, 1, 4.5f, 0, 0) , Enemy(100, 80, 1, 4.5f, 1, 0) , Enemy(100, 90, 1, 4.5f, 0, 0), 
		Enemy(100, 100, 1, 4.5f, 1, 0) , Enemy(100, 110, 1, 4.5f, 0, 0) , Enemy(100, 120, 1, 4.5f, 1, 0) , Enemy(100, 130, 1, 4.5f, 0, 0),
		Enemy(100, 140, 1, 4.5f, 1, 0) , Enemy(100, 150, 1, 4.5f, 0, 0) },
		{ Goal(85, 155, 30, 30, true, 1) },
		{ Wall(55, 55, 100, 1) , Wall(145, 55, 100, 1) , Wall(85, 25, 30, 2) , Wall(55, 55, 30, 2) , Wall(115, 55, 30, 2) , Wall(55, 155, 30, 2) ,
		Wall(115, 155, 30, 2) , Wall(85, 25, 30, 1) , Wall(115, 25, 30, 1) ,
		Wall(85, 155, 30, 1), Wall(115, 155, 30, 1) , Wall(85, 185, 30, 2) });

	Level level2 = Level(2, 20, 70,
		{ Enemy(60, 70, 1, 5, 2, 20) },
		{ Goal(85, 85, 30, 30, true, 1) },
		{});

	levelList.push_back(level1);
	levelList.push_back(level2);
}