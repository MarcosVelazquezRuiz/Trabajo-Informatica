#pragma once
#define MAX_PLATAFORMAS 200

#include "Pared.h"
#include "Hombre.h"
#include "EnemigoBase.h"

class ListaPlataformas {
public:
	ListaPlataformas();
	virtual ~ListaPlataformas();
	bool Agregar(Pared* p);
	void Dibuja();
	void Mueve(float t);
	int getNum() { return numero; }

	virtual void destruirContenido();

	Pared* operator [](int i);
	bool rebote(EnemigoBase &e);
	bool rebote(Hombre &h);
private:
	Pared* lista[MAX_PLATAFORMAS];
	int numero;
};

