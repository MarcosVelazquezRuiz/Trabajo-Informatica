#pragma once
#include "Vector2D.h"
#include "ObjetoMovil.h"
#include "ETSIDI.h"
#include "Puerta.h"

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
	int getVida();
	int getMonedas();
	int getLlaves();
	void setVida(int v);
	void setMonedas(int v);
	void setLlaves(int v);
	bool Choque(Hombre h, Puerta p);

private:
	float altura;
	int vida;
	int monedas;
	int llaves;
	SpriteSequence sprite{ "imagenes/MedievalRangerRun.png", 8 };

};

