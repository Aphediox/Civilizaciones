#include "civilizaciones.h"

civilizacion::civilizacion(){
    nombre = " ";
    x = 0;
    y = 0;
    puntuacion = 0;
}
civilizacion::civilizacion(string nombre, float x, float y, unsigned int punt){
    this->nombre = nombre;
    this ->x = x;
    this->y = y;
    this->puntuacion = punt;
}

void civilizacion::setNombre(string nombre){
    this->nombre = nombre;
}
void civilizacion::setX(float x){
    this->x = x;
}
void civilizacion::setY(float y){
    this->y = y;
}
void civilizacion::setPunt(unsigned int punt){
    this->puntuacion = punt;
}
string civilizacion::getNombre(){return nombre;}
float civilizacion::getX(){return x;}
float civilizacion::getY(){return y;}
unsigned int civilizacion::getPunt(){return puntuacion;}