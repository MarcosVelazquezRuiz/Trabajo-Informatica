#pragma once

#include "Hombre.h" 
#include "Pared.h" 
#include "EnemigoBase.h"
#include "mundo.h"


class Interaccion
{
public:

	static bool rebote(Hombre& h, Pared c);//Estan ya en la memoria
	static bool rebote(EnemigoBase &e, Pared c);
	static int contacto(Hombre &h, EnemigoBase &e);
};