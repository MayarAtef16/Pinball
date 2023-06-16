
#include <cmath>
using namespace std;
#include "Magnets.h"
Magnets::Magnets(float Radius, Vector2D center) : Radius(Radius), center(center) {}

void Magnets::draw(Interface& interface)
{
    interface.drawMagnets(Radius, center);
}
Vector2D Magnets::collideWith(Ball& ball, float collisionTime)
{
    return Vector2D{ 0, 0 };  // Should be replaced with the actual collision logic
}