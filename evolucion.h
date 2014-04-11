#ifndef EVOLUCION_H
#define EVOLUCION_H
#include "individuo.h"
#include "cmath"

class Evolucion
{
public:
    Evolucion();
private:
    void calcularFuncionNormal(Individuo * pIndividuo);
};

#endif // EVOLUCION_H
