
#include "stone.h"

stone::stone(int xpos) {
	x = xpos;
	speed = 6.0;
	sr =x+2;
	sl =x-2;
	st = -218 + y;
	sb = -222 + y;

	//remove = false;
	//y = 0;
}
void stone::render() {
	glLoadIdentity();
	glTranslatef(x, -220.0 + y, 0.0);
	glBegin(GL_POLYGON);
	glColor3f(1, 0, 0);
	double radius = 5.0;
	double ori_x = 0.0;
	double ori_y = 0.0;
	for (int i = 0; i <= 300; i++) {
		double angle = 2 * 3.14 * i / 300;
		double x = cos(angle) * radius;
		double y = sin(angle) * radius;
		glVertex2d(ori_x + x, ori_y + y);
	}
	glEnd();
}
void stone::shoot() {
	
	 y =y+ speed;	
	 st +=speed ;
	 sb += speed;
	//std::cout << y <<"\n";
	
}
void stone::sremove() {
	if (y >= HEIGHT) {
		remove = true;
	}
	//std::cout << "sremove called\n";
}
