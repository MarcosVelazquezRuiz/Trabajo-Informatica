#pragma once
#include "Enemigo.h"
#include "freeglut.h"

Enemigo::Enemigo() {

	
}

void Enemigo::dibuja() {

	glTranslatef(posicion.x, posicion.y, 0);
	glutSolidSphere(radio, 20, 20);
	glTranslatef(-posicion.x, -posicion.y, 0);
}

int Enemigo::getVida() {

	return vida; //Devuelve la vida del enemigo
}

Enemigo::~Enemigo() {


}
