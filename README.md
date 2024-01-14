# Introduction
The cave game is a text-based simulation where a player (P) starts in a room located at the bottom-left corner of a cave grid and must navigate through various rooms to reach the exit located at the top-right corner. However, there is a malicious monster (M) within the cave that aims to impede the player's progress.

The cave is represented as a grid of rooms, and each room has different characteristics. There are normal rooms, poisonous rooms (marked in green), and trap rooms (marked in dark red). The player has a finite number of health points, which may decrease depending on the type of room they enter. Normal rooms do not cause health loss, while poisonous rooms cause the player to lose health points after each move until they are cured. Trap rooms immediately decrease the player's health by a fixed amount and end their turn.

The player can make up to two moves per turn, while the monster moves once. If the player enters a poisonous or trap room, the room's color changes to indicate its hazardous nature.

The game is designed using classes, including Character (abstract base class with Player and Monster subclasses), Room (with PoisonRoom and TrapRoom subclasses), Map, and Game. The classes and their methods form the application programming interface (API) for the game.

The player and monster move through the rooms, and the game checks for end-game conditions, such as the player and monster being in the same room or the player reaching the exit. The game manages the overall game state and alternates between player and monster turns.

The player has health points, can be damaged, poisoned, and has a probability of curing poison. The player moves in the direction specified by the user's mouse click, and their goal is to visit every room while avoiding the monster.

The monster, on the other hand, senses the player's position and decides whether to move towards the player or towards the exit based on their relative positions.

The game utilizes modular design, where each class manages its own data and the game focuses on checking end-game conditions and changing turns. The map is a collection of rooms arranged in a rectangular grid, and the game initializes the map, player, and monster during setup.
