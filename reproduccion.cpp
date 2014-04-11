#include "reproduccion.h"

Reproduccion::Reproduccion(int pProbabilidadMutacion, int pProbabilidadInvertir)
{
    if(pProbabilidadMutacion> 100 || pProbabilidadMutacion < 0)
        this->_probabilidadMutacion = 5;
    else
        this->_probabilidadMutacion = pProbabilidadMutacion;

    if(pProbabilidadInvertir> 100 || pProbabilidadInvertir < 0)
        this->_probabilidadInvertir = 5;
    else
        this->_probabilidadInvertir = pProbabilidadMutacion;
}

Individuo * Reproduccion::cruce(Individuo *pPadre, Individuo *pMadre){
    unsigned short filtro1 = -1; // obtenemos el maximo usigned short
    int puntoCruce = rand()%16; // seleccionamos un gen a partir del cual obtenes nuesto
    int mutar = rand()%100;
    int invertir = rand()%100;
    // punto de cruce
    filtro1 = filtro1 << puntoCruce; // creamos filtro padre
    unsigned short filtro2 = ~filtro1; // filtro de la madre
    unsigned short cromosomaDominante, cromosomaRecesivo, cromosomaHijo;
    if((rand()%100) < 50) { // madre es la dominante, quien aporta mas???
        cromosomaDominante = pMadre->getCromosoma();
        cromosomaRecesivo = pPadre->getCromosoma();
    }
    else{
        cromosomaDominante = pPadre->getCromosoma();
        cromosomaRecesivo = pMadre->getCromosoma();
    }
    cromosomaDominante = cromosomaDominante & filtro1;
    cromosomaRecesivo  = cromosomaRecesivo  & filtro2;
    cromosomaHijo = cromosomaDominante | cromosomaRecesivo;
    Individuo * nuevoIndividuo = new Individuo(-1,cromosomaHijo);
    if(mutar < this->_probabilidadMutacion)
        this->Mutacion(nuevoIndividuo);
    if(invertir < this->_probabilidadInvertir)
        this->Inversion(nuevoIndividuo);
    this->fitness(nuevoIndividuo);
    nuevoIndividuo->setPadre(pPadre->getId());
    nuevoIndividuo->setMadre(pMadre->getId());
    return nuevoIndividuo;
}

void Reproduccion::Mutacion(Individuo * pIndividuo){

    int bitMutado = rand()%16;
    unsigned short mascaraMutar = 1;
    mascaraMutar=mascaraMutar<<bitMutado;
    unsigned short cromosomaMutado = pIndividuo->getCromosoma();
    cromosomaMutado = cromosomaMutado ^ mascaraMutar;
    pIndividuo->setCromosoma(cromosomaMutado);
}

void Reproduccion::Inversion(Individuo * pIndividuo){
    int bitInicio = rand()%16;
    int bitFinal = rand()%16;
    unsigned short cromosomaInvertido = pIndividuo->getCromosoma();
    unsigned short mascaraInvertir = 1;
    if(bitInicio > bitFinal){
        int bitTmp = bitInicio;
        bitInicio = bitFinal;
        bitFinal = bitTmp;
    }
    mascaraInvertir = mascaraInvertir << bitInicio;
    while(bitInicio <= bitFinal){
        cromosomaInvertido = cromosomaInvertido ^ mascaraInvertir;
        bitInicio++;
        mascaraInvertir = mascaraInvertir << 1;
    }
    pIndividuo->setCromosoma(cromosomaInvertido);
}

void Reproduccion::fitness(Individuo * pIndividuo){

    double resultado = (double)(pow(M_E,(-(1/(pow(150,4)))*pow((pIndividuo->getCromosoma()-32000),2)))*1000);
    pIndividuo->setFitness(resultado);
}
