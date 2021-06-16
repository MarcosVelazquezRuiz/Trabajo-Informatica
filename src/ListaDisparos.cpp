#pragma once
#include "ListaDisparos.h"
#include "Interaccion.h"

ListaDisparos::ListaDisparos(){
	numero = 0;
	for (int i = 0; i < MAX_DISPAROS; i++) {
		lista[i] = 0; 
	}
}

bool ListaDisparos::Agregar(Disparo* d){
	int agregar = 1;
	for (int i = 0; i < MAX_DISPAROS; i++) {
		if (lista[i] == d) {
			agregar = 0;
		}
	}

	if ((numero < MAX_DISPAROS) && (agregar == 1)) {
		lista[numero++] = d; 
	}
	else return false;
	return true;
}

void ListaDisparos::Dibuja(){
	for (int i = 0; i < numero; i++) {
		lista[i]->Dibuja();
	}
}

void ListaDisparos::DestruirContenido(){
	for (int i = 0; i < numero; i++) {
		delete lista[i];
		numero = 0;
	}
}

void ListaDisparos::eliminar(int index){
	if ((index < 0) || (index >= numero))
		return;
	delete lista[index];
	numero--;
	for (int i = index; i < numero; i++)
		lista[i] = lista[i + 1];
}

void ListaDisparos::eliminar(Disparo* d){
	for (int i = 0; i < numero; i++)
		if (lista[i] == d) {
			eliminar(i);
			return;
		}
}
void ListaDisparos::Mueve(float t){
	for (int i = 0; i < numero; i++) {
		lista[i]->mueve(t);
	}
}

Disparo* ListaDisparos::Colision(EnemigoBase& e) {
	for (int i = 0; i < numero; i++) {
		if (Interaccion::colision(*(lista[i]), e)) return lista[i];
	}
}

Disparo* ListaDisparos::colision(ParedVertical &v)
{
	for (int i = 0; i < numero; i++) {
		if (Interaccion::colision(*(lista[i]), v)) return lista[i];
	}
}

Disparo* ListaDisparos::operator[](int i){
	if (i >= numero)//si me paso devuelvo la ultima
		i = numero - 1;
	if (i < 0)//si el indice es negativo devuelvo la primera
		i = 0;
	return lista[i];;
}
