
#pragma once
#include "Obstacle.h"

// Represents a thin vertically infinite wall, on which the ball can bounce


class Switch : public Obstacle
{
private:

    bool  collidedLastFrame;
    float Length;
    float Width;
    bool numberOfCollide =false;
    int counter;
public:

    Switch(float Length, float Width);

    Vector2D collideWith(Ball& ball, float collisionTime) override;
    void draw(Interface& interface) override;
};