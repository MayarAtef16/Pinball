#pragma once

#include "Obstacle.h"


// Represents a (controllable) flipper
class Kicker : public Obstacle
{
private:
    
    Vector2D center; 
    float Radius;  
   

public:
    // The angle should probably be removed from the constructor after adding the controls
    Kicker(Vector2D center, float Radius);

    Vector2D collideWith(Ball& ball, float collisionTime) override;
    void draw(Interface& interface) override;
};
