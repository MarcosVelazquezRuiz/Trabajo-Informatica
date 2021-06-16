#pragma once
#define MAX_DISPAROS 10


#include "Disparo.h"
#include "Hombre.h"
#include "EnemigoBase.h"
#include "Interaccion.h"

class ListaDisparos{
public:
	ListaDisparos();
	bool Agregar(Disparo* d); 
	void Dibuja();
	void Mueve(float t);

	void DestruirContenido(); 
	void eliminar(int index);
	void eliminar(Disparo* d);
	
	Disparo* Colision(EnemigoBase& e);
	Disparo* colision(ParedVertical& v);
	Disparo* operator [](int i);

	int getNumero() { return numero; }
	friend class Interaccion;
private:
	Disparo* lista[MAX_DISPAROS];
	int numero;
};

