#include <cmath>
using namespace std;
#include "VibraniumBumper.h"
VibraniumBumper::VibraniumBumper(float Radius, Vector2D center, float minorRadius) : Radius(Radius), center(center), minorRadius(minorRadius), collidedLastFrame(false) {}

void VibraniumBumper::draw(Interface& interface)
{
    interface.drawVibraniumBumper(Radius, center, minorRadius);
}
Vector2D VibraniumBumper::collideWith(Ball& ball, float collisionTime)
{
    if (!collidedLastFrame && ((abs(center.x - ball.getCenter().x) < (Radius + ball.getRadius())) && (abs(center.y - ball.getCenter().y) < (Radius + ball.getRadius()))))
    {
        collidedLastFrame = true;
        cout << collidedLastFrame;
        return Vector2D{ ball.getVelocity().x * -2, ball.getVelocity().y * -2 } / collisionTime;
    }
    else
    {
        collidedLastFrame = false;
        cout << collidedLastFrame;
        return Vector2D{ 0, 0 };
    }
}
