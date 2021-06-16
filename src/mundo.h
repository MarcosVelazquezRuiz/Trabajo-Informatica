#pragma once
#include "Hombre.h"
#include "Pared.h"
#include "Interaccion.h"
#include "ListaPlataformas.h"
#include "PlatMoviles.h"
#include "EnemigoBase.h"
#include "Disparo.h"
#include "ListaDisparos.h"
#include "ParedVertical.h"
#include "ListaPlataformasVerticales.h"
#include "Vida.h"
#include "ListaVidas.h"
#include "Moneda.h"
#include "ListaMonedas.h"
#include "ListaEnemigosBase.h"
#include "ListaEnemigosMedio.h"
#include "ListaEnemigoAvanzado.h"
#include "Puerta.h"
#include "VidaHUD.h"
#include "MonedasHUD.h"
#include "Llave.h"
#include "ListaLlaves.h"
#include "LlavesHUD.h"
class  Mundo {
public:

	Hombre hombre;
	
	ListaPlataformas plataformas;
	ListaDisparos disparos;
	ListaPlataformasVerticales verticales;
	ListaVidas corazones;
	ListaMonedas monedas;
	ListaLlaves llaves;
	Puerta puerta;

	VidaHUD barravida;
	MonedasHUD monedero;
	LlavesHUD llavero;
	ListaEnemigosBase enemigosBase;
	ListaEnemigosMedio enemigosMedio;
	ListaEnemigosAvanzado enemigosAvanzado;

	double eyex, eyey, eyez;// posicion del ojo
	double lookx, looky, lookz;      // hacia que punto mira  (0,0,0) 

	Mundo();
	virtual ~Mundo();

	void dibuja();
	void mueve();
	void inicializa();
	void tecla(unsigned char key);
	void teclaEspecial(unsigned char key);
	void NoPresionoTecla(unsigned char key);
	
	bool GetMuerte() { return muerte; }
	bool GetFin() { return FinNivel; }
	int GetNivel() { return nivel; }

	void setNivel(int n) { nivel = n; }
	void setMuerte(bool m) { muerte = m; }

	int camara=30;

	bool cargarNivel();
	void reset();

	

private:
	
	bool FinNivel;
	int nivel;
	bool muerte;
	int orientacion = 1;
	
};