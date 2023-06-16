#pragma once
#include "Obstacle.h"

// Represents a thin vertically infinite wall, on which the ball can bounce


class ThurstBumper : public Obstacle
{
private:

    Vector2D center;  // Center of rotation
    float Radius;
    float minorRadius;
    bool collidedLastFrame;
public:
   
    ThurstBumper(float Radius, Vector2D center,float minorRaius);

    Vector2D collideWith(Ball& ball, float collisionTime) override;
    void draw(Interface& interface) override;
};