
#include <cmath>
using namespace std;
#include "PopBumber.h"
PopBumber::PopBumber(float Radius, Vector2D center) : Radius(Radius),center(center), collidedLastFrame(false) {}

void PopBumber::draw(Interface& interface)
{
    interface.drawPopBumber( Radius, center);
}
Vector2D PopBumber::collideWith(Ball& ball, float collisionTime)
{
    if (!collidedLastFrame && ((abs(center.x - ball.getCenter().x) < (Radius + ball.getRadius()))&& (abs(center.y - ball.getCenter().y) < (Radius + ball.getRadius()))))
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


