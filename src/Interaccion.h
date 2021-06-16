#pragma once

#include "Hombre.h" 
#include "Pared.h" 
#include "EnemigoBase.h"
#include "EnemigoMedio.h"
#include "EnemigoAvanzado.h"
#include "Disparo.h"
#include "ParedVertical.h"
#include "Vida.h"
#include "Moneda.h"
#include "Llave.h"
class Interaccion
{
public:

	static bool rebote(Hombre& h, Pared c);//Estan ya en la memoria
	static bool rebote(Hombre& h, ParedVertical v);

	static bool rebote(EnemigoBase& e, Pared c);
	static bool contacto(Hombre& h, EnemigoBase& e);
	static bool contacto(Hombre& h, EnemigoMedio& e);
	static bool contacto(Hombre& h, EnemigoAvanzado& e);


	static bool colision(Disparo d, ParedVertical v);
	static bool colision(Disparo d, Pared p);
	static bool colision(Disparo& d, EnemigoBase& e);
	static bool colision(Disparo& d, EnemigoMedio& e);
	static bool colision(Disparo& d, EnemigoAvanzado& e);


	static bool colision(Vida e, Hombre &h);
	static bool colision(Moneda e, Hombre &h);
	static bool colision(Llave l, Hombre& h);
};