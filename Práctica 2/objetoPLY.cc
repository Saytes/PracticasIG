//Archivo perteneciente a la P2 de Jorge Gutiérrez Segovia grupo C1

#include "objetoPLY.h"
#include<vector>
#include<GL/gl.h>


ObjetoPLY::ObjetoPLY(){

}

ObjetoPLY::ObjetoPLY(char * fichero){

	_file_ply obj;
	std::vector<int> faces;
	obj.open(fichero);
	obj.read(vertices, faces);

	for(int i=0;i<faces.size();i++){
		GLuint cara = (GLuint)faces[i];
		caras.push_back(cara);
	}

}
