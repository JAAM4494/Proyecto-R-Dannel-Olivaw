#include "individuo.h"


Individuo::Individuo(int pId,unsigned short pCromosoma)
{
    this->_cromosoma = pCromosoma;
    this->_id = pId;
    this->_siguiente = NULL;
    this->_madre = -1;
    this->_padre = -1;
    this->_generacion = 0;
}
unsigned short Individuo::getCromosoma(){
    return this->_cromosoma;
}
int Individuo::getId(){
    return this->_id;
}
double Individuo::getFitness(){
    return this->_valorFitness;
}
void Individuo::setFitness(double pFitness){
    this->_valorFitness = pFitness;
}
void Individuo::setId(int id){
    this->_id = id;
}
void Individuo::setCromosoma(unsigned short pCromosoma){
    this->_cromosoma = pCromosoma;
}
void Individuo::setSiguiente(Individuo *siguiente){
    this->_siguiente = siguiente;
}
Individuo * Individuo::getSiguiente(){
     return this->_siguiente;
 }
int Individuo::getPadre(){
    return this->_padre;
}

int Individuo::getMadre(){
    return this->_madre;
}

void Individuo::setPadre(int pPadre){
    this->_padre = pPadre;
}

void Individuo::setMadre(int pMadre){
    this->_madre = pMadre;
}
int  Individuo::getGeneracion(){
    return this->_generacion;
}

void Individuo::setGeneracion(int pGeneracion){
    this->_generacion = pGeneracion;
}

void Individuo::imprimir()
{
    printf("Individuo id= %d, Generacion %d, Padre=%d, Madre=%d, Cromosoma=%u, fitness=%f\n",this->_id, this->_generacion, this->_padre, this->_madre, this->_cromosoma, this->_valorFitness);
}
