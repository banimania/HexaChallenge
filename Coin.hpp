#pragma once

#include "Player.hpp"

#ifndef COIN_H
#define COIN_H

class Coin {
	public:
		int x, y;
		bool obtained = false;
		void render();
		void logicCoin(Player player);

		Coin(int x, int y);
};

#endif