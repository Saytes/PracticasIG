//Archivo perteneciente a la P2 de Jorge Gutiérrez Segovia grupo C1
#ifndef _OBJETOROTACION_H
#define _OBJETOROTACION_H
#include<vector>
#include<GL/gl.h>
#include"objeto3d.h"
#include <math.h>
#include<iostream>

class ObjetoRotacion : public Objeto3d{

	public:

	    ObjetoRotacion();
		void generaRotacion(std::vector<Vertice> aRotar, int iteraciones, bool tapaS, bool tapaI,float anguloRotacion);
		Vertice rotarPunto(Vertice v, float ang);

	protected:
};
#endif
