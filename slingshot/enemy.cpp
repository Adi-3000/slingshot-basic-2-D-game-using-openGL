#include "enemy.h"
#include <iostream>

enemy::enemy(float xpos, float ypos,int move) {
	x = xpos;
	y = ypos;
	espeed = 05.0;
	m = move;
	sr = x + 12;
	sl = x - 12;
	st =  y+40;
	sb =  y-15;
	
}
void enemy::render() {
	glLoadIdentity();
	glTranslatef(x, y, 0.0);
	glBegin(GL_POLYGON);
	glColor3f(0.2, 0.2, 1);
	glVertex2d(-10, 0);
	glVertex2d(0, -15);
	glVertex2d(+10, 0);
	glVertex2d(+10, 10);
	glVertex2d(+0, 15);
	glVertex2d(-10, 10);
	glVertex2d(-10, 0);
	glVertex2d(0, 40);
	glEnd();
}
void enemy::move() {
	
		switch (m) {
		case 1:
			if (x < 270)
			{
				x += espeed;
				sr += espeed;
				sl += espeed;
			}
			else
				m = -1;
			break;

		case -1:
			if (x > -270) {
				x -= espeed;
				sr -= espeed;
				sl -= espeed;
			}
			else
				m = 1;
			break;
		case 0:
			break;
		}
	
}
void enemy::hitcheck(stone astone) {
	/*std::cout << "*****hitcheck called****\n";
	std::cout << "top="<<st<<"stone top="<<astone.st<<"\n";
	std::cout << "btm="<<sb<<"stone top="<<astone.sb<<"\n";
	std::cout << "rt="<<sr<<"stone top="<<astone.sr<<"\n";
	std::cout << "lf="<<sl<<"stone top="<<astone.sl<<"\n";
	*/
	if (astone.st >=sb  &&  astone.sb<= st && astone.sl <= sr &&  astone.sr>=sl )
	{
		hit = true;
		std::cout << "*****hit****\n";

	}
}