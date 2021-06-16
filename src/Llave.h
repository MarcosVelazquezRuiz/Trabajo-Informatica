
#pragma once
#include <ETSIDI.h>
#include <Hombre.h>

using ETSIDI::SpriteSequence;

class Llave {
	SpriteSequence llave{ "imagenes/llave.png",2,2,250};
public:
	friend class Interaccion;
	Llave(float x = 0.0, float y = 0.0);
	~Llave();
	float radio;
	void dibuja();
	void mueve();
	void setPos(float x, float y);
	void setRadio(float r);
	Vector2D getPos() { return posicion; }

protected:
	Vector2D posicion;

};