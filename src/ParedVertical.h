#pragma once
#include "Pared.h"
#include <ETSIDI.h>

class ParedVertical
{
	friend class Interaccion;
	ETSIDI::Sprite* vert;
public:
	ParedVertical(float x1, float y1, float x2, float y2);

	void Dibuja();
	void setPos(float lim1x, float lim1y, float lim2x, float lim2y);
	float distancia(Vector2D punto, Vector2D* direccion = 0);
	
	Vector2D limitev1;
	Vector2D limitev2;

};

