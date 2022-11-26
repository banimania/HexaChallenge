#pragma once

#include "Level.hpp"

#include <vector>

using namespace std;

#ifndef LEVELMANAGER_H
#define LEVELMANAGER_H

class LevelManager {
	public:
		vector<Level> levelList;
		Level getLevelFromId(int id);
		void initLevelManager();
};

#endif