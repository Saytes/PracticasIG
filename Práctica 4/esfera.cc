//Archivo perteneciente a la P4 de Jorge Gutiérrez Segovia grupo C1
#include "esfera.h"

Esfera::Esfera(){

    std::vector<Vertice> perfil;
    Vertice v;
    int n = 60;
    float alpha = M_PI/2, suma = 2*M_PI/n, radio = 0.5;
    for(int i=0; i<=n/2; i++){
        v.x =  -radio*cos(alpha);
        v.y =  -radio*sin(alpha);
        v.z =  0.0;
        perfil.push_back(v);
        alpha += suma;
    }
    vx = 0.0;
    vy = 0.0;
    vz = 0.0;
    generaRotacion(perfil, 100, true, true,360,vx, vy, vz);
}
