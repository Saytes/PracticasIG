//Archivo perteneciente a la P2 de Jorge Gutiérrez Segovia grupo C1
#ifndef _ESCENA_H
#define _ESCENA_H
#include <string>
#include "ejes.h"
#include "cubo.h"
#include "objetoPLY.h"
#include "tetraedro.h"

class Escena {
private:
// tama�o de los ejes
#define AXIS_SIZE 5000
Ejes ejes;

// variables que definen la posicion de la camara en coordenadas polares
GLfloat Observer_distance;
GLfloat Observer_angle_x;
GLfloat Observer_angle_y;

// variables que controlan la ventana y la transformacion de perspectiva
GLfloat Width,Height,Front_plane,Back_plane;

private:
	void clear_window();
	void draw_axis();
	void draw_objects();

//Transformaci�n de c�mara
	void change_projection();
	void change_observer();

// Variables para cambiar de modo y objetos
 	Objeto3d *objeto3d;
	char modo;
	bool ajedrez;
	std::string mostrarM;
  std::string directPLY;
  char* d;
public:

     Escena();
	void inicializar(int UI_window_width,int UI_window_height);
	void redimensionar(int newWidth,int newHeight) ;

	// Dibujar
	void dibujar() ;

	// Interacci�n con la escena
	int teclaPulsada(unsigned char Tecla1,int x,int y) ;
	void teclaEspecial(int Tecla1,int x,int y);
};
#endif
