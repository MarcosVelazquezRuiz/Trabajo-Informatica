
#pragma once
#include <ETSIDI.h>
#include <Hombre.h>

using ETSIDI::SpriteSequence;

class Moneda {


	SpriteSequence moneda{ "imagenes/gema.png",4,1,150 };
public:
	friend class Interaccion;
	Moneda(float x = 0.0, float y = 0.0);
	~Moneda();


	float radio;
	void dibuja();
	void mueve();

	void setPos(float x, float y);
	void setRadio(float r);

	Vector2D getPos() { return posicion; }

protected:
	Vector2D posicion;

};