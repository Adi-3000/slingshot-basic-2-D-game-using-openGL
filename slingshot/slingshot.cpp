#include <stdlib.h>
#include <charconv>
#include <GL/glut.h>
#include <iostream>
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <string.h>
#include <string>
#include <vector>
#include "stone.h"
#include "enemy.h"
#include "newgame.h"
#include "levels.h"
using namespace std;

#define WINDOW_WIDTH  600
#define WINDOW_HEIGHT 600
#define wire1 150.0
#define wire2 100.0

void timer(int);
void Init();
int main(int argc, char* argv[]);
float xpos = 0, ypos = 0, stone_x = 0;
int state = 0;
//stone
vector<stone> stonelist;
//vector<stone>::iterator it;
 //enemy
vector<enemy> enemylist;
//vector<enemy>::iterator en;
//for  text
//
levels lv;
newgame game;




void life() {
//displaying chances
	glLoadIdentity();
	glTranslatef(0, -100.0, 0.0);
	char life[15 + sizeof(char)];
	char lf[] = "life= ";
	glColor3f(1, 1, 1);
	sprintf_s(life, "%d", game.chance);
	game.bitmap_output(WINDOW_WIDTH / 2 - 70, WINDOW_HEIGHT / 2 + 50, lf);
	game.bitmap_output(WINDOW_WIDTH / 2 - 30, WINDOW_HEIGHT / 2+50, life);
}
void scores() {
//displaying chances
	glLoadIdentity();
	glTranslatef(0, -100.0, 0.0);
	char scores[15 + sizeof(char)];
	glColor3f(1, 1, 1);
	char sc[] = "score= ";
	sprintf_s(scores, "%d", game.score);
	game.bitmap_output(WINDOW_WIDTH / 2 - 580, WINDOW_HEIGHT / 2+50, sc);
	game.bitmap_output(WINDOW_WIDTH / 2 - 520, WINDOW_HEIGHT / 2+50, scores);
}
void level() {
//displaying chances
	glLoadIdentity();
	glTranslatef(0, -100.0, 0.0);
	char lvl[15 + sizeof(char)];
	glColor3f(1, 1, 1);
	char sc[] = "level= ";
	sprintf_s(lvl, "%d", lv.lvl);
	game.bitmap_output(WINDOW_WIDTH / 2 - 360, WINDOW_HEIGHT / 2+50, sc);
	game.bitmap_output(WINDOW_WIDTH / 2 - 300, WINDOW_HEIGHT / 2 + 50, lvl);
}


void display()
{
	//
	// clear window to black
	//
	glClearColor(0, 0, 0, 0);
	glClear(GL_COLOR_BUFFER_BIT);
	
	switch (state) {
	case 0:
		game.start();
		break;
	case 1:
		game.background();
		game.player(xpos);
			if (enemylist.empty()&&stonelist.empty()) 
				game.congrats();

			if (!enemylist.empty() && game.chance == 0 && stonelist.empty())
				game.gameover();

	for (enemy &anenemy:enemylist) {
		anenemy.render(); 
		anenemy.move();
		for (int j = stonelist.size() - 1; j >= 0; j--) {
			anenemy.hitcheck(stonelist[j]);
		}
	}
	for (stone &bullet : stonelist) {
		bullet.render();
		bullet.shoot();
		bullet.sremove();

	}
	life();
	level();
	scores();
		
		break;
	case 2:
		game.pause();
	}
	glutSwapBuffers();
	//for displaying enemy
}

//for contuinity

void fire(){
	//for clearing list of useless stones
	cout << stonelist.size();
	auto it = stonelist.begin();
	for (it; it != stonelist.end();it++ ) {
		stone temp = *it;
		if (temp.remove) {
			stonelist.erase(it);
			if (stonelist.empty())
				break;
			else
			it = stonelist.begin();
		}
	}
	//for clearing enemylist of hit enemies
	auto en = enemylist.begin();
	for (en; en != enemylist.end(); en++) {
		enemy temp = *en;
		if (temp.hit) {
			game.score += 10;
			enemylist.erase(en);
			if (enemylist.empty())
				break;
			else
				en = enemylist.begin();
		}
	}
}

void special(int key, int x, int y)
{
	switch (key)
	{
	case GLUT_KEY_UP:
		if (game.chance > 0) {
			game.chance--;
			stonelist.push_back(stone(xpos));
			glutIdleFunc(fire);
		}
		break;
	case GLUT_KEY_LEFT:
		if(xpos>-240)
		xpos-=5.0;
		break;
	case GLUT_KEY_RIGHT:
		if(xpos<240)
		xpos+=5.0;
		cout << xpos << "\n";
		break;
	case GLUT_KEY_F1:
		state = 2;
		break;
	case GLUT_KEY_F2:
		state = 1;
		break;

	}
	glutPostRedisplay();
}
void onKeyDown(unsigned char key, int x, int y)
{
	switch (key)
	{
	case ' ':
		if (game.chance > 0) {
			game.chance--;
			stonelist.push_back(stone(xpos));
			glutIdleFunc(fire);
		}
		break;
	case 13 :
	case 's':
	case 'S':
		if (enemylist.empty()) {
			if (lv.lvl == 5)
				lv.lvl = 0;
			lv.lvl++;
		}
		lv.loadlevels();
		xpos = 0;
		game.score = 0;
		enemylist = lv.enemylist;
		game.chance = lv.chance;
		state = 1;
		break;
	
	case 27:
		exit(1);
	}

	glutPostRedisplay();
}
//
// This function is called when the window size changes.
// w : is the new width of the window in pixels.
// h : is the new height of the window in pixels.
//
void onResize(int w, int h)
{
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-w/3.0 , w/3.0 , -h/3.0 , h/3.0 );
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

//initialize the opengl setup and variables
void Init() {

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_LINE_SMOOTH);
	glEnable(GL_POLYGON_SMOOTH);
	glEnable(GL_POINT_SMOOTH);
}
void timer(int) {
	glutPostRedisplay();
	glutTimerFunc(1000 / 100, timer, 0);//60fps
}

int main(int argc, char* argv[])
{
	
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
	glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
	glutCreateWindow("SLINGSHOT");
	glutDisplayFunc(display);
	//glutIdleFunc(display);
	glutReshapeFunc(onResize);
	glutTimerFunc(0, timer, 0);
	glutSpecialFunc(special);
	glutKeyboardFunc(onKeyDown);
	Init();
	glutMainLoop();
	return 0;
}