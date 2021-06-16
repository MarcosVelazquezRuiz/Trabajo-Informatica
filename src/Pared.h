#pragma once
#include "Vector2D.h"
#include <ETSIDI.h>

class Pared{
	friend class Interaccion;
	ETSIDI::Sprite* plat;
public:
	Pared(float x1, float y1, float x2, float y2);

	virtual void Dibuja();
	void setPos(float lim1x, float lim1y, float lim2x, float lim2y);
	float distancia(Vector2D punto, Vector2D* direccion = 0);
	virtual void Mueve(float t);
	Vector2D GetPos() { return limite1; };
	Vector2D GetPos(int num);

	Vector2D limite1;
	Vector2D limite2;
};
