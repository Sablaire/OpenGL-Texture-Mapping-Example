#pragma comment(lib, "opengl32.lib")
#pragma comment(lib, "glu32.lib")
#pragma comment(lib,"glaux.lib")
#include <windows.h>
#include <cmath>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <GL/glaux.h>
#include <stdlib.h> 
#include <time.h>
#define checkImageWidth 150
#define checkImageHeight 150
float checkImage[checkImageHeight][checkImageWidth][4];
GLuint texName;
int x[150], y[150];
void makeCheckImage(){
int i, j;
float r, g, b;
for (i=0;i<checkImageHeight;i++){
for (j=0;j<checkImageWidth;j++){
if(i>=0&&j==70&&i<=55) {r=0; g=1; b=0;} 
else { r=0.7; g=1.; b=1.; }
checkImage[i][j][0]=(float)r;
checkImage[i][j][1]=(float)g;
checkImage[i][j][2]=(float)b;
checkImage[i][j][3]=(float)255; }}
for (i=-2*checkImageHeight/4;i<checkImageHeight;i++){
	x[i]=(10*(1-cos(10000*i*3.14/180)*sin(100000*i*3.14/180*5.625))+50);
	y[i]=(10*(cos(10000*i*3.14/180)*cos(100000*i*3.14/180*5.625))+60); }	
for (i=0;i<checkImageHeight;i++){
	r=0.8; g=0.2; b=0.2;
checkImage[x[i]][y[i]][0]=(float)r;
checkImage[x[i]][y[i]][1]=(float)g;
checkImage[x[i]][y[i]][2]=(float)b;
checkImage[x[i]][y[i]][3]=(float)255;}
for (i=-2*checkImageHeight/4;i<checkImageHeight;i++){
	x[i]=(10*(cos(10000*i*3.14/180)*sin(100000*i*3.14/180*5.625))+80);
	y[i]=(10*(cos(10000*i*3.14/180)*cos(100000*i*3.14/180*5.625))+60);}	
for (i=0;i<checkImageHeight;i++){
	r=0.8; g=0.2; b=0.2;
checkImage[x[i]][y[i]][0]=(float)r;
checkImage[x[i]][y[i]][1]=(float)g;
checkImage[x[i]][y[i]][2]=(float)b;
checkImage[x[i]][y[i]][3]=(float)255;}
for (i=-2*checkImageHeight/4;i<checkImageHeight;i++){
	x[i]=(10*(1-cos(10000*i*3.14/180)*sin(100000*i*3.14/180*5.625))+50);
	y[i]=(10*(1-cos(10000*i*3.14/180)*cos(100000*i*3.14/180*5.625))+70); }	
for (i=0;i<checkImageHeight;i++){
	r=0.8; g=0.2; b=0.2;
checkImage[x[i]][y[i]][0]=(float)r;
checkImage[x[i]][y[i]][1]=(float)g;
checkImage[x[i]][y[i]][2]=(float)b;
checkImage[x[i]][y[i]][3]=(float)255;}
for (i=-2*checkImageHeight/4;i<checkImageHeight;i++){
	x[i]=(10*(cos(10000*i*3.14/180)*sin(100000*i*3.14/180*5.625))+80);
	y[i]=(10*(1-cos(10000*i*3.14/180)*cos(100000*i*3.14/180*5.625))+70); }	
for (i=0;i<checkImageHeight;i++){
	r=0.8; g=0.2; b=0.2;
checkImage[x[i]][y[i]][0]=(float)r;
checkImage[x[i]][y[i]][1]=(float)g;
checkImage[x[i]][y[i]][2]=(float)b;
checkImage[x[i]][y[i]][3]=(float)255;}}

void init(void){
glClearColor(0.0,0.3,1.0,0.0);
glShadeModel(GL_FLAT);
glEnable(GL_DEPTH_TEST);
makeCheckImage();
glPixelStorei(GL_UNPACK_ALIGNMENT,1);
glGenTextures(1,&texName);
glBindTexture(GL_TEXTURE_2D,texName);
glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,GL_REPEAT);
glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T,GL_REPEAT);
glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_NEAREST);
glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_NEAREST);
glTexImage2D(GL_TEXTURE_2D,0,GL_RGBA,checkImageWidth,checkImageHeight,
0,GL_RGBA,GL_FLOAT,checkImage); }

void display(void){
glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
glEnable(GL_TEXTURE_2D);
glTexEnvf(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,GL_REPLACE);
glBindTexture(GL_TEXTURE_2D,texName);
glBegin(GL_QUADS);
glTexCoord2f(0.0,0.0); glVertex3f(-2.0,-2,0.0);
glTexCoord2f(0.0,1.0); glVertex3f(-2.0,2,0.0);
glTexCoord2f(1.0,1.0); glVertex3f(2.0,2,0.0);
glTexCoord2f(1.0,0.0); glVertex3f(2.0,-2,0.0);
glEnd();
glFlush();
glDisable(GL_TEXTURE_2D); }

void reshape(int w, int h){
glViewport(0,0,(GLsizei) w, (GLsizei) h);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluPerspective(60.0,(GLfloat)w/(GLfloat)h,1.0,30.0);
glMatrixMode(GL_MODELVIEW);
glLoadIdentity();
glTranslatef(0.0,0.0,-3.6); }

int main(int argc, char * argv){
glutInit(&argc,&argv);
glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB|GLUT_DEPTH);
glutInitWindowSize(500,500);
glutCreateWindow("SRM");
init();
glutDisplayFunc(display);
glutReshapeFunc(reshape);
glutMainLoop();
return 0; }
