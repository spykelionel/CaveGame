#ifndef CHARACTER_H_INCLUDED
#define CHARACTER_H_INCLUDED
#include<vector>

class Character {
protected:
    Vector position;
    int movesLeft;

public:
    Character(const Vector& position) : position(position), movesLeft(2) {}

    virtual void senseGame(class Game& game) = 0;
    virtual void moveCharacter(const Vector& direction, Game& game) = 0;
    virtual void updateCharacter(Game& game) = 0;

    void resetMoveAllowance() {
        movesLeft = 2;
    }

    void takeDamage(int amount) {
        // Implement taking damage logic
        std::cout << "Character took " << amount << " damage.\n";
    }
};

#endif // CHARACTER_H_INCLUDED
