
#include "Game.h"

#define GRAVITY 400.0f
 
            //Flipper(FlipperType type, Vector2D center, float length, float angle, float majorRadius, float minorRadius) 
Game::Game() : leftFlipper(LEFT, Vector2D{ GAME_WIDTH / 2.0f - (FLIPPER_LENGTH + FLIPPERS_DISTANCE / 2.0f), GAME_HEIGHT - 80.0f }, FLIPPER_LENGTH, 30.0f, FLIPPER_MAJOR_RADIUS, FLIPPER_MINOR_RADIUS),
rightFlipper(RIGHT, Vector2D{ GAME_WIDTH / 2.0f + (FLIPPER_LENGTH + FLIPPERS_DISTANCE / 2.0f), GAME_HEIGHT - 80.0f }, FLIPPER_LENGTH, -30.0f, FLIPPER_MAJOR_RADIUS, FLIPPER_MINOR_RADIUS)


/*
firstThurst(30, Vector2D{ GAME_WIDTH / 2.0f - (375 / 2.0f), GAME_HEIGHT - 475.0f }, 10),
firstVibranium(30, Vector2D{ GAME_WIDTH / 2.0f - (450 / 2.0f), GAME_HEIGHT - 400.0f }, 30 / 2),
livescore(100,60, "0",100*5,60/100,"0",0),
switchy(10, 90),
gate(10,90),
speedboosters(40, Vector2D{ GAME_WIDTH / 2.0f + (600 / 2.0f), GAME_HEIGHT - 400.0f })
,Collectables(30,"CIE202"),
scoremultiplier(50, Vector2D{ GAME_WIDTH / 2.0f + (570/ 2.0f), GAME_HEIGHT - 600.0f })*/


{

    file.open("InputPinball.txt");
    if (!file)
    {
        cout << "error";
    }
   
    pobstacle = NULL;
    pobstacle = new Obstacle * [gamesize];

    
    Vector2D dimension;
    Vector2D velocity;
    file >> dimension.x;
    file >> dimension.y;
    file >> velocity.x;
    file >> velocity.y;
    ball = new Ball(dimension, velocity);
    float x ;
    float y ;
    string letters;
    float z;
    bool g;
    float m;
    string l;

   
    file >> x;
    file >> y;
    file >> letters;
    file >> z;
    file >> m;
    file >> l;
    file >> g;
    livescore = new liveScore(x, y, letters, z, m, l, g);
    file >> gamesize;
    for (int i = 0; i < gamesize; i++)
    {
        float x = 0;
        float y = 0;
        float minorRadius;
        Vector2D Dimension;
        float Radius = 0;
        string letters;
        float z;
        bool g;
        float m;
        string l;
        // float Length, float Width, string letter, float positionX, float positionY, string scoree, bool GameOveer


        file >> input;
        if (input == "wall")
        {

            file >> x;

            pobstacle[i] = new Wall(x);

        }
        else if (input == "ceiling")
        {

            file >> x;

            pobstacle[i] = new Ceiling(x);

        }
        else if (input == "popbumber")
        {

            file >> Radius;
            file >> Dimension.x;
            file >> Dimension.y;

            pobstacle[i] = new PopBumber(Radius, Dimension);



        }
        else if (input == "thurstbumber")
        {

            file >> Radius;
            file >> Dimension.x;
            file >> Dimension.y;
            file >> minorRadius;
            pobstacle[i] = new ThurstBumper(Radius, Dimension, minorRadius);



        }
        else if (input == "vibranumbumber")
        {

            file >> Radius;
            file >> Dimension.x;
            file >> Dimension.y;
            file >> minorRadius;
            pobstacle[i] = new VibraniumBumper(Radius, Dimension, minorRadius);



        }
        else if (input == "collectables")
        {
            file >> x;
            file >> letters;
            file >> y;
            file >> z;
            pobstacle[i] = new Collectables(x, letters,y,z);



        }

        else if (input == "gate")
        {

            file >> x;
            file >> y;


            pobstacle[i] = new Gate(x, y);
        }
        else if (input == "switch")
        {
            file >> x;
            file >> y;

            pobstacle[i] = new Switch(x, y);
        }
        else if (input == "scorMultiplier")
        {
            file >> Radius;
            file >> Dimension.x;
            file >> Dimension.y;

            pobstacle[i] = new ScoreMultiplier(Radius, Dimension);
        }
        else if (input == "speedboosters1")
        {
            file >> Radius;
            file >> Dimension.x;
            file >> Dimension.y;

            pobstacle[i] = new Speedboosters(Radius, Dimension);
        }
        else if (input == "leftkicker")
        {

            file >> Dimension.x;
            file >> Dimension.y;
            file >> Radius;
            pobstacle[i] = new Kicker(Dimension, Radius);
        }
        else if (input == "rightslightshot")
        {

            file >> Dimension.x;
            file >> Dimension.y;
            file >> Radius;
            pobstacle[i] = new Kicker(Dimension, Radius);
        }
        else if (input == "bullseye")
        {
            file >> Radius;
            file >> Dimension.x;
            file >> Dimension.y;

            pobstacle[i] = new Bullseye(Radius, Dimension);
        }
        else if (input == "Magnets")
        {
            file >> Radius;
            file >> Dimension.x;
            file >> Dimension.y;

            pobstacle[i] = new Magnets(Radius, Dimension);

        }
        else if (input == "Ramp")
        {
            file >> x;
            file >> y;

            pobstacle[i] = new Ramps(x, y);

        }
    }
    lastFrame = high_resolution_clock::now();
    exit = left = right = false;
}

