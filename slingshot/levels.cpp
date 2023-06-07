#include "levels.h"
levels::levels() {
	lvl = 0;
}
void levels::loadlevels() {
	switch (lvl) {
	case 1:lvl1();
		break;
	case 2:lvl2();
		break;
	case 3:lvl3();
		break;
	case 4:lvl4();
		break;
	case 5:lvl5();
		break;
	
	}
}
void levels::lvl1() {
	chance = 5;
	enemylist.clear();
	enemylist.push_back(enemy(100, wire1, 0));//xpos,ypos,movement(1=right,-1=left,0=null;
	enemylist.push_back(enemy(-100, wire2, 0));//xpos,ypos,movement(1=right,-1=left,0=null;
}
void levels::lvl2() {
	chance = 3;
	enemylist.clear();
	enemylist.push_back(enemy(100, wire1, 0));//xpos,ypos,movement(1=right,-1=left,0=null;
	enemylist.push_back(enemy(0, wire1, 0));//xpos,ypos,movement(1=right,-1=left,0=null;
	enemylist.push_back(enemy(-100, wire2, 0));//xpos,ypos,movement(1=right,-1=left,0=null;
}
void levels::lvl3() {
	chance = 3;
	enemylist.clear();
	enemylist.push_back(enemy(100, wire1, 0));//xpos,ypos,movement(1=right,-1=left,0=null;
	enemylist.push_back(enemy(-100, wire2, 1));//xpos,ypos,movement(1=right,-1=left,0=null;
}
void levels::lvl4() {
	chance = 2;
	enemylist.clear();
	enemylist.push_back(enemy(100, wire1, 1));//xpos,ypos,movement(1=right,-1=left,0=null;
	enemylist.push_back(enemy(-100, wire2, -1));//xpos,ypos,movement(1=right,-1=left,0=null;
}
void levels::lvl5() {
	chance = 1;
	enemylist.clear();
	enemylist.push_back(enemy(100, wire1, 1));//xpos,ypos,movement(1=right,-1=left,0=null;
	enemylist.push_back(enemy(0, wire2, -0));//xpos,ypos,movement(1=right,-1=left,0=null;
	enemylist.push_back(enemy(-100, wire2, -1));//xpos,ypos,movement(1=right,-1=left,0=null;
}
/*
void levels::lvl6() {
	enemylist.push_back(enemy(100, wire1, 0));//xpos,ypos,movement(1=right,-1=left,0=null;
	enemylist.push_back(enemy(-100, wire2, 0));//xpos,ypos,movement(1=right,-1=left,0=null;
}
void levels::lvl7() {
	enemylist.push_back(enemy(100, wire1, 0));//xpos,ypos,movement(1=right,-1=left,0=null;
	enemylist.push_back(enemy(-100, wire2, 0));//xpos,ypos,movement(1=right,-1=left,0=null;
}
void levels::lvl8() {
	enemylist.push_back(enemy(100, wire1, 0));//xpos,ypos,movement(1=right,-1=left,0=null;
	enemylist.push_back(enemy(-100, wire2, 0));//xpos,ypos,movement(1=right,-1=left,0=null;
}
void levels::lvl9() {
	enemylist.push_back(enemy(100, wire1, 0));//xpos,ypos,movement(1=right,-1=left,0=null;
	enemylist.push_back(enemy(-100, wire2, 0));//xpos,ypos,movement(1=right,-1=left,0=null;
}
void levels::lvl10() {
	enemylist.push_back(enemy(100, wire1, 0));//xpos,ypos,movement(1=right,-1=left,0=null;
	enemylist.push_back(enemy(-100, wire2, 0));//xpos,ypos,movement(1=right,-1=left,0=null;
}
*/