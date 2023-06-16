
#include <cmath>
using namespace std;
#include "Bullseye.h"
Bullseye::Bullseye(float Radius, Vector2D center) : Radius(Radius), center(center) {}

void Bullseye::draw(Interface& interface)
{
    interface.drawBullseye(Radius, center);
}
Vector2D Bullseye::collideWith(Ball& ball, float collisionTime)
{
    return Vector2D{ 0, 0 };  // Should be replaced with the actual collision logic
}