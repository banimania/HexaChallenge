#include "Game.hpp"
#include "main.hpp"
#include "Player.hpp"
#include "Enemy.hpp"
#include "Level.hpp"

#include <vector>
#include <iostream>
#include <gl/glut.h>
#include <windows.h> 

using namespace std;

Player player = Player(100, 100, 1, 4);
Level level = Level(120, 50, { Enemy(90, 40, 2, 4.5f) });

bool Game::init(int argc, char** argv) {

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

	glutInitWindowPosition(400, 200);
	glutInitWindowSize(WIDTH, HEIGHT);
	glutCreateWindow("HexaChallenge");

	glutDisplayFunc(render);
	glutIdleFunc(idle);
	
    level.start(player);

	cout << "Init successful in " << glutGet(GLUT_ELAPSED_TIME) << "ms!";

	glutMainLoop();

	return true;
}

void render() {
    glClearColor(0.45f, 0.45f, 0.45f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

	level.renderBackground();

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 200.0, 200.0, 0.0);

    level.logic(player);

    player.handleMovement();
    player.renderPlayer();

    glFlush();
}

void timer(int time) {
	glutPostRedisplay();
	glutTimerFunc(DELAY, timer, 0);
}

void idle() {

	glutPostRedisplay();

    Sleep(1);
}

/*void printFPS() {
	static chrono::time_point<chrono::steady_clock> oldTime = chrono::high_resolution_clock::now();
	static int fps; fps++;

	if (chrono::duration_cast<chrono::seconds>(chrono::high_resolution_clock::now() - oldTime) >= chrono::seconds{ 1 }) {
		oldTime = chrono::high_resolution_clock::now();
		cout << "FPS: " << fps << endl;
		fps = 0;
	}
}*/