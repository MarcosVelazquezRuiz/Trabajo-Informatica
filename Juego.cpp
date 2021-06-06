#include "ETSIDI.h"
#include "freeglut.h"
#include <iostream>
<<<<<<< Updated upstream
#include "Coordinador.h"



using namespace std;

Coordinador coordinador;

=======
#include "Mundo.h"

using namespace std;
using namespace ETSIDI;

Mundo mundo;
>>>>>>> Stashed changes

//los callback, funciones que seran llamadas automaticamente por la glut
//cuando sucedan eventos
//NO HACE FALTA LLAMARLAS EXPLICITAMENTE
void OnDraw(void); //esta funcion sera llamada para dibujar
void OnTimer(int value); //esta funcion sera llamada cuando transcurra una temporizacion
void OnKeyboardDown(unsigned char key, int x, int y); //cuando se pulse una tecla	
void onSpecialKeyboardDown(int key, int x, int y); //Tecla especial
void OnKeyboardUp(unsigned char key, int x, int y);


int main(int argc, char* argv[])
{
	//Inicializar el gestor de ventanas GLUT
	//y crear la ventana
	glutInit(&argc, argv);
	glutInitWindowSize(800, 600);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutCreateWindow("Juego Computatis");

	//habilitar luces y definir perspectiva
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHTING);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_COLOR_MATERIAL);
	glMatrixMode(GL_PROJECTION);
	gluPerspective(40.0, 800 / 600.0f, 0.1, 150);

	//Registrar los callbacks
	glutDisplayFunc(OnDraw);
	glutTimerFunc(25, OnTimer, 0);//le decimos que dentro de 25ms llame 1 vez a la funcion OnTimer()
	glutKeyboardFunc(OnKeyboardDown);
	glutSpecialFunc(onSpecialKeyboardDown); //gestion de los cursores
	glutKeyboardUpFunc(OnKeyboardUp);
<<<<<<< Updated upstream
	
	//Inicialización de la escena


=======
	//Inicialización de la escena
	mundo.inicializa();
>>>>>>> Stashed changes

	//pasarle el control a GLUT,que llamara a los callbacks
	glutMainLoop();

	return 0;
}

void OnDraw(void)
{
	//Borrado de la pantalla	
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//Para definir el punto de vista
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	
<<<<<<< Updated upstream
	coordinador.Dibuja();
=======
	mundo.dibuja();
>>>>>>> Stashed changes
	
	

	//no borrar esta linea ni poner nada despues
	glutSwapBuffers();
}
void OnKeyboardDown(unsigned char key, int x_t, int y_t)
{
	//poner aqui el código de teclado
<<<<<<< Updated upstream
	
	coordinador.Tecla(key);
	
=======
	mundo.tecla(key);
>>>>>>> Stashed changes

	glutPostRedisplay();
}

void onSpecialKeyboardDown(int key, int x, int y)
{
	
}

void OnTimer(int value)
{
	//poner aqui el código de animacion
<<<<<<< Updated upstream
	
	coordinador.Mueve();
=======
	mundo.mueve();
>>>>>>> Stashed changes

	//no borrar estas lineas
	glutTimerFunc(25, OnTimer, 0);
	glutPostRedisplay();
}
<<<<<<< Updated upstream

void OnKeyboardUp(unsigned char key, int x, int y) 
{
	coordinador.NoPresionoTecla(key);
=======
void OnKeyboardUp(unsigned char key, int x, int y) {

	mundo.NoPresionoTecla(key);
>>>>>>> Stashed changes
}
