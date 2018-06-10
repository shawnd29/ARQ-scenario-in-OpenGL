#include<GL/glut.h>
#include<stdio.h>
#define dx 25
#define dy 25

GLfloat x[25];
GLfloat y[20];
GLfloat r;
GLfloat s;

void *currentfont;
void slide(GLint maxx,GLint maxy,GLfloat x0,GLfloat y0);
void drawstring(float x,float y,float z,char *string);
void setFont(void *font);
void draw();
void computer();
void text(void);
void delay();
void delay1();
void frame();
void title();
void timer1();
void ttime();
void saw();
void gbn();
void window(GLfloat x2,GLfloat y2,GLfloat z);
void saw_1(GLint l,GLint i,GLint j);
void saw_2(GLint l,GLint i, GLint j);
void saw_3(GLint l,GLint i, GLint j);
void gbn_1(GLint l,GLint i, GLint j,GLfloat x2,GLfloat y2);
void gbn_2(GLint l,GLint i, GLint j,GLfloat x2,GLfloat y2);
void gbn_3(GLint l,GLint i, GLint j,GLfloat x2,GLfloat y2);
void sw_1(GLint l,GLint i, GLint j,GLfloat x2,GLfloat y2);
void sw_2(GLint l,GLint i, GLint j,GLfloat x2,GLfloat y2);
void sw_3(GLint l,GLint i, GLint j,GLfloat x2,GLfloat y2);
void move_gbn_packet1a(GLint l,GLfloat x1,GLfloat y1,GLint i,GLint j);
void  move_packet1a(GLint l,GLfloat x1,GLfloat y1,GLint i,GLint j,GLfloat x2,GLfloat y2);
void  move_packet1b(GLint l,GLfloat x1,GLfloat y1,GLint i,GLint j,GLint k,GLfloat x2,GLfloat y2);
void  move_packet1b_err(GLint l,GLfloat x1,GLfloat y1,GLint i,GLint j,GLint k,GLfloat x2,GLfloat y2);
void choice(GLint i,GLint j);
void choice1(GLint l);
void choice2(void);
void  move_packet1c(GLint l,GLfloat x1,GLfloat y1,GLint i,GLint j,GLfloat x2,GLfloat y2);
void  move_packet1d(GLint l,GLfloat x1,GLfloat y1,GLint i,GLint j,GLfloat x2,GLfloat y2);
void  move_packet1e(GLint l,GLfloat x1,GLfloat y1,GLint i,GLint j,GLint k,GLfloat x2,GLfloat y2);
void  move_packet1e_err(GLint l,GLfloat x1,GLfloat y1,GLint i,GLint j,GLint k,GLfloat x2,GLfloat y2);
void  move_packet1f(GLint l,GLfloat x1,GLfloat y1,GLint i,GLint j,GLfloat x2,GLfloat y2);
void resize(int w,int h);

