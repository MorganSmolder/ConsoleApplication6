// ConsoleApplication6.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "Vector.h"
#include "TextureManager.h"
#include "RenderModuleStubb.h"

char title[] = "3D Shapes";

RenderModuleStubb r;
TextureManager Tman;

void initGL() {
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f); 
	glClearDepth(1.0f);                
	glEnable(GL_DEPTH_TEST);   
	glEnable(GL_TEXTURE_2D);
	glDepthFunc(GL_LEQUAL);  
	glShadeModel(GL_SMOOTH);   
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST); 
	std::cout << "dog test" << std::endl;
}

void loadTex(){
	if (!Tman.loadNewTexture("./demo/1.bmp", "BMP", "1", &r)) std::cout << "ERROR! 1" << std::endl;
	if (!Tman.loadNewTexture("./demo/2.TGA", "TGA", "2", &r)) std::cout << "ERROR! 2" << std::endl;
	if (!Tman.loadNewTexture("./demo/3.tga", "TGA", "3", &r)) std::cout << "ERROR! 3" << std::endl;
	if (!Tman.loadNewTexture("./demo/4.bmp", "BMP", "4", &r)) std::cout << "ERROR! 4" << std::endl;
	if (!Tman.loadNewTexture("./demo/5.bmp", "BMP", "5", &r)) std::cout << "ERROR! 5" << std::endl;
}

void display() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); 
	glMatrixMode(GL_MODELVIEW); 

	glLoadIdentity();              
	glTranslatef(0, 0.0f, -7.0f);  
	
	r.DrawQuad({ -1, 2 }, { 2, -1 });

	glutSwapBuffers(); 
}

void reshape(GLsizei width, GLsizei height) { 
	if (height == 0) height = 1;               
	GLfloat aspect = (GLfloat)width / (GLfloat)height;

	glViewport(0, 0, width, height);


	glMatrixMode(GL_PROJECTION); 
	glLoadIdentity();          

	gluPerspective(45.0f, aspect, 0.1f, 100.0f);
}

void keys(unsigned char key, int x, int y){
	switch( key ){
		case '1':
			Tman.useTexture("1", &r);
			break;
		case '2':
			Tman.useTexture("2", &r);
			break;
		case '3':
			Tman.useTexture("3", &r);
			break;
		case '4':
			Tman.useTexture("4", &r);
			break;
		case '5':
			Tman.useTexture("5", &r);
			break;
	}

	display();
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE); 
	glutInitWindowSize(640, 480);  
	glutInitWindowPosition(50, 50); 
	glutCreateWindow(title);    
	glutDisplayFunc(display); 
	glutReshapeFunc(reshape); 
	glutKeyboardFunc(keys);
	initGL();
	loadTex();
	glutMainLoop();               
	return 0;
}