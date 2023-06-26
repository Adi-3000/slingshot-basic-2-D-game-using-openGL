#include "obstacles.h"

obstacles::obstacles(int type,float xpos, float ypos, int move) {
	this->type = type;
	x = xpos;
	y = ypos;
	espeed = 05.0;
	m = move;
	tr = x + 15;
	tl = x - 15;
	tt = y + 15;
	tb = y - 15;
				
	
}

void obstacles::render() {
	switch (type) {
	case 1://bounce
		glLoadIdentity();
		glTranslatef(x, y, 0.0);
		glBegin(GL_POLYGON);
		glColor3f(0.6, 0.2, 0.3);
		glVertex2d(+15, -15);
		glVertex2d(+15, 15);
		glVertex2d(-15, 15);
		glVertex2d(-15, -15);;
		glEnd();
		if (m != 0)
			move();
		break;
	 
	case 2: //spark
		glLoadIdentity();
		glTranslatef(x, y, 0.0);
		glBegin(GL_TRIANGLES);
		glColor3f(1, 0.6, 0);
		glVertex2d(+15, -15);
		glVertex2d(0, 15);
		glVertex2d(-15, -15);;
		glEnd();
		if (m != 0)
			move();
		break;
	}
	
}
void obstacles::move() {
	switch (m) {
	case 1:
		if (x < 260)
		{
			x += espeed;
			tr += espeed;
			tl += espeed;
		}
		else
			m = -1;
		break;

	case -1:
		if (x > -260) {
			x -= espeed;
			tr -= espeed;
			tl -= espeed;
		}
		else
			m = 1;
		break;
	case 0:
		break;
	}

}
void obstacles::hitcheck(stone& astone) {

	if (astone.st >= tb && astone.sb <= tt && astone.sl <= tr && astone.sr >= tl)
	{
		hit = true;
		switch (type) {
		case 1 :
			astone.state = -1;
		break;
		case 2:
			astone.remove = true;
		}
		//std::cout << "*****hit****\nstate="<<astone.state<<"\n";

	}
}