#include "Interface.h"

Interface::Interface()
{
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;  // Remove this line if the game was too laggy
    window.create(sf::VideoMode(GAME_WIDTH, GAME_HEIGHT), "Pinball", sf::Style::Titlebar, settings);
    window.setVerticalSyncEnabled(true);
}

void Interface::getControls(bool & exit, bool & left, bool & right)
{
    sf::Event event;
    while (window.pollEvent(event));
    exit = sf::Keyboard::isKeyPressed(sf::Keyboard::Escape);
    left = sf::Keyboard::isKeyPressed(sf::Keyboard::Left);
    right = sf::Keyboard::isKeyPressed(sf::Keyboard::Right);
}



void Interface::clear()
{
    window.clear(backgroundColor);
}

void Interface::display()
{
    window.display();
}

void Interface::drawBall(Vector2D center, float radius)
{
    sf::CircleShape circle(radius);
    circle.setOrigin(radius, radius);
    circle.setOutlineThickness(outlineThickness);
    circle.setOutlineColor(outlineColor);
    circle.setFillColor(ballFillColor);
    circle.setPosition(center.x, center.y);
    window.draw(circle);
}

void Interface::drawFlipper(FlipperType type, Vector2D center, float length, float angle, float majorRadius, float minorRadius)
{
    float flip = type == LEFT ? 1.0f : -1.0f;

    // Draw the major circle outline
    sf::CircleShape majorCircleOutline(majorRadius); //circleradius=====majorradius
    majorCircleOutline.setOutlineThickness(outlineThickness);
    majorCircleOutline.setOutlineColor(outlineColor);
    majorCircleOutline.setFillColor(flipperFillColor);
    majorCircleOutline.setOrigin(majorRadius, majorRadius);
    majorCircleOutline.setPosition(center.x, center.y); 
    window.draw(majorCircleOutline);

    // Draw the minor circle outline
    sf::CircleShape minorCircleOutline(minorRadius);
    minorCircleOutline.setOutlineThickness(outlineThickness);
    minorCircleOutline.setOutlineColor(outlineColor);
    minorCircleOutline.setFillColor(flipperFillColor);
    minorCircleOutline.setOrigin(minorRadius - length, minorRadius);
    minorCircleOutline.setPosition(center.x, center.y);
    minorCircleOutline.rotate(angle);
    minorCircleOutline.setScale(flip, 1.0f);
    window.draw(minorCircleOutline);

    // Draw the convex shape connecting the two circles
    sf::ConvexShape convexBody(4);
    convexBody.setPoint(0, sf::Vector2f(0, -outlineThickness));
    convexBody.setPoint(1, sf::Vector2f(0, 2 * majorRadius + outlineThickness));
    convexBody.setPoint(2, sf::Vector2f(length, majorRadius + minorRadius + outlineThickness));
    convexBody.setPoint(3, sf::Vector2f(length, majorRadius - minorRadius - outlineThickness));
    convexBody.setFillColor(flipperFillColor);
    convexBody.setOrigin(0, majorRadius);
    convexBody.setPosition(center.x, center.y);
    convexBody.setRotation(angle);
    convexBody.setScale(flip, 1.0f);
    window.draw(convexBody);

    // Draw the inside circle
    sf::CircleShape insideCircle(minorRadius);
    insideCircle.setFillColor(outlineColor);
    insideCircle.setOrigin(minorRadius, minorRadius);
    insideCircle.setPosition(center.x, center.y);
    window.draw(insideCircle);

    // Draw the top line
  sf::ConvexShape topLine(4);
    topLine.setPoint(0, sf::Vector2f(0, -outlineThickness));
    topLine.setPoint(1, sf::Vector2f(0, 0));
    topLine.setPoint(2, sf::Vector2f(length, majorRadius - minorRadius));
    topLine.setPoint(3, sf::Vector2f(length, majorRadius - minorRadius - outlineThickness));
    topLine.setFillColor(outlineColor);
    topLine.setOrigin(0, majorRadius);
    topLine.setPosition(center.x, center.y);
    topLine.setRotation(angle);
    topLine.setScale(flip, 1.0f);
    window.draw(topLine);

    // Draw the bottom line
    sf::ConvexShape bottomLine(4);
    bottomLine.setPoint(0, sf::Vector2f(0, 2 * majorRadius));
    bottomLine.setPoint(1, sf::Vector2f(0, 4 * minorRadius + outlineThickness));
    bottomLine.setPoint(2, sf::Vector2f(length, majorRadius + minorRadius + outlineThickness));
    bottomLine.setPoint(3, sf::Vector2f(length, majorRadius + minorRadius));
    bottomLine.setFillColor(outlineColor);
    bottomLine.setOrigin(0, majorRadius);
    bottomLine.setPosition(center.x, center.y);
    bottomLine.setRotation(angle);
    bottomLine.setScale(flip, 1.0f);
    window.draw(bottomLine);
}

