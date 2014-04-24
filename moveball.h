#ifndef MOVEBALL_H
#define MOVEBALL_H

#include "ball.h"

class moveBall
{
private:
    int _scale_x;
    int _scale_y;
    int _deceleration;
    Ball * _ball;
public:
    moveBall();
    ~moveBall();
    void move();
};

#endif // MOVEBALL_H
