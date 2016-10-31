//Archivo perteneciente a la P2 de Jorge Gutiérrez Segovia grupo C1

#include "objetoRota.h"

ObjRotacion::ObjRotacion(){};


void ObjRotacion::generaRotacion(std::vector<Vertice> aRotar, int iteraciones, bool tapaS, bool tapaI){

    bool salir = false;
    int tamIni = aRotar.size();
    Vertice pTapaSup, pTapaInf; //Punto de la tapa superior y tapa inferior

    if(aRotar[0].x == 0.0){ // Hay tapa Superior.

        //Tras comprobar si hay tapa inferior, la introduzco en el vértice
        //creado antes y lo borro del vector de puntos a rotar
        pTapaSup.x= aRotar[0].x;
        pTapaSup.y= aRotar[0].y;
        pTapaSup.z= aRotar[0].z;

        aRotar.erase(aRotar.begin());
    }else{
        //Si no existe el punto, lo creo para crear la tapa en caso de que me la
        //pidan.
        pTapaSup.x = 0;
        pTapaSup.y = aRotar[0].y;
        pTapaSup.z = aRotar[0].z;
      }

    if(aRotar[tamIni-1].x == 0.0){// Hay tapa inferior.

        //Tras comprobar si hay tapa inferior, la introduzco en el vértice
        // creado antes y lo borro del vector de puntos a rotar
        pTapaInf.x= aRotar[tamIni-1].x;
        pTapaInf.y= aRotar[tamIni-1].y;
        pTapaInf.z= aRotar[tamIni-1].z;

        aRotar.pop_back();
    }else{
      //Si no existe el punto, lo creo para crear la tapa en caso de que me la
      //pidan.
        pTapaInf.x = 0;
        pTapaInf.y = aRotar[tamIni-1].y;
        pTapaInf.z = aRotar[tamIni-1].z;
    }


    float anguloRotacion = (2.0*3.1415)/(iteraciones*1.0); //Genero ángulo en radianes

    //Copio los vértices en mi vector de la clase Objeto3D
    vertices = aRotar;
    //Creo dos índices para trabajar sobre los vectores de caras y vértices
    //de mi clase Objeto3D
    unsigned int indiceVertice = tamIni;

    //Redimensiono mi vector, para poder acceder a posiciones independientemente
    vertices.resize(tamIni*(iteraciones));
    caras.clear();

    for(int i=0; i<iteraciones-1; i++){

        aRotar[0] = rotarPunto(aRotar[0], anguloRotacion);
        vertices[indiceVertice] = aRotar[0];
        indiceVertice++;

        for(unsigned int j=1; j < tamIni;j++){

            aRotar[j] = rotarPunto(aRotar[j], anguloRotacion);
            vertices[indiceVertice] = aRotar[j];

            //Introduzco la primera "Media Cara"
            Cara c;
            c.v0 = indiceVertice;
            c.v1 = indiceVertice-1;
            c.v2 = indiceVertice-tamIni;

            caras.push_back(c);

            //Introduzco la segunda "Media Cara"
            c.v0 = indiceVertice-tamIni;
            c.v1 = indiceVertice-1;
            c.v2 = indiceVertice-tamIni-1;

            caras.push_back(c);
            indiceVertice++;
        }
    }


    //Unir las últimas caras con las primeras
     for(unsigned int i=1; i < tamIni ; i++){

        //Introduzco la primera "Media Cara"
        Cara c;
        c.v0 = i-1;
        c.v1 = (indiceVertice - tamIni) + i;
        c.v2 = i;

        caras.push_back(c);

        //Introduzco la segunda "Media Cara"
        c.v0 = i-1;
        c.v1 = (indiceVertice - tamIni) + i-1;
        c.v2 = (indiceVertice - tamIni) + i;
        caras.push_back(c);
    }

    // Uno las tapas
    if(tapaS == true){

        vertices.push_back(pTapaSup);

        for(int i=0; i<iteraciones+1; i++){
            Cara c;
            c.v0 = vertices.size()-1;
            c.v1 = (i*tamIni);
            c.v2 = ((i+1)*tamIni) % (iteraciones*tamIni);
            caras.push_back(c);
        }
    }

    if(tapaI == true){

        vertices.push_back(pTapaInf);
        int ultimoVertice = tamIni-1;

        for(int i=0; i<iteraciones+1; i++){
            Cara c;
            c.v0 = vertices.size()-1;
            c.v1 = ultimoVertice + ((i+1) * tamIni) % (iteraciones*tamIni);
            c.v2 = ultimoVertice + (i*tamIni);
            caras.push_back(c);
        }
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

Vertice ObjRotacion::rotarPunto(Vertice v, float ang){

    Vertice sol;

    sol.x = (cos(ang)*v.x) + (sin(ang)*(v.z));
    sol.y = v.y;
    sol.z = (-1.0)*(sin(ang)*v.x)+(cos(ang)*(v.z));

    return sol;
}
