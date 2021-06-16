#include <Moneda.h>


Moneda::Moneda(float x, float y) {

	posicion.x = x;
	posicion.y = y;
	radio = 3.0f;
	moneda.setSize(2, 2);
	moneda.setCenter(1, 1);

}
Moneda::~Moneda() {

}
void Moneda::dibuja() {

	glPushMatrix();
	glTranslatef(posicion.x, posicion.y, 0);
	moneda.draw();
	glPopMatrix();

}
void Moneda::setPos(float x, float y) {

	posicion.x = x;
	posicion.y = y;
}
void Moneda::setRadio(float r) {

	radio = r;
}
void Moneda::mueve() {
	moneda.loop();
}