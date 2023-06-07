#include "newgame.h"

void newgame::bitmap_output(int x, int y, char* string)
{
	//conversion to char array
	int len, i;
	glRasterPos2f(x, y);
	len = (int)strlen(string);
	for (i = 0; i < len; i++) {
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, string[i]);
	}
}
void newgame::start() {
	level = 0;
	score = 0;
	glClearColor(0, 0, 0, 0);
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();
	glTranslatef(0, 0, 0.0);
	glEnable(GL_POLYGON_SMOOTH);
	glHint(GL_POLYGON_SMOOTH_HINT, GL_NICEST);
	glBegin(GL_POLYGON);
	glColor3f(0.2, 0.2, 0.4);
	glVertex2d(300, 300);
	glVertex2d(-300, 300);
	glVertex2d(-300, -300);
	glVertex2d(300, -300);
	glEnd();
	char instructions[3][30] = { "**SLINGSHOT**","PRESS S TO PLAY","PRESS F1 TO PAUSE"};

		glColor3f(1, 1, 1);
	bitmap_output(-50, 100, instructions[0]);
		glColor3f(1, 1, 1);
	bitmap_output(-50, 00, instructions[1]);
		glColor3f(1, 1, 1);
	bitmap_output(-50, -50, instructions[2]);

}
void newgame::pause() {
	glClearColor(0, 0, 0, 0);
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();
	glTranslatef(0, 0, 0.0);
	glEnable(GL_POLYGON_SMOOTH);
	glHint(GL_POLYGON_SMOOTH_HINT, GL_NICEST);
	glBegin(GL_POLYGON);
	glColor3f(0.1, 0.3, 0);
	glVertex2d(300, -300);
	glVertex2d(300, -300);
	glVertex2d(-300, -300);
	glVertex2d(-300, -300);
	glEnd();
	char instructions[2][30] = { "*SLINGSHOT*","*PRESS F2 TO RESUME*" };
	glColor3f(1, 1, 1);
	bitmap_output(-50, 50, instructions[0]);
	glColor3f(1, 1, 1);
	bitmap_output(-100, -50, instructions[1]);
	char scores[15 + sizeof(char)];
	glColor3f(1, 1, 1);
	char sc[] = "*SCORE=        * ";
	sprintf_s(scores, "%d", score);
	bitmap_output(-50, 0 , sc);
	bitmap_output(35,0 , scores);

}
void newgame::congrats() {
	glClearColor(0, 0, 0, 0);
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();
	glTranslatef(0, 0, 0.0);
	glEnable(GL_POLYGON_SMOOTH);
	glHint(GL_POLYGON_SMOOTH_HINT, GL_NICEST);
	glBegin(GL_POLYGON);
	glColor3f(0.1, 0.3, 0);
	glVertex2d(300, -300);
	glVertex2d(300, -300);
	glVertex2d(-300, -300);
	glVertex2d(-300, -300);
	glEnd();
	if (chance != 0) {
	score += chance * 10;
	chance = 0;
	}
	char instructions[2][30] = { "*LEVEL CLEARED*","*PRESS S TO CONTINUE*" };
	glColor3f(1, 1, 1);
	bitmap_output(-60, 50, instructions[0]);
	glColor3f(1, 1, 1);
	bitmap_output(-100, -50, instructions[1]);
	char scores[15 + sizeof(char)];
	glColor3f(1, 1, 1);
	char sc[] = "*SCORE=        * ";
	sprintf_s(scores, "%d", score);
	bitmap_output(-50, 0, sc);
	bitmap_output(35, 0, scores);

}
void newgame::gameover() {
	glClearColor(0, 0, 0, 0);
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();
	glTranslatef(0, 0, 0.0);
	glEnable(GL_POLYGON_SMOOTH);
	glHint(GL_POLYGON_SMOOTH_HINT, GL_NICEST);
	glBegin(GL_POLYGON);
	glColor3f(0.1, 0.3, 0);
	glVertex2d(300, -300);
	glVertex2d(300, -300);
	glVertex2d(-300, -300);
	glVertex2d(-300, -300);
	glEnd();
	char instructions[2][30] = { "*YOU LOST*","*PRESS S TO RESTART*" };
	glColor3f(1, 1, 1);
	bitmap_output(-50, 50, instructions[0]);
	glColor3f(1, 1, 1);
	bitmap_output(-100, -50, instructions[1]);
	char scores[15 + sizeof(char)];
	glColor3f(1, 1, 1);
	char sc[] = "*SCORE=        * ";
	sprintf_s(scores, "%d", score);
	bitmap_output(-50, 0, sc);
	bitmap_output(35, 0, scores);


}
void newgame::background() {
	glClearColor(0, 0, 0, 0);
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();
	glTranslatef(0, 0, 0.0);
	glEnable(GL_POLYGON_SMOOTH);
	glHint(GL_POLYGON_SMOOTH_HINT, GL_NICEST);
	//ground
	glBegin(GL_POLYGON);
	glColor3f(0.1, 0.3, 0);
	glVertex2d(300, -300);
	glVertex2d(300, -230);
	glVertex2d(-300, -230);
	glVertex2d(-300, -300);
	glEnd();
	//sky
	glBegin(GL_POLYGON);
	glColor3f(0.2, 0.2, 0.4);
	glVertex2d(300, -230);
	glVertex2d(300, 300);
	glVertex2d(-300, 300);
	glVertex2d(-300, -230);
	glEnd();
	//Drawstars();
	//POLE RIGHT
	glBegin(GL_POLYGON);
	glColor3f(0.3, 0, 0.1);
	glVertex2d(270, -260);
	glVertex2d(270, 200);
	glVertex2d(250, 200);
	glVertex2d(250, -260);
	glEnd();
	//POLE LEFT
	glBegin(GL_POLYGON);
	glColor3f(0.3, 0, 0.1);
	glVertex2d(-270, -260);
	glVertex2d(-270, 200);
	glVertex2d(-250, 200);
	glVertex2d(-250, -260);
	glEnd();

	//WIRE1
	glColor3f(0, 0, 0);
	glLineWidth(3.0);
	glBegin(GL_LINES);
	glVertex2d(-265, wire1);
	glVertex2d(265, wire1);
	glEnd();
	//WIRE2
	glColor3f(0, 0, 0);
	glLineWidth(3.0);
	glBegin(GL_LINES);
	glVertex2d(-265, wire2);
	glVertex2d(265, wire2);
	glEnd();

	glDisable(GL_POLYGON_SMOOTH);
	glHint(GL_POLYGON_SMOOTH_HINT, GL_DONT_CARE);
}
void newgame::player(int x) {
	xpos = x;
	glLoadIdentity();
	glTranslatef(xpos, -220.0, 0.0);
	glBegin(GL_POLYGON);
	glColor3f(1, 0, 0);
	double radius = 10.0;
	double ori_x = 0.0;
	double ori_y = 0.0;
	for (int i = 0; i <= 300; i++) {
		double angle = 2 * 3.14 * i / 300;
		double x = cos(angle) * radius;
		double y = sin(angle) * radius;
		glVertex2d(ori_x + x, ori_y + y);
	}
	glEnd();
	//slingshot
	glLoadIdentity();
	glTranslatef(xpos, -270.0, 0.0);
	glBegin(GL_POLYGON);
	glColor3f(1, 1, 0);
	glVertex2d(-8, 0);
	glVertex2d(+8, 0);
	glVertex2d(+8, 40);
	glVertex2d(+20, 60);
	glVertex2d(+14, 66);
	glVertex2d(0, 40);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(1, 1, 0);
	glVertex2d(0, 40);
	glVertex2d(-14, 66);
	glVertex2d(-20, 60);
	glVertex2d(-8, 40);
	glVertex2d(-8, 0);
	glEnd();
	//END OF SLINGSHOT
}