void Interface::drawWall(float position)
{
    sf::Vertex line[] =
            {
                    sf::Vertex(sf::Vector2f(position, 0), outlineColor),
                    sf::Vertex(sf::Vector2f(position, GAME_HEIGHT), outlineColor)
            };
    window.draw(line,2, sf::Lines);
}

void Interface::drawCeiling(float position)
{
    sf::Vertex line[] =
    {
            sf::Vertex(sf::Vector2f(0, position), outlineColor),//up:(0,gh),(GW,GH) l:(0,0),(gw,0)
            sf::Vertex(sf::Vector2f(GAME_HEIGHT, position), outlineColor)
    };
    window.draw(line, 2, sf::Lines);
}


void Interface::drawPopBumber(float Radius, Vector2D center)
{    //bigCircle
    sf::CircleShape popbumber(Radius);

    popbumber.setFillColor(flipperFillColor);
    popbumber.setOrigin(Radius, Radius); //raduis
    popbumber.setPosition((center.x),( center.y));// center
    popbumber.setOutlineThickness(outlineThickness);
    popbumber.setOutlineColor(outlineColor);
    window.draw(popbumber);

    sf::CircleShape pop;
   pop.setRadius(Radius/2);
   pop.setPointCount(4);
   pop.setOrigin(Radius /2, Radius / 2);
   pop.setPosition((center.x), (center.y));
   pop.setFillColor(FillColor);
   pop.setOutlineThickness(outlineThickness);
   pop.setOutlineColor(outlineColor);
   pop.setRotation(45);
    window.draw(pop);


}
void Interface::drawThurstBumper(float Radius, Vector2D center,float minorRadius)
{
    sf::CircleShape ThurstBumper(Radius);

    ThurstBumper.setFillColor(FillColor);
    ThurstBumper.setOrigin(Radius, Radius); //raduis
    ThurstBumper.setPosition(center.x, center.y);// center
    ThurstBumper.setOutlineThickness(outlineThickness);
    ThurstBumper.setOutlineColor(outlineColor);
    window.draw(ThurstBumper);



    sf::CircleShape majorCircleOutline(minorRadius);
    majorCircleOutline.setOutlineThickness(outlineThickness);
    majorCircleOutline.setOutlineColor(outlineColor);
    majorCircleOutline.setFillColor(flipperFillColor);
    majorCircleOutline.setOrigin(minorRadius, minorRadius);
    majorCircleOutline.setPosition(center.x, center.y);
    window.draw(majorCircleOutline);


}
void Interface::drawKicker( Vector2D center, float Radius)
{
    sf::ConvexShape convexKicker(4);
    convexKicker.setPoint(0, sf::Vector2f(-outlineThickness, Radius));
    convexKicker.setPoint(1, sf::Vector2f(-outlineThickness, Radius));
    convexKicker.setPoint(2, sf::Vector2f(Radius / 2, Radius));
    convexKicker.setFillColor(FillColor);
    convexKicker.setOutlineColor(outlineColor);
    convexKicker.setOutlineThickness(outlineThickness);
    convexKicker.setOrigin(0, Radius);
    convexKicker.setPosition(center.x, center.y);

    window.draw(convexKicker);

}


