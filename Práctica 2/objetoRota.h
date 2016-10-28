//Archivo perteneciente a la P2 de Jorge Gutiérrez Segovia grupo C1
#ifndef _OBJROTACION_H
#define _OBJROTACION_H
#include<vector>
#include<GL/gl.h>
#include"objeto3d.h"
#include <math.h>

class ObjRotacion : public Objeto3d{

	public:

	    ObjRotacion();
			void generaRotacion(std::vector<Vertice> aRotar, int iteraciones, bool tapaS, bool tapaI);
		  Vertice rotarPunto(Vertice v, float ang);

	protected:
};
#endif
