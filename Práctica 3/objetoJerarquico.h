//Archivo perteneciente a la P3 de Jorge Gutiérrez Segovia grupo C1
#ifndef _OBJETOJERARQUICO_H
#define _OBJETOJERARQUICO_H
#include "cilindro.h"
#include "cubo.h"
class ObjetoJerarquico{

	public:
		ObjetoJerarquico(); // Constructor por defecto
		void dibujarSubidor(bool ajedrez);
        void dibujarBase(int traslacion, bool ajedrez);
        void dibujarRespaldo(bool ajedrez);
        void dibujarAsiento(int traslacion, bool ajedrez);
        void dibujarReposaPies(bool ajedrez);
        void dibujarBrazo(bool ajedrez);
		void dibujarSilla(float angulo1, float angulo2, int traslacion, bool ajedrez);

    private:
        Cubo cubo;
        Cilindro cilindro;
};

#endif
