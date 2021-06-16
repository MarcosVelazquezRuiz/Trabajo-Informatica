#include "ObjetoMovil.h"

void ObjetoMovil::mueve(float t)
{
	posicion = posicion + velocidad * t + aceleracion * (0.5f * t * t);
	velocidad = velocidad + aceleracion * t;
}
void ObjetoMovil::setPos(float x, float y) {

	posicion.x = x;
	posicion.y = y;

}
void ObjetoMovil::setVel(float vx, float vy) {

	velocidad.x = vx;
	velocidad.y = vy;

}
void ObjetoMovil::setAc(float ax, float ay)
{
	aceleracion.x = ax;
	aceleracion.y = ay;
}

