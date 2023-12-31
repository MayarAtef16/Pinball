#pragma once

#include "Drawable.h"
#include "Collidable.h"
#include<conio.h>
#include <iostream>
using namespace std;
// Represents a (controllable) flipper
class Flipper: public Drawable, Collidable
{
private:
    FlipperType type;  // Left or right flipper
    Vector2D center;  // Center of rotation
    float length;  // Flipper length
    float angle;  // Angle of rotation
    float majorRadius;  // The radius of the rotation end
    float minorRadius;  // The radius of the other end
    bool exit, left, right;
public:
    // The angle should probably be removed from the constructor after adding the controls
    Flipper(FlipperType type, Vector2D center, float length, float angle, float majorRadius, float minorRadius);

    Vector2D collideWith(Ball & ball, float collisionTime) override;
    void draw(Interface & interface) override;
    void control();
};
