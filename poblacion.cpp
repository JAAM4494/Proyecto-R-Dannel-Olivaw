#include "poblacion.h"

Poblacion::Poblacion(int pTamanoPoblacion, int pMaxNacimientos,
                     short pProbabilidadNacimientos, bool pReemplazoPoblacion)
{
    this->_reemplazoPoblacion = pReemplazoPoblacion;
    this->_generacion = 0;
    this->_tamanoPoblacion = pTamanoPoblacion;
    this->_seleccionado = -1; // no hay nadie seleccionado
    if(this->_reemplazoPoblacion){
        this->_maxNacimientos = pTamanoPoblacion;
        this->_probabilidadNacimientos = 100;
    }
    else{
        if(pProbabilidadNacimientos > 100 && pProbabilidadNacimientos < 0)
            this->_probabilidadNacimientos = 50; // en caso de que se inserte un valor incorrecto se asume un nacimiento de un 50%
        else
            this->_probabilidadNacimientos = pProbabilidadNacimientos;
        this->_maxNacimientos = pMaxNacimientos;
        }
    this->_counter = 0;

}

Poblacion::~Poblacion()
{
    if(this->_poblacion)
    {
        Individuo * _Current = this->_poblacion;
        Individuo * _TmpPtr;

        while(_Current != 0)
        {
            _TmpPtr = _Current;
            _Current = _Current->getSiguiente();
            delete _TmpPtr;
        }
    }
}

void Poblacion::inicializar()
{
    this->_poblacion = new Individuo(this->_counter,rand());
    for(int i=1;i<this->_tamanoPoblacion;i++)
    {
        this->_counter++;
        unsigned short cromosoma=rand()/65535;
        Individuo *tmp = new Individuo(this->_counter,cromosoma);
        tmp->setSiguiente(this->_poblacion);
        this->_poblacion = tmp;
    }
    this->_seleccionado = -1; // no hay nadie seleccionado
}

void Poblacion::nuevaGeneracion(Reproduccion *rep){
    Individuo *nacimientos = NULL;
    int numeroNacimientos =0;
    Individuo *padre1 = NULL;
    Individuo *padre2 = NULL;
    for(int i=0;i<this->_maxNacimientos;i++){
        if((rand()%100) < this->_probabilidadNacimientos){

            padre1 = this->seleccionNatural();
            this->_seleccionado = padre1->getId();
            padre2 = this->seleccionNatural();
            this->_seleccionado = -1;
            Individuo *tmp = rep->cruce(padre1,padre2);
            tmp->setSiguiente(nacimientos);
            nacimientos = tmp;
            this->_counter++;
            nacimientos->setId(this->_counter);
            nacimientos->setGeneracion(this->_generacion);
            numeroNacimientos++;

        }
    }
    mezclarPoblacion(nacimientos);
    this->_generacion++;
    printf("GENERACION ............................ %d\n", this->_generacion);
}

int Poblacion::getSumatoriaFitness(){
    int fitnessTotal =0;
    Individuo *tmp = this->_poblacion;
    while(tmp != NULL){
        if(tmp->getId() != this->_seleccionado){
            fitnessTotal = fitnessTotal + (int)tmp->getFitness();
        }
        tmp = tmp->getSiguiente();
    }
    return fitnessTotal;
}

Individuo *  Poblacion::seleccionNatural(){
    int fitnessTotal = this->getSumatoriaFitness();
    int afortunado = (rand()%fitnessTotal);
    int min =0, max =0;
    //int i=0;
    Individuo *tmp = this->_poblacion;
    while(tmp != NULL)
    {
        if(tmp->getId()!=this->_seleccionado)
        {

            max = max+(int)tmp->getFitness();
            if(afortunado < max)
                break;
            min = max;
        }
        tmp = tmp->getSiguiente();
    }
    return tmp;
}

