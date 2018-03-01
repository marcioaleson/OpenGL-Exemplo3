#include <GL/gl.h>
#include <GL/glext.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <time.h>
#include <windows.h>

static int elbow = 0, fist = 0, forefinger =0, middlefinger =0, thumb = 0;
GLfloat shoulder = 0.0;

void init(void){
	glClearColor (0.0, 0.0, 0.0, 0.0);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);
}

void display(void){
	glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	//Braço
	glPushMatrix();
    glRotatef (-90.0, 0.0, 0.0, 1.0);
    glTranslatef(1.25, 0.0, 0.0);
    glTranslatef(0.0, shoulder, 0.0);

    glPushMatrix();
    glScalef (2.0, 0.5, 0.5);
    glColor3f(1.0, 0.0, 0.0);
    glutSolidCube (1.0);
    glPopMatrix();

    glTranslatef (1.0, 0.0, 0.0);
    glRotatef ((GLfloat) elbow, 0.0, 0.0, 1.0);
    glTranslatef(1.0, 0.0, 0.0);
    //Antebraço
    glPushMatrix();
    glScalef (2.0, 0.5, 0.5);
    glColor3f(0.0, 0.0, 1.0);
    glutSolidCube (1.0);
    glPopMatrix();
    //Cotovelo
    glPushMatrix();
    glTranslatef (-1.0, 0.0, 0.0);
    glColor3f(1.0, 0.0, 1.0);
    glutSolidTorus(0.5, 0.0, 20.0, 20.0);
    glPopMatrix();

    //Punho
    glPushMatrix();
    glRotatef((GLfloat) fist, 1.0, 0.0, 0.0);
    glColor3f(1.0, 1.0, 0.0);
    glTranslatef(1.25, 0.0, 0.0);
    glutSolidCube(0.5);
    glColor3f(0.0, 1.0, 1.0);
    //Indicador
    glPushMatrix();
    glTranslatef(0.25, 0.25, 0.15);
    glRotatef((GLfloat) -forefinger, 0.0, 0.0, 1.0);
    glTranslatef(0.25, 0.0, 0.0);
    glScalef(0.5, 0.1, 0.1);
    glutSolidCube(1.0);
    glPopMatrix();
    //Médio
    glPushMatrix();
    glColor3f(1.0, 0.5, 0.0);
    glTranslatef(0.25, 0.25, -0.15);
    glRotatef((GLfloat) -middlefinger, 0.0, 0.0, 1.0);
    glTranslatef(0.25, 0.0, 0.0);
    glScalef(0.5, 0.1, 0.1);
    glutSolidCube(1.0);
    glPopMatrix();
    //Polegar
    glPushMatrix();
    glColor3f(1.0, 1.0, 1.0);
    glTranslatef(0.25, -0.25, 0.0);
    glRotatef((GLfloat) thumb, 0.0, 0.0, 1.0);
    glTranslatef(0.25, 0.0, 0.0);
    glScalef(0.5, 0.1, 0.1);
    glutSolidCube(1.0);
    glPopMatrix();
    glPopMatrix();
	glPopMatrix();
	//Base
	glPushMatrix();
    glScalef(6.0, 0.5, 0.5);
    glColor3f(0.0, 1.0, 0.0);
    glutSolidCube(1.0);
	glPopMatrix();
	glutSwapBuffers();
}

void reshape (int w, int h){
  glViewport (0, 0, (GLsizei) w, (GLsizei) h);
  glMatrixMode (GL_PROJECTION);
  glLoadIdentity ();
  gluPerspective(65.0, (GLfloat) w/(GLfloat) h, 1.0, 20.0);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  glTranslatef (0.0, 0.0, -5.0);
  glTranslatef(0.0, 2.0, 0.0);
}

void keyboard (unsigned char key, int x, int y){
	switch (key) {
		case 'c':

			if((elbow + 5) % 360 < 90.0){
				elbow = (elbow + 5) % 360;
				glutPostRedisplay();

			}
			break;
		case 'C':

			if((elbow - 5) % 360 > -90.0){
				elbow = (elbow - 5) % 360;
				glutPostRedisplay();

			}
			break;
		case 'o':
			if(shoulder + 0.09 < 2.65){
				shoulder += 0.09;
				glutPostRedisplay();
			}
			break;
		case 'O':

			if(shoulder - 0.09 > -2.65){
				shoulder -= 0.09;
				glutPostRedisplay();
			}

			break;
		case 'p':

			fist = (fist + 5) % 360;
			glutPostRedisplay();

			break;
		case 'P':

			fist = (fist - 5) % 360;
			glutPostRedisplay();

			break;
		case 'u':

			if((forefinger + 5) % 360 < 30)
				forefinger = (forefinger + 5) % 360;
			if((middlefinger + 5) % 360 < 30)
				middlefinger = (middlefinger + 5) % 360;
			if((thumb + 5) % 360 < 30)
				thumb = (thumb + 5) % 360;
			glutPostRedisplay();

			break;
		case 'U':

			if((forefinger - 5) % 360 > -30)
				forefinger = (forefinger - 5) % 360;
			if((middlefinger - 5) % 360 > -30)
				middlefinger = (middlefinger - 5) % 360;
			if((thumb - 5) % 360 > -30)
				thumb = (thumb - 5) % 360;
			glutPostRedisplay();

			break;
		case 'i':

			if((forefinger + 5) % 360 < 30)
				forefinger = (forefinger + 5) % 360;
			glutPostRedisplay();
			break;
		case 'I':
			if((forefinger - 5) % 360 > -30)
				forefinger = (forefinger - 5) % 360;
			glutPostRedisplay();

			break;
		case 'd':

			if((thumb + 5) % 360 < 30)
				thumb = (thumb + 5) % 360;
			glutPostRedisplay();

			break;
		case 'D':

			if((thumb - 5) % 360 > -30)
				thumb = (thumb - 5) % 360;
			glutPostRedisplay();

			break;
		case 'm':

			if((middlefinger + 5) % 360 < 30)
				middlefinger = (middlefinger + 5) % 360;
			glutPostRedisplay();

			break;
		case 'M':

			if((middlefinger - 5) % 360 > -30)
				middlefinger = (middlefinger - 5) % 360;
			glutPostRedisplay();

			break;
		case 27:

			exit(0);

			break;
		default:
			break;
	}
}

int main(int argc, char** argv){
  glutInit(&argc, argv);
  glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
  glutInitWindowSize (500, 500);
  glutInitWindowPosition (100, 100);
  glutCreateWindow (argv[0]);
  init ();
  glutDisplayFunc(display);
  glutReshapeFunc(reshape);
  glutKeyboardFunc(keyboard);
  glutMainLoop();
  return 0;
}
