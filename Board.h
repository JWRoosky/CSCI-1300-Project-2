#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include <vector>
#define RED "\033[;41m"     /* Red */
#define GREEN "\033[;42m"   /* Green */
#define BLUE "\033[;44m"    /* Blue */
#define MAGENTA "\033[;45m" /* Magenta */
#define CYAN "\033[;46m"    /* Cyan */
#define ORANGE "\033[48;2;230;115;0m"  /* Orange (230,115,0)*/
#define RESET "\033[0m"

using namespace std;

struct Candy
{
    string name;
    string description;
    string effect_type;
    int effect_value;
    string candy_type;
    double price;
};

class Tile
{
    private:
        string _color;
        string _tile_type;
    public:
        // Constructors
        Tile();
        Tile(string color, string tileType);

        // Accessors
        string getColor() const;
        string getTileType() const;
        
        // Mutators
        void setColor(string color);
        void setTileType(string tileType);
};

struct Card
{
    string color;
    bool isDouble;
};

class Candy_Store {
    private:
        vector<Candy> _inventory;
        string _name;
    public:
        Candy_Store();
        Candy_Store(vector<Candy> inventory, string name);

        // Accessors
        string getName() const;
        int getInventorySize() const;
        void printInventory();
        Candy findCandy(string candy_name);

        // Mutators
        void setName(string name);
        void removeCandy(string target);

        bool candyInInventory(string candy_name);
};

class Board
{
private:
    const static int _BOARD_SIZE = 83;
    Tile _tiles[_BOARD_SIZE];
    const static int _MAX_CANDY_STORE = 3;
    int _candy_store_position[_MAX_CANDY_STORE];
    int _candy_store_count;
    vector<int> _player_positions;

public:
    Board(int num_players);

    void resetBoard(int num_players);
    void displayTile(int);
    void displayBoard();

    bool setPlayerPosition(int player, int new_position);

    int getBoardSize() const;
    int getCandyStoreCount() const;
    vector<int> getPlayerPositions() const;

    bool addCandyStore(int);
    bool populateCandyStores();
    bool isPositionCandyStore(int); 

    bool movePlayer(int player, int tiles_to_move_forward);
    int getCandyStoreIndex(int board_position);

    // Tile setters


    // Card functions
    bool isMagentaTileAhead(bool isDoubleCard);
    bool isGreenTileAhead(bool isDoubleCard);
    bool isBlueTileAhead(bool isDoubleCard);
};

#endif