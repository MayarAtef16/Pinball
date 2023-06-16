
#include <cmath>
using namespace std;
#include "Collectables.h"
Collectables::Collectables(float size, string letter,float x,float y) : size(size),letter(letter),x(x),y(y),collidedLastFrame(false) {}

void Collectables::draw(Interface& interface)
{
    interface.drawCollectables(size,letter,x,y);
}
Vector2D Collectables::collideWith(Ball& ball, float collisionTime)
{   int counter = 0;
    
       if (!collidedLastFrame && ((abs((350) - ball.getCenter().x) < ((25) + ball.getRadius())) && (abs((350) - ball.getCenter().y) < (25 + ball.getRadius()))))
        {
            collidedLastFrame = true;
            cout << collidedLastFrame;

            return Vector2D{ ball.getVelocity().x * -2, ball.getVelocity().y * -2 } / collisionTime;


        }
        else if (!collidedLastFrame && ((abs((400) - ball.getCenter().x) < ((25) + ball.getRadius())) && (abs((400) - ball.getCenter().y) < (25 + ball.getRadius()))))
        {
            collidedLastFrame = true;
            cout << collidedLastFrame;

            return Vector2D{ ball.getVelocity().x * -2, ball.getVelocity().y * -2 } / collisionTime;


        }
        else if (!collidedLastFrame && ((abs((450) - ball.getCenter().x) < ((25) + ball.getRadius())) && (abs((450) - ball.getCenter().y) < (25 + ball.getRadius()))))
        {
            collidedLastFrame = true;
            cout << collidedLastFrame;

            return Vector2D{ ball.getVelocity().x * -2, ball.getVelocity().y * -2 } / collisionTime;


        }
        else if (!collidedLastFrame && ((abs((500) - ball.getCenter().x) < ((25) + ball.getRadius())) && (abs((500) - ball.getCenter().y) < (25 + ball.getRadius()))))
        {
            collidedLastFrame = true;
            cout << collidedLastFrame;

            return Vector2D{ ball.getVelocity().x * -2, ball.getVelocity().y * -2 } / collisionTime;


        }
        else if (!collidedLastFrame && ((abs((550) - ball.getCenter().x) < ((25) + ball.getRadius())) && (abs((550) - ball.getCenter().y) < (25 + ball.getRadius()))))
       {
           collidedLastFrame = true;
           cout << collidedLastFrame;

           return Vector2D{ ball.getVelocity().x * -2, ball.getVelocity().y * -2 } / collisionTime;


       }
        else if (!collidedLastFrame && ((abs((600) - ball.getCenter().x) < ((25) + ball.getRadius())) && (abs((350) - ball.getCenter().y) < (25 + ball.getRadius()))))
       {
           collidedLastFrame = true;
           cout << collidedLastFrame;

           return Vector2D{ ball.getVelocity().x * -2, ball.getVelocity().y * -2 } / collisionTime;


       }
        else
        {
            collidedLastFrame = false;
            cout << collidedLastFrame;
            counter++;
            return Vector2D{ 0, 0 };
          
      

    }
}


