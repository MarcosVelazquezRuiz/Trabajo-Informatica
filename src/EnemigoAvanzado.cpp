#pragma once
#include "EnemigoAvanzado.h"
#include "math.h"

EnemigoAvanzado::EnemigoAvanzado() {

	posicion.x = 9.0f;
	posicion.y = 5.0f;
	velocidad.x = 6.0f;
	velocidad.y = 0.0f;
	aceleracion.x = 0.0f;
	aceleracion.y = 0.0f;
	damage = 3; //El daño causado por defecto es de 3 corazones (muerte inmediata)
	vida = 3; //La vida es 3 por defecto
	radio = 1.0f; //estaba en 0.5
	limiteVertical1 = 12.0f; //Limites definidos para el movimiento del enemigo avanzado
	limiteVertical2 = 0.0f;
	limiteHorizontal1 = 10.0f;
	limiteHorizontal2 = 4.0f;

	fantasma.setSize(2, 1.5);
	fantasma.setCenter(1, 0.75);

}


void EnemigoAvanzado::dibuja() {



	glPushMatrix();
	glTranslatef(posicion.x, posicion.y - 0.75, 0);
	if (velocidad.x < 0)fantasma.flip(false, false);
	if (velocidad.x > 0)fantasma.flip(true, false);

	fantasma.draw();
	glPopMatrix();
}



void EnemigoAvanzado::mueve(float t) {

	ObjetoMovil::mueve(t);
	//Bucle de movimiento
	fantasma.loop();

	if(round(posicion.x) == limiteHorizontal1) {
		//Hacia abajo
		velocidad.y = -6.0f;
		velocidad.x = 0.0f;
	}
	if (round(posicion.y) == limiteVertical2) {
		//Hacia la izquierda
		velocidad.y = 0.0f;
		velocidad.x = -6.0f;
	}
	if (round(posicion.x) == limiteHorizontal2) {
		//Hacia arriba
		velocidad.y = 6.0f;
		velocidad.x = 0.0f;
	}
	if (round(posicion.y) == limiteVertical1 && round(posicion.x) == limiteHorizontal2) {
		//Hacia la derecha
		velocidad.y = 0.0f;
		velocidad.x = 6.0f;
	}
}

void EnemigoAvanzado::setLimites(float limV1, float limV2, float limH1, float limH2) {

	limiteVertical1 = limV1;
	limiteVertical2 = limV2;
	limiteHorizontal1 = limH1;
	limiteHorizontal2 = limH2;
}

EnemigoAvanzado::~EnemigoAvanzado() {


}