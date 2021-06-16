#pragma once
#include "Disparo.h"
#include "freeglut.h"
#include "ETSIDI.h"


Disparo::Disparo() {
	radio = 0.15f;
	velocidad.x = 20.f;
}

Disparo::Disparo(int d,Vector2D orgn) {
	radio = 0.15f;
	origen = orgn;
	origenDisp = orgn;
	velocidad.x = 20.0f;
	orientacion = d;
	disp = new ETSIDI::Sprite("imagenes/flecha.png", orgn.x, orgn.y, 2, 2);
}

Disparo::~Disparo()
{
}

void Disparo::mueve(float t) {

	if (orientacion == 1) {
		ObjetoMovil::mueve(t);
		if (posicion.x >= origen.x + 3.5) {
			origen = origen + velocidad * t + aceleracion * (0.5f * t * t);
		}
		else if (posicion.x <= origen.x - 3.5) {
			origen = origen + velocidad * t + aceleracion * (0.5f * t * t);
		}
	}
	else if (orientacion == 0) {
		posicion = posicion - velocidad * t - aceleracion * (0.5f * t * t);
		velocidad = velocidad - aceleracion * t;
		if (posicion.x >= origen.x + 3.5) {
			origen = origen - velocidad * t - aceleracion * (0.5f * t * t);
		}
		else if (posicion.x <= origen.x - 3.5) {
			origen = origen - velocidad * t - aceleracion * (0.5f * t * t);
		}
	}
	disp->loop();
}
void Disparo::Dibuja() {
	disp->setPos(posicion.x, posicion.y);
	if (orientacion == 1) disp->flip(false, false);
	else if (orientacion == 0)disp->flip(true, true);
		disp->draw();

}

void Disparo::setVel(float vx, float vy){
	velocidad.x = vx;
	velocidad.y = vy;
}

void Disparo::setPos(float ix, float iy){
	origen.x = ix;
	origen.y = iy;
	posicion.x = ix;
	posicion.y = iy;
	origenDisp.x = ix;
	origenDisp.y = iy;
}
bool Disparo::fuerapantalla() {
	if (origen.x <= origenDisp.x - 11 || origen.x >= origenDisp.x + 11) return true;
	else return false;
}
float Disparo::getRadio()
{
	return radio;
}

Vector2D Disparo::getPos()
{
	return posicion;
}

