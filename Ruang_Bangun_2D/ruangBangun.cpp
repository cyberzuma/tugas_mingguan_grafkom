#include <cstdlib>
#include <iostream>
#include <windows.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <math.h>
#define PI 3.14

using namespace std;

//ket: w=weight | h=height
float i,radius,jumlah_titik,x_tengah,y_tengah;
float pxw,pxh,wspxw,wspxh;
float spsiw,spsih;
float s;

void init() {
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	//membuat background warna merah
    glClearColor(0.0,0.0,0.0,0.0);
    //set viewport dengan nilai 320 x 240, inisialisasi windowsize
    //glViewport(0,0,320,240);
    // set the 2D clipping area
    gluOrtho2D(0.0, wspxw, 0.0, wspxh);
    //glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);
    glPointSize(5.0);
}

void draw() {
	glClear(GL_COLOR_BUFFER_BIT);
	
	//trapesium (1,1)
	glBegin(GL_POLYGON);
    glColor3f (1.0, 0.9, 0.9);
    glVertex2f (spsiw, spsih);
    glVertex2f (spsiw+s, spsih);    
    glVertex2f (spsiw+s-30, spsih+s);
    glVertex2f (spsiw+30, spsih+s);
    glEnd();
    //-----------------------------
    
    //segitiga (1,2)
    glBegin(GL_POLYGON);
    glColor3f (0.5, 1.0, 0.5);
    glVertex2f (2*spsiw+s, spsih);
    glVertex2f ((2*spsiw+2*s), spsih);
    glVertex2f ((2*spsiw+1.5*s), spsih+s);
    glEnd();
    //-----------------------------
    
    //jajargenjang (1,3)
    glBegin(GL_POLYGON);
    glColor3f (0.5, 0.1, 0.9);
    glVertex2f (3*spsiw+2*s, spsih);
    glVertex2f ((3*spsiw+3*s)-30, spsih);
    glVertex2f ((3*spsiw+3*s), spsih+s);
    glVertex2f (3*spsiw+2*s+30, spsih+s);
    glEnd();
    //-----------------------------
    
    //lingkaran (2,1)
	glBegin(GL_POLYGON);
    glColor3f (1.0, 1.0, 0.0);
	radius=s/2;
	jumlah_titik=50;
	x_tengah=(spsiw+s/2);
	y_tengah=(2*spsih+1.5*s);
	for (i=0;i<=50;i++){
        float sudut=i*(2*PI/jumlah_titik);
        float x=x_tengah+radius*cos(sudut);
        float y=y_tengah+radius*sin(sudut);
		glVertex2f(x,y);
	}
    glEnd();
    
    glBegin(GL_POLYGON);
    glColor3f (0.0, 0.0, 0.0);
	radius=s/4;
	jumlah_titik=50;
	x_tengah=(spsiw+s/2);
	y_tengah=(2*spsih+1.5*s);
	for (i=0;i<=50;i++){
        float sudut=i*(2*PI/jumlah_titik);
        float x=x_tengah+radius*cos(sudut);
        float y=y_tengah+radius*sin(sudut);
		glVertex2f(x,y);
	}
    glEnd();
    //-----------------------------
    
    //setLingkaran (2,2)
	glBegin(GL_POLYGON);
    glColor3f (0.5, 0.5, 0.5);
	radius=s/2;
	jumlah_titik=100;
	x_tengah=(2*spsiw+1.5*s);
	y_tengah=(2*spsih+1.5*s);
	for (i=0;i<=50;i++){
        float sudut=i*(2*PI/jumlah_titik);
        float x=x_tengah+radius*cos(sudut);
        float y=y_tengah+radius*sin(sudut);
		glVertex2f(x,y);
	}
    glEnd();
    //-----------------------------
    
    //cone (2,3)
	glBegin(GL_POLYGON);
    glColor3f (0.9, 0.3, 0.0);
	radius=s/2;
	jumlah_titik=100;
	x_tengah=(3*spsiw+s*2.5);
	y_tengah=(2*spsih+1.5*s);
	for (i=0;i<=50;i++){
        float sudut=i*(2*PI/jumlah_titik);
        float x=x_tengah+radius*cos(sudut);
        float y=y_tengah+radius*sin(sudut);
		glVertex2f(x,y);
	}
    glEnd();
    
    glBegin(GL_POLYGON);
    glColor3f (0.9, 0.3, 0.0);
    glVertex2f (3*spsiw+s*2.5, 2*spsih+s);
    glVertex2f (3*spsiw+3*s, 2*spsih+s*1.5);
    glVertex2f (3*spsiw+2*s, 2*spsih+s*1.5);       
    glEnd();    
    //-----------------------------
       
    //persegi (3,1)
	glBegin(GL_POLYGON);
    glColor3f (1.0, 0.5, 0.5);
    glVertex2f (spsiw, 3*spsih+2*s);
    glVertex2f (spsiw, (3*spsih+3*s));
    glVertex2f (spsiw+s, (3*spsih+3*s));
    glVertex2f (spsiw+s, 3*spsih+2*s);
    glEnd();
    //-----------------------------
    
    //plus (3,2)
	glBegin(GL_POLYGON);
	glColor3f (0.0, 1.0, 1.0);
	glVertex2f (2*spsiw+s*4/3, 3*spsih+s*7/3);    
    glVertex2f (2*spsiw+s*4/3, 3*spsih+2*s);    
    glVertex2f (2*spsiw+s*5/3, 3*spsih+2*s);    
    glVertex2f (2*spsiw+s*5/3, 3*spsih+s*7/3);   
    glVertex2f (2*spsiw+s*2, 3*spsih+s*7/3);    
    glVertex2f (2*spsiw+s*2, 3*spsih+s*8/3);  
    glVertex2f (2*spsiw+s*5/3, 3*spsih+s*8/3);  
    glVertex2f (2*spsiw+s*5/3, 3*spsih+3*s);  
    glVertex2f (2*spsiw+s*4/3, 3*spsih+3*s);  
    glVertex2f (2*spsiw+s*4/3, 3*spsih+s*8/3); 
    glVertex2f (2*spsiw+s, 3*spsih+s*8/3);  
    glVertex2f (2*spsiw+s, 3*spsih+s*7/3);
    glEnd();
    //-----------------------------
    
    //divide (3,3)
	glBegin(GL_POLYGON);
	glColor3f (0.5, 0.5, 0.7);
	glVertex2f (3*spsiw+s*2, 3*spsih+s*2.4);   
    glVertex2f (3*spsiw+s*3, 3*spsih+s*2.4);  
    glVertex2f (3*spsiw+s*3, 3*spsih+s*2.6);      
    glVertex2f (3*spsiw+s*2, 3*spsih+s*2.6);
    glEnd();
    
    glBegin(GL_POLYGON);//ling kanan
    glColor3f (0.5, 0.5, 0.7);
	radius=s/6;
	jumlah_titik=50;
	x_tengah=(3*spsiw+s*2.5);
	y_tengah=(3*spsih+s*2.85);
	for (i=0;i<=50;i++){
        float sudut=i*(2*PI/jumlah_titik);
        float x=x_tengah+radius*cos(sudut);
        float y=y_tengah+radius*sin(sudut);
		glVertex2f(x,y);
	}
    glEnd();
    
    glBegin(GL_POLYGON);//ling kiri
    glColor3f (0.5, 0.5, 0.7);
	radius=s/6;
	jumlah_titik=50;
	x_tengah=(3*spsiw+s*2.5);
	y_tengah=(3*spsih+s*2.15);
	for (i=0;i<=50;i++){
        float sudut=i*(2*PI/jumlah_titik);
        float x=x_tengah+radius*cos(sudut);
        float y=y_tengah+radius*sin(sudut);
		glVertex2f(x,y);
	}
    glEnd();
    //-----------------------------
            
    glFlush();
}

int main(int argc, char *argv[])
{
    //setting tampilan layar
    pxw= 1360;  //ukuran resolusi monitor
    pxh= 760;
    
    wspxw= 800; //ukuran tampilan layar
    wspxh= 600;
        
    if(wspxw > wspxh)
    {
         s= ((wspxh-(spsih*4))/3)*wspxh/wspxw;
    }
    else
    {
         s= ((wspxw-(spsiw*4))/3)*wspxh/wspxw;
    }
        
    spsiw= 90; //ukuran jarak antar objek
    spsih= 35;    
    
    cout<<s;
    
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize (wspxw, wspxh); //ukuran tampilan layar
    glutInitWindowPosition ((pxw/2)-(wspxw/2),(pxh/2)-(wspxh/2)); //agar layar percis di tengah :bd
    glutCreateWindow ("Program ruangBangun | by Zuma");
    init ();
    glutDisplayFunc(draw);
    glutMainLoop();
    return 0;    
}
