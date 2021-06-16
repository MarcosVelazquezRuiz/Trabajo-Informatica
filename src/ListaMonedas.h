#pragma once
#include <Moneda.h>

#include "Interaccion.h"


#define MAX_Monedas 100

class ListaMonedas
{
public:
	ListaMonedas();
	//virtual ~ListaEsferas();

	bool agregar(Moneda* e);
	void dibuja();
	void mueve();

	void destruirContenido();
	void eliminar(int index);
	void eliminar(Moneda* e);

	Moneda* colision(Hombre& h);
	Moneda* operator [](int i);

	int getNumero() { return numero; }

	int numero;

private:
	Moneda* lista[MAX_Monedas];

};