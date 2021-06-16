#pragma once
#include "Pared.h"
#include "ObjetoMovil.h"
#include <ETSIDI.h>

class PlatMoviles:public Pared, public ObjetoMovil{
	ETSIDI::Sprite* plat;
protected:
	int mov = 0;
	Vector2D origen;

public:
	PlatMoviles(float x1, float y1, float x2, float y2);
	void Dibuja();
	void Mueve(float t);
};

