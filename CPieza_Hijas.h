#ifndef CPIEZA_HIJAS_H
#define CPIEZA_HIJAS_H
#include "Header.h"
#include "CPieza.h"
class PPeon: public CPieza{
private:
    bool primerMovimiento;
public:
    PPeon();
    PPeon(int x, int y, char c);
    ~PPeon();
    bool confirmar_mov(int posX, int posY) override; //override anula la función 
    //confirmarMovimiento de la clase base CPieza
};

class PTorre: public CPieza{
public:
    PTorre();
    PTorre(int x, int y, char c);
    ~PTorre();
    bool confirmar_mov(int posX, int posY)override;
};
class PAlfil: public CPieza{
public:
    PAlfil();
    PAlfil(int x, int y, char c);
    ~PAlfil();
    bool confirmar_mov(int posX, int posY)override;
};
class PCaballo: public CPieza{
public:
    PCaballo();
    PCaballo(int x, int y, char c);
    ~PCaballo();
    bool confirmar_mov(int posX, int posY)override;
};
class PReina: public CPieza{
    public:
    PReina();
    PReina(int x, int y, char c);
    ~PReina();
    bool confirmar_mov(int posX, int posY)override;
};

class PRey: public CPieza{
    public:
    PRey();
    PRey(int x, int y, char c);
    ~PRey();
    bool confirmar_mov(int posX, int posY)override;
};
#endif