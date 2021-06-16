#include "ListaPlataformas.h"
#include "Interaccion.h"

ListaPlataformas::ListaPlataformas() {
	numero = 0;
	for (int i = 0; i < MAX_PLATAFORMAS; i++) {
		lista[i] = 0;
	}
}
ListaPlataformas::~ListaPlataformas() {

}
void ListaPlataformas::destruirContenido() {
	for (int i = 0; i < numero; i++) {
		delete lista[i];
		numero = 0;
	}
}

bool ListaPlataformas::Agregar(Pared* p) {

	if (numero < MAX_PLATAFORMAS) {
		for (int i = 0; i < numero; i++) {
			if (lista[i] == p) {
				return false;
			}
		}
		lista[numero] = p;
		numero++;
		return true;
	}
	else {
		return false;
	}
}

void ListaPlataformas::Dibuja() {
	for (int i = 0; i < numero; i++) {
		lista[i]->Dibuja();
	}
}

Pared* ListaPlataformas::operator [](int i) {
	if (i >= numero) { //si me paso, devuelvo la ultima 
		i = numero - 1;
	}
	if (i < 0) {//si el indice es negativo, devuelvo la primera 
		i = 0;
		return lista[i];
	}
	return lista[i];
}

bool ListaPlataformas::rebote(Hombre &h)
{
	for (int i = 0; i < numero; i++) {
		if (Interaccion::rebote(h, *(lista[i])))
			return true;
	}
	return false;

}

bool ListaPlataformas::rebote(EnemigoBase &e) {

	for (int i = 0; i < numero; i++) {
		if (Interaccion::rebote(e, *(lista[i])))
			return true;
	}
	return false;
}

void ListaPlataformas::Mueve(float t)
{
	for (int i = 0; i < numero; i++) {
		lista[i]->Mueve(t);
	}
}
