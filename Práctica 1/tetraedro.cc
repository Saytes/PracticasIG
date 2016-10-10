//Archivo perteneciente a la P1 de Jorge Gutiérrez Segovia grupo C1
#include<tetraedro.h>

Tetraedro::Tetraedro(){

	// Vertices


    vertices.push_back(-50.0);
    vertices.push_back(-50.0);
	vertices.push_back(50.0);
	//----------------
	vertices.push_back(50.0);
	vertices.push_back(-50.0);
	vertices.push_back(-50.0);
	//----------------
	vertices.push_back(50.0);
	vertices.push_back(50.0);
	vertices.push_back(50.0);
	//----------------
	vertices.push_back(-50.0);
	vertices.push_back(50.0);
	vertices.push_back(-50.0);

    for(int i=0; i<vertices.size();i+=3){
            colors.push_back(0.0);
            colors.push_back(0.0);
            colors.push_back(0.0);
            color1.push_back(0.0);
            color1.push_back(1.0);
            color1.push_back(0.0);
            color2.push_back(1.0);
            color2.push_back(1.0);
            color2.push_back(0.0);

    }

    // Caras
    caras.push_back(0);
    caras.push_back(1);
    caras.push_back(2);
    //----------------
    caras.push_back(1);
    caras.push_back(2);
    caras.push_back(3);
    //----------------
    caras.push_back(0);
    caras.push_back(1);
    caras.push_back(3);
    //----------------
    caras.push_back(0);
    caras.push_back(2);
    caras.push_back(3);
	//----------------
}
