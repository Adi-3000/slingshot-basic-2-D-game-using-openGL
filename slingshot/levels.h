#pragma once
#include <stdlib.h>
#include <GL/glut.h>
#include <iostream>
#include <stdio.h>
#include <vector>
#include "enemy.h"
#define wire1 150.0
#define wire2 100.0

class levels
{
public:
	int lvl,chance,speed;
	std::vector<enemy>enemylist;
	levels();
	void loadlevels();
	void lvl1();
	void lvl2();
	void lvl3();
	void lvl4();
	void lvl5();
	void lvl6();
	void lvl7();
	void lvl8();
	void lvl9();
	void lvl10();
};

