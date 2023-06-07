#pragma once
#include<GL/glut.h>
#include <iostream>
#include<math.h>
#include "stone.h"
#define width 300;
class enemy
{ public:
	float x, y;
	float espeed = 10.0;
	float sr, sl, st, sb;
	int m;
	bool hit=false;
	enemy(float xpos, float ypos,int move);
	void render();
	void move();
	void hitcheck(stone astone);
};


