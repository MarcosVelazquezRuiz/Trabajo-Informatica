#pragma once
#include "Vector2D.h"
#include "ColorRGB.h"

class Pared
{

	friend class Interaccion;

public:
	Pared(float x1, float y1, float x2, float y2);
//virtual ~Pared();
	

	void Dibuja();
	void setColor(Byte r, Byte v, Byte a);
	void setPos(float lim1x, float lim1y, float lim2x, float lim2y);
	float distancia(Vector2D punto, Vector2D* direccion = 0);
	void Mueve(float t);

private:

	ColorRGB color;

	Vector2D limite1;
	Vector2D limite2;
};

