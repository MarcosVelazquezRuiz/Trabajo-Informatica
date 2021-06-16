#pragma once
#include "Vector2D.h"
#include "ETSIDI.h"
#include "Pared.h"

class Puerta : public Pared {
	ETSIDI::Sprite* puerta;
	
public:
	Puerta(float x1 = 0.0f, float y1 = 0.0f, float x2 = 0.0f, float y2 = 0.0f);
	virtual ~Puerta();
	void Dibuja();
	void SetPos(float lim1x, float lim1y, float lim2x, float lim2y);
	
};
