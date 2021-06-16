#pragma once
#include "Interaccion.h"
#include "ObjetoMovil.h"
#include "ListaPlataformas.h"
#define MAX_ENEMIGOS 100

class ListaEnemigosBase:public ObjetoMovil {

public:
	ListaEnemigosBase();
	virtual ~ListaEnemigosBase();
private:
	//Vector de punteros a objetos de tipo EnemigoBase (permite asignacion dinamica de memoria)
	EnemigoBase* lista[MAX_ENEMIGOS];
	int numero; //Contador del numero de objetos de tipo EnemigoBase que hay en el vector
public:
	bool agregar(EnemigoBase* e);
	void dibuja();
	void mueve(float t);
	void rebote(Pared p);
	void destruirContenido();
	void eliminar(int index); //Borrado de enemigos por posicion
	void eliminar(EnemigoBase* e); //Borrado de enemigos por direccion de memoria
	EnemigoBase* getEnemigo(int i);
	int getNumeroEnemigos() { return numero; };
	EnemigoBase* colision(Hombre& h);
	EnemigoBase* operator [](int i);
};