Individuo* Poblacion::obtenerMasDebil(Individuo *pPoblacion){
    Individuo* masDebil= pPoblacion;
    Individuo* tmp = pPoblacion;
    while(tmp != NULL){
        if(masDebil->getFitness() > tmp->getFitness())
        {
            masDebil = tmp;
        }
        tmp = tmp->getSiguiente();
    }
    return masDebil;
}

Individuo* Poblacion::obtenerMasFuerte(Individuo *pPoblacion){
    Individuo* masFuerte= pPoblacion;
    Individuo* tmp = pPoblacion;
    while(tmp != NULL){
        if(masFuerte->getFitness() < tmp->getFitness())
        {
            masFuerte = tmp;
        }
        tmp = tmp->getSiguiente();
    }
    return masFuerte;
}

void Poblacion::cambiarIndividuos(Individuo * Individuo1, Individuo * Individuo2){
    //qDebug()<<"Bongo **************************23\n";
    int id=Individuo1->getId();
    unsigned short cromosoma = Individuo1->getCromosoma();
    double fitness = Individuo1->getFitness();
    //qDebug()<<"Bongo **************************\n";
    int generacion =Individuo1->getGeneracion();
    //qDebug()<<"Bongo **************************\n";
    int padre = Individuo1->getPadre();
    int madre = Individuo1->getMadre();
    Individuo1->setFitness(Individuo2->getFitness());

    Individuo1->setId(Individuo2->getId());
    Individuo1->setCromosoma(Individuo2->getCromosoma());
    Individuo1->setGeneracion(Individuo2->getGeneracion());
    Individuo1->setPadre(Individuo2->getPadre());
    Individuo1->setMadre(Individuo2->getMadre());
    //qDebug()<<"Bongo **************************22\n";
    Individuo2->setId(id);
    Individuo2->setCromosoma(cromosoma);
    Individuo2->setFitness(fitness);
    Individuo2->setGeneracion(generacion);
    Individuo2->setMadre(madre);
    Individuo2->setPadre(padre);
}

void Poblacion::mezclarPoblacion(Individuo *pNuevaGeneracion){
    Individuo *  debilGeneracionActual = this->obtenerMasDebil(this->_poblacion);
    Individuo *  fuerteNuevaGeneracion = this->obtenerMasFuerte(pNuevaGeneracion);

    //int tmp =0;
    while(debilGeneracionActual->getFitness() <
          fuerteNuevaGeneracion->getFitness())
    {
       // qDebug()<<"Bongo **************************\n";
        this->cambiarIndividuos(debilGeneracionActual,fuerteNuevaGeneracion);
        //qDebug()<<"Bongo **************************\n";
        debilGeneracionActual = this->obtenerMasDebil(this->_poblacion);
        fuerteNuevaGeneracion = this->obtenerMasFuerte(pNuevaGeneracion);
    }
}

void Poblacion::aplicarFitness(Reproduccion *rep){
    Individuo * tmp = this->_poblacion;
    while(tmp != NULL)
    {
        rep->fitness(tmp);
        tmp = tmp->getSiguiente();
    }
}

void Poblacion::imprimirMejor(){
    Individuo * mejor = this->_poblacion;
    Individuo * tmp = this->_poblacion;
    while(tmp!=NULL){
        if(mejor->getFitness()<tmp->getFitness())
            mejor = tmp;
        tmp = tmp->getSiguiente();
    }
    printf("Mejor Individuo id %d, Generacion %d, fitness %f, cromosoma %hu\n",mejor->getId(), mejor->getGeneracion(),mejor->getFitness(), mejor->getCromosoma());
}

void Poblacion::imprimirPoblacion(){
    printf("########################################################################\n");
    printf("Generacion\n");
    Individuo * tmp = this->_poblacion;
    while(tmp!=NULL){
        tmp->imprimir();
        tmp = tmp->getSiguiente();
    }
    this->imprimirMejor();
    printf("########################################################################\n");
}
