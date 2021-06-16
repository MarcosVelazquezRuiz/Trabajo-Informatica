#pragma once
#include "Enemigo.h"
#include "ETSIDI.h"

using ETSIDI::SpriteSequence;

class EnemigoAvanzado:public Enemigo {

	SpriteSequence fantasma{ "imagenes/fantasma2.png",6,1,500 };

private:
	//Añadir atributos si fuera necesario
	float limiteVertical1;
	float limiteVertical2;
	float limiteHorizontal1;
	float limiteHorizontal2;
public:
	EnemigoAvanzado();
	virtual ~EnemigoAvanzado();
	void setLimites(float limV1, float limV2, float limH1, float limH2);
	void mueve(float t);
	void dibuja();

	friend class Interaccion;
};