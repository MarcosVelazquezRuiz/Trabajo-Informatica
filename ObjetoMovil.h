#pragma once
#include "Vector2D.h"

class ObjetoMovil {

	friend class Interaccion;

public:
	void mueve(float t);

	void setPos(float x, float y);
	void setVel(float vx, float vy);
	void setAc(float ax, float ay);

	Vector2D getPos() { return posicion; }
	Vector2D getVel() { return velocidad; }
	Vector2D getAc() { return aceleracion; }

protected:
	Vector2D posicion;
	Vector2D velocidad;
	Vector2D aceleracion;
};