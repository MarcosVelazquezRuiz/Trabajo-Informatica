#include <ListaVidas.h>


ListaVidas::ListaVidas()
{
	numero = 0;
	for (int i = 0; i < MAX_VIDAS; i++)
		lista[i] = 0;
}

bool ListaVidas::agregar(Vida* d)
{
	if (numero < MAX_VIDAS)
		lista[numero++] = d; // último puesto sin rellenar
	else
		return false; // capacidad máxima alcanzada
	return true;
}
void ListaVidas::dibuja()
{
	for (int i = 0; i < numero; i++)
		lista[i]->dibuja();
}
void ListaVidas::mueve()
{
	for (int i = 0; i < numero; i++)
		lista[i]->mueve();
}
void ListaVidas::destruirContenido()
{
	for (int i = 0; i < numero; i++)
		delete lista[i];
	numero = 0;
}

void ListaVidas::eliminar(int index)
{
	if ((index < 0) || (index >= numero))
		return;
	delete lista[index];
	numero--;
	for (int i = index; i < numero; i++)
		lista[i] = lista[i + 1];
}

Vida* ListaVidas::colision(Hombre& h)
{
	for (int i = 0; i < numero; i++) {
		if (Interaccion::colision(*(lista[i]), h))
			return lista[i];
	}
	return 0;
}


void ListaVidas::eliminar(Vida* e)
{

	for (int i = 0; i < numero; i++)
		if (lista[i] == e) {
			eliminar(i);
			return;
		}

}
Vida* ListaVidas::operator[](int i)
{
	if (i >= numero)//si me paso devuelvo la ultima
		i = numero - 1;
	if (i < 0)//si el indice es negativo devuelvo la primera
		i = 0;
	return lista[i];;
}
