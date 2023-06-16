
#include "Kicker.h"

Kicker::Kicker(Vector2D center, float Radius) :
    center(center),Radius(Radius) {}

Vector2D Kicker::collideWith(Ball& ball, float collisionTime)
{
    return Vector2D{ 0, 0 };  // Should be replaced with the actual collision logic
}

void Kicker::draw(Interface& interface)
{
    interface.drawKicker( center,Radius);
}
