//Archivo perteneciente a la P2 de Jorge Gutiérrez Segovia grupo C1
#ifndef _OBJETOPLY_H
#define _OBJETOPLY_H
#include "objeto3d.h"
#include "file_ply_stl.h"

class ObjetoPLY : public Objeto3d{

	public:
		ObjetoPLY(); // Constructor por defecto

		ObjetoPLY(char * fichero); //Constructor por parámetros

	protected:

};

#endif
