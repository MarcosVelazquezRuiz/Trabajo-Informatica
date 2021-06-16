#pragma once
#define MAX_PLATAFORMASVERTICALES 200

#include "ParedVertical.h"
#include "Hombre.h"

class ListaPlataformasVerticales
{
public:
	ListaPlataformasVerticales();
	bool Agregar(ParedVertical* p);
	void Dibuja();
	int getNum() { return numero; }
	ParedVertical* operator [] (int i);

	bool rebote(Hombre& h);
private:
	ParedVertical* lista[MAX_PLATAFORMASVERTICALES];
	int numero;
};

