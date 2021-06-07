#pragma once
#include "Hombre.h"
#include "Pared.h"
#include "Interaccion.h"
#include "ListaPlataformas.h"
#include "PlatMoviles.h"
#include "EnemigoBase.h"

class  Mundo {
public:

	Hombre hombre;
	EnemigoBase enemigo;
	EnemigoBase enemigo1;
	EnemigoBase enemigo2;
	EnemigoBase enemigo3;
	//Pared paredtest;
	//Pared plataforma;
	ListaPlataformas plataformas;

	double eyex, eyey, eyez;// posicion del ojo
	double lookx, looky, lookz;      // hacia que punto mira  (0,0,0) 

	Mundo();

	void dibuja();
	void mueve();
	void rotarOjo();
	void MoverCamara();
	void inicializa();
	void tecla(unsigned char key);
	void teclaEspecial(unsigned char key);
	void NoPresionoTecla(unsigned char key);

	bool GetMuerte() { return muerte; }
	bool GetFin() { return FinNivel; }
	int GetNivel() { return nivel; }

	bool cargarNivel();
	void reset();

private:
	int nivel;
	bool FinNivel;
	bool muerte;

};