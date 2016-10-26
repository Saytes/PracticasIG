//Archivo perteneciente a la P2 de Jorge Gutiérrez Segovia grupo C1
#ifndef _OBJROTACION_H
#define _OBJROTACION_H
#include<vector>
#include<GL/gl.h>
#include "objeto3d.h"

class ObjRotacion : Objeto3d{

	public:

	    ObjRotacion();
	    void generaRotacion(std::vector<GLfloat> perfil, int it);
		std::vector<GLfloat> rotar(std::vector<GLfloat> vertice, float ang);

	protected:
};
#endif
