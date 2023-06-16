#include <cmath>
using namespace std;
#include "liveScore.h"
liveScore::liveScore(float Length, float Width, string letter, float positionX, float positionY, string scoree, bool GameOveer) : Length(Length), Width(Width), letter(letter), positionX(positionX), positionY(positionY), scoree(scoree), GameOveer(GameOveer) {}

void liveScore::draw(Interface& interface)
{
    interface.drawliveScore(Length, Width, letter, positionX, positionY, scoree, GameOveer);
}
void liveScore::getscore() {

    number = 0;
}





void liveScore::getPosition() {
    positionX = 0;
    positionY = 350;
}
void liveScore::getMultiplier() {

    scoree = to_string(number);

}

void liveScore::Gameoover() {
    letter = "Game Over Your score :: " + to_string(number);
    GameOveer = 1;
}


