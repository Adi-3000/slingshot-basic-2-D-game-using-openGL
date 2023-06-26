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
	case 6:lvl6();
		break;
	case 7:lvl7();
		break;
	case 8:lvl8();
		break;
	case 9:lvl9();
		break;
	case 10:lvl10();
		break;
	case 11:lvl11();
		break;
	case 12:lvl12();
		break;
	case 13:lvl13();
		break;
	
	}
}
void levels::lvl1() {
	wire = 2;
	chance = 5;
	enemylist.clear();
	enemylist.push_back(enemy(100, wire1, 0));//xpos,ypos,movement(1=right,-1=left,0=null;
	enemylist.push_back(enemy(-100, wire2, 0));//xpos,ypos,movement(1=right,-1=left,0=null;
}
void levels::lvl2() {
	wire = 2;
	chance = 3;
	enemylist.clear();
	enemylist.push_back(enemy(100, wire1, 0));//xpos,ypos,movement(1=right,-1=left,0=null;
	enemylist.push_back(enemy(0, wire1, 0));//xpos,ypos,movement(1=right,-1=left,0=null;
	enemylist.push_back(enemy(-100, wire2, 0));//xpos,ypos,movement(1=right,-1=left,0=null;
}
void levels::lvl3() {
	wire = 2;
	chance = 3;
	enemylist.clear();
	enemylist.push_back(enemy(100, wire1, 0));//xpos,ypos,movement(1=right,-1=left,0=null;
	enemylist.push_back(enemy(-100, wire2, 1));//xpos,ypos,movement(1=right,-1=left,0=null;
}
void levels::lvl4() {
	wire = 2;
	chance = 2;
	enemylist.clear();
	enemylist.push_back(enemy(100, wire1, 1));//xpos,ypos,movement(1=right,-1=left,0=null;
	enemylist.push_back(enemy(-100, wire2, -1));//xpos,ypos,movement(1=right,-1=left,0=null;
}
void levels::lvl5() {
	wire = 2;
	chance = 1;
	enemylist.clear();
	enemylist.push_back(enemy(100, wire1, 1));//xpos,ypos,movement(1=right,-1=left,0=null;
	enemylist.push_back(enemy(0, wire2, -0));//xpos,ypos,movement(1=right,-1=left,0=null;
	enemylist.push_back(enemy(-100, wire2, -1));//xpos,ypos,movement(1=right,-1=left,0=null;
}
void levels::lvl6() {
	wire = 3;
	chance = 2;
	enemylist.clear();
	oblist.clear();
	enemylist.push_back(enemy(100, wire2, 0));//xpos,ypos,movement(1=right,-1=left,0=null;
	oblist.push_back(obstacles(1,100, wire1, 0));//type(1=bounce,2=spark),xpos,ypos,movement(1=right,-1=left,0=null;
	enemylist.push_back(enemy(-100, wire3, 0));//xpos,ypos,movement(1=right,-1=left,0=null;
}
void levels::lvl7() {
	wire = 3;
	chance = 2;
	enemylist.clear();
	oblist.clear();
	enemylist.push_back(enemy(100, wire2, 0));//xpos,ypos,movement(1=right,-1=left,0=null;
	oblist.push_back(obstacles(1, 100, wire1, 1));//type(1=bounce,2=spark),xpos,ypos,movement(1=right,-1=left,0=null;
	enemylist.push_back(enemy(-100, wire2, 0));//xpos,ypos,movement(1=right,-1=left,0=null;
	enemylist.push_back(enemy(-100, wire2, 0));//xpos,ypos,movement(1=right,-1=left,0=null;
}
void levels::lvl8() {
	wire = 3;
	chance = 2;
	enemylist.clear();
	oblist.clear();
	enemylist.push_back(enemy(100, wire2, 0));//xpos,ypos,movement(1=right,-1=left,0=null;
	oblist.push_back(obstacles(1,100, wire1, 1));//type(1=bounce,2=spark),xpos,ypos,movement(1=right,-1=left,0=null;
	enemylist.push_back(enemy(-100, wire1, 1));//xpos,ypos,movement(1=right,-1=left,0=null;
	enemylist.push_back(enemy(-150, wire2, 1));//xpos,ypos,movement(1=right,-1=left,0=null;
}
void levels::lvl9() {
	wire = 3;
	chance = 1;
	enemylist.clear();
	oblist.clear();
	oblist.push_back(obstacles(1, 0, wire1, 1));//type(1=bounce,2=spark),xpos,ypos,movement(1=right,-1=left,0=null;
	enemylist.push_back(enemy(100, wire2, -1));//xpos,ypos,movement(1=right,-1=left,0=null;
	enemylist.push_back(enemy(-100, wire3, 1));//xpos,ypos,movement(1=right,-1=left,0=null;
	enemylist.push_back(enemy(-100, wire2, 0));//xpos,ypos,movement(1=right,-1=left,0=null;
}
void levels::lvl10() {
	wire = 3;
	chance = 1;
	enemylist.clear();
	oblist.clear();
	oblist.push_back(obstacles(1, 100, wire1, 1));//type(1=bounce,2=spark),xpos,ypos,movement(1=right,-1=left,0=null;
	enemylist.push_back(enemy(100, wire2, -1));//xpos,ypos,movement(1=right,-1=left,0=null;
	enemylist.push_back(enemy(-100, wire3, 1));//xpos,ypos,movement(1=right,-1=left,0=null;
}
void levels::lvl11() {
	wire = 3;
	chance = 1;
	enemylist.clear();
	oblist.clear();
	oblist.push_back(obstacles(2, 100, wire1, 0));//type(1=bounce,2=spark),xpos,ypos,movement(1=right,-1=left,0=null;
	enemylist.push_back(enemy(100, wire2, -1));//xpos,ypos,movement(1=right,-1=left,0=null;
	enemylist.push_back(enemy(-100, wire3, 1));//xpos,ypos,movement(1=right,-1=left,0=null;
}
void levels::lvl12() {
	wire = 3;
	chance = 1;
	enemylist.clear();
	oblist.clear();
	oblist.push_back(obstacles(2, 100, wire1, -1));//type(1=bounce,2=spark),xpos,ypos,movement(1=right,-1=left,0=null;
	enemylist.push_back(enemy(100, wire2, 0));//xpos,ypos,movement(1=right,-1=left,0=null;
	enemylist.push_back(enemy(-100, wire3, 1));//xpos,ypos,movement(1=right,-1=left,0=null;
}
void levels::lvl13() {
	wire = 3;
	chance = 1;
	enemylist.clear();
	oblist.clear();
	oblist.push_back(obstacles(2, 100, wire1, -1));//type(1=bounce,2=spark),xpos,ypos,movement(1=right,-1=left,0=null;
	enemylist.push_back(enemy(100, wire2, -1));//xpos,ypos,movement(1=right,-1=left,0=null;
	enemylist.push_back(enemy(-100, wire3, 1));//xpos,ypos,movement(1=right,-1=left,0=null;
}


