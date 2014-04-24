#ifndef BALL_H
#define BALL_H

class Ball
{
public:
    Ball(int pId, int pPosx, int pPosy);
    Ball();
    int getId();
    int getPosx();
    int getPosy();
    int getVelocityX();
    int getVelocityY();
    int getAngle();
    int getSpeed();
    void setPosx(int pPosx);
    void setPosy(int pPosy);
    void setAngle(int pAngle);
    void setspeed(int pDecel);
private:
    int _id;
    int _posx;
    int _posy;
    int _angle;
    int _speed;
    int _velocity_x;
    int _velocity_y;
};

#endif // BALL_H
