#include "mundo.h"
#include "math.h"
#include "freeglut.h"

void Mundo::rotarOjo() {

	float DistY;
	DistY = sqrt(pow(eyex - lookx, 2) + pow(eyey - looky, 2));
	float theta;
	theta = atan2(eyey, eyex);
	theta += 0.025;

	eyex = DistY * cos(theta);
	eyey = DistY * sin(theta);

}
void Mundo::inicializa() {
	eyex = 20;
	eyey = 20; 
	eyez = 20;  // posicion del ojo
	lookx = looky = lookz = 0;

	


}

void Mundo::Dibuja() {

	
}

void Mundo::Mueve() {


	

	//rotarOjo(); // Aqui veo que puedo usar una funcion dentro de otra

}

void Mundo::tecla(unsigned char key) {


	
}
