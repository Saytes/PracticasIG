//Archivo perteneciente a la P3 de Jorge Gutiérrez Segovia grupo C1
#ifndef _OBJETOJERARQUICO_H
#define _OBJETOJERARQUICO_H
#include "cilindro.h"
#include "cubo.h"
class ObjetoJerarquico{

	public:
		ObjetoJerarquico(); // Constructor por defecto
		void dibujarSubidor();
        void dibujarBase();
        void dibujarRespaldo();
        void dibujarAsiento();
        void dibujarReposaPies();
        void dibujarBrazo();

    private:
        Cubo cubo;
        Cilindro cilindro;
};

#endif
