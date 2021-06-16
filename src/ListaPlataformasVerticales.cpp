#include "ListaPlataformasVerticales.h"
#include "Interaccion.h"

ListaPlataformasVerticales::ListaPlataformasVerticales() {
	numero = 0;
	for (int i = 0; i < MAX_PLATAFORMASVERTICALES; i++) {
		lista[i] = 0;
	}
}

bool ListaPlataformasVerticales::Agregar(ParedVertical* p) {
	if (numero < MAX_PLATAFORMASVERTICALES) {
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

void ListaPlataformasVerticales::Dibuja() {
	for (int i = 0; i < numero; i++) {
		lista[i]->Dibuja();
	}
}

ParedVertical* ListaPlataformasVerticales::operator [](int i) {
	if (i >= numero) { //si me paso, devuelvo la ultima 
		i = numero - 1;
	}
	if (i < 0) {//si el indice es negativo, devuelvo la primera 
		i = 0;
		return lista[i];
	}
	return lista[i];
}

bool ListaPlataformasVerticales::rebote(Hombre& h)
{
	for (int i = 0; i < numero; i++) {
		if (Interaccion::rebote(h, *(lista[i])))
			return true;
	}
	return false;

}