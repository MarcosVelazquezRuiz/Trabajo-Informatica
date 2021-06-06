#include "PlatMoviles.h"
#include "freeglut.h"

PlatMoviles::PlatMoviles(float x1, float y1, float x2, float y2) : Pared(x1, y1, x2, y2)
{
	origen.x = x1;
	origen.y = x2;
	limite1.x = x1;
	limite2.x = x2;
	limite1.y = y1;
	limite2.y = y2;
	velocidad.x = 50.0f;
}

void PlatMoviles::Dibuja()
{
	glDisable(GL_LIGHTING);
	glColor3ub(rojo, verde, azul);
	glBegin(GL_POLYGON);
	glVertex3d(limite1.x, limite1.y, 10);
	glVertex3d(limite2.x, limite2.y, 10);
	glVertex3d(limite2.x, limite2.y, -10);
	glVertex3d(limite1.x, limite1.y, -10);
	glEnd();
	glEnable(GL_LIGHTING);
}

void PlatMoviles::Mueve(float t)
{
	if (mov == 1) {
		limite1 = limite1 - velocidad * t - aceleracion * (0.5f * t * t);
		velocidad = velocidad - aceleracion * t;
		limite2 = limite2 - velocidad * t - aceleracion * (0.5f * t * t);
		velocidad = velocidad - aceleracion * t;
		if (limite2.x <= origen.y - 5) {
			mov = 0;
		}
	}
	else if (mov == 0) {
		limite1 = limite1 + velocidad * t + aceleracion * (0.5f * t * t);
		velocidad = velocidad + aceleracion * t;
		limite2 = limite2 + velocidad * t + aceleracion * (0.5f * t * t);
		velocidad = velocidad + aceleracion * t;
		if (limite1.x >= origen.x + 5) {
			mov = 1;
		}
	}
}