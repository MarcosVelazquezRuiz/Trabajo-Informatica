#pragma once
#include "Enemigo.h"
#include "ETSIDI.h"

using ETSIDI::SpriteSequence;

class EnemigoBase:public Enemigo {


	SpriteSequence basico{ "imagenes/slime.png",2,2,200, };


protected: //Para que los enemigos derivados lo puedan ver

	int damage;
	int vida;
	float radio;
public:
	EnemigoBase();
	virtual ~EnemigoBase();
	void dibuja();
	int getVida();
	void mueve(float t);

	friend class Interaccion;
};
