
#include "LlavesHUD.h"
#include "freeglut.h"

using namespace std;

LlavesHUD::LlavesHUD() //Constructor
{

	llave.setSize(1, 1);
	llave.setCenter(0.5, 0.5);
}

LlavesHUD::~LlavesHUD() //Destructor
{

}
void LlavesHUD::DibujarTexto(const char* texto, int longitud, int x, int y) {
	glMatrixMode(GL_PROJECTION);
	double* aux = new double[16];
	glGetDoublev(GL_PROJECTION_MATRIX, aux);
	glLoadIdentity();
	glOrtho(0, 1000, 0, 750, -5, 5);
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
void LlavesHUD::Dibuja(Hombre h)
{
	Vector2D posicion = h.getPos();
	int llaves = h.getLlaves();

	glPushMatrix();
	glTranslatef(posicion.x - 11, 7, 0);
	glColor3f(0.0f, 0.0f, 0.0f);
	llave.setState(1);
	llave.draw();

	stringstream sstr;
	string llav;
	sstr << h.getLlaves();

	//sstr << "0";
	llav = sstr.str();
	glDisable(GL_LIGHTING);
	glColor3ub(255,255, 255);
	DibujarTexto(llav.data(), llav.size(), (posicion.x + 2500) * 40 / 640, 604);//x_ojo
	glEnable(GL_LIGHTING);

	glPopMatrix();



}
