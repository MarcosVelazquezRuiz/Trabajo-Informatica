#pragma once
#include "Vector2D.h"
#include "ColorRGB.h"
#include "ObjetoMovil.h"

class Enemigo:public ObjetoMovil{

protected: //Para que los enemigos derivados lo puedan ver

	ColorRGB color;
	int damage;
	int vida;
	float radio;
public:
	Enemigo();
	virtual ~Enemigo();
	void dibuja();
	int getVida();

	friend class Interaccion;
};