void Interface::drawVibraniumBumper(float Radius, Vector2D center, float minorRadius)
{
    sf::CircleShape circleofVibreaniumBumper(Radius);
    circleofVibreaniumBumper.setOrigin(Radius, Radius);
    circleofVibreaniumBumper.setPosition(center.x, center.y);
    circleofVibreaniumBumper.setFillColor(SwitchColor);
    circleofVibreaniumBumper.setOutlineThickness(outlineThickness);
    circleofVibreaniumBumper.setOutlineColor(outlineColor);
    window.draw(circleofVibreaniumBumper);

    sf::CircleShape TriangleInsideVibraniumBumper;
    TriangleInsideVibraniumBumper.setRadius(minorRadius);
    TriangleInsideVibraniumBumper.setPointCount(3);
    TriangleInsideVibraniumBumper.setOrigin(Radius/2,Radius/2);
    TriangleInsideVibraniumBumper.setPosition(center.x, center.y);
    TriangleInsideVibraniumBumper.setFillColor(FillColor);
    TriangleInsideVibraniumBumper.setOutlineThickness(outlineThickness);
    TriangleInsideVibraniumBumper.setOutlineColor(outlineColor);
    window.draw(TriangleInsideVibraniumBumper);
}
void Interface::drawliveScore(float Length, float Width, string Letter,float positionX,float positionY,string scoree,bool GameOveer) {
  
  
    sf::RectangleShape score(sf::Vector2f(Length,Width));
    score.setPosition(sf::Vector2f(Length*6 , Width/100));
    score.setOutlineColor(outlineColor);
    score.setOutlineThickness(outlineThickness);
    score.setFillColor(FillColor);
    window.draw(score);

    int counter = 0;
 
    int size =30;
    sf::Font font;
    if (!font.loadFromFile("sansation.ttf")) {
        cout << "error";
    }
    for (int i = 5; counter <scoree.size(); i = i + 5) {
        sf::Text score3("a", font, 50);

        score3.setFont(font);
        score3.setCharacterSize(size);
        score3.setFillColor(sf::Color::Black);
        score3.setString(scoree[counter]);
        score3.setPosition(sf::Vector2f(Length*6 + i, Width/100));
        score3.setOutlineColor(sf::Color::Black);
        score3.setOutlineThickness(outlineThickness);
        counter++;

        window.draw(score3);
    }
    if (GameOveer == 1) {
        int counter2 = 0;
        for (int i = 20; counter2 < Letter.size(); i = i + 20) {
            sf::Text score2("a", font, 50);

            score2.setFont(font);
            score2.setCharacterSize(size);
            score2.setFillColor(sf::Color::Black);
            score2.setString(Letter[counter2]);
            score2.setPosition(sf::Vector2f(positionX + i, positionY));
            score2.setOutlineColor(sf::Color::Black);
            score2.setOutlineThickness(outlineThickness);
            counter2++;

            window.draw(score2);
        }
    }
}
void  Interface::drawSwitch(float Length, float Width) {


    sf::RectangleShape switchy(sf::Vector2f(0, Width));
    switchy.setPosition(sf::Vector2f(Width*5,Length*2));
    switchy.setOutlineColor(outlineColor);
    switchy.setOutlineThickness(outlineThickness);
    switchy.setFillColor(SwitchColor);
    window.draw(switchy);
 
}


void  Interface::drawGate(float Length, float Width) {


    sf::RectangleShape Gatey(sf::Vector2f(0, Width));
    Gatey.setPosition(sf::Vector2f(Width * 4, Length*2));
    Gatey.setOutlineColor(outlineColor);
    Gatey.setOutlineThickness(outlineThickness);
    Gatey.setFillColor(GateColor);
    window.draw(Gatey);
   

}

void Interface::drawSpeedboosters(float Radius, Vector2D center) {

    sf::CircleShape speedbooster(Radius);

    speedbooster.setFillColor(sf::Color::Cyan);
    speedbooster.setOrigin(Radius, Radius); //raduis
    speedbooster.setPosition(center.x, center.y);// center
    speedbooster.setOutlineThickness(outlineThickness);
    speedbooster.setOutlineColor(outlineColor);
    window.draw(speedbooster);
}

