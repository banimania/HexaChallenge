#pragma once

#ifndef BACKGROUND_H
#define BACKGROUND_H

class Background {
	public:
		int x, y, width, height;
		void render();

		Background(int x, int y, int width, int height);
};

#endif