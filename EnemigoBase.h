#pragma once
#include "Enemigo.h"

class EnemigoBase:public Enemigo {

protected: //Para que los enemigos derivados lo puedan ver

	ColorRGB color;
	int damage;
	int vida;
	float radio;
public:
	EnemigoBase();
	virtual ~EnemigoBase();
	void dibuja();
	int getVida();

	friend class Interaccion;
};
