#pragma once
#include<GL/glut.h>
#include <iostream>
#include<math.h>
#include "stone.h"
class obstacles
{public:
	float x, y;
	float espeed = 10.0;
	float tr, tl, tt, tb;
	int m,type;
	bool hit = false;
	obstacles(int type,float xpos, float ypos, int move);
	void render();
	void move();
	void hitcheck(stone& astone);
};

