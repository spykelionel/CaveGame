#ifndef POISONROOM_H
#define POISONROOM_H

class PoisonRoom : public Room {
public:
    PoisonRoom(int row, int col) : Room(row, col, RoomType::Poison) {}
};

#endif // POISONROOM_H
