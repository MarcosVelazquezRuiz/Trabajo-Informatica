#include <ListaLlaves.h>


ListaLlaves::ListaLlaves()
{
	numero = 0;
	for (int i = 0; i < MAX_Llaves; i++)
		lista[i] = 0;
}

bool ListaLlaves::agregar(Llave* l)
{
	if (numero < MAX_Llaves)
		lista[numero++] = l; // �ltimo puesto sin rellenar
	else
		return false; // capacidad m�xima alcanzada
	return true;
}
void ListaLlaves::dibuja()
{
	for (int i = 0; i < numero; i++)
		lista[i]->dibuja();
}
void ListaLlaves::mueve()
{
	for (int i = 0; i < numero; i++)
		lista[i]->mueve();
}
void ListaLlaves::destruirContenido()
{
	for (int i = 0; i < numero; i++)
		delete lista[i];
	numero = 0;
}

void ListaLlaves::eliminar(int index)
{
	if ((index < 0) || (index >= numero))
		return;
	delete lista[index];
	numero--;
	for (int i = index; i < numero; i++)
		lista[i] = lista[i + 1];
}

Llave* ListaLlaves::colision(Hombre& h)
{
	for (int i = 0; i < numero; i++) {
		if (Interaccion::colision(*(lista[i]), h))
			return lista[i];
	}
	return 0;
}


void ListaLlaves::eliminar(Llave* e)
{

	for (int i = 0; i < numero; i++)
		if (lista[i] == e) {
			eliminar(i);
			return;
		}

}
Llave* ListaLlaves::operator[](int i)
{
	if (i >= numero)//si me paso devuelvo la ultima
		i = numero - 1;
	if (i < 0)//si el indice es negativo devuelvo la primera
		i = 0;
	return lista[i];;
}
