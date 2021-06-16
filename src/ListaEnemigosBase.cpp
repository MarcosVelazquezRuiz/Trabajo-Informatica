#include "ListaEnemigosBase.h"

ListaEnemigosBase::ListaEnemigosBase() {

	//Definicion del constructor
	numero = 0;
	for (int i = 0; i < MAX_ENEMIGOS; i++) {

		lista[i] = 0; //Se ponen a 0 todos los punteros (NULL)
	}
}

bool ListaEnemigosBase::agregar(EnemigoBase *e) {

	int agregar = 1;

	for (int i = 0; i < MAX_ENEMIGOS; i++) {

		if (lista[i] == e) {
			//Si ya existe ese puntero (enemigo) impide que se añada 
			agregar = 0;
		}
	}

	if ((numero < MAX_ENEMIGOS) && (agregar == 1)) {

		lista[numero++] = e; //Si hay hueco se añade el enemigo en el ultimo puesto y se incrementa el contador de enemigos base
	}
	else {

		return false; //capacidad maxima alcanzada
	}
	return true;
}

void ListaEnemigosBase::dibuja() {

	for (int i = 0; i < numero; i++) {
		//Como se almacenan direcciones de memoria en el vector se hace uso del operador ->
		lista[i]->dibuja();
	}
}

void ListaEnemigosBase::mueve(float t) {

	for (int i = 0; i < numero; i++) {

		lista[i]->mueve(t);
	}
}

void ListaEnemigosBase::rebote(Pared p) {

	for (int i = 0; i < numero; i++) {

		Interaccion::rebote(*(lista[i]), p);
	}
}

void ListaEnemigosBase::destruirContenido() {

	for (int i = 0; i < numero; i++) { //Destruccion de enemigos contenidos

		delete lista[i];
		numero = 0; //Inicializa la lista
	}
}

void ListaEnemigosBase::eliminar(int index) {

	if ((index < 0) || (index >= numero)) {

		return;
	}
	delete lista[index];
	numero--; //Se ha borrado un enemigo
	for (int i = index; i < numero; i++) {

		lista[i] = lista[i + 1]; //Eliminación del hueco que se ha creado en el vector (se desplaza todo una posicion a la izq)
	}
}

void ListaEnemigosBase::eliminar(EnemigoBase *e) {

	for (int i = 0; i < numero; i++) {

		if (lista[i] == e) {

			eliminar(i);
			return;
		}
	}
}

EnemigoBase* ListaEnemigosBase::colision(Hombre &h) {

	for (int i = 0; i < numero; i++) {

		if (Interaccion::contacto(h, *(lista[i]))) {

			return lista[i];
		}
	}
	return 0; //no hay colisión
}

EnemigoBase* ListaEnemigosBase::operator [](int i) {

	if (i >= numero) {
		//si me paso, devuelvo la ultima
		i = numero - 1;
	}
	if (i < 0) {
		//si el indice es negativo, devuelvo la primera
		i = 0;
	}
	return lista[i]; //Devuelve el puntero donde esta situada la esfera indicada
}

EnemigoBase* ListaEnemigosBase::getEnemigo(int i) {

	return lista[i];
}

ListaEnemigosBase::~ListaEnemigosBase() {


}