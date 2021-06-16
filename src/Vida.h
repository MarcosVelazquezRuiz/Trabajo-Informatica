#pragma once
#include <ETSIDI.h>
#include <Hombre.h>

using ETSIDI::SpriteSequence;

class Vida  {


	SpriteSequence vida{ "imagenes/corazon.png", 2,2,150};
public:
	friend class Interaccion;
	Vida(float x = 0.0, float y = 0.0);
	~Vida();


	float radio;
	void dibuja();
	void mueve();

	void setPos(float x, float y);
	void setRadio(float r);

	Vector2D getPos() { return posicion; }

protected:
	Vector2D posicion;

};