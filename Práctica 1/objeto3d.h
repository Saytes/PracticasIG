//Archivo perteneciente a la P1 de Jorge Gutiérrez Segovia grupo C1
#ifndef _OBJETO3D_H
#define _OBJETO3D_H
#include<vector>
#include<GL/gl.h>
//Clase principal de la cual heredan Cubo y Tetraedro

class Objeto3d{

	public:
		Objeto3d(); // Constructor por defecto
		enum TipoPoligono{
			FILL, LINE, POINTS
		};
		void drawObjeto3d(TipoPoligono polygon = FILL, bool modoA=false) const;

	protected:

		bool modoA;
		GLuint nver;				// Número total de vértices
		GLuint ntri;				// Número total de triángulos
		std::vector<GLfloat> vertices;		// Vector de Vértices
		std::vector<GLfloat> colors;		// Vector de Vértices
		std::vector<GLfloat> color1;		// Vector de Vértices
		std::vector<GLfloat> color2;		// Vector de Vértices
		std::vector<GLuint> caras;		// Vector de Caras
};

#endif
