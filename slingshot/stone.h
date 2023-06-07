#pragma once
#include<GL/glut.h>
#include <iostream>
#include<math.h>

#define HEIGHT 600
class stone
{
	public:

	float x, y=10.0, speed;
	float sr, sl, st, sb;
	bool remove=false;
	void render();
	void shoot();
	void sremove();
	stone(int xpos);
};

