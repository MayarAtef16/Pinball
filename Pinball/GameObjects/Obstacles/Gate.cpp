#include <cmath>
using namespace std;
#include "Gate.h"
Gate::Gate(float Length, float Width) : Length(Length), Width(Width),collidedLastFrame(false) {}

void  Gate::draw(Interface& interface)
{
    interface.drawGate(Length, Width);
}
Vector2D  Gate::collideWith(Ball& ball, float collisionTime)
{
    if (!collidedLastFrame && ((abs((Width * 4) - ball.getCenter().x) < ball.getRadius())
        &&       
        ((Length * 2) < ball.getCenter().y && ball.getCenter().y < ((Length * 2) + 90))
        &&
       ( ball.getVelocity().x>0) ))

       /* ||
         ( (abs(((Width*4)) - ball.getCenter().x) < ball.getRadius())
          &&
          ((Length*2)<ball.getCenter().y && ball.getCenter().y<((Length*2)+90))))*/

    {
       
            collidedLastFrame = true;
            cout << "yes" << endl;
            return Vector2D{ ball.getVelocity().x*-2,0} / collisionTime;
      

    }

    else
    {
        collidedLastFrame = false;
        cout << "no" << endl;
        return Vector2D{ 0, 0 };
    }
}

