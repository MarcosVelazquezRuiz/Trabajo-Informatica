#pragma once
#include "EnemigoBase.h"
#include "freeglut.h"

EnemigoBase::EnemigoBase() {

	velocidad.x = -3.0f;
	velocidad.y = 0.0f;
	aceleracion.x = 0.0f;
	aceleracion.y = -9.8f;
	damage = 1; //El daño causado por defecto es 1
	vida = 1; //La vida es 1 por defecto
	radio = 1.5f;

	basico.setSize(3, 3);
	basico.setCenter(1.5, 1.5);
}

void EnemigoBase::dibuja() {
	glPushMatrix();
	glTranslatef(posicion.x, posicion.y-0.75, 0);
	if (velocidad.x > 0.01)basico.flip(false, false);
	if (velocidad.x < -0.01)basico.flip(true, false);
	
	basico.draw();
	glPopMatrix();
}
void EnemigoBase::mueve(float t)
{
	posicion = posicion + velocidad * t + aceleracion * (0.5f * t * t);
	velocidad = velocidad + aceleracion * t;
	basico.loop();
}
int EnemigoBase::getVida() {

	return vida; //Devuelve la vida del enemigo
}

EnemigoBase::~EnemigoBase() {


}
