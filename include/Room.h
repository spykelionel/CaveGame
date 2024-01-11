#ifndef ROOM_H
#define ROOM_H
#include "Types.h"

class Room {
public:
    int row, col;
    RoomType type;
    // By default all rooms are of type=normal.
    Room(int row, int col, RoomType type = RoomType::Normal) : row(row), col(col), type(type) {}

};
#endif // ROOM_H
