#pragma once

#include "Interaccion.h"
#include "ObjetoMovil.h"
#include "EnemigoAvanzado.h"
#define MAX_ENEMIGOS 10

class ListaEnemigosAvanzado :public ObjetoMovil {

public:
	ListaEnemigosAvanzado();
	virtual ~ListaEnemigosAvanzado();
private:
	EnemigoAvanzado* lista[MAX_ENEMIGOS];
	int numero; 
public:
	bool agregar(EnemigoAvanzado* e);
	void dibuja();
	void mueve(float t);
	void destruirContenido();
	void eliminar(int index);
	void eliminar(EnemigoAvanzado* e); 
	int getNumeroEnemigos() { return numero; }
	EnemigoAvanzado* colision(Hombre& h);
	EnemigoAvanzado* operator [](int i);
};
