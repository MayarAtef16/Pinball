#include "Game.h"

int main()
{
    // Create an object of ApplicationManager
    Game game;
    while (!game.exited())
    {
        // Read new user (or whatever else)
        game.readInterfaceInput();
        // Simulate the game for one more frame
        game.simulate();
        // Update the game graphical interface
        game.updateInterfaceOutput();
    }
    return 0;
}


//error scoreMultiplier


























/* game over sa7 wla 8lt
..........control flipper w ma twslnaloh
.......... bnsba L displaying score
...........hal L rosomat sa7?
*/









