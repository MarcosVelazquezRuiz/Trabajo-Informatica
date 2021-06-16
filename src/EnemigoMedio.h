#pragma once
#include "Enemigo.h"
#include "ETSIDI.h"

using ETSIDI::SpriteSequence;


class EnemigoMedio:public Enemigo {


	SpriteSequence medio{ "imagenes/volador.png",4,1,200 };

private:
	//Añadir atributos si fuera necesario
	float limite1;
	float limite2;
public:
	EnemigoMedio();
	virtual ~EnemigoMedio();
	void dibuja();
	void mueve(float t);

	friend class Interaccion;
};