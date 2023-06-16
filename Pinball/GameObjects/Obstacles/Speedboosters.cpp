
#include <cmath>
using namespace std;
#include "Speedboosters.h"
Speedboosters::Speedboosters(float Radius, Vector2D center) : Radius(Radius), center(center) {}

void Speedboosters::draw(Interface& interface)
{
    interface.drawSpeedboosters(Radius, center);
}
Vector2D Speedboosters::collideWith(Ball& ball, float collisionTime)
{
    return Vector2D{ 0, 0 };  // Should be replaced with the actual collision logic
}


