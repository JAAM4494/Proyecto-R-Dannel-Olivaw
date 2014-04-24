#include "ball.h"

Ball::Ball(int pId, int pPosx, int pPosy)
{
    this->_id = pId;
    this->_posx = pPosx;
    this->_posy = pPosy;
    this->_angle = 0;
    this->_speed = 0;
    this->_velocity_x = 0;
    this->_velocity_y = 0;
}

int Ball::getId(){
    return this->_id;
}
int Ball::getPosx(){
    return this->_posx;
}
int Ball::getPosy(){
    return this->_posy;
}
int Ball::getVelocityX(){
    return this->_velocity_x;
}
int Ball::getVelocityY(){
    return this->_velocity_y;
}
int Ball::getAngle(){
    return this->_angle;
}
int Ball::getSpeed(){
    return this->_speed;
}
void Ball::setPosx(int pPosx){
    this->_posx = pPosx;
}
void Ball::setPosy(int pPosy){
    this->_posy = pPosy;
}
void Ball::setAngle(int pAngle){
    this->_angle = pAngle;
}
void Ball::setspeed(int pSpeed){
    this->_speed = pSpeed;
}
