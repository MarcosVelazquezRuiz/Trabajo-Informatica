#include "EnemigoMedio.h"

EnemigoMedio::EnemigoMedio() {

	posicion.x = 10.0f;
	posicion.y = 2.0f;
	velocidad.x = 0.0f;
	velocidad.y = 4.0f;
	aceleracion.x = 0.0f;
	//aceleracion.y = -9.8f;
	damage = 2; //El daño causado por defecto es de 2 corazones
	vida = 2; //La vida es 2 por defecto
	radio = 1.5f;
	limite1 = 12.0f; //Limites definidos para el movimiento del enemigo medio
	limite2 = 0.0f;

	medio.setSize(3, 3);
	medio.setCenter(1.5, 1.5);
}

void EnemigoMedio::dibuja() {



	glPushMatrix();
	glTranslatef(posicion.x, posicion.y - 0.75, 0);
	if (velocidad.y > 0.01)medio.flip(false, false);
	if (velocidad.y < -0.01)medio.flip(true, false);

	medio.draw();



	glPopMatrix();
}

void EnemigoMedio::mueve(float t) {

	ObjetoMovil::mueve(t);

	Vector2D vel_inicial = velocidad;
	medio.loop();
	if (posicion.y > limite1) {

		velocidad.y = -vel_inicial.y;
	}
	if (posicion.y < limite2) {

		velocidad.y = -vel_inicial.y;
	}
}

EnemigoMedio::~EnemigoMedio () {


}