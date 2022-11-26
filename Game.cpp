#include "Game.hpp"
#include "main.hpp"
#include "Player.hpp"
#include "Enemy.hpp"
#include "Level.hpp"

#include <vector>
#include <string>
#include <gl/glut.h>
#include <windows.h> 
#include <iostream>

using namespace std;

Player player = Player(100, 100, 1, 4);

Level actualLevel = Level(420, 100, 100, {}, {});

int eTime;
string secondsToTimeFormat(int seconds);

bool Game::init(int argc, char** argv) {

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

	glutInitWindowPosition(400, 200);
	glutInitWindowSize(W_WIDTH, W_HEIGHT);
	glutCreateWindow("HexaChallenge");

	glutDisplayFunc(render);
	glutIdleFunc(idle);
	
	game.levelManager.initLevelManager();

	game.currentLevel = 1;
	actualLevel = game.levelManager.getLevelFromId(1);
	actualLevel.start(player);

	cout << "Init successful in " << glutGet(GLUT_ELAPSED_TIME) << "ms!";

	glutMainLoop();

	return true;
}

void Game::restartFromLevel(int levelIndex, bool withDeath) {
	game.levelManager.getLevelFromId(levelIndex).start(player);
	game.currentLevel = levelIndex;
	if (withDeath) {
		player.deathcount++;
	}
}

void render() {
    glClearColor(0.45f, 0.45f, 0.45f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 200.0, 200.0, 0.0);

	actualLevel.renderBackground();
	renderInfo();

	actualLevel.logic(player);

    player.handleMovement();
    player.renderPlayer();

    glFlush();
}

void idle() {

	glutPostRedisplay();

    Sleep(1);
	eTime++;
}

void renderInfo() {
	//Black bar
	glBegin(GL_QUADS);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex2f(0, 0);
	glVertex2f(0, HEIGHT/14);
	glVertex2f(WIDTH, HEIGHT/14);
	glVertex2f(WIDTH, 0);
	glEnd();

	//LEVEL COUNT
	string levelText = "Level:" + to_string(game.currentLevel);
	glPushMatrix();
	glColor3f(1.0f, 1.0f, 1.0f);
	glTranslatef(10.0f, 10.0f, 0.0f);
	glScalef(0.1f, -0.075f, 0.0f);
	for (int i = 0; i < levelText.size(); i++) {
		glutStrokeCharacter(GLUT_STROKE_ROMAN, levelText[i]);
	}
	glPopMatrix();

	//DEATH COUNT
	string deathText = "Deaths:" + to_string(player.deathcount);
	glPushMatrix();
	glColor3f(1.0f, 1.0f, 1.0f);
	glTranslatef(60.0f, 10.0f, 0.0f);
	glScalef(0.1f, -0.075f, 0.0f);
	for (int i = 0; i < deathText.size(); i++) {
		glutStrokeCharacter(GLUT_STROKE_ROMAN, deathText[i]);
	}
	glPopMatrix();

	//TIME COUNT
	string elapsedTime = "Time:" + secondsToTimeFormat(eTime / 60);
	glPushMatrix();
	glColor3f(1.0f, 1.0f, 1.0f);
	glTranslatef(120.0f, 10.0f, 0.0f);
	glScalef(0.1f, -0.075f, 0.0f);
	for (int i = 0; i < elapsedTime.size(); i++) {
		glutStrokeCharacter(GLUT_STROKE_ROMAN, elapsedTime[i]);
	}
	glPopMatrix();
}

string secondsToTimeFormat(int seconds) {
	string timeFormat = "";
	string ss = to_string(seconds % 60);
	string mm = to_string((seconds / 60) % 60);
	string hh = to_string(seconds / 3600);

	if (ss.size() == 1) {
		ss = "0" + ss;
	}

	if (mm.size() == 1) {
		mm = "0" + mm;
	}

	if (hh.size() == 1) {
		hh = "0" + hh;
	}

	strcmp(hh.c_str(), "00") == 0 ? timeFormat = mm + ":" + ss : timeFormat = hh + ":" + mm + ":" + ss;
	return timeFormat;
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