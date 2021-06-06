#pragma once
#define MAX_PLATAFORMAS 200

#include "Pared.h"
#include "Hombre.h"

class ListaPlataformas {
public:
	ListaPlataformas();
	bool Agregar(Pared* p);
	void Dibuja();
	void Mueve(float t);
	int getNum() { return numero; }
	Pared* operator [](int i);
	
	bool rebote(Hombre &h);
private:
	Pared* lista[MAX_PLATAFORMAS];
	int numero;
};

