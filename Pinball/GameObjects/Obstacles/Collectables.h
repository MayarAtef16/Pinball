#pragma once


#include "Obstacle.h"

// Represents a thin vertically infinite wall, on which the ball can bounce


class Collectables : public Obstacle
{
private:
    float x;
    float y;
    float size;
    string letter;
    bool collidedLastFrame;
public:
    // The angle should probably be removed from the constructor after adding the controls
    Collectables(float size,string letter,float x,float y);

    Vector2D collideWith(Ball& ball, float collisionTime) override;
    void draw(Interface& interface) override;
};