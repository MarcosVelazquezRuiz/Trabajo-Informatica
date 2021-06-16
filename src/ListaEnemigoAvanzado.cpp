#include "ListaEnemigoAvanzado.h"

ListaEnemigosAvanzado::ListaEnemigosAvanzado() {

	numero = 0;
	for (int i = 0; i < MAX_ENEMIGOS; i++) {

		lista[i] = 0; 
	}
}

bool ListaEnemigosAvanzado::agregar(EnemigoAvanzado *e) {

	int agregar = 1;

	for (int i = 0; i < MAX_ENEMIGOS; i++) {

		if (lista[i] == e) {
			
			agregar = 0;
		}
	}

	if ((numero < MAX_ENEMIGOS) && (agregar == 1)) {

		lista[numero++] = e; 
	}
	else {

		return false;
	}
	return true;
}

void ListaEnemigosAvanzado::dibuja() {

	for (int i = 0; i < numero; i++) {
		
		lista[i]->dibuja();
	}
}

void ListaEnemigosAvanzado::mueve(float t) {

	for (int i = 0; i < numero; i++) {

		lista[i]->mueve(t);
	}
}

void ListaEnemigosAvanzado::destruirContenido() {

	for (int i = 0; i < numero; i++) { 

		delete lista[i];
		numero = 0; 
	}
}

void ListaEnemigosAvanzado::eliminar(int index) {

	if ((index < 0) || (index >= numero)) {

		return;
	}
	delete lista[index];
	numero--; 
	for (int i = index; i < numero; i++) {

		lista[i] = lista[i + 1]; 
	}
}

void ListaEnemigosAvanzado::eliminar(EnemigoAvanzado *e) {

	for (int i = 0; i < numero; i++) {

		if (lista[i] == e) {

			eliminar(i);
			return;
		}
	}
}

EnemigoAvanzado* ListaEnemigosAvanzado::colision(Hombre &h) {

	for (int i = 0; i < numero; i++) {

		if (Interaccion::contacto(h, *(lista[i]))) {

			return lista[i];
		}
	}
	return 0; //no hay colisión
}

EnemigoAvanzado* ListaEnemigosAvanzado::operator [](int i) {

	if (i >= numero) {
		
		i = numero - 1;
	}
	if (i < 0) {
		
		i = 0;
	}
	return lista[i]; 
}

ListaEnemigosAvanzado::~ListaEnemigosAvanzado() {


}