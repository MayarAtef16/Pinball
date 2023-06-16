
#pragma once
#include "Obstacle.h"

// Represents a thin vertically infinite wall, on which the ball can bounce


class Gate : public Obstacle
{
private:


    float Length;
    float Width;
    bool collidedLastFrame;
public:

    Gate(float Length, float Width);

    Vector2D collideWith(Ball& ball, float collisionTime) override;
    void draw(Interface& interface) override;
};