void Game::readInterfaceInput()               
{
    interface.getControls(exit, left, right);
  
    if (left)
        leftFlipper.control();
    else if (right)
        rightFlipper.control();

}

void Game::simulate()
{
    // Measuring time elapsed in-between frames
    high_resolution_clock::time_point thisFrame = high_resolution_clock::now();
    duration<float> timeSpan = duration_cast<duration<float>>(thisFrame - lastFrame);
    lastFrame = thisFrame;
    float deltaTime = timeSpan.count();  // Delta time in seconds

    Vector2D resultantAcceleration = {0, GRAVITY};  // Starting with gravity as the first acceleration contributer
    for (int i = 0; i < gamesize; i++)
    {
        resultantAcceleration += pobstacle[i]->collideWith(*ball, deltaTime);
        
    }

    ball->move(resultantAcceleration, deltaTime);

}

void Game::updateInterfaceOutput()





{
    interface.clear();


    leftFlipper.draw(interface);
    rightFlipper.draw(interface);
    //magnet.draw(interface);

    //leftKicker.draw(interface);
             //  rightKicker.draw(interface);


    for (int i = 0; i < gamesize; i++)
    {
        pobstacle[i]->draw(interface);
    }
   // bullseye.draw(interface);


    // The following two lines be replaced with a loop over collidable obstacles
    //leftWall.draw(interface);
   // rightWall.draw(interface);



   /* firstThurst.draw(interface);
    firstVibranium.draw(interface);
    livescore.draw(interface);
    switchy.draw(interface);
    gate.draw(interface);
    speedboosters.draw(interface);
    Collectables.draw(interface);
    scoremultiplier.draw(interface);*/
    if (ball->getLength() > GAME_HEIGHT)
            {

                livescore->getscore();
                livescore->Gameoover();
                livescore->getPosition();
                livescore->draw(interface);
            }
            else
            {

                livescore->getMultiplier();
                livescore->draw(interface);
            }


            //  secondThurst.draw(interface);*/

            ball->draw(interface);
            interface.display();
        }
    

/*void Game::lose()
{
    if (ball.getCenter().y - GAME_HEIGHT >= 0)

        Gameover.draw(interface);
}*/



bool Game::exited()
{
    return exit;
}
/* else if (input == "livescore")
        {

        file >> x;
        file >> y;
        file >> letters;
        file >> z;
        file >> m;
        file >> l;
        file >> g;
        pobstacle[i] = new liveScore(x, y, letters, z, m, l, g);



        }*/