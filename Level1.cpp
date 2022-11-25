#include <vector>
#include "Level.hpp"

using namespace std;

class Level1: public Level {
	public:
		int startX = 140;
		int startY = 80;
		vector<Enemy> enemies { Enemy(100, 100, 2, 4.5f) };
};