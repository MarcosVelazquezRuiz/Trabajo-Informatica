#include "Pared.h"
#include "freeglut.h"
#include "ColorRGB.h"

Pared::Pared(float x1, float y1, float x2, float y2) {
	limite1.x = x1;
	limite1.y = y1;
	limite2.x = x2;
	limite2.y = y2;
}

void Pared::Dibuja()
{
	glDisable(GL_LIGHTING);
	color.ponColor();
	glBegin(GL_POLYGON);
	glVertex3d(limite1.x, limite1.y, 1);
	glVertex3d(limite2.x, limite2.y, 1);
	glVertex3d(limite2.x, limite2.y, -1);
	glVertex3d(limite1.x, limite1.y, -1);
	glEnd();
	glEnable(GL_LIGHTING);
}

void Pared::Mueve(float t) {}

void Pared::setColor(Byte r, Byte v, Byte a)
{
	color.set(r, v, a);
}

void Pared::setPos(float lim1x, float lim1y, float lim2x, float lim2y)
{
	limite1.x = lim1x;
	limite1.y = lim1y;
	limite2.x = lim2x;
	limite2.y = lim2y;
}

float Pared::distancia(Vector2D punto, Vector2D *direccion) {

	Vector2D u = (punto - limite1);
	Vector2D v = (limite2 - limite1).unitario();
	float longitud = (limite1 - limite2).modulo();
	Vector2D dir;
	float valor = u * v;
	float distancia = 0;

	if (valor < 0)
		dir = u;
	else if (valor > longitud)
		dir = (punto - limite2);
	else
		dir = u - v * valor;
	distancia = dir.modulo();
	if (direccion != 0) //si nos dan un vector… 
		*direccion = dir.unitario();
	return distancia;
}