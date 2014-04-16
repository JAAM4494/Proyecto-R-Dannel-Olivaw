#include "ball.h"

Ball::Ball(int pId, int pPosx, int pPosy)
{
    this->_id = pId;
    this->_posx = pPosx;
    this->_posy = pPosy;
    this->_angle;
    this->_speed;
    this->_velocity_x;
    this->_velocity_y;
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
    this->_xpos = pPosx;
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
