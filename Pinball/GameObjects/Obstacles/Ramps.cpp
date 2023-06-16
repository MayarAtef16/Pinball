#include <cmath>
using namespace std;
#include "Ramps.h"
Ramps::Ramps(float Length, float Width) : Length(Length), Width(Width) {}

void  Ramps::draw(Interface& interface)
{
    interface.drawRamp(Length, Width);
}
Vector2D  Ramps::collideWith(Ball& ball, float collisionTime)
{
    return Vector2D{ 0, 0 };  // Should be replaced with the actual collision logic
}


