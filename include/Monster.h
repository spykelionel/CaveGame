#ifndef MONSTER_H_INCLUDED
#define MONSTER_H_INCLUDED

// Class representing a monster
class Monster {
private:
    int row, col;

public:
    Monster(int startRow, int startCol) : row(startRow), col(startCol) {}

    // Move the monster to a new room with boundary checks
    void moveToRoom(const Room& room);

    // Getter functions for monster's position
    int getRow() const {
        return row;
    }

    int getCol() const {
        return col;
    }

    // Function to sense the player's position
    void sensePlayer(const Player& player);
};


#endif // MONSTER_H_INCLUDED
