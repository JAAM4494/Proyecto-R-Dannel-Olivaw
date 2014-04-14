#ifndef POBLACION_H
#define POBLACION_H
#include "individuo.h"
#include "cstdlib"
#include <stdio.h>
#include "reproduccion.h"
using namespace std;
/*
  Esta clase representa la poblacion
  */
class Poblacion
{
public:
    Poblacion(int pTamanoPoblacion, int pMaxNacimientos,
              short pProbabilidadNacimientos, bool pReemplazoPoblacion );
    ~Poblacion();
    void inicializar(); // genera una poblacion aleatoria, la cual llamaremos generacion 0
    void nuevaGeneracion(Reproduccion *rep);// genera una nueva generacion
    void aplicarFitness(Reproduccion *rep);
    Individuo *  seleccionNatural();
    void mezclarPoblacion(Individuo *pNuevaGeneracion);
    Individuo *  obtenerMasFuerte(Individuo *pPoblacion);
    Individuo *  obtenerMasDebil(Individuo *pPoblacion);
    void cambiarIndividuos(Individuo * Individuo1, Individuo * Individuo2);
    void imprimirMejor();
    void imprimirPoblacion();
private:
    Individuo *  _poblacion;// representa la poblacion de individuos
    int _seleccionado; // pocision individuo seleccionado
    int _counter; // cuanto indivduos han sido creados
    int _tamanoPoblacion; // parametro que representa cuantos individuos vamos a tener
    int _maxNacimientos; // cuantos nacimientos se pueden dar
    short _probabilidadNacimientos;// representa con que probabilidad van a nacer individuos,
    bool  _reemplazoPoblacion;// true si la poblacion se va a reemplazar completamente, false de lo contrario
    /*
      Los parametros anteriores juntos determinan caracteristicas muy importantes, por ejemplo si _reemplazoPoblacion es
      true quiere decir que:
      1) _maxNacimientos == _tamanoPoblacion
      2) _probabilidadNacimientos == 100%
      El tamanio de la poblacion, esta acotado por la variable _tamanoPoblacion, en este ejemplo no se proporciona
      un mecanismo para permitir poblaciones variables
      */
    int getSumatoriaFitness();
    int _generacion;
};

#endif // POBLACION_H
