#include "Hombre.h"
#include "freeglut.h"
#include "ETSIDI.h"
#include <math.h>

Hombre::Hombre() {

	rojo = verde = azul = 255;
	altura = 2;
	vida = 3; //3 corazones de vida
	sprite.setCenter(2, 2);
	sprite.setSize(4, 4);
	aceleracion.y = -9.8;
}

void Hombre::Dibuja()
{
	glPushMatrix();
	glTranslatef(posicion.x, posicion.y, 0);
	glColor3f(1.0f, 0.0f, 0.0f);
//  glutSolidSphere(altura, 20, 20);
	if (velocidad.x > 0.01)sprite.flip(false, false);
	if (velocidad.x < -0.01)sprite.flip(true, false);
	if ((velocidad.x < 0.01) && (velocidad.x > -0.01))
		sprite.setState(0);
	else if (sprite.getState() == 0)
		sprite.setState(1, false);
	sprite.draw();
	glPopMatrix();

}


float Hombre::getAltura()
{
	return altura;
}

void Hombre::mueve(float t)
{
	posicion = posicion + velocidad * t + aceleracion * (0.5f * t * t);
	velocidad = velocidad + aceleracion * t;
	sprite.loop();
}

void Hombre::MovLateral(float VelocidadInicial) {

	Vector2D vel = getVel();
	

	setVel(VelocidadInicial, vel.y);

}

void Hombre::Salto(float altura) {
	Vector2D acel = getAc();
	Vector2D vel = getVel();
	setAc(0,-9.8);

	setVel(vel.x, altura);

}


