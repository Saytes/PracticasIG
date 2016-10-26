//Archivo perteneciente a la P2 de Jorge Gutiérrez Segovia grupo C1

#include "objetoPLY.h"
#include <vector>
#include <GL/gl.h>
#include <iostream>


ObjetoPLY::ObjetoPLY(){

}

ObjetoPLY::ObjetoPLY(char * fichero){

	_file_ply obj;
	std::vector<GLfloat> vertex;
	std::vector<int> faces;
	obj.open(fichero);
	obj.read(vertex, faces);
	for(int i=0;i<vertex.size();i=i+3){
		Vertice vertice;
		vertice.x = vertex[i];
		vertice.y = vertex[i+1];
		vertice.z = vertex[i+2];
		vertices.push_back(vertice);
	}
	for(int i=0;i<faces.size();i=i+3){
		Cara cara;
		cara.v0 = (GLuint)faces[i];
		cara.v1 = (GLuint)faces[i+1];
		cara.v2 = (GLuint)faces[i+2];
		caras.push_back(cara);
	}
	for(unsigned int i=0; i<vertices.size();i++){
			Vertice vc;
			vc.x = 0;
			vc.y = 0;
			vc.z = 0;
			colors.push_back(vc);
			vc.x = 1.0;
			vc.y = 0.0;
			vc.z = 0.0;
			color1.push_back(vc);
			vc.x = 0.0;
			vc.y = 1.0;
			vc.z = 1.0;
			color2.push_back(vc);
	}
}
