#pragma once
#include "Pared.h"
#include "ObjetoMovil.h"

class PlatMoviles:public Pared, public ObjetoMovil
{
protected:
	int mov = 0;
	Vector2D origen, limite1, limite2;
	unsigned char rojo, verde, azul;

public:
	PlatMoviles(float x1, float y1, float x2, float y2);
	void Dibuja();
	void Mueve(float t);
};

