#pragma once
#include "EnemigoBase.h"
#include "freeglut.h"

EnemigoBase::EnemigoBase() {

	posicion.x = 5.0f;
	posicion.y = 2.0f;
	velocidad.x = -3.0f;
	velocidad.y = 0.0f;
	aceleracion.x = 0.0f;
	aceleracion.y = -9.8f;
	damage = 1; //El da�o causado por defecto es 1
	radio = 1.0f;
	color.r = 255; //El enemigo es blanco por defecto
	color.g = 255;
	color.b = 255;
}

void EnemigoBase::dibuja() {

	glTranslatef(posicion.x, posicion.y, 0);
	glutSolidSphere(radio, 20, 20);
	glTranslatef(-posicion.x, -posicion.y, 0);
}

int EnemigoBase::getVida() {

	return vida; //Devuelve la vida del enemigo
}

EnemigoBase::~EnemigoBase() {


}
