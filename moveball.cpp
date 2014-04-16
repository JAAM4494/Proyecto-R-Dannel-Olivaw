#include "moveball.h"

moveBall::moveBall()
{
    this->_scale_x = 0;      //
    this->_scale_y = 0;      //
    this->_deceleration = 1; //Desaleracion
    this->_ball = new ball(1, 25, 25);
}
moveBall::~moveBall(){

}

moveBall::move(){

}
