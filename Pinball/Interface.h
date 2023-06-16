#pragma once

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
using namespace std;
#include <iostream>
#include "Defs.h"


// Represents the game interface
// This class is the ONLY one that interacts with the user
// This class is also the ONLY one aware of the graphics library being used
// That is, if the graphics library was to be changes, this class is the only thing to be changed
class Interface
{
private:
    sf::RenderWindow window;  // Represents the game window
    const sf::Color  // Colors used for drawing (can change the whole theme of the game)
        backgroundColor = sf::Color::Blue,
        outlineColor = sf::Color::Black,
        ballFillColor = sf::Color::Red,
        flipperFillColor = sf::Color::Red,
        FillColor = sf::Color::Green,
        OUTColor = sf::Color::Black,
        SwitchColor = sf::Color::Magenta,
        GateColor = sf::Color::Cyan,
        RampColor=sf::Color::Green;
    
    const float outlineThickness = -2.0f;  // Negative sign means inwards     

public:
    Interface();  // Constructor
    void getControls(bool & exit, bool & left, bool & right);  // Detects the buttons pressed

    void clear();  // Clears the frame (first step in rendering a new frame)
    void display();  // Displays the frame (last step in rendering a new frame)

    void drawBall(Vector2D center, float radius);  // Draws a ball
    void drawFlipper(FlipperType type, Vector2D center, float length, float angle, float majorRadius, float minorRadius);  // Draws a flipper
    void drawWall(float position);  // Draws a vertical wall
    void drawCeiling(float position);
    void drawPopBumber(float Radius, Vector2D center);
    void drawVibraniumBumper(float Radius, Vector2D center,float minorRadius);
    void drawThurstBumper(float Radius, Vector2D center,float minorRadius);
    void drawKicker(Vector2D center, float Radius);
    void drawliveScore(float Length, float Width, string letter,float positionX, float positionY,string scoree,bool GameOveer);
    void   drawSwitch(float Length, float Width);
    void drawGate(float Length, float Width);
   void drawSpeedboosters(float Radius, Vector2D center);
  void drawCollectables(int size,string letter,float x,float y);
 void drawScoreMultiplier(float Radius, Vector2D center);
 void drawBullseye(float Radius, Vector2D center);
 void drawMagnets(float Radius, Vector2D center);
 void drawRamp(float Length, float Width);
};