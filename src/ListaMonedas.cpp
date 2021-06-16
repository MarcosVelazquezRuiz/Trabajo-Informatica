#include <ListaMonedas.h>


ListaMonedas::ListaMonedas()
{
	numero = 0;
	for (int i = 0; i < MAX_Monedas; i++)
		lista[i] = 0;
}

bool ListaMonedas::agregar(Moneda* d)
{
	if (numero < MAX_Monedas)
		lista[numero++] = d; // último puesto sin rellenar
	else
		return false; // capacidad máxima alcanzada
	return true;
}
void ListaMonedas::dibuja()
{
	for (int i = 0; i < numero; i++)
		lista[i]->dibuja();
}
void ListaMonedas::mueve()
{
	for (int i = 0; i < numero; i++)
		lista[i]->mueve();
}
void ListaMonedas::destruirContenido()
{
	for (int i = 0; i < numero; i++)
		delete lista[i];
	numero = 0;
}

void ListaMonedas::eliminar(int index)
{
	if ((index < 0) || (index >= numero))
		return;
	delete lista[index];
	numero--;
	for (int i = index; i < numero; i++)
		lista[i] = lista[i + 1];
}

Moneda* ListaMonedas::colision(Hombre& h)
{
	for (int i = 0; i < numero; i++) {
		if (Interaccion::colision(*(lista[i]), h))
			return lista[i];
	}
	return 0;
}


void ListaMonedas::eliminar(Moneda* e)
{

	for (int i = 0; i < numero; i++)
		if (lista[i] == e) {
			eliminar(i);
			return;
		}

}
Moneda* ListaMonedas::operator[](int i)
{
	if (i >= numero)//si me paso devuelvo la ultima
		i = numero - 1;
	if (i < 0)//si el indice es negativo devuelvo la primera
		i = 0;
	return lista[i];;
}
