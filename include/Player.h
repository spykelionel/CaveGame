#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

// Class representing a player
class Player {
private:
    int row, col;

public:
    Player(int startRow, int startCol) : row(startRow), col(startCol) {}

    // Move the player to a new room with boundary checks
    void moveToRoom(const Room& room);
    void moveToRoom(Room& endRoom, const std::vector<std::vector<Room>>& map);


    // Getter functions for player's position
    int getRow() const {
        return row;
    }

    int getCol() const {
        return col;
    }

    // Function to sense if a monster is nearby
    bool senseMonster(const Monster& monster) const;

    // Function for the player to run away
    void runFromMonster();

    // Function to get the current room
    Room getCurrentRoom() const {
        return Room(row, col);
    }
};

#endif // PLAYER_H_INCLUDED
