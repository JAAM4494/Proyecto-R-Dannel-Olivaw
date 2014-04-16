#ifndef BALL_H
#define BALL_H

class Ball
{
public:
    Ball(int pId, int pPosx, int pPosy);
    Ball();
private:
    int Ball::getId();
    int Ball::getPosx();
    int Ball::getPosy();
    int Ball::getVelocityX();
    int Ball::getVelocityY();
    int Ball::getAngle();
    int Ball::getSpeed();
    void Ball::setPosx(int pPosx);
    void Ball::setPosy(int pPosy);
    void Ball::setAngle(int pAngle);
    void Ball::setspeed(int pDecel);
};

#endif // BALL_H
