#pragma once
#include "Hombre.h"
#include "Pared.h"
#include "Interaccion.h"

class  Mundo {
public:

	Hombre hombre;
	Pared paredtest;

	double eyex, eyey, eyez;// posicion del ojo
	double lookx, looky, lookz;      // hacia que punto mira  (0,0,0) 


	void dibuja();


	void mueve();



	void rotarOjo();
	void MoverCamara();
	void inicializa();
	void tecla(unsigned char key);
	void teclaEspecial(unsigned char key);
	void NoPresionoTecla(unsigned char key);


private:

};