#pragma once
#include <stdlib.h>
#include <charconv>
#include <string>
#include<GL/glut.h>
#include<math.h>
#define WIDTH  600.00
#define HEIGHT 600.00
#define wire1 100.0
#define wire2 150.0
class newgame
{
public:
	int level,score,chance;
	int xpos = 0;
	void start();
	void background();
	void pause();
	void player(int x);
	void congrats();
	void gameover();
	void bitmap_output(int x, int y, char* string);
};

