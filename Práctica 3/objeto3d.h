//Archivo perteneciente a la P2 de Jorge Gutiérrez Segovia grupo C1
#ifndef _OBJETO3D_H
#define _OBJETO3D_H
#include<vector>
#include<GL/gl.h>
//Clase principal de la cual heredan Cubo y Tetraedro


struct Vertice{

    GLfloat x,y,z;
};

struct Cara{

    GLuint v0,v1,v2;
};

class Objeto3d{

	public:
		Objeto3d(); // Constructor por defecto
		enum TipoPoligono{
			FILL, LINE, POINTS
		};
		void drawObjeto3d(TipoPoligono polygon = FILL, bool modoA=false) const;
    std::vector<Vertice> getVertices();
    void setVertices(std::vector<Vertice> v);
    std::vector<Cara> getCaras();
    virtual void generaRotacion(std::vector<Vertice> aRotar, int iteraciones,bool tapaS, bool tapaI,float anguloRotacion);

	protected:

		bool modoA;       //Booleano que regula el modo ajedrez
        std::vector<Vertice> vertices, colors,color1,color2;		// Vectores de Vértices
		std::vector<Cara> caras, caras1, caras2;		// Vectores de Caras
};

#endif
