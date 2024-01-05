#include <iostream>
#include <cstdlib>
#include <ctime>

// Forward declarations
class Room;
class Player;
class Monster;

// Class representing a room
class Room
{
public:
    int row, col;

    Room(int row, int col) : row(row), col(col) {}

    // You may add more functionalities to the Room class, e.g., room type, etc.
};

// Class representing a player
class Player
{
private:
    int row, col;

public:
    Player(int startRow, int startCol) : row(startRow), col(startCol) {}

    // Move the player to a new room with boundary checks
    void moveToRoom(const Room& room);

    // Getter functions for player's position
    int getRow() const
    {
        return row;
    }

    int getCol() const
    {
        return col;
    }

    // Function to sense if a monster is nearby
    bool senseMonster(const Monster& monster) const;

    // Function for the player to run away
    void runFromMonster();

    // Function to get the current room
    Room getCurrentRoom() const
    {
        return Room(row, col);
    }
};

// Class representing a monster
class Monster
{
private:
    int row, col;

public:
    Monster(int startRow, int startCol) : row(startRow), col(startCol) {}

    // Move the monster to a new room with boundary checks
    void moveToRoom(const Room& room);

    // Getter functions for monster's position
    int getRow() const
    {
        return row;
    }

    int getCol() const
    {
        return col;
    }

    // Function to sense the player's position
    void sensePlayer(const Player& player);
};

// Class representing the game
class Game
{
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

void Player::moveToRoom(const Room& room)
{
    // Move only one room at a time towards the specified room
    if (room.row == row + 1 || room.row == row - 1)
    {
        int newRow = row + (room.row - row) / abs(room.row - row);
        if (newRow >= 0 && newRow < 5)
        {
            row = newRow;
        }
    }
    if (room.col == col + 1 || room.col == col - 1)
    {
        int newCol = col + (room.col - col) / abs(room.col - col);
        if (newCol >= 0 && newCol < 5)
        {
            col = newCol;
        }
    }
}

bool Player::senseMonster(const Monster& monster) const
{
    // For simplicity, assume a distance of 2 rooms as "nearby" for the player
    return (std::abs(row - monster.getRow()) <= 2) && (std::abs(col - monster.getCol()) <= 2);
}

void Player::runFromMonster()
{
    // For simplicity, the player moves to a random adjacent room different from the current room
    int randomMove;
    Room nextRoom = getCurrentRoom();

    do
    {
        randomMove = rand() % 4;  // 0: up, 1: down, 2: left, 3: right
        nextRoom = getCurrentRoom();

        switch (randomMove)
        {
        case 0:
            nextRoom.row--;
            break;
        case 1:
            nextRoom.row++;
            break;
        case 2:
            nextRoom.col--;
            break;
        case 3:
            nextRoom.col++;
            break;
        }
    }
    while (nextRoom.row == row && nextRoom.col == col);

    moveToRoom(nextRoom);
    std::cout << "Player ran away to room (" << row << ", " << col << ").\n";
}


void Monster::moveToRoom(const Room& room) {
    // Move only one room at a time towards the player
    int newRow = row;
    int newCol = col;

    if (room.row < row) {
        newRow--;
    } else if (room.row > row) {
        newRow++;
    }

    if (room.col < col) {
        newCol--;
    } else if (room.col > col) {
        newCol++;
    }

    // Update the monster's position
    if (newRow >= 0 && newRow < 5 && newCol >= 0 && newCol < 5) {
        row = newRow;
        col = newCol;
    }
}


void Monster::sensePlayer(const Player& player)
{
    // For simplicity, the monster always moves towards the player
    if (player.getRow() < row)
    {
        row--;
    }
    else if (player.getRow() > row)
    {
        row++;
    }

    if (player.getCol() < col)
    {
        col--;
    }
    else if (player.getCol() > col)
    {
        col++;
    }
}
void Game::movePlayerToEnd() {
    std::cout << "Moving player from start to end...\n";

    while (player.getRow() != endRoom.row || player.getCol() != endRoom.col) {
        // Move the player toward the exit
        Room nextRoom = player.getCurrentRoom();

        if (nextRoom.row < endRoom.row) {
            nextRoom.row++;
        } else if (nextRoom.row > endRoom.row) {
            nextRoom.row--;
        }

        if (nextRoom.col < endRoom.col) {
            nextRoom.col++;
        } else if (nextRoom.col > endRoom.col) {
            nextRoom.col--;
        }

        player.moveToRoom(nextRoom);
        std::cout << "Player is now in room (" << player.getRow() << ", " << player.getCol() << ").\n";

        // Sense if a monster is nearby after the player has moved
        if (player.senseMonster(monster)) {
            std::cout << "A monster is nearby!\n";
            // Player has the option to run away
            player.runFromMonster();
        }

        // Move the monster after the player has moved
        monster.sensePlayer(player);
        monster.moveToRoom(player.getCurrentRoom());
        std::cout << "Monster is now in room (" << monster.getRow() << ", " << monster.getCol() << ").\n";

        // Check if the player is in the same room as the monster
        if (monster.getRow() == player.getRow() && monster.getCol() == player.getCol()) {
            std::cout << "Oh no! The player was attacked by the monster. Game over!\n";
            return;
        }
    }

    std::cout << "Player reached the end room without being attacked by the monster. Victory!\n";
}


int main()
{
// Initialize the random number generator with the current time
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    // Create a game with a 5x5 map
    Game game(5, 5);

    // Move the player from the start to the end, avoiding the monster
    game.movePlayerToEnd();

    return 0;
}
