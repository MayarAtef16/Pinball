#pragma once
#include "Drawable.h"

class liveScore : public Drawable
{
private:
    float positionX;
    float positionY;
    int number = 0;
    string letter;
    Vector2D center;
    float Length;
    float Width;
    string scoree;
    bool GameOveer;
public:

    liveScore(float Length, float Width, string letter, float positionX, float positionY, string scoree, bool GameOveer);


   
    void draw(Interface& interface) override;
    void getPosition();
    void getMultiplier();
    void Gameoover();
    void getscore();
};