void resize(int w,int h)
{
    glViewport(1000,1000,w,h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    if(w<=h)
        glOrtho(0,500,0*(GLfloat)(h/w),500*(GLfloat)(h/w),0,500);
    else
        glOrtho(0*(GLfloat)(w/h),500*(GLfloat)(w/h),0,500,0,500);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void drawstring(float x,float y,float z,char *string)
{
	    char *c;
	glRasterPos3f(x,y,z);

	for(c=string;*c!='\0';c++)
	{	glColor3f(0.0,0.0,0.0);
		glutBitmapCharacter(currentfont,*c);
	}
}

void setFont(void *font)
{
	currentfont=font;
}


void title()												// to draw the starting screen
{

	setFont(GLUT_BITMAP_TIMES_ROMAN_24);


	glColor3f(1.0,1.0,1.0);
	drawstring(20.0,435.0,1.0,"*  * G R A P H I C A L   I L L U S T R A T I O N   OF   A U T O M A T I C   R E Q U E S T    ");

	glColor3f(1.0,1.0,1.0);
	drawstring(200.0,410.0,1.0," P R O T O C O L S *  *");

	glColor3f(1.0,1.0,1.0);
	drawstring(220.0,320.0,1.0,"SUBMITTED   BY");

	glColor3f(0.0,1.0,1.0);
	drawstring(180.0,280.0,1.0," Rajil Paloth");

	glColor3f(0.0,1.0,1.0);
	drawstring(180.0,255.0,1.0," Shawn Rahul D'Souza");

	glColor3f(0.0,1.0,1.0);
	drawstring(180.0,100.0,1.0,"  St. Joseph Engineering College");
    glFlush();

glutSwapBuffers();

}




void text(void)											// to draw the text in menu screen
{
	setFont(GLUT_BITMAP_HELVETICA_18);
	glColor3f(1.0,1.0,1.0);
	drawstring(75.0,455.0,1.0,"*  *  *  *  *  *  *  *    A U T O M A T I C   R E P E A T   R E Q U E S T  ( A R Q )   *  *  *  *  *  *  *  *");

	glColor3f(1.0,1.0,1.0);
	drawstring(210.0,405.0,1.0,"INTRODUCTION");

	glColor3f(1.0,1.0,1.0);
	drawstring(205.0,350.0,1.0," STOP AND WAIT ");

	glColor3f(1.0,1.0,1.0);
	drawstring(210.0,295.0,1.0,"GO BACK - N");

	glColor3f(1.0,1.0,1.0);
	drawstring(200.0,240.0,1.0,"SELECTIVE  REPEAT");

	glColor3f(1.0,1.0,1.0);
	drawstring(225.0,185.0,1.0," QUIT");

	//glColor3f(1.0,1.0,1.0);
	//drawstring(225.0,130.0,1.0,"  EXIT");
	glFlush();
glutSwapBuffers();
}

void draw() // TO DRAW POLYGON FOR DISPLAY MENUS
{

	glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_POLYGON);  // introduction
	glColor3f(0.7f,0.2f,0.2f);
    glVertex2i(305,425);
	glVertex2i(180,425);
	glVertex2i(180,395);
    glVertex2i(305,395);
	glEnd();
	glFlush();

	glBegin(GL_POLYGON);  // stop and wait
	glColor3f(0.7f,0.2f,0.2f);
    glVertex2i(305,370);
	glVertex2i(180,370);
	glVertex2i(180,340);
    glVertex2i(305,340);
	glEnd();
	glFlush();

	glBegin(GL_POLYGON);  // go back n
	glColor3f(0.7f,0.2f,0.2f);
    glVertex2i(305,315);
	glVertex2i(180,315);
	glVertex2i(180,285);
    glVertex2i(305,285);
	glEnd();
	glFlush();

	glBegin(GL_POLYGON);  // sliding window
	glColor3f(0.7f,0.2f,0.2f);
    glVertex2i(305,260);
	glVertex2i(180,260);
	glVertex2i(180,230);
    glVertex2i(305,230);
	glEnd();
	glFlush();

	glBegin(GL_POLYGON);  // exit
	glColor3f(0.7f,0.2f,0.2f);
    glVertex2i(305,205);
	glVertex2i(180,205);
	glVertex2i(180,175);
    glVertex2i(305,175);
	glEnd();
	glFlush();

text();
}
void intro()
{

    glClear(GL_COLOR_BUFFER_BIT);

    setFont(GLUT_BITMAP_TIMES_ROMAN_24);
	glColor3f(1.0,1.0,1.0);
	drawstring(75.0,455.0,1.0,"*  *  *  *  *  *  *  *    I N T R O D U C T I O N    *  *  *  *  *  *  *  *");

	setFont(GLUT_BITMAP_HELVETICA_18 );
	glColor3f(1.0,0.0,0.0);
	drawstring(75.0,355.0,1.0,"S T O P    A N D   W A I T");

	setFont(GLUT_BITMAP_HELVETICA_18 );
	glColor3f(0.0,0.7,0.3);
	drawstring(75.0,255.0,1.0,"G O   B A C K  -  N");

	setFont(GLUT_BITMAP_HELVETICA_18 );
	glColor3f(1.0,0.6,0.3);
	drawstring(75.0,155.0,1.0,"S L I D I N G   W I N D O W");

	setFont(GLUT_BITMAP_HELVETICA_12);
	glColor3f(1.0,1.0,1.0);
	drawstring(25.0,435,1.0,"The Automatic Repeat Request (ARQ) protocol is the process of sending and receiving data packets from a sender to a receiver.In this way, there are ");

	setFont(GLUT_BITMAP_HELVETICA_12);
	glColor3f(1.0,1.0,1.0);
	drawstring(25.0,425.0,1.0,"three major ways of transmitting these data:");

	setFont(GLUT_BITMAP_HELVETICA_12);
	glColor3f(1.0,1.0,1.0);
	drawstring(75.0,405.0,1.0,"1. Stop and wait ARQ");

	setFont(GLUT_BITMAP_HELVETICA_12);
	glColor3f(1.0,1.0,1.0);
	drawstring(75.0,395.0,1.0,"2. Go Back N ARQ");

	setFont(GLUT_BITMAP_HELVETICA_12);
	glColor3f(1.0,1.0,1.0);
	drawstring(75.0,385.0,1.0,"3. Selective Repeat ARQ");

	setFont(GLUT_BITMAP_HELVETICA_12);
	glColor3f(1.0,1.0,1.0);
	drawstring(25.0,335.0,1.0,"The Stop and wait ARQ is the simplest way of sending packets. In this way, a packet is individually sent. An acknowledgement is sent after every");

    setFont(GLUT_BITMAP_HELVETICA_12);
	glColor3f(1.0,1.0,1.0);
	drawstring(25.0,325.0,1.0,"packet has been successfully received by the receiver.");

     setFont(GLUT_BITMAP_HELVETICA_12);
	glColor3f(1.0,1.0,1.0);
	drawstring(25.0,305.0,1.0,"Although it is easy to implement, Stop and wait ARQ is slow and difficult to maintain.");

	 setFont(GLUT_BITMAP_HELVETICA_12);
	glColor3f(1.0,1.0,1.0);
	drawstring(25.0,235.0,1.0,"The Go Back N ARQ aims to reduce the number of sent packets by enclosing them in a special window at the sender.");

    setFont(GLUT_BITMAP_HELVETICA_12);
	glColor3f(1.0,1.0,1.0);
	drawstring(25.0,225.0,1.0,"Depending on the size of the packet, the size of the window can vary.");

    setFont(GLUT_BITMAP_HELVETICA_12);
	glColor3f(1.0,1.0,1.0);
	drawstring(25.0,205.0,1.0,"However, this implies that the receiver will only receive packets one at a time and sends an acknowledgement as such.");

    setFont(GLUT_BITMAP_HELVETICA_12);
	glColor3f(1.0,1.0,1.0);
	drawstring(25.0,135.0,1.0,"The Selective Repeat protocol has windows at both the sender and receiver. In this way, it is much more stable and can send a number of packets");

     setFont(GLUT_BITMAP_HELVETICA_12);
	glColor3f(1.0,1.0,1.0);
	drawstring(25.0,125.0,1.0,"efficiently.");

	setFont(GLUT_BITMAP_HELVETICA_12);
	glColor3f(1.0,1.0,1.0);
	drawstring(25.0,105.0,1.0,"By applying the concept of a sliding window, more resources will be conserved as it has to focus on a few selected packets at a time.");


    glutSwapBuffers();
     choice2();

}

void delay()  //the delay between each packet's next step
{ int i,j;
   j=1500;
	while(j!=0)
	{
		j--;
		i=20000;
        while(i!=0)
		{
			i--;
		}
	}

}


void delay1()  // A longer delay time. used to indicate error
{ int i,j;
   j=20000;
	while(j!=0)
	{
		j--;
		i=28000;
		while(i!=0)
		{
			i--;
		}
	}

}

void computer()									// to draw the sender and receiver computers
{
	glClear(GL_COLOR_BUFFER_BIT);
glColor3f(1.0f,1.0f,1.0f);
setFont(GLUT_BITMAP_HELVETICA_12);
drawstring(105.0,450.0,1.0,"SENDER");

glColor3f(1.0f,1.0f,1.0f);
drawstring(350.0,450.0,1.0,"RECEIVER");

	glColor3f(0.7,0.2,0.0);//monitor
	glBegin(GL_LINE_LOOP);
	glVertex2f(85,380);
	glVertex2f(85,440);
	glVertex2f(150,440);
	glVertex2f(150,380);
	glEnd();
	glFlush();


	glColor3f(0.7,0.2,0.0);//monitor
	glBegin(GL_LINE_LOOP);
	glVertex2f(87,382);
	glVertex2f(87,438);
	glVertex2f(148,438);
	glVertex2f(148,382);
	glEnd();
	glFlush();

	glColor3f(0.7,0.0,0.2);//vertical stand
	glBegin(GL_LINES);
	glVertex2f(105,380);
	glVertex2f(105,375);
	glVertex2f(129,380);
	glVertex2f(129,375);
	glEnd();
	glFlush();

	glColor3f(0.7,0.3,0.2); //horizontal stand
	glBegin(GL_QUADS);
	glVertex2f(98,370);
	glVertex2f(98,375);
	glVertex2f(138,375);
	glVertex2f(138,370);
	glEnd();
	glFlush();


	glColor3f(0.7,0.2,0.2);  //CPU
	glBegin(GL_LINE_LOOP);
	glVertex2f(80,350);
	glVertex2f(80,370);
	glVertex2f(155,370);
	glVertex2f(155,350);
	glEnd();
	glFlush();


	glColor3f(0.7,0.8,0.2);  //CPU
	glBegin(GL_QUADS);
	glVertex2f(95,360);
	glVertex2f(95,365);
	glVertex2f(115,365);
	glVertex2f(115,360);
	glEnd();
	glFlush();



	glColor3f(0.7,0.2,0.8);  //CPU
	glBegin(GL_QUADS);
	glVertex2f(132,358);
	glVertex2f(132,361);
	glVertex2f(140,361);
	glVertex2f(140,358);
	glEnd();
	glFlush();


	glColor3f(0.7,0.2,0.2);//keyboard outline
	glBegin(GL_LINE_LOOP);
	glVertex2f(77,325);
	glVertex2f(87,350);
	glVertex2f(148,350);
	glVertex2f(158,325);
	glEnd();
	glFlush();


	glColor3f(0.7,0.2,0.2);//keyboard outline
	glBegin(GL_POLYGON);
	glVertex2f(77,325);
	glVertex2f(158,325);
	glVertex2f(158,322);
	glVertex2f(77,322);
	glEnd();
	glFlush();


	glColor3f(0.7,0.0,0.2); //horizontal lines of keyboard
	glBegin(GL_LINES);
	glVertex2f(85,345);
	glVertex2f(150,345);
	glVertex2f(83,340);
	glVertex2f(152,340);
	glVertex2f(81,335);
	glVertex2f(154,335);
	glVertex2f(79,330);
	glVertex2f(156,330);
	glVertex2f(77,325);
	glVertex2f(158,325);
	glEnd();
	glFlush();



    glColor3f(0.7,0.0,0.2); //vertical lines of keyboard
	glBegin(GL_LINES);
	glVertex2f(89,322);
	glVertex2f(97,350);
	glVertex2f(103,322);
	glVertex2f(107,350);
	glVertex2f(117,322);
	glVertex2f(117,350);
	glVertex2f(131,322);
	glVertex2f(127,350);
	glVertex2f(145,322);
	glVertex2f(137,350);
	glEnd();
	glFlush();

	// COMPUTER AT RECEIVER

	glColor3f(0.7,0.2,0.0);//monitior
	glBegin(GL_LINE_LOOP);
	glVertex2f(335,380);
	glVertex2f(335,440);
	glVertex2f(400,440);
	glVertex2f(400,380);
	glEnd();
	glFlush();


	glColor3f(0.7,0.2,0.0);//monitior
	glBegin(GL_LINE_LOOP);
	glVertex2f(337,382);
	glVertex2f(337,438);
	glVertex2f(398,438);
	glVertex2f(398,382);
	glEnd();
	glFlush();


	glColor3f(0.7,0.0,0.2);//ver
	glBegin(GL_LINES);
	glVertex2f(355,380);
	glVertex2f(355,375);
	glVertex2f(379,380);
	glVertex2f(379,375);
	glEnd();
	glFlush();

	glColor3f(0.7,0.3,0.2);//hor
	glBegin(GL_QUADS);
	glVertex2f(348,370);
	glVertex2f(348,375);
	glVertex2f(388,375);
	glVertex2f(388,370);
	glEnd();
	glFlush();


	glColor3f(0.7,0.2,0.2);//CPU
	glBegin(GL_LINE_LOOP);
	glVertex2f(330,350);
	glVertex2f(330,370);
	glVertex2f(405,370);
	glVertex2f(405,350);
	glEnd();
	glFlush();


	glColor3f(0.7,0.8,0.2);  //CPU
	glBegin(GL_QUADS);
	glVertex2f(345,360);
	glVertex2f(345,365);
	glVertex2f(365,365);
	glVertex2f(365,360);
	glEnd();
	glFlush();



	glColor3f(0.7,0.2,0.8);  //CPU
	glBegin(GL_QUADS);
	glVertex2f(382,358);
	glVertex2f(382,361);
	glVertex2f(390,361);
	glVertex2f(390,358);
	glEnd();
	glFlush();

	glColor3f(0.7,0.2,0.2);//keyboard
	glBegin(GL_LINE_LOOP);
	glVertex2f(327,322);
	glVertex2f(337,350);
	glVertex2f(398,350);
	glVertex2f(408,322);
	glEnd();
	glFlush();

	glColor3f(0.7,0.2,0.2);//keyboard
	glBegin(GL_POLYGON);
	glVertex2f(327,325);
	glVertex2f(408,325);
	glVertex2f(408,322);
	glVertex2f(327,322);
	glEnd();
	glFlush();



	glColor3f(0.7,0.0,0.2); //horizontal lines of keyboard
	glBegin(GL_LINES);
	glVertex2f(335,345);
	glVertex2f(400,345);
	glVertex2f(333,340);
	glVertex2f(402,340);
	glVertex2f(331,335);
	glVertex2f(404,335);
	glVertex2f(329,330);
	glVertex2f(406,330);
	glVertex2f(327,325);
	glVertex2f(408,325);
	glEnd();
	glFlush();



    glColor3f(0.7,0.0,0.2); //vertical lines of keyboard
	glBegin(GL_LINES);
	glVertex2f(339,322);
	glVertex2f(347,350);
	glVertex2f(353,322);
	glVertex2f(357,350);
	glVertex2f(367,322);
	glVertex2f(367,350);
	glVertex2f(381,322);
	glVertex2f(377,350);
	glVertex2f(395,322);
	glVertex2f(387,350);
	glEnd();
	glFlush();



	glColor3f(0.3,0.6,0.8);//connectin wire
	glBegin(GL_LINES);
	glVertex2f(155,360);
	glVertex2f(330,360);
	glEnd();
	glFlush();


	glColor3f(1.0,1.0,1.0);
	glBegin(GL_POLYGON);
	glVertex2f(410,425);
	glVertex2f(410,430);
	glVertex2f(425,430);
	glVertex2f(425,425);
	glEnd();
	glFlush();

setFont(GLUT_BITMAP_HELVETICA_12);
glColor3f(1.0,1.0,1.0);
drawstring(432.0,425.5,1.0,"DATA FRAMES");
glFlush();

	glColor3f(0.0,1.0,1.0);
	glBegin(GL_POLYGON);
	glVertex2f(410,410);
	glVertex2f(410,415);
	glVertex2f(420,415);
	glVertex2f(420,410);
	glEnd();
	glFlush();

glColor3f(1.0,1.0,1.0);
drawstring(432.0,410.5,1.0,"ACK ");
glFlush();

	glColor3f(1.0,1.0,0.0);
	glBegin(GL_POLYGON);
	glVertex2f(410,395);
	glVertex2f(410,400);
	glVertex2f(420,400);
	glVertex2f(420,395);
		glEnd();
	glColor3f(1.0,1.0,1.0);
drawstring(432.0,395.5,1.0,"NAK");
glVertex2f(432.0,375.5);

glColor3f(1.0f,1.0f,1.0f);
setFont(GLUT_BITMAP_HELVETICA_18);
drawstring(102.0,405.0,1.0,"HELLO");

glFlush();
frame();
}

void slide(GLint maxx,GLint maxy,GLfloat x0,GLfloat y0) // TO DRAW WINDOWS (Rectangular Mesh)
{ int i,j;
	for(i=0;i<maxx;i++)
		x[i]=x0+i*dx;

	for(j=0;j<maxy;j++)
		y[j]=y0+j*dy;

	for(i=0;i<maxx-1;i++)
		for(j=0;j<maxy-1;j++)
		{

	       glBegin(GL_LINE_LOOP);
		   glVertex2f(x[i],y[j]);
		   glVertex2f(x[i],y[j+1]);
		   glVertex2f(x[i+1],y[j+1]);
		   glVertex2f(x[i+1],y[j]);
		   glEnd();
		   glFlush();


		}
}

void frame()
{
	glColor3f(0.0,0.0,1.0);
	slide(8,2,50,250);
	slide(8,2,300,220);
	slide(8,2,50,120);
	glFlush();

// frame number for frame 1

	glColor3f(1.0,1.0,1.0);
	drawstring(60,260.0,0.0,"1");
	glColor3f(1.0,1.0,1.0);
	drawstring(87,260.0,0.0,"2");
	glColor3f(1.0,1.0,1.0);
	drawstring(112,260.0,0.0,"3");
	glColor3f(1.0,1.0,1.0);
	drawstring(137,260.0,0.0,"4");
	glColor3f(1.0,1.0,1.0);
	drawstring(162,260.0,0.0,"5");
	glColor3f(1.0,1.0,1.0);
	drawstring(187,260.0,0.0,"6");
	glColor3f(1.0,1.0,1.0);
	drawstring(210,260.0,0.0,"7");
	glEnd();
	glFlush();





	// frame number for frame 2

	glColor3f(1.0,1.0,1.0);
	drawstring(310,230.0,0.0,"1");
	glColor3f(1.0,1.0,1.0);
	drawstring(337,230.0,0.0,"2");
	glColor3f(1.0,1.0,1.0);
	drawstring(362,230.0,0.0,"3");
	glColor3f(1.0,1.0,1.0);
	drawstring(387,230.0,0.0,"4");
	glColor3f(1.0,1.0,1.0);
	drawstring(411,230.0,0.0,"5");
	glColor3f(1.0,1.0,1.0);
	drawstring(436,230.0,0.0,"6");
	glColor3f(1.0,1.0,1.0);
	drawstring(461,230.0,0.0,"7");
	glEnd();
	glFlush();



	// frame number for frame 3

	glColor3f(1.0,1.0,1.0);
	drawstring(60,130.0,0.0,"1");
	glColor3f(1.0,1.0,1.0);
	drawstring(87,130.0,0.0,"2");
	glColor3f(1.0,1.0,1.0);
	drawstring(112,130.0,0.0,"3");
	glColor3f(1.0,1.0,1.0);
	drawstring(137,130.0,0.0,"4");
	glColor3f(1.0,1.0,1.0);
	drawstring(162,130.0,0.0,"5");
	glColor3f(1.0,1.0,1.0);
	drawstring(187,130.0,0.0,"6");
	glColor3f(1.0,1.0,1.0);
	drawstring(210,130.0,0.0,"7");
	glEnd();
	glFlush();
	}





void display(void)
{
glutSwapBuffers();
	glClear(GL_COLOR_BUFFER_BIT);
title();
delay1();
draw();
}

void design(GLint l,GLint i, GLint j,GLfloat x2, GLfloat y2)
{
    GLint p=275,q=245;
    computer();
    timer1();
    choice1(l);
    choice(i,j);
    if (l==2|l==3)
        {if(x2==175)
            window(x2,p,25);
         else if (x2==200)
            window(x2,p,50);
         else
            window(x2,p,0);
        }
    if(l==3)
    {if(y2==425)
            window(y2,q,25);
         else if (y2==450)
            window(y2,q,50);
         else
            window(y2,q,0);
}
}

void timer1()
{   r+=0.5;

    setFont(GLUT_BITMAP_HELVETICA_12);
    glColor3f(0.7,0.4,0.3);
	drawstring(30,55.0,0.0,"TIMER");

    glColor3f(1.0,1.0,1.0);
	glBegin(GL_POLYGON);
	glVertex2f(60,60);
	glVertex2f(60+r,60);
	glVertex2f(60+r,55);
	glVertex2f(60,55);
	glEnd();
	glFlush();

}

void ttime()
{

   glColor3f(1.0f,1.0f,1.0f);
   setFont(GLUT_BITMAP_HELVETICA_18);
    drawstring(352.0,405.0,1.0,"HELLO");
    glutSwapBuffers();
    delay1();
    glutSwapBuffers();
    int n=(int)r;
    glColor3f(1.0f,1.0f,1.0f);
	setFont(GLUT_BITMAP_HELVETICA_18);
	drawstring(340,135,0,"THE TOTAL TIME IS");

	printf("%d",n);
	glColor3f(1.0f,1.0f,1.0f);
	setFont(GLUT_BITMAP_HELVETICA_18);
    if (n==258)
    drawstring(340,120,0,"258 units");
    if (n==340)
    drawstring(340,120,0,"340 units");
    if (n==288)
    drawstring(340,120,0,"288 units");
    glutSwapBuffers();
    delay1();
}

void saw()          //Stop and Wait ARQ
{
    r=0.0;
     saw_1(1,0,1);     // Packet 1
      saw_2(1,25,2);     // Packet 2
     saw_1(1,50,3);      // Packet 3
      saw_1(1,75,4);       // Packet 4
        saw_3(1,100,5);      // Packet 5
      saw_1(1,125,6);      // Packet 6
     saw_1(1,150,7);      // Packet 7
     ttime();
choice2();

}

void gbn()
{
    r=0.0;
    gbn_1(2,0,1,50.0,0.0);
     gbn_2(2,25,2,75.0,0.0);
   gbn_1(2,50,3,100.0,0.0);
    gbn_1(2,75,4,125.0,0.0);
    gbn_3(2,100,5,150.0,0.0);
    gbn_1(2,125,6,175.0,0.0);
    gbn_1(2,150,7,200.0,0.0);

     ttime();
    choice2();

}
void sw()
{
    r=0.0;
    sw_1(3,0,1,50.0,300.0);
    sw_2(3,25,2,75.0,325.0);
    sw_3(3,100,5,150.0,400.0);

     ttime();
    choice2();
}
void saw_1(GLint l,GLint i, GLint j)        // perfect sending and receiving
{


    move_packet1a(l,60+i,230,j,1,0,0); // Vertical (down) movement to send from frame 1 (a)

    move_packet1b(l,80+i,165,j,2,i,0,0);// Horizontal movement from frame 1 to mid  (b)

     move_packet1c(l,310+i,170,j,3,0,0);// Vertical (up) movement to receive in frame 2 from mid  (c)

    delay1();

    move_packet1d(l,310+i,140,j,4,0,0);// Vertical (down) movement to send from frame 2  (d)

    move_packet1e(l,310+i,75,j,5,i,0,0); // Horizontal movement from receiver frame 1 to mid (e)

    move_packet1f(l,60+i,75,j,6,0,0); // Horizontal movement from receiver frame 1 to mid (f)

    delay1();
}

void saw_2(GLint l,GLint i, GLint j)
{


    move_packet1a(l,60+i,230,j,1,0,0); // Vertical (down) movement to send from frame 2 (a)

    move_packet1b_err(l,100+i,165,j,2,i,0,0);// Horizontal error movement from frame 2 to mid  (b)
    delay1();
    r+=5;
    move_packet1a(l,60+i,230,j,3,0,0); // Vertical (down) movement to resend from frame 3 (a)

    move_packet1b(l,100+i,165,j,4,i,0,0);// Horizontal movement from frame 3 to mid  (b)

    move_packet1c(l,310+i,170,j,5,0,0);      // Vertical (up) movement to receive in frame 3 from mid  (c)

    delay1();

    move_packet1d(l,310+i,140,j,6,0,0);      // Vertical (down) movement to send from frame 3  (d)

    move_packet1e(l,275+i,75,j,7,i,0,0);       // Horizontal movement from receiver frame 3 to mid (e)

    move_packet1f(l,60+i,75,j,8,0,0);         // Horizontal movement from receiver frame 3 to mid (f)
    delay1();
}

void saw_3(GLint l,GLint i, GLint j)
{


     move_packet1a(l,60+i,230,j,1,0,0); // Vertical (down) movement to resend from frame 3 (a)

    move_packet1b(l,80+i,165,j,2,i,0,0);// Horizontal movement from frame 3 to mid  (b)

    move_packet1c(l,310+i,170,j,3,0,0);      // Vertical (up) movement to receive in frame 3 from mid  (c)

    delay1();

    move_packet1d(l,310+i,140,j,4,0,0);      // Vertical (down) movement to send from frame 3  (d)

    move_packet1e_err(l,310+i,75,j,5,i,0,0);       // Horizontal error movement from receiver frame 3 to mid (e)
    delay1();
    r+=5;

     move_packet1a(l,60+i,230,j,6,0,0); // Vertical (down) movement to resend from frame 3 (a)

    move_packet1b(l,80+i,165,j,7,i,0,0);// Horizontal movement from frame 3 to mid  (b)

    move_packet1c(l,310+i,180,j,8,0,0);      // Vertical (up) movement to receive in frame 3 from mid  (c)
    delay1();

    move_packet1d(l,310+i,140,j,9,0,0);      // Vertical (down) movement to send from frame 3  (d)

    move_packet1e(l,310+i,75,j,10,i,0,0);

    move_packet1f(l,60+i,75,j,11,0,0);         // Horizontal movement from receiver frame 3 to mid (f)
    delay1();
}

void gbn_1(GLint l,GLint i, GLint j,GLfloat x2,GLfloat y2)
{
      move_packet1a(l,60+i,230,j,1,x2,y2); // Vertical (down) movement to send from frame 1 (a)

    move_packet1b(l,80+i,165,j,2,i,x2,y2);// Horizontal movement from frame 1 to mid  (b)

   move_packet1c(l,310+i,170,j,3,x2,y2);// Vertical (up) movement to receive in frame 2 from mid  (c)

     delay1();

   move_packet1d(l,310+i,140,j,4,x2,y2);// Vertical (down) movement to send from frame 2  (d)

    move_packet1e(l,310+i,75,j,5,i,x2,y2); // Horizontal movement from receiver frame 1 to mid (e)

    move_packet1f(l,60+i,75,j,6,x2,y2); // Horizontal movement from receiver frame 1 to mid (f)

     delay1();
}

void gbn_2(GLint l,GLint i, GLint j,GLfloat x2,GLfloat y2)
{
     move_packet1a(l,60+i,230,j,1,x2,y2); // Vertical (down) movement to send from frame 1 (a)

   move_packet1b_err(l,100+i,165,j,2,i,x2,y2);// Horizontal error movement from frame 2 to mid  (b)
    delay1();
    r+=5;

    move_packet1a(l,60+i+25,230,j+1,1,x2,y2); // Vertical (down) movement to resend from frame 3 (a)

    move_packet1b(l,100+i+25,165,j+1,2,i,x2,y2);// Horizontal movement from frame 3 to mid  (b)

    move_packet1a(l,60+i+50,230,j+2,1,x2,y2); // Vertical (down) movement to resend from frame 3 (a)


    move_packet1b(l,100+i+50,165,j+2,2,i,x2,y2);// Horizontal movement from frame 3 to mid  (b)

    // Resend

    move_packet1d(l,310+i,140,j,12,x2,y2);// Vertical (down) movement to send from frame 2  (d) NAK

    move_packet1e(l,310+i,75,j,12,i,x2,y2); // Horizontal movement from receiver frame 1 to mid (e)  NAK

    move_packet1f(l,60+i,75,j,12,x2,y2); // Horizontal movement from receiver frame 1 to mid (f)     NAK

     delay1();

    move_packet1a(l,60+i,230,j,3,x2,y2); // Vertical (down) movement to send from frame 1 (a)

    move_packet1b(l,80+i,165,j,4,i,x2,y2);// Horizontal movement from frame 1 to mid  (b)

   move_packet1c(l,310+i,170,j,5,x2,y2);// Vertical (up) movement to receive in frame 2 from mid  (c)

     delay1();

   move_packet1d(l,310+i,140,j,6,x2,y2);// Vertical (down) movement to send from frame 2  (d)

    move_packet1e(l,310+i,75,j,7,i,x2,y2); // Horizontal movement from receiver frame 1 to mid (e)

    move_packet1f(l,60+i,75,j,8,x2,y2); // Horizontal movement from receiver frame 1 to mid (f)

     delay1();
}

void gbn_3(GLint l,GLint i, GLint j,GLfloat x2,GLfloat y2)
{
 move_packet1a(l,60+i,230,j,1,x2,y2); // Vertical (down) movement to send from frame 1 (a)

    move_packet1b(l,80+i,165,j,2,i,x2,y2);// Horizontal movement from frame 1 to mid  (b)

   move_packet1c(l,310+i,170,j,3,x2,y2);// Vertical (up) movement to receive in frame 2 from mid  (c)

     delay1();

   move_packet1d(l,310+i,140,j,4,x2,y2);// Vertical (down) movement to send from frame 2  (d)

    move_packet1e_err(l,310+i,75,j,5,i,x2,y2); // Horizontal movement from receiver frame 1 to mid (e)

   delay1();
   r+=5;


    move_packet1a(l,60+i+25,230,j+1,1,x2,y2); // Vertical (down) movement to resend from frame 3 (a)

    move_packet1b(l,100+i+25,165,j+1,2,i,x2,y2);// Horizontal movement from frame 3 to mid  (b)

    move_packet1a(l,60+i+50,230,j+2,1,x2,y2); // Vertical (down) movement to resend from frame 3 (a)

    move_packet1b(l,100+i+50,165,j+2,2,i,x2,y2);// Horizontal movement from frame 3 to mid  (b)

    //resend

    move_packet1d(l,310+i,140,j,12,x2,y2);// Vertical (down) movement to send from frame 2  (d) NAK

    move_packet1e(l,310+i,75,j,12,i,x2,y2); // Horizontal movement from receiver frame 1 to mid (e)  NAK

    move_packet1f(l,60+i,75,j,12,x2,y2); // Horizontal movement from receiver frame 1 to mid (f)     NAK

     delay1();

     move_packet1a(l,60+i,230,j,6,x2,y2); // Vertical (down) movement to send from frame 1 (a)

    move_packet1b(l,80+i,165,j,7,i,x2,y2);// Horizontal movement from frame 1 to mid  (b)

   move_packet1c(l,310+i,170,j,8,x2,y2);// Vertical (up) movement to receive in frame 2 from mid  (c)

      delay1();

   move_packet1d(l,310+i,140,j,9,x2,y2);// Vertical (down) movement to send from frame 2  (d)

    move_packet1e(l,310+i,75,j,10,i,x2,y2); // Horizontal movement from receiver frame 1 to mid (e)

    move_packet1f(l,60+i,75,j,11,x2,y2); // Horizontal movement from receiver frame 1 to mid (f)



}


void sw_1(GLint l,GLint i, GLint j,GLfloat x2,GLfloat y2)
{
      move_packet1a(l,60+i,230,j,1,x2,y2); // Vertical (down) movement to send from frame 1 (a)

    move_packet1b(l,80+i,165,j,2,i,x2,y2);// Horizontal movement from frame 1 to mid  (b)

   move_packet1c(l,310+i,170,j,3,x2,y2);// Vertical (up) movement to receive in frame 2 from mid  (c)

   delay1();

   move_packet1d(l,310+i,140,j,4,x2,y2);// Vertical (down) movement to send from frame 2  (d)

    move_packet1e(l,310+i,75,j,5,i,x2,y2); // Horizontal movement from receiver frame 1 to mid (e)

    move_packet1f(l,60+i,75,j,6,x2,y2); // Horizontal movement from receiver frame 1 to mid (f)

   delay1();
}

void sw_2(GLint l,GLint i, GLint j,GLfloat x2,GLfloat y2)
{
     move_packet1a(l,60+i,230,j,1,x2,y2); // Vertical (down) movement to send from frame 1 (a)

   move_packet1b_err(l,100+i,165,j,2,i,x2,y2);// Horizontal error movement from frame 2 to mid  (b)
    delay1();
    r+=5;

    // sending the i+1 packet
    move_packet1a(l,60+i+25,230,j+1,1,x2,y2); // Vertical (down) movement to resend from frame 3 (a)

    move_packet1b(l,100+i+25,165,j+1,2,i,x2,y2);// Horizontal movement from frame 3 to mid  (b)

    move_packet1c(l,310+i+25,170,j+1,3,x2,y2);// Vertical (up) movement to receive in frame 2 from mid  (c)

   delay1();

   move_packet1d(l,310+i+25,140,j+1,4,x2,y2);// Vertical (down) movement to send from frame 2  (d)

    move_packet1e(l,310+i+25,75,j+1,5,i,x2,y2); // Horizontal movement from receiver frame 1 to mid (e)

    move_packet1f(l,60+i+25,75,j+1,6,x2,y2); // Horizontal movement from receiver frame 1 to mid (f)

   delay1();
     // sending the i+2 packet
    move_packet1a(l,60+i+50,230,j+2,1,x2,y2); // Vertical (down) movement to resend from frame 3 (a)

    move_packet1b(l,100+i+50,165,j+2,2,i,x2,y2);// Horizontal movement from frame 3 to mid  (b)

    move_packet1c(l,310+i+50,170,j+2,3,x2,y2);// Vertical (up) movement to receive in frame 2 from mid  (c)
   delay1();

   move_packet1d(l,310+i+50,140,j+2,4,x2,y2);// Vertical (down) movement to send from frame 2  (d)

    move_packet1e(l,310+i+50,75,j+2,5,i,x2,y2); // Horizontal movement from receiver frame 1 to mid (e)

    move_packet1f(l,60+i+50,75,j+2,6,x2,y2); // Horizontal movement from receiver frame 1 to mid (f)
   delay1();
    // resending lost packet

    move_packet1d(l,310+i,140,j,12,x2,y2);// Vertical (down) movement to send from frame 2  (d) NAK

    move_packet1e(l,310+i,75,j,12,i,x2,y2); // Horizontal movement from receiver frame 1 to mid (e)  NAK

    move_packet1f(l,60+i,75,j,12,x2,y2); // Horizontal movement from receiver frame 1 to mid (f)     NAK
		delay1();

    move_packet1a(l,60+i,230,j,3,x2,y2); // Vertical (down) movement to send from frame 1 (a)

    move_packet1b(l,80+i,165,j,4,i,x2,y2);// Horizontal movement from frame 1 to mid  (b)

   move_packet1c(l,310+i,170,j,5,x2,y2);// Vertical (up) movement to receive in frame 2 from mid  (c)
delay1();

   move_packet1d(l,310+i,140,j,6,x2,y2);// Vertical (down) movement to send from frame 2  (d)

    move_packet1e(l,310+i,75,j,7,i,x2,y2); // Horizontal movement from receiver frame 1 to mid (e)

    move_packet1f(l,60+i,75,j,8,x2,y2); // Horizontal movement from receiver frame 1 to mid (f)
    delay1();

}

void sw_3(GLint l,GLint i, GLint j,GLfloat x2,GLfloat y2)
{
 move_packet1a(l,60+i,230,j,1,x2,y2); // Vertical (down) movement to send from frame 1 (a)

    move_packet1b(l,80+i,165,j,2,i,x2,y2);// Horizontal movement from frame 1 to mid  (b)

   move_packet1c(l,310+i,170,j,3,x2,y2);// Vertical (up) movement to receive in frame 2 from mid  (c)
	delay1();

   move_packet1d(l,310+i,140,j,4,x2,y2);// Vertical (down) movement to send from frame 2  (d)

    move_packet1e_err(l,310+i,75,j,5,i,x2,y2); // Horizontal movement from receiver frame 1 to mid (e)

   delay1();
   r+=5;

       // sending the i+1 packet

    move_packet1a(l,60+i+25,230,j+1,1,x2,y2); // Vertical (down) movement to resend from frame 3 (a)

    move_packet1b(l,100+i+25,165,j+1,2,i,x2,y2);// Horizontal movement from frame 3 to mid  (b)

    move_packet1c(l,310+i+25,170,j+1,3,x2,y2);// Vertical (up) movement to receive in frame 2 from mid  (c)
	delay1();

   move_packet1d(l,310+i+25,140,j+1,4,x2,y2);// Vertical (down) movement to send from frame 2  (d)

    move_packet1e(l,310+i+25,75,j+1,5,i,x2,y2); // Horizontal movement from receiver frame 1 to mid (e)

    move_packet1f(l,60+i+25,75,j+1,6,x2,y2); // Horizontal movement from receiver frame 1 to mid (f)
	delay1();

     // sending the i+2 packet

    move_packet1a(l,60+i+50,230,j+2,1,x2,y2); // Vertical (down) movement to resend from frame 3 (a)

    move_packet1b(l,100+i+50,165,j+2,2,i,x2,y2);// Horizontal movement from frame 3 to mid  (b)

    move_packet1c(l,310+i+50,170,j+2,3,x2,y2);// Vertical (up) movement to receive in frame 2 from mid  (c)
	delay1();

   move_packet1d(l,310+i+50,140,j+2,4,x2,y2);// Vertical (down) movement to send from frame 2  (d)

    move_packet1e(l,310+i+50,75,j+2,5,i,x2,y2); // Horizontal movement from receiver frame 1 to mid (e)

    move_packet1f(l,60+i+50,75,j+2,6,x2,y2); // Horizontal movement from receiver frame 1 to mid (f)
	delay1();
    //resend


    move_packet1d(l,310+i,140,j,12,x2,y2);// Vertical (down) movement to send from frame 2  (d) NAK

    move_packet1e(l,310+i,75,j,12,i,x2,y2); // Horizontal movement from receiver frame 1 to mid (e)  NAK

    move_packet1f(l,60+i,75,j,12,x2,y2); // Horizontal movement from receiver frame 1 to mid (f)     NAK
	delay1();

     move_packet1a(l,60+i,230,j,6,x2,y2); // Vertical (down) movement to send from frame 1 (a)

    move_packet1b(l,80+i,165,j,7,i,x2,y2);// Horizontal movement from frame 1 to mid  (b)

   move_packet1c(l,310+i,170,j,8,x2,y2);// Vertical (up) movement to receive in frame 2 from mid  (c)
	delay1();

   move_packet1d(l,310+i,140,j,9,x2,y2);// Vertical (down) movement to send from frame 2  (d)

    move_packet1e(l,310+i,75,j,10,i,x2,y2); // Horizontal movement from receiver frame 1 to mid (e)

    move_packet1f(l,60+i,75,j,11,x2,y2); // Horizontal movement from receiver frame 1 to mid (f)
	delay1();


}

void  move_packet1a(GLint l,GLfloat x1,GLfloat y1,GLint i,GLint j,GLfloat x2,GLfloat y2)       // Vertical (down) movement to send from frame 1
{
    design(l,i,j,x2,y2);

	glColor3f(1.0,1.0,1.0);
	glBegin(GL_POLYGON);
	glVertex2f(x1,y1);
	glVertex2f(x1+5,y1);
	glVertex2f(x1+5,y1-25);
	glVertex2f(x1,y1-25);
	glEnd();
	glFlush();

    delay();


  glutSwapBuffers();
  if (y1>185)
        move_packet1a(l,x1,y1-10,i,j,x2,y2);

}

void  move_packet1b(GLint l,GLfloat x1,GLfloat y1,GLint i,GLint j,GLint k,GLfloat x2,GLfloat y2)       // Horizontal movement from frame 1 to mid
{
  design(l,i,j,x2,y2);

	glColor3f(1.0,1.0,1.0);
	glBegin(GL_POLYGON);
	glVertex2f(x1,y1);
	glVertex2f(x1-25,y1);
	glVertex2f(x1-25,y1-7);
	glVertex2f(x1,y1-7);
    glEnd();
	glFlush();
    delay();

  glutSwapBuffers();
  if ((x1)<310+k)
    move_packet1b(l,x1+10,y1,i,j,k,x2,y2);

}


void  move_packet1b_err(GLint l,GLfloat x1,GLfloat y1,GLint i,GLint j,GLint k,GLfloat x2,GLfloat y2)       // Error movement from sender frame to mid
{
  design(l,i,j,x2,y2);

	glColor3f(1.0,0.0,0.0);
	glBegin(GL_POLYGON);
	glVertex2f(x1,y1);
	glVertex2f(x1-25,y1);
	glVertex2f(x1-25,y1-7);
	glVertex2f(x1,y1-7);
    glEnd();
	glFlush();
    delay();

  glutSwapBuffers();
  if (x1<(150+k))
    move_packet1b_err(l,x1+10,y1,i,j,k,x2,y2);

}

void  move_packet1c(GLint l,GLfloat x1,GLfloat y1,GLint i,GLint j,GLfloat x2,GLfloat y2)       // Vertical (up) movement to receive in frame 2 from mid
{
     design(l,i,j,x2,y2);

	glColor3f(1.0,1.0,1.0);
	glBegin(GL_POLYGON);
	glVertex2f(x1,y1);
	glVertex2f(x1+5,y1);
	glVertex2f(x1+5,y1-25);
	glVertex2f(x1,y1-25);
	glEnd();
	glFlush();

 delay();

  glutSwapBuffers();
  if (y1<200)
    move_packet1c(l,x1,y1+10,i,j,x2,y2);


}


void  move_packet1d(GLint l,GLfloat x1,GLfloat y1,GLint i,GLint j ,GLfloat x2,GLfloat y2)       // Vertical (down) movement to send from frame 2
{
     design(l,i,j,x2,y2);

	glColor3f(0.0,1.0,1.0);
	if((l==2|l==3)&&j==12)
    glColor3f(1.0,1.0,0.0);
	glBegin(GL_POLYGON);
	glVertex2f(x1,y1);
	glVertex2f(x1+5,y1);
	glVertex2f(x1+5,y1-25);
	glVertex2f(x1,y1-25);
	glEnd();
	glFlush();

 delay();

  glutSwapBuffers();

  if (y1>95)
    move_packet1d(l,x1,y1-10,i,j,x2,y2);
}

void  move_packet1e(GLint l,GLfloat x1,GLfloat y1,GLint i,GLint j,GLint k,GLfloat x2,GLfloat y2)       // Horizontal movement from receiver frame 1 to mid
{
    design(l,i,j,x2,y2);

	glColor3f(0.0,1.0,1.0);
	if((l==2|l==3)&&j==12)
    glColor3f(1.0,1.0,0.0);
	glBegin(GL_POLYGON);
	glVertex2f(x1,y1);
	glVertex2f(x1-25,y1);
	glVertex2f(x1-25,y1-7);
	glVertex2f(x1,y1-7);
    glEnd();
	glFlush();
    delay();

  glutSwapBuffers();
  if (x1>(100+k))
    move_packet1e(l,x1-10,y1,i,j,k,x2,y2);


}

void  move_packet1e_err(GLint l,GLfloat x1,GLfloat y1,GLint i,GLint j,GLint k,GLfloat x2,GLfloat y2)       // Horizontal movement from receiver frame 1 to mid
{
    design(l,i,j,x2,y2);

    glColor3f(1.0,0.0,0.0);
	glBegin(GL_POLYGON);
	glVertex2f(x1,y1);
	glVertex2f(x1-25,y1);
	glVertex2f(x1-25,y1-7);
	glVertex2f(x1,y1-7);
    glEnd();
	glFlush();
    delay();

  glutSwapBuffers();
  if (x1>(300+k))
    move_packet1e_err(l,x1-10,y1,i,j,k,x2,y2);


}

void  move_packet1f(GLint l,GLfloat x1,GLfloat y1,GLint i,GLint j,GLfloat x2,GLfloat y2)       // Vertical (up) movement from acknowledgment to frame 1
{
    design(l,i,j,x2,y2);
	glColor3f(0.0,1.0,1.0);
	if((l==2|l==3)&&j==12)
    glColor3f(1.0,1.0,0.0);
	glBegin(GL_POLYGON);
	glVertex2f(x1,y1);
	glVertex2f(x1+5,y1);
	glVertex2f(x1+5,y1+25);
	glVertex2f(x1,y1+25);
	glEnd();
	glFlush();

 delay();

  glutSwapBuffers();

  if (y1<85)
    move_packet1f(l,x1,y1+10,i,j,x2,y2);

}


    void window(GLfloat x2,GLfloat y2,GLfloat z)
    {

    glColor3f(0.0,1.0,1.0); // window frame
	glBegin(GL_LINE_LOOP);
	glVertex2f(x2,y2+5);
	glVertex2f(x2+75-z,y2+5);
	glVertex2f(x2+75-z,y2-30);
	glVertex2f(x2,y2-30);
	glEnd();
	glFlush();

    }
void choice1(GLint l)
{
    switch(l)
    {
    case 1 :

    setFont(GLUT_BITMAP_TIMES_ROMAN_24);

	glColor3f(1.0,1.0,1.0);
	drawstring(157.0,460.0,1.0,"S T O P   A N D   W A I T   A R Q   ");
    break;

    case 2:

    setFont(GLUT_BITMAP_TIMES_ROMAN_24);

	glColor3f(1.0,1.0,1.0);
	drawstring(150.0,460.0,1.0,"G O  B A C K  -  N   A R Q  ");
	break;

	case 3:

    setFont(GLUT_BITMAP_TIMES_ROMAN_24);

	glColor3f(1.0,1.0,1.0);
	drawstring(140.0,460.0,1.0,"S E L E C T I V E   R E P E A T   A R Q   ");
    }
}

void choice(GLint i,GLint j)    // Prints the desired text when the packet is being transmitted
{
    setFont(GLUT_BITMAP_HELVETICA_18);
    glColor3f(1.0,1.0,1.0);

    switch (i)                  // to choose which packet is being sent
    {
    case 1 :
        switch (j)              // to chose which phase of the packet is being done
        {
            case 1:

            drawstring(165.0,300.0,1.0," S E N D I N G   P A C K E T   O N E    ");
            glColor3f(1.0,1.0,1.0);
            slide(2,2,50,250);
            break;


            case 2:

            drawstring(160.0,300.0,1.0," S E N D I N G   P A C K E T   O N E ......    ");
            glColor3f(1.0,1.0,1.0);
            slide(2,2,50,250);
            break;


            case 3:

            drawstring(165.0,300.0,1.0," P A C K E T   O N E   R E C E I V E D    ");
             glColor3f(0.0,1.0,0.0);
            slide(2,2,50,250);
            break;

            case 4:

            drawstring(125.0,300.0,1.0," S E N D I N G   A C K N O W L E D G E M E N T  O N E   ");
            glColor3f(1.0,1.0,1.0);
            slide(2,2,300,220);

            break;


            case 5:

            drawstring(120.0,300.0,1.0," S E N D I N G   A C K N O W L E D G E M E N T  O N E ....      ");
            glColor3f(1.0,1.0,1.0);
            slide(2,2,300,220);

            break;


            case 6:

            drawstring(125.0,300.0,1.0," A C K N O W L E D G E M E N T  O N E  R E C E I V E D    ");
            glColor3f(0.0,1.0,0.0);
            slide(2,2,300,220);
            break;
        }

	break;
   case 2 :
        switch (j)              // to chose which phase of the packet is being done
        {
            case 1:

            drawstring(165.0,300.0,1.0," S E N D I N G   P A C K E T   T W O    ");
            glColor3f(1.0,1.0,1.0);
            slide(2,2,75,250);

            break;


            case 2:

            drawstring(150.0,300.0,1.0," E R R O R  S E N D I N G  P A C K E T   T W O  ");
            glColor3f(1.0,0.0,0.0);
            slide(2,2,75,250);
            slide(2,2,325,220);

            break;


            case 3:

            drawstring(160.0,300.0,1.0," R E S E N D I N G   P A C K E T   T W O    ");
             glColor3f(1.0,1.0,1.0);
            slide(2,2,75,250);

            break;

            case 4:

            drawstring(160.0,300.0,1.0," R E S E N D I N G   P A C K E T   T W O ...  ");
            glColor3f(1.0,1.0,1.0);
            slide(2,2,75,250);

            break;


            case 5:

            drawstring(165.0,300.0,1.0," P A C K E T   T W O   R E C E I V E D      ");
             glColor3f(0.0,1.0,0.0);
            slide(2,2,325,220);

            break;

            case 6:

            drawstring(125.0,300.0,1.0," S E N D I N G   A C K N O W L E D G E M E N T   T W O ");
              glColor3f(1.0,1.0,1.0);
            slide(2,2,325,220);

            break;


            case 7:

            drawstring(120.0,300.0,1.0," S E N D I N G   A C K N O W L E D G E M E N T   T W O ....      ");
              glColor3f(1.0,1.0,1.0);
            slide(2,2,325,220);

            break;


            case 8:

            drawstring(125.0,300.0,1.0," A C K N O W L E D G E M E N T   T W O   R E C E I V E D    ");
            glColor3f(0.0,1.0,0.0);
            slide(2,2,325,220);

            break;

            case 12:

            drawstring(150.0,300.0,1.0," S E N D I N G   A   N A K   F O R    T W O   ");
            glColor3f(1.0,1.0,1.0);
            slide(2,2,325,220);

            break;
        }

	break;

	case 3 :
        switch (j)              // to chose which phase of the packet is being done
        {
            case 1:

            drawstring(160.0,300.0,1.0," S E N D I N G   P A C K E T   T H R E E    ");
            glColor3f(1.0,1.0,1.0);
            slide(2,2,100,250);

            break;


            case 2:

            drawstring(155.0,300.0,1.0," S E N D I N G   P A C K E T   T H R E E ......    ");
            glColor3f(1.0,1.0,1.0);
            slide(2,2,100,250);

            break;


            case 3:

            drawstring(160.0,300.0,1.0," P A C K E T   T H R E E   R E C E I V E D    ");
            glColor3f(0.0,1.0,0.0);
            slide(2,2,100,250);

            break;

            case 4:

            drawstring(120.0,300.0,1.0," S E N D I N G   A C K N O W L E D G E M E N T   T H R E E  ");
              glColor3f(1.0,1.0,1.0);
            slide(2,2,350,220);

            break;


            case 5:

            drawstring(115.0,300.0,1.0," S E N D I N G   A C K N O W L E D G E M E N T   T H R E E ....      ");
              glColor3f(1.0,1.0,1.0);
            slide(2,2,350,220);

            break;


            case 6:

            drawstring(120.0,300.0,1.0," A C K N O W L E D G E M E N T  T H R E E   R E C E I V E D    ");
            glColor3f(0.0,1.0,0.0);
            slide(2,2,350,220);

            break;
        }

	break;

	case 4 :
        switch (j)              // to chose which phase of the packet is being done
        {
            case 1:

            drawstring(165.0,300.0,1.0," S E N D I N G   P A C K E T   F O U R    ");
            glColor3f(1.0,1.0,1.0);
            slide(2,2,125,250);

            break;


            case 2:

            drawstring(160.0,300.0,1.0," S E N D I N G   P A C K E T   F O U R  ......    ");
            glColor3f(1.0,1.0,1.0);
            slide(2,2,125,250);

            break;


            case 3:

            drawstring(165.0,300.0,1.0," P A C K E T  F O U R   R E C E I V E D    ");
            glColor3f(0.0,1.0,0.0);
            slide(2,2,125,250);

            break;

            case 4:

            drawstring(125.0,300.0,1.0," S E N D I N G   A C K N O W L E D G E M E N T   F O U R   ");
            glColor3f(1.0,1.0,1.0);
            slide(2,2,375,220);

            break;


            case 5:

            drawstring(120.0,300.0,1.0," S E N D I N G   A C K N O W L E D G E M E N T   F O U R ....      ");
            glColor3f(1.0,1.0,1.0);
            slide(2,2,375,220);

            break;


            case 6:

            drawstring(125.0,300.0,1.0," A C K N O W L E D G E M E N T  F O U R   R E C E I V E D    ");
            glColor3f(0.0,1.0,0.0);
            slide(2,2,375,220);

            break;
        }

	break;

case 5 :
        switch (j)              // to chose which phase of the packet is being done
        {
            case 1:

            drawstring(165.0,300.0,1.0," S E N D I N G   P A C K E T   F I V E    ");
            glColor3f(1.0,1.0,1.0);
            slide(2,2,150,250);

            break;


            case 2:

            drawstring(160.0,300.0,1.0," S E N D I N G   P A C K E T   F I V E   ......    ");
            glColor3f(1.0,1.0,1.0);
            slide(2,2,150,250);

            break;


            case 3:

            drawstring(165.0,300.0,1.0," P A C K E T   F I V E    R E C E I V E D    ");
            glColor3f(0.0,1.0,0.0);
            slide(2,2,150,250);

            break;

            case 4:

            drawstring(125.0,300.0,1.0," S E N D I N G   A C K N O W L E D G E M E N T   F I V E   ");
            glColor3f(1.0,0.0,0.0);
            slide(2,2,400,220);

            break;


            case 5:

            drawstring(105.0,300.0,1.0," E R R O R   S E N D I N G   A C K N O W L E D G E M E N T   F I V E ....      ");
            glColor3f(1.0,0.0,0.0);
            slide(2,2,400,220);

            break;


            case 6:

            drawstring(160.0,300.0,1.0," R E S E N D I N G   P A C K E T   F I V E     ");
             glColor3f(1.0,1.0,1.0);
            slide(2,2,150,250);

            break;

            case 7:

            drawstring(160.0,300.0,1.0," R E S E N D I N G   P A C K E T   F I V E ...  ");
            glColor3f(1.0,1.0,1.0);
            slide(2,2,150,250);

            break;


            case 8:

            drawstring(165.0,300.0,1.0," P A C K E T   F I V E   R E C E I V E D      ");
            glColor3f(0.0,1.0,0.0);
            slide(2,2,150,250);

            break;

            case 9:

            drawstring(125.0,300.0,1.0," S E N D I N G   A C K N O W L E D G E M E N T   F I V E ");
              glColor3f(1.0,1.0,1.0);
            slide(2,2,400,220);

            break;


            case 10:

            drawstring(120.0,300.0,1.0," S E N D I N G   A C K N O W L E D G E M E N T   F I V E ....      ");
              glColor3f(1.0,1.0,1.0);
            slide(2,2,400,220);

            break;


            case 11:

            drawstring(125.0,300.0,1.0," A C K N O W L E D G E M E N T   F I V E   R E C E I V E D    ");
            glColor3f(0.0,1.0,0.0);
            slide(2,2,400,220);

            break;

            case 12:

            drawstring(150.0,300.0,1.0," S E N D I N G   A   N A K   F O R    F I V E   ");
            glColor3f(1.0,1.0,1.0);
            slide(2,2,400,220);

            break;

        }

	break;

	case 6 :
        switch (j)              // to chose which phase of the packet is being done
        {
            case 1:

            drawstring(165.0,300.0,1.0," S E N D I N G   P A C K E T   S I X    ");
            glColor3f(1.0,1.0,1.0);
            slide(2,2,175,250);

            break;


            case 2:

            drawstring(160.0,300.0,1.0," S E N D I N G   P A C K E T   S I X ......    ");
            glColor3f(1.0,1.0,1.0);
            slide(2,2,175,250);

            break;


            case 3:

            drawstring(165.0,300.0,1.0," P A C K E T   S I X   R E C E I V E D    ");
            glColor3f(0.0,1.0,0.0);
            slide(2,2,175,250);

            break;

            case 4:

            drawstring(125.0,300.0,1.0," S E N D I N G   A C K N O W L E D G E M E N T   S I X  ");
            glColor3f(1.0,1.0,1.0);
            slide(2,2,425,220);

            break;


            case 5:

            drawstring(120.0,300.0,1.0," S E N D I N G   A C K N O W L E D G E M E N T   S I X ....      ");
            glColor3f(1.0,1.0,1.0);
            slide(2,2,425,220);

            break;


            case 6:

            drawstring(125.0,300.0,1.0," A C K N O W L E D G E M E N T  S I X   R E C E I V E D    ");
            glColor3f(0.0,1.0,0.0);
            slide(2,2,425,220);

            break;
        }

    break;

	case 7 :
        switch (j)              // to chose which phase of the packet is being done
        {
            case 1:

            drawstring(160.0,300.0,1.0," S E N D I N G   P A C K E T   S E V E N    ");
            glColor3f(1.0,1.0,1.0);
            slide(2,2,200,250);

            break;


            case 2:

            drawstring(155.0,300.0,1.0," S E N D I N G   P A C K E T   S E V E N ......    ");
            glColor3f(1.0,1.0,1.0);
            slide(2,2,200,250);

            break;


            case 3:

            drawstring(160.0,300.0,1.0," P A C K E T   S E V E N   R E C E I V E D    ");
            glColor3f(0.0,1.0,0.0);
            slide(2,2,200,250);

            break;

            case 4:

            drawstring(120.0,300.0,1.0," S E N D I N G   A C K N O W L E D G E M E N T   S E V E N  ");
            glColor3f(1.0,1.0,1.0);
            slide(2,2,450,220);

            break;


            case 5:

            drawstring(115.0,300.0,1.0," S E N D I N G   A C K N O W L E D G E M E N T   S E V E N ....      ");
            glColor3f(1.0,1.0,1.0);
            slide(2,2,450,220);

            break;


            case 6:

            drawstring(120.0,300.0,1.0," A C K N O W L E D G E M E N T  S E V E N   R E C E I V E D    ");
            glColor3f(0.0,1.0,0.0);
            slide(2,2,450,220);
            break;
        }
	break;
	}
	glEnd();
	glFlush();

}



void choice2(void)				// text for keyboard interaction

{   glutSwapBuffers();
	glColor3f(1.0f,1.0f,1.0f);
	setFont(GLUT_BITMAP_HELVETICA_18);
	drawstring(340.0,80.0,1.0,"DO YOU WISH TO CONTINUE?");
	glColor3f(1.0f,1.0f,1.0f);
	drawstring(340.0,65.0,1.0,"PRESS  Y / N");
	glFlush();
	glutSwapBuffers();
	delay1();
}



void mykeyboard(unsigned char key,int x,int y)
{
	if(key=='y' || key=='Y')
	{

		draw();


	}
	else if(key=='N' || key=='n')
	{
		exit(0);
	}
}

void myMouse(int btn, int state, int x, int y)
{

	if(btn==GLUT_LEFT_BUTTON && state == GLUT_DOWN )
	{
		x=x/2;
		y=(1000-y)/2.1;
		 printf("x=%d\ny=%d\n",x,y);
		if ((x>=180 && x<=305) && (y>=395 && y<=425 ))// 1 menu

		{
            intro();

		}

		if((x>=180 && x<=305) && (y>=374 && y<=405 ))//   2 menu
		{
        saw();

		}
		if((x>=180 && x<=305) && (y>=340 && y<=370 ))  // 3 menu
		{
        gbn();
		}

		if((x>=180 && x<=305) && (y>=305 && y<=335 ))  // 4 menu
		{
        sw();

		}

		if((x>=180 && x<=305) && (y>=270 && y<=300 ))  // 5 menu
		{
            exit(0);
		}

	}
}

void myInit()
{
    glClearColor(0.0,0.0,0.0,0.0);
	glColor3f(0.0f,0.0f,0.0f);
	glPointSize(5.0);
	gluOrtho2D(0.0,500.0,0.0,500.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();


}

int main(int argc,char **argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGBA);

  	glutInitWindowPosition(0,0);
	glutInitWindowSize(1000,1000);
	glutCreateWindow("Automatic Repeat Request");
        glutDisplayFunc(display);
  //     glutReshapeFunc(resize);
    glutMouseFunc(myMouse);
    glutKeyboardFunc(mykeyboard);
	myInit();
	glutMainLoop();


}
