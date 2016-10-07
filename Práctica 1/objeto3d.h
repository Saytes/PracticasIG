#ifndef _MALLA_H
#define _MALLA_H
#include<vector>
#include<GL/gl.h>

//Definición de variables globales

const unsigned int X=0, Y=1, Z=2; // Indices de ejes

typedef GLfloat Real; //Número float mínimo 32 bits

typedef GLuint Natural; //Número int unsigned de mínimo 32 bits

//Clase principal de la cual heredan Cubo y Tetraedro

class Objeto3d{	
	
	public:
		//Objeto3d(); // Constructor por defecto
		//drawObjeto3d();
		
	private:

		Natural nver;				// Número total de vértices	
		Natural ntri;				// Número total de triángulos
		std::vector<Real> vertices;		// Vector de Vértices
		std::vector<Natural> caras;		// Vector de Caras

};

#endif
