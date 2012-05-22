//  by zumara 

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdarg.h>
#include <GL/glut.h>

using namespace std;

static GLfloat rx = 2.0;
static GLfloat ry = 1.5;
static GLfloat rz = 2.0;

float angle = 0.0f;
float lx=0.0f,lz=-1.0f;
float x=0.0f, z=15.0f;

float deltaAngle = 0.0f;
float deltaMove = 0;

GLfloat  ambient_light[] = {0.3, 0.3, 0.45, 1.0};
GLfloat   source_light[] = {1.0, 1.0, 1.0, 1.0};
GLfloat      light_pos[] = {2.0f, 1.5f, 2.0f, 100.0};
GLfloat   mat_specular[] = {0.9, 0.8, 0.8, 1.0};
GLfloat  mat_shininess[] = {50.0};

void reshape(int w, int h) {

	if (h == 0)
		h = 1;
	float ratio =  w * 1.0 / h;

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glViewport(0, 0, w, h);
	gluPerspective(45.0f, ratio, 0.1f, 100.0f);
	glMatrixMode(GL_MODELVIEW);
}

void drawBangunRuang() {   
       
    // Draw ground
	glColor3f(0.25f, 0.5f, 0.25f);
	glBegin(GL_QUADS);
		glVertex3f(-5.0f, 0.0f, -5.0f);
		glVertex3f(-5.0f, 0.0f,  5.0f);
		glVertex3f( 5.0f, 0.0f,  5.0f);
		glVertex3f( 5.0f, 0.0f, -5.0f);
	glEnd();
		    	
     // Draw penyangga   
	glBegin(GL_QUADS);                 // Draw using quads
      glColor3f(1.0f, 1.5f, 1.0f);     // Orange
      glVertex3f( 0.1f, 0.1f, -0.1f); // Top-right of the quad (Top)
      glVertex3f(-0.1f, 0.1f, -0.1f); // Top-left of the quad (Top)
      glVertex3f(-0.1f, 0.1f,  0.1f); // Bottom-left of the quad (Top)
      glVertex3f( 0.1f, 0.1f,  0.1f); // Bottom-right of the quad (Top)
   
      glVertex3f( 0.1f, -0.1f,  0.1f); // Top-right of the quad (Bottom)
      glVertex3f(-0.1f, -0.1f,  0.1f); // Top-left of the quad (Bottom)
      glVertex3f(-0.1f, -0.1f, -0.1f); // Bottom-left of the quad (Bottom)
      glVertex3f( 0.1f, -0.1f, -0.1f); // Bottom-right of the quad (Bottom)
      
      glColor3f(1.0f, 0.0f, 0.0f);     // Red black
      glVertex3f( 0.1f,  3.0f, 0.1f);  // Top-right of the quad (Front)
      glVertex3f(-0.1f,  3.0f, 0.1f);  // Top-left of the quad (Front)
      glVertex3f(-0.1f, -0.1f, 0.1f);  // Bottom-left of the quad (Front)
      glVertex3f( 0.1f, -0.1f, 0.1f);  // Bottom-right of the quad (Front)
      
      //glColor3f(1.0f, 0.5f, 0.5f);     // Orange
      glVertex3f( 0.1f, -0.1f, -0.1f); // Bottom-left of the quad (Back)
      glVertex3f(-0.1f, -0.1f, -0.1f); // Bottom-right of the quad (Back)
      glVertex3f(-0.1f,  3.0f, -0.1f); // Top-right of the quad (Back)
      glVertex3f( 0.1f,  3.0f, -0.1f); // Top-left of the quad (Back)
      
      //glColor3f(1.0f, 0.0f, 0.0f);     // Orange
      glVertex3f(-0.1f,  3.0f,  0.1f); // Top-right of the quad (Left)
      glVertex3f(-0.1f,  3.0f, -0.1f); // Top-left of the quad (Left)
      glVertex3f(-0.1f, -0.1f, -0.1f); // Bottom-left of the quad (Left)
      glVertex3f(-0.1f, -0.1f,  0.1f); // Bottom-right of the quad (Left)
      
      //glColor3f(1.0f, 0.5f, 0.0f);     // Orange
      glVertex3f( 0.1f,  3.0f, -0.1f); // Top-right of the quad (Right)
      glVertex3f( 0.1f,  3.0f,  0.1f); // Top-left of the quad (Right)
      glVertex3f( 0.1f, -0.1f,  0.1f); // Bottom-left of the quad (Right)
      glVertex3f( 0.1f, -0.1f, -0.1f); // Bottom-right of the quad (Right)
   glEnd(); 
	
    // Draw lampu
    glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
	glTranslatef(0.0f, 3.24f, 0.0f);
	glutSolidSphere(0.25f,50,50);

    // Draw kubus
	glColor3f(1.0f, 0.5f, 0.0f);     // Orange
    glTranslatef(1.2f, -3.0f, 0.0f);
    glutSolidCube(0.5f);
    
    // Draw kubus
	glColor4f(0.05, 1.0, 0.89, 1.0); // blue
    glTranslatef(1.2f, 0.0f, 1.0f);
    glutSolidCube(0.5f);
    
    // Draw kubus
	glColor4f(1.0,0.5,1.0,1.0); // purple
    glTranslatef(-4.0f, 0.0f, 2.0f);
    glutSolidCube(0.5f);
    
    // Draw kubus
	glColor4f(1.0,1.0,1.0,1.0); // purple
    glTranslatef(-1.0f, 0.0f, -4.0f);
    glutSolidCube(0.5f);
    
    // Draw sumber cahaya	
	glColor4f(1.0, 0.5, 0.0, 1.0);    
    glTranslatef(rx, ry, rz);        
    glutWireCube(0.1f);

//========== light effect ==========
   glEnable (GL_DEPTH_TEST);

   glEnable       ( GL_LIGHTING );
   glLightModelfv ( GL_LIGHT_MODEL_AMBIENT,ambient_light);
   glLightfv      ( GL_LIGHT0,GL_DIFFUSE,source_light);
   glLightfv      ( GL_LIGHT0,GL_POSITION,light_pos);
   glEnable       ( GL_LIGHT0 );
   
   glEnable        ( GL_COLOR_MATERIAL );
   glColorMaterial ( GL_FRONT, GL_AMBIENT_AND_DIFFUSE );
   
   glShadeModel(GL_SMOOTH);   

   glEnable     ( GL_CULL_FACE );
   glClearColor ( 0.0, 0.0, 0.0, 0.0 );
}

