#include <Llave.h>


Llave::Llave(float x, float y) {

	posicion.x = x;
	posicion.y = y;
	radio = 3.0f;

	llave.setSize(2, 2);
	llave.setCenter(1, 1);

}
Llave::~Llave() {

}
void Llave::dibuja() {

	glPushMatrix();
	glTranslatef(posicion.x, posicion.y, 0);
	llave.draw();


	glPopMatrix();
}
void Llave::setPos(float x, float y) {

	posicion.x = x;
	posicion.y = y;
}
void Llave::setRadio(float r) {

	radio = r;
}
void Llave::mueve() {
	llave.loop();
}