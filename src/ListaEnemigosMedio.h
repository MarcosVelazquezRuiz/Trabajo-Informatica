#pragma once
#include "Interaccion.h"
#include "ObjetoMovil.h"
#include "EnemigoMedio.h"
#define MAX_ENEMIGOS 100

class ListaEnemigosMedio :public ObjetoMovil {

public:
	ListaEnemigosMedio();
	virtual ~ListaEnemigosMedio();
private:
	//Vector de punteros a objetos de tipo EnemigoMedio (permite asignacion dinamica de memoria)
	EnemigoMedio* lista[MAX_ENEMIGOS];
	int numero; //Contador del numero de objetos de tipo EnemigoMedio que hay en el vector
public:
	bool agregar(EnemigoMedio* e);
	void dibuja();
	void mueve(float t);
	void destruirContenido();
	void eliminar(int index); //Borrado de enemigos por posicion
	void eliminar(EnemigoMedio* e); //Borrado de enemigos por direccion de memoria
	int getNumeroEnemigos() { return numero; }
	EnemigoMedio* colision(Hombre& h);
	EnemigoMedio* operator [](int i);
};

