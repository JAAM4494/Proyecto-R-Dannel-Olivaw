#ifndef REPRODUCCION_H
#define REPRODUCCION_H
#include "individuo.h"
#include "cstdlib"
#include <stdio.h>
#include "cmath"

using namespace std;
class Reproduccion
{
public:
    Reproduccion(int pProbabilidadMutacion, int pProbabilidadInvertir);
    Individuo * cruce(Individuo *pPadre, Individuo *pMadre);
    void Mutacion(Individuo * pIndividuo);
    void Inversion(Individuo * pIndividuo);
    void fitness(Individuo * pIndividuo);
private:
    int _probabilidadMutacion;
    int _probabilidadInvertir;
};

#endif // REPRODUCCION_H
