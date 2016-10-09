//Archivo perteneciente a la P1 de Jorge Gutiérrez Segovia
#include<tetraedro.h>
#include<math.h>


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
