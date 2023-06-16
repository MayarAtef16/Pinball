
#include <cmath>
using namespace std;
#include "ScoreMultiplier.h"
ScoreMultiplier::ScoreMultiplier(float Radius, Vector2D center) : Radius(Radius), center(center),collidedLastFrame(false) {}

void ScoreMultiplier::draw(Interface& interface)
{
    interface.drawScoreMultiplier(Radius, center);
}
Vector2D ScoreMultiplier::collideWith(Ball& ball, float collisionTime)
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


