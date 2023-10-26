#include "Header.h"
#include "CPieza.h"
#include "CPieza_Hijas.h"

PPeon::PPeon():CPieza(),
primerMovimiento(true) {icono[0]='P';}

PPeon::PPeon(int x, int y, char c):
CPieza(x,y,c),primerMovimiento(true) {icono[0]='P';}

bool PPeon:: confirmar_mov(int x, int y; CPieza* casilla){
    if ((posX=x)&&(posY=y)){
        cout<<"Movimiento NO válido"<<endl;//La posición de destino no debe
        //ser igual a la posición actual
        return false,
    }
    if()
}
