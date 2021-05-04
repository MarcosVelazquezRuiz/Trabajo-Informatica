#pragma once

class  Mundo {
public:

	double eyex, eyey, eyez;// posicion del ojo
	double lookx, looky, lookz;      // hacia que punto mira  (0,0,0) 


	void Dibuja();


	void Mueve();



	void rotarOjo();
	void inicializa();
	void tecla(unsigned char key);



private:

};