#include "mundo.h"
#include "math.h"
#include "freeglut.h"
#include "ETSIDI.h"

void Mundo::rotarOjo() {

	float DistY;
	DistY = sqrt(pow(eyex - lookx, 2) + pow(eyey - looky, 2));
	float theta;
	theta = atan2(eyey, eyex);
	theta += 0.025;

	eyex = DistY * cos(theta);
	eyey = DistY * sin(theta);

}
void Mundo::MoverCamara() {

	float DistY;
	DistY = sqrt(pow(eyex - lookx, 2) + pow(eyey - looky, 2));
	float theta;
	theta = atan2(eyey, eyex); paredtest.Dibuja();
	theta += 0.025;

	eyex = DistY * cos(theta);
	eyey = DistY * sin(theta);

}
void Mundo::inicializa() {
	  // posicion del ojo
	
	hombre.setPos(0, 3);
	paredtest.setColor(0, 150, 0);
	paredtest.setPos(-5, 0, 5, 0);


}

void Mundo::dibuja() {

	gluLookAt(0, 10, 30,  // posicion del ojo
		0, 0, 0,      // hacia que punto mira  (0,0,0) 
		0.0, 1.0, 0.0);

	hombre.Dibuja();
	paredtest.Dibuja();

}

void Mundo::mueve() {

	hombre.mueve(0.025f);
	
	Interaccion::rebote(hombre, paredtest);
	//rotarOjo(); // Aqui veo que puedo usar una funcion dentro de otra

}

void Mundo::tecla(unsigned char key) {
	switch (key){
	
	case ' ':

		if (Interaccion::rebote(hombre, paredtest)) {// Definir algo que cuando este en el "suelo" pueda saltar otra vez
			hombre.Salto(10);;


		}
		break;
	case 'a':
		
		hombre.MovLateral(-5);

			
		//dispder = 0;
		break;

	case 'd':;
		

		hombre.MovLateral(5);

		break;


	}

}
void Mundo::NoPresionoTecla(unsigned char key) {
	switch (key) {
	case 'd':

		hombre.MovLateral(0);

		break;
	case 'a':

		hombre.MovLateral(0);

		break;


	}
}
