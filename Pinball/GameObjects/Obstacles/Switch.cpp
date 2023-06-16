#include <cmath>
using namespace std;
#include "Switch.h"
Switch::Switch(float Length, float Width) :Length(Length), Width(Width), collidedLastFrame(false){
counter = 0; }
void  Switch::draw(Interface& interface)
{
  interface.drawSwitch(Length, Width);
}
Vector2D  Switch::collideWith(Ball& ball, float collisionTime)
{ 
   if(!collidedLastFrame  &&( (abs((Width*5) - ball.getCenter().x) < ball.getRadius()) 
       &&
       ((Length*2)<ball.getCenter().y && ball.getCenter().y<((Length*2)+90))))
       
     /*  ||
      ( (abs(((Width*5)+30) - ball.getCenter().x) < ball.getRadius()) 
       && 
       ((Length*2)<ball.getCenter().y && ball.getCenter().y<((Length*2)+90))))*/
   
   {   
       if (counter == 0)
       {
           collidedLastFrame = true;
           cout << "yes" << endl;
           counter++;
           return Vector2D{ 0,0 } / collisionTime;
          
       }
       else  
       {
           collidedLastFrame = true;
           cout << "yes" << endl;
           return Vector2D{ ball.getVelocity().x*-2,0 } / collisionTime;
       }

      
    }
  
   else
    {
        collidedLastFrame = false;
        cout << "no"<<endl;
        return Vector2D{ 0, 0 };
    }
}