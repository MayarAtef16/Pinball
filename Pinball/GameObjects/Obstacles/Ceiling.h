#pragma once

#include "Obstacle.h"

// Represents a thin vertically infinite wall, on which the ball can bounce
class Ceiling : public Obstacle
{
private:
    float position;  // The horizontal position of the wall
    bool collidedLastFrame;  // Whether or not the last frame was a collision (to prevent flapping)

public:
    explicit Ceiling(float position);  //mkan L het7t feh aw m2asato 
    void draw(Interface& interface) override; //nrsm fe Linterface 
    Vector2D collideWith(Ball& ball, float collisionTime) override;  
};



