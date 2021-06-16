#pragma once
#include <Llave.h>

#include "Interaccion.h"


#define MAX_Llaves 100

class ListaLlaves
{
public:
	ListaLlaves();
	//virtual ~ListaEsferas();

	bool agregar(Llave* e);
	void dibuja();
	void mueve();

	void destruirContenido();
	void eliminar(int index);
	void eliminar(Llave* e);

	Llave* colision(Hombre& h);
	Llave* operator [](int i);

	int getNumero() { return numero; }

	int numero;

private:
	Llave* lista[MAX_Llaves];

};