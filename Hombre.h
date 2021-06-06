#pragma once
#include "Vector2D.h"
#include "ObjetoMovil.h"
#include "ETSIDI.h"

using ETSIDI::SpriteSequence;

class Hombre:public ObjetoMovil
{

	friend class Interaccion;

public:
	Hombre();
//	virtual ~Hombre();
	

	void Dibuja();
	float getAltura();
	void mueve(float t);
	void MovLateral(float VelocidadInicial);
	void Salto(float altura);


private:
	float altura;

	unsigned char rojo;
	unsigned char verde;
	unsigned char azul;

	SpriteSequence sprite{ "imagenes/MedievalRangerRun.png", 8 };

};

