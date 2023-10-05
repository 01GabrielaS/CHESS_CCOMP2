#ifndef CPIEZA_H // (if not defined) verficia si "CPIEZA_H" está definido o no, tal sea el caso que no, 
//se define la siguiente etiqueta:
#define CPIEZA_H //esta directiva define CPIEZA_H como un marcador que indica que el archivo de encabeza-
//-do se ha incluido.

#include "Header.h"
class CPieza{
protected:
    int posX;
    int posY;
    char color;
    std::string icono;
public:
    CPieza();
    CPieza(int x, int y, char c);
    virtual ~CPieza()=default; //se aplica el virtual ya que, como va a variar
    //dependiendo del caso de ficha, no se podrá desarrollar una sóla lógica en la clase de imlementación
    //para todos 
    void setPosX(int X);
    void setPosY(int Y);
    int getPosX()const;
    int getPosY()const;
    char getColor()const;
    std::string getIcono();
    virtual bool confirmar_mov(int posX,int posY)=0;//  Falta implementar un tercer argumento : CPieza* casilla
    //el 'virtual bool =0' indica que es una función virtual pura, y la clase CPieza se converte 
    //en una clase abstracta
    //Las clases abstractas no pueden ser instanciadas directamente
    };

#endif //marca en final del bloque condicional, todo el contenido entre #ifndef y #endif se incluirá u omitirá dependien
//-do del caso