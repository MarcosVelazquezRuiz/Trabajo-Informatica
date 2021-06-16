#pragma once
#include <Vida.h>

#include "Interaccion.h"


#define MAX_VIDAS 100

class ListaVidas
{
public:
	ListaVidas();
	//virtual ~ListaEsferas();

	bool agregar(Vida* e);
	void dibuja();
	void mueve();
	
	void destruirContenido();
	void eliminar(int index);
	void eliminar(Vida* e);

	Vida* colision(Hombre& h);
	Vida* operator [](int i);

	int getNumero() { return numero; }

	int numero;

private:
	Vida* lista[MAX_VIDAS];

};