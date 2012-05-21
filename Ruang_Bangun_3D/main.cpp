#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>

float angle, angle2;

int moving, startx, starty;

GLfloat  ambient_light[] = {0.3, 0.3, 0.45, 1.0};
GLfloat   source_light[] = {0.9, 0.8, 0.8, 1.0};
GLfloat      light_pos[] = {7.0, 0.0, 0.0, 1.0};


void init( void )
{
   glEnable       ( GL_LIGHTING );
   glLightModelfv ( GL_LIGHT_MODEL_AMBIENT,ambient_light );
   glLightfv      ( GL_LIGHT0,GL_DIFFUSE,source_light );
   glLightfv      ( GL_LIGHT0,GL_POSITION,light_pos );
   glEnable       ( GL_LIGHT0 );

   glEnable        ( GL_COLOR_MATERIAL );
   glColorMaterial ( GL_FRONT, GL_AMBIENT_AND_DIFFUSE );

      glEnable     ( GL_CULL_FACE );
   glClearColor ( 0.0, 0.0, 0.0, 0.0 );
}

void draw_ball(void)
{  
   // Draw kubus
	glColor4f ( 1.0, 0.0, 0.0, 1.0 );
    glTranslatef(1.2f, -1.0f, 0.0f);
    glutSolidCube(0.5f);
}

void display ( void )
{
   glClear   ( GL_COLOR_BUFFER_BIT );
   glLightfv ( GL_LIGHT0,GL_POSITION,light_pos );
   glPushMatrix   ( );
   glTranslatef ( 0.0, 0.0, -4.0 );
   glRotatef  ( angle2, 1.0, 0.0, 0.0 );
   glRotatef  ( angle, 0.0, 1.0, 0.0  );
   draw_ball ( );
   glPopMatrix  ( );
   glutSwapBuffers ( );
}

void reshape ( int w, int h )
{
   glViewport     ( 0, 0, w, h );
   glMatrixMode   ( GL_PROJECTION );
   glLoadIdentity ( );
   if ( h==0 )
      gluPerspective ( 80, ( float ) w, 1.0, 5000.0 );
   else
      gluPerspective ( 80, ( float ) w / ( float ) h, 1.0, 5000.0 );
   glMatrixMode   ( GL_MODELVIEW );
   glLoadIdentity ( );
}

void mouse ( int button, int state, int x, int y )
{
   if ( button == GLUT_LEFT_BUTTON && state == GLUT_DOWN )
   {
      moving = 1;
      startx = x;
      starty = y;
   }

   if ( button == GLUT_LEFT_BUTTON && state == GLUT_UP )
      moving = 0;
}

void motion ( int x, int y )
{
   if ( moving )
   {
      angle  = angle + (x - startx);
      angle2 = angle2 + (y - starty);
      startx = x;
      starty = y;
      glutPostRedisplay();
   }
}

void idle_func ( void )
{
   angle = angle + 0.1;
   if (angle == 360) angle = 0;
      glutPostRedisplay ( );
}

int main ( int argc, char** argv )
{
   glutInit ( &argc, argv );
   glutInitDisplayMode ( GLUT_RGB | GLUT_DOUBLE );
   glutInitWindowSize  ( 250, 250 );
   glutCreateWindow    ( argv[0] );
   init ( );
   glutReshapeFunc  ( reshape   );
   glutMouseFunc    ( mouse     );
   glutMotionFunc   ( motion    );
   glutDisplayFunc  ( display   );
   glutIdleFunc     ( idle_func );
   glutMainLoop ( );
   return 0;
}
