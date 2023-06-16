#pragma once
#include "Obstacle.h"

// Represents a thin vertically infinite wall, on which the ball can bounce


class Speedboosters : public Obstacle
{
private:

    Vector2D center;  // Center of rotation
    float Radius;
public:
    // The angle should probably be removed from the constructor after adding the controls
    Speedboosters(float Radius, Vector2D center);

    Vector2D collideWith(Ball& ball, float collisionTime) override;
    void draw(Interface& interface) override;
};