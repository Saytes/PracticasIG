//Archivo perteneciente a la P1 de Jorge Gutiérrez Segovia
#include<cubo.h>

Cubo::Cubo(){

	// Vertice
	vertices.push_back(0.0);
    vertices.push_back(0.0);
	vertices.push_back(75.0);
    //------------------------
    vertices.push_back(75.0);
    vertices.push_back(0.0);
    vertices.push_back(75.0);
    //------------------------
    vertices.push_back(0.0);
    vertices.push_back(75.0);
    vertices.push_back(75.0);
    //------------------------
    vertices.push_back(75.0);
    vertices.push_back(75.0);
    vertices.push_back(75.0);
    //------------------------
    vertices.push_back(0.0);
    vertices.push_back(0.0);
    vertices.push_back(0.0);
    //------------------------
    vertices.push_back(75.0);
    vertices.push_back(0.0);
    vertices.push_back(0.0);
    //------------------------
    vertices.push_back(0.0);
    vertices.push_back(75.0);
    vertices.push_back(0.0);
    //------------------------
    vertices.push_back(75.0);
    vertices.push_back(75.0);
    vertices.push_back(0.0);

	for(int i=0; i<vertices.size();i+=3){
			colors.push_back(0.0);
			colors.push_back(0.0);
			colors.push_back(0.0);
			color1.push_back(1.0);
            color1.push_back(0.0);
            color1.push_back(0.0);
            color2.push_back(0.0);
            color2.push_back(1.0);
            color2.push_back(1.0);

    }

	// Caras
    caras.push_back(2);
    caras.push_back(3);
    caras.push_back(7);
    //----------------
	caras.push_back(2);
    caras.push_back(7);
    caras.push_back(6);
	//----------------

    caras.push_back(6);
    caras.push_back(7);
    caras.push_back(4);
    //----------------
    caras.push_back(7);
    caras.push_back(5);
    caras.push_back(4);
	//----------------

    caras.push_back(0);
    caras.push_back(1);
    caras.push_back(2);
    //----------------
    caras.push_back(1);
    caras.push_back(3);
    caras.push_back(2);
    //----------------

	caras.push_back(1);
    caras.push_back(7);
    caras.push_back(3);
    //----------------
    caras.push_back(1);
    caras.push_back(5);
    caras.push_back(7);
	//----------------

    caras.push_back(2);
    caras.push_back(6);
    caras.push_back(4);
    //----------------
    caras.push_back(0);
    caras.push_back(2);
    caras.push_back(4);
	//----------------

    caras.push_back(0);
    caras.push_back(4);
    caras.push_back(1);
    //----------------
    caras.push_back(1);
    caras.push_back(4);
    caras.push_back(5);
	//----------------


}
