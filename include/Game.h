#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

// Class representing the game
class Game {
private:
    Player player;
    Monster monster;
    Room startRoom;
    Room endRoom;

public:
    Game(int numRows, int numCols) : player(0, 0), monster(numRows - 1, numCols - 2), startRoom(0, 0), endRoom(numRows - 1, numCols - 1) {}

    // Function to move the player from the start to the end, avoiding the monster
    void movePlayerToEnd();
};

// Implement functions outside class declarations


#endif // GAME_H_INCLUDED
