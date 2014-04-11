#include "evolucion.h"


Evolucion::Evolucion()
{

}

void Evolucion::calcularFuncionNormal(Individuo * pIndividuo)
{
    /*
     * here I need to define the fitness value according to the Billiard problem
     * instead of what is being done now
     */
    int resultado = (int)pow(M_E,(-(1/(pow(150,4)))*(pIndividuo->getCromosoma()-32000)))*1000;
    pIndividuo->setFitness(resultado);
}
