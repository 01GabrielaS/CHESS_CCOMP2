/*
    This header file contains the Board class.
*/

#ifndef _BOARD_H
#define _BOARD_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <array>
using namespace std;

class Board : public sf::Drawable{ //clase board que hereda de sf::drawable
    sf::RenderTarget* target;

public:

    Board(sf::Color l_col = sf::Color::White, sf::Color d_col = sf::Color::Black); //toma dos argumentos por defecto
    
    // Member function that sets Board stuff, can choose square colors in parameters
    void load(sf::Color l_col = sf::Color::White, sf::Color d_col = sf::Color::Black);

private:

    array<sf::RectangleShape, 64> matriz_tabla; //array que almacena los 64 cuadrados del tablero

    //IMPLEMENTACIÓN
    void setTarget(sf::RenderTarget& target);  // Función para establecer el target


    // Draw class on SFML Window
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;//dibuja cuadrados de tablero
    //sobreescribe la funcion draw de la clase base drawable
    //& target hace referencia a lienzo, o ventana en este caso, se pasa como referencia para que los cambios persistan incluso despues de la funcion
    //render states es una estructura que contiene una serie de configuraciones que afectan cómo se realiza el dibujo
    //sf::RenderTarget es una clase base para cualquier objeto que pueda ser usado como destino de renderizado,
    //dentro de el, encuentras renderwindow y rendertexture




};


#endif