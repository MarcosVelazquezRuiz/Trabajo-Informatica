#pragma once
#include "Vector2D.h"
#include "ObjetoMovil.h"
#include "ETSIDI.h"

class Disparo:public ObjetoMovil {
	friend class Interaccion;
public:
	Disparo();
	Disparo(int d,Vector2D Origen);
	virtual ~Disparo();
	void Dibuja();
	void mueve(float t);
	void setVel(float vx, float vy);
	void setPos(float ix, float iy);
	float getRadio();
	bool fuerapantalla();
	Vector2D getPos();
protected:
	ETSIDI::Sprite* disp;
	int orientacion;
	float radio;
	Vector2D origen;
	Vector2D origenDisp;

};