void Interface::drawCollectables(int size,string letter,float x,float y) {
    int counter = 0;
  
    sf::Font font;
    if (!font.loadFromFile("sansation.ttf")) {
        cout << "error";
    }
     for (int i = 350; counter<6; i=i+50) {
         sf::CircleShape collectables(x / 14);

         collectables.setFillColor(backgroundColor);
         collectables.setOrigin(x / 14, y / 14); //raduis
         collectables.setPosition(i, i);// center
         collectables.setOutlineThickness(outlineThickness);
         collectables.setOutlineColor(outlineColor);
         window.draw(collectables);
        sf::Text letter1("a",font,50);
        
        letter1.setFont(font);
        letter1.setCharacterSize(size);
        letter1.setOrigin((x/15) , (y/15) );
        letter1.setFillColor(sf::Color::Red);
        letter1.setString(letter[counter]);
        letter1.setPosition(sf::Vector2f(i,i));
        letter1.setOutlineColor(outlineColor);
        letter1.setOutlineThickness(outlineThickness);
        counter++;

        window.draw(letter1);
  }
}
void Interface::drawScoreMultiplier(float Radius, Vector2D center) {


    sf::CircleShape circleofScoreMultiplier(Radius);
    circleofScoreMultiplier.setOrigin(Radius, Radius);
    circleofScoreMultiplier.setPosition(center.x, center.y);
    circleofScoreMultiplier.setFillColor(SwitchColor);
    circleofScoreMultiplier.setOutlineThickness(outlineThickness);
    circleofScoreMultiplier.setOutlineColor(outlineColor);
    window.draw(circleofScoreMultiplier);



}
void Interface::drawBullseye(float Radius, Vector2D center) {


    sf::CircleShape circleofBullseye(Radius);
    circleofBullseye.setOrigin(Radius, Radius);
    circleofBullseye.setPosition(center.x, center.y);
    circleofBullseye.setFillColor(SwitchColor);
    circleofBullseye.setOutlineThickness(outlineThickness);
    circleofBullseye.setOutlineColor(outlineColor);
    window.draw(circleofBullseye);
}
void Interface::drawMagnets(float Radius, Vector2D center) {


    // Draw the convex shape connecting the two circles
    sf::ConvexShape convexBodyMagnets(5);
    convexBodyMagnets.setPoint(1, sf::Vector2f(Radius, Radius));
    convexBodyMagnets.setPoint(0, sf::Vector2f(Radius/8, Radius/6));
    convexBodyMagnets.setPoint(3, sf::Vector2f(Radius, Radius/6 ));
    convexBodyMagnets.setPoint(4, sf::Vector2f(-Radius,-Radius/6 ));
    convexBodyMagnets.setPoint(2, sf::Vector2f(10, Radius/3));
    convexBodyMagnets.setFillColor(sf::Color::Cyan);
    convexBodyMagnets.setOrigin(0, Radius);
    convexBodyMagnets.setOutlineThickness(outlineThickness);
    convexBodyMagnets.setOutlineColor(outlineColor);
    convexBodyMagnets.setPosition(center.x, center.y);
    
    window.draw(convexBodyMagnets);
}
void  Interface::drawRamp(float Length, float Width) {


    sf::RectangleShape Rampy(sf::Vector2f(Length, Width));
    Rampy.setPosition(sf::Vector2f(Width * 1.3, Width / 2));
    Rampy.setOutlineColor(outlineColor);
    Rampy.setOutlineThickness(outlineThickness);
    Rampy.setFillColor(RampColor);
    window.draw(Rampy);
    sf::RectangleShape Ramp2(sf::Vector2f(Length, Width));
    Ramp2.setPosition(sf::Vector2f(Width * 1.5, Width / 2));
    Ramp2.setOutlineColor(outlineColor);
    Ramp2.setOutlineThickness(outlineThickness);
    Ramp2.setFillColor(RampColor);
    window.draw(Ramp2);


}