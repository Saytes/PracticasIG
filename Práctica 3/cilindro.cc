//Archivo perteneciente a la P3 de Jorge Gutiérrez Segovia grupo C1

#include "cilindro.h"

Cilindro::Cilindro(){

    std::vector<Vertice> perfil;
    Vertice v;
    v.x =  0.5;
    v.y =  0.5;
    v.z =  0.0;
    perfil.push_back(v);
    v.x =  0.5;
    v.y = -0.5;
    v.z =  0.0;
    perfil.push_back(v);
    generaRotacion(perfil, 100, true, true,360);
}
