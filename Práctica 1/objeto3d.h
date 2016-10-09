//Archivo perteneciente a la P1 de Jorge Gutiérrez Segovia
#ifndef _OBJETO3D_H
#define _OBJETO3D_H
#include<vector>
#include<GL/gl.h>
//Clase principal de la cual heredan Cubo y Tetraedro

class Objeto3d{

	public:
		Objeto3d(); // Constructor por defecto
		enum TipoDibujo{
			LINEAS, PUNTOS, AJEDREZ, SOLIDO
		};
		void drawObjeto3d(TipoDibujo modo = SOLIDO) const;

	protected:

		GLuint nver;				// Número total de vértices
		GLuint ntri;				// Número total de triángulos
		std::vector<GLfloat> vertices;		// Vector de Vértices
		std::vector<GLuint> caras;		// Vector de Caras
};

#endif
