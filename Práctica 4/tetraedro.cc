//Archivo perteneciente a la P4 de Jorge Gutiérrez Segovia grupo C1

#include"tetraedro.h"

Tetraedro::Tetraedro(){

	// Vertice
	Vertice v1;

    //------------------------
    //Abajo derecha(0)
	v1.x = -50.0;
	v1.y = -50.0;
	v1.z = 50.0;
	vertices.push_back(v1);
    //------------------------
    //Abajo izq(1)
	v1.x = 50.0;
	v1.y = -50.0;
	v1.z = -50.0;
	vertices.push_back(v1);
	//----------------
    //Origen(2)
	v1.x = 50.0;
	v1.y = 50.0;
	v1.z = 50.0;
	vertices.push_back(v1);
	//----------------
    //Vertice de arriba(3)
	v1.x = -50.0;
	v1.y = 50.0;
	v1.z = -50.0;
	vertices.push_back(v1);

    for(int i=0; i<vertices.size();i++){
				Vertice vc;
				vc.x = 0.0;
				vc.y = 0.0;
				vc.z = 0.0;
				colors.push_back(vc);
				vc.x = 0.0;
				vc.y = 1.0;
				vc.z = 0.0;
				color1.push_back(vc);
				vc.x = 1.0;
				vc.y = 1.0;
				vc.z = 0.0;
				color2.push_back(vc);
    }

    // Caras
    //Base
	Cara c1;
	c1.v0 = 0;
	c1.v1 = 1;
	c1.v2 = 2;
	caras.push_back(c1);
    //----------------
    //Lateral derecho
    c1.v0 = 3;
	c1.v1 = 2;
	c1.v2 = 1;
	caras.push_back(c1);
    //----------------
    //Cara frontal
    c1.v0 = 3;
	c1.v1 = 1;
	c1.v2 = 0;
	caras.push_back(c1);
    //----------------
    //Lateral izquierdo
	c1.v0 = 0;
	c1.v1 = 2;
	c1.v2 = 3;
	caras.push_back(c1);
	//----------------

	for(int i = 0; i<caras.size(); i+=2){
		caras1.push_back(caras[i]);
		caras2.push_back(caras[i+1]);

	}

}
