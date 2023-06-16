#pragma once
#include "Obstacle.h"

// Represents a thin vertically infinite wall, on which the ball can bounce


class ScoreMultiplier : public Obstacle
{
private:

    Vector2D center;  // Center of rotation
    float Radius;
    bool collidedLastFrame;
public:
    // The angle should probably be removed from the constructor after adding the controls
    ScoreMultiplier(float Radius, Vector2D center);

    Vector2D collideWith(Ball& ball, float collisionTime) override;
    void draw(Interface& interface) override;
};