
#include "MonedasHUD.h"
#include "freeglut.h"

using namespace std;

MonedasHUD::MonedasHUD() //Constructor
{

	moneda.setSize(1, 1);
	moneda.setCenter(0.5, 0.5);
}

MonedasHUD::~MonedasHUD() //Destructor
{

}
void MonedasHUD::DibujarTexto(const char* texto, int longitud, int x, int y) {
	glMatrixMode(GL_PROJECTION);
	double* aux = new double[16];
	glGetDoublev(GL_PROJECTION_MATRIX, aux);
	glLoadIdentity();
	glOrtho(0, 1000, 0, 750, -5, 5); //0,800, 0, 600, -5, 5);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glPushMatrix();
	glLoadIdentity();
	glRasterPos2i(x, y);
	for (int i = 0; i < longitud; i++) {
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, (int)texto[i]);

	}
	glPopMatrix();
	glMatrixMode(GL_PROJECTION);
	glLoadMatrixd(aux);
	glMatrixMode(GL_MODELVIEW);
}
void MonedasHUD::Dibuja(Hombre h)
{
	Vector2D posicion = h.getPos();
	int monedas = h.getMonedas();

	glPushMatrix();
	glTranslatef(posicion.x - 11, 8, 0);
	glColor3f(1.0f, 0.0f, 0.0f);
	moneda.setState(1);
	moneda.draw();

	stringstream sstr;
	string mon;
	sstr << h.getMonedas();
	
	//sstr << "0";
	mon = sstr.str();
	glDisable(GL_LIGHTING);
	glColor3ub(0, 150, 0);
	DibujarTexto(mon.data(), mon.size(), (posicion.x+2500)*40/640 , 637);//x_ojo
	glEnable(GL_LIGHTING);

	glPopMatrix();


	
}
