#pragma once
#include <fstream>
#include <chrono>
using namespace std::chrono;

#include <string>
using namespace std;

#include "Interface.h"
#include "Defs.h"
#include "GameObjects/Ball.h"
#include "GameObjects/Obstacles/Wall.h"
#include "GameObjects/Obstacles/Ceiling.h"
#include "GameObjects/Obstacles/Kicker.h"
#include "GameObjects/Obstacles/PopBumber.h"
#include "GameObjects/Obstacles/ThurstBumper.h"
#include "GameObjects/Obstacles/VibraniumBumper.h"
#include "GameObjects/liveScore.h"
#include "GameObjects/Obstacles/Switch.h"
#include "GameObjects/Obstacles/Gate.h"
#include "GameObjects/Obstacles/Speedboosters.h"
#include "GameObjects/Obstacles/ScoreMultiplier.h"
#include "GameObjects/Obstacles/Collectables.h"
#include "GameObjects/Obstacles/Bullseye.h"
#include "GameObjects/Obstacles/Magnets.h"
#include "GameObjects/Collidable.h"
#include "GameObjects/Obstacles/Ramps.h"

#include "GameObjects/Flipper.h"

// Represents a game, keeps track of everything relevant to the game and delegates the tasks to their proper objects
class Game
{
private:
    high_resolution_clock::time_point lastFrame;  // Time point of the last rendered frame
    Interface interface;  // An object representing the game interface
    bool exit, left, right;  // Flags about the user's current controls
    int gamesize;
    string input;
    fstream file;
    // file.open("../pinpall.txt");
    Obstacle** pobstacle;

    Ball* ball;// The ball (obviously :D)
    liveScore* livescore;
    Flipper leftFlipper, rightFlipper;  // The right and left flippers
    //Magnets magnet;
   // Kicker   leftKicker, rightKicker;// The right and left Kickers
   
   /* ThurstBumper firstThurst;
    VibraniumBumper  firstVibranium;
    liveScore    livescore;
    Switch switchy;
    Gate gate;
    Speedboosters speedboosters;
    Collectables Collectables;
    ScoreMultiplier scoremultiplier;*/
  
    


   
public:
    Game();
    void readInterfaceInput();
    void simulate();
 
    void updateInterfaceOutput();
   void lose();
    bool exited();
};
