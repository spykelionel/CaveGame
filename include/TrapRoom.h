#ifndef TRAPROOM_H_INCLUDED
#define TRAPROOM_H_INCLUDED

// Class representing a trap room (inherits from Room)
class TrapRoom : public Room {
public:
    TrapRoom(int row, int col) : Room(row, col, RoomType::Trap) {}
};


#endif // TRAPROOM_H_INCLUDED