void computePos(float deltaMove) {

	x += deltaMove * lx * 0.1f;
	z += deltaMove * lz * 0.1f;
}

void computeDir(float deltaAngle) {

	angle += deltaAngle;
	lx = sin(angle);
	lz = -cos(angle);
}

void renderScene(void) { 
	if (deltaMove)
		computePos(deltaMove);
	if (deltaAngle)
		computeDir(deltaAngle);

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);    	
	
    glLoadIdentity();		
	gluLookAt(	x, 3.0f, z,
				x+lx, 3.0f,  z+lz,
				0.0f, 3.0f,  0.0f);
				
    glPushMatrix();
			glTranslatef(-0,0,0);
			drawBangunRuang();
			glPopMatrix();
			
	glutSwapBuffers();
}

void processNormalKeys(unsigned char key, int xx, int yy) {
     	
    if (key == 27)
		exit(0);
    
    switch (key) {
		case '8' : if(rz>=-1)rz = rz-1; break;
        case '2' : if(rz<=6)rz = rz+1; break;    
        
        case '4' : if(rx>=-1)rx = rx-1; break;
        case '6' : if(rx<=6)rx = rx+1; break;          
    }
}

void pressKey(int key, int xx, int yy) {

	switch (key) {
		case GLUT_KEY_LEFT : deltaAngle = -0.001f; break;
		case GLUT_KEY_RIGHT : deltaAngle = 0.001f; break;
		case GLUT_KEY_UP : deltaMove = 0.1f; break;
		case GLUT_KEY_DOWN : deltaMove = -0.1f; break;
        case GLUT_KEY_F1 : glutFullScreen(); break;         
	}
 }

void releaseKey(int key, int x, int y) {

	switch (key) {
		case GLUT_KEY_LEFT :
		case GLUT_KEY_RIGHT : deltaAngle = 0.0f;break;
		case GLUT_KEY_UP :
		case GLUT_KEY_DOWN : deltaMove = 0;break;
	}
}

int main(int argc, char **argv) {

	glutInit(&argc, argv);
	cout << "Keterangan :" << endl;
    cout << "------------------------------" << endl;
    cout << "Tekan 8 untuk memindahkan sumber cahaya ke arah depan" << endl;
    cout << "Tekan 2 untuk memindahkan sumber cahaya ke arah belakang" << endl;
    cout << "Tekan 4 untuk memindahkan sumber cahaya ke arah kiri" << endl;
    cout << "Tekan 6 untuk memindahkan sumber cahaya ke arah kanan" << endl;
    cout << "" << endl;
    cout << "Tekan arrow keypad untuk memindahkan kamera" << endl;
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(200,200);
	glutInitWindowSize(640,480);
	glutCreateWindow("Bangun 3D - No Shadow");
	
	glutDisplayFunc(renderScene);
	glutReshapeFunc(reshape);
	glutIdleFunc(renderScene);	

	glutSpecialFunc(pressKey);
    glutKeyboardFunc(processNormalKeys);	

	glutIgnoreKeyRepeat(1);
	glutSpecialUpFunc(releaseKey);

	glEnable(GL_DEPTH_TEST);
	
	glutMainLoop();
	
	return 1;
}
