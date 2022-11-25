#include "Game.hpp"
#include "main.hpp"

int main(int argc, char** argv) {
	
	game = Game();
	if (game.init(argc, argv)) {
		return 0;
	}

	return 1;
}