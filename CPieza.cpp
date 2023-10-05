#include "Header.h" 
#include "CPieza.h"

CPieza::CPieza(): posX{0}, posY{0},color{'B'}, icono {"pB"}{}
CPieza::CPieza(int x,int y ,char c):
posY{y},posX{x},color(c){
    icono="p";
    icono.push_back(color);
}
//CPieza::~CPieza(){} (no se implementa el destructor porque es una función virtual)
void CPieza::setPosX(int x){posX=x;}
void CPieza::setPosY(int y){posY=y;}
int CPieza::getPosX()const{return posX;}
int CPieza::getPosY()const{return posY;}
char CPieza::getColor()const{return color;} 
std::string CPieza::getIcono(){return icono;}
//virtual bool CPieza::CPieza(){} (Tampoco se implementa)
//Las clases derivadas deben contener una implementación concreta, si no
//será tomada como clase abstracta y no se podrán crear instancias de ese
//objeto.
// Esto te permite garantizar que todas las clases derivadas de CPieza 
//implementen su propia lógica de movimiento.