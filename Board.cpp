#include "Board.h"
#include <cstdlib>
#include <ctime>
#include <cassert>

Tile::Tile(){
    _color = "";
    _tile_type = "";
}

Tile::Tile(string color, string tileType){
    _color = color;
    _tile_type = tileType;
}

string Tile::getColor() const{
    return _color;
}

string Tile::getTileType() const{
    return _tile_type;
}

void Tile::setColor(string color) {
    _color = color;
}

void Tile::setTileType(string tileType) {
    _tile_type = tileType;
}

Board::Board(int num_players)
{
    resetBoard(num_players);
}

void Board::resetBoard(int num_players)
{
    const int COLOR_COUNT = 3;
    const string COLORS[COLOR_COUNT] = {MAGENTA, GREEN, BLUE};
    Tile new_tile;
    string current_color;


    for (int i = 0; i < _BOARD_SIZE - 1; i++)
    {
        current_color = COLORS[i % COLOR_COUNT];
        new_tile = {current_color, "regular tile"};
        _tiles[i] = new_tile;
    }
    new_tile = {ORANGE, "regular tile"};
    _tiles[_BOARD_SIZE - 1] = new_tile;

    _candy_store_count = 0;
    for (int i = 0; i < _MAX_CANDY_STORE; i++)
    {
        _candy_store_position[i] = -1; 
    }

    for (int i = 0; i < num_players; i++){
        _player_positions.push_back(0);
    }
}

void Board::displayTile(int position) {
    if (position < 0 || position >= _BOARD_SIZE) {
        return;
    }

    Tile target = _tiles[position];

    cout << target.getColor() << " ";

    bool playerOnTile = false;
    for (int i = 0; i < _player_positions.size(); i++) {
        if (position == _player_positions[i]) {
            cout << i + 1;
            playerOnTile = true;
        }
    }

    if (!playerOnTile) {
        cout << " ";
    }

    cout << " " << RESET;
}


// void Board::displayTile(int position)
// {
//     if (position < 0 || position >= _BOARD_SIZE)
//     {
//         return;
//     }
//     Tile target = _tiles[position];
//     cout << target.color;
//     for (int i = 0; i < _player_positions.size(); i++) {
//         if (position == _player_positions[i]) {
//             cout << i + 1;
//         } else {
//             cout << " ";
//         }
//     }
//     cout << " " << RESET;
//     // keep this old code in case i fuck something up and i need the logic
//     // if (position == _player_positions[0])
//     // {
//     //     cout << "X";
//     // }
//     // else
//     // {
//     //     cout << " ";
//     // }
//     // cout << " " << RESET;
// }

void Board::displayBoard()
{
    // First horizontal segment
    for (int i = 0; i <= 23; i++)
    {
        displayTile(i);
    }
    cout << endl;
    // First vertical segment
    for (int i = 24; i <= 28; i++)
    {
        for (int j = 0; j < 23; j++)
        {
            cout << "   ";
        }
        displayTile(i);
        cout << endl;
    }
    // Second horizontal segment
    for (int i = 52; i > 28; i--)
    {
        displayTile(i);
    }
    cout << endl;
    // Second vertical segment
    for (int i = 53; i <= 57; i++)
    {
        displayTile(i);
        for (int j = 0; j < 23; j++)
        {
            cout << "   ";
        }
        cout << endl;
    }
    // Third horizontal segment
    for (int i = 58; i < _BOARD_SIZE; i++)
    {
        displayTile(i);
    }
    cout << ORANGE << "Castle" << RESET << endl;
}

bool Board::setPlayerPosition(int player, int new_position)
{
    if (new_position >= 0 && new_position < _BOARD_SIZE)
    {
        _player_positions[player - 1] = new_position;
        return true;
    }
    return false;
}

int Board::getBoardSize() const
{
    return _BOARD_SIZE;
}

int Board::getCandyStoreCount() const
{
    return _candy_store_count;
}

vector<int> Board::getPlayerPositions() const
{
    return _player_positions;
}

bool Board::addCandyStore(int position)
{
    if (_candy_store_count >= _MAX_CANDY_STORE)
    {
        return false;
    }
    _candy_store_position[_candy_store_count] = position;
    _candy_store_count++;
    return true;
}
/*
bool Board::populateCandyStores(){
    // this code will randomly generate a magenta tile in the first 27 tiles using modulus
    // and place a candy store there.
    // it will use altered logic to place a candy store on a green tile somewhere between 28 - 54
    // and a candy store on some a store on some blue tile 55 - 82
}
*/

bool Board::isPositionCandyStore(int board_position)
{
    for (int i = 0; i < _candy_store_count; i++)
    {
        if(_candy_store_position[i] == board_position)
        {
            return true;
        }
    }
    return false;
}

bool Board::movePlayer(int player, int tiles_to_move_forward)
{
    int new_player_position = tiles_to_move_forward + _player_positions[player - 1];
    if(new_player_position < 0 || new_player_position >= _BOARD_SIZE)
    {
        return false;
    }
    _player_positions[player - 1] = new_player_position;
    return true;
}

Candy_Store::Candy_Store(){
    for (int i = 0; i < 3; i++){
        _inventory.push_back(Candy());
    }
    _name = "";
}

Candy_Store::Candy_Store(vector<Candy> inventory, string name) {
    for (int i = 0; i < 3; i++) {
        _inventory.push_back(inventory[i]);
    }
    _name = name;
}

string Candy_Store::getName() const{
    return _name;
}

void Candy_Store::printInventory() {
    for (int i = 0; i < _inventory.size(); i++) {
        cout << "Name: " << _inventory[i].name << endl;
        cout << "Description: " << _inventory[i].description << endl;
        cout << "Effect: " << _inventory[i].effect_type << endl;
        cout << "Effect Value: " << _inventory[i].effect_value << endl;
        cout << "Candy Type: " << _inventory[i].candy_type << endl;
        cout << "Price: " << _inventory[i].price << endl;
        cout << "--------------------------------------------------------------------------" << endl;
    }
}

void Candy_Store::removeCandy(string target) {
    vector<Candy> temp;
    for (int i = 0; i < _inventory.size(); i++) {
        if (_inventory[i].name != target) {
            temp.push_back(_inventory[i]);
        }
    }
    _inventory = temp;
}

Candy Candy_Store::findCandy(string candy_name) {
    for (int i = 0; i < _inventory.size(); i++) {
        if (_inventory[i].name == candy_name) {
            return _inventory[i];
        }
    }
    Candy empty;
    return empty;
}

void Candy_Store::setName(string name) {
    _name = name;
}

int Candy_Store::getInventorySize() const{
    return _inventory.size();
}

bool Candy_Store::candyInInventory(string candy_name){
    for (int i = 0; i < _inventory.size(); i++) {
        if (_inventory[i].name == candy_name) {
            return true;
        }
    }
    return false;
}

int Board::getCandyStoreIndex(int board_position) {
    for (int i = 0; i < _candy_store_count; i++){
        if (_candy_store_position[i] == board_position){
            return i;
        }
    }
    return -1;
}


// bool Board::isMagentaTileAhead(bool isDoubleCard){
//     if (isDoubleCard) {
//         for (int i = _player_position + 1; i < _BOARD_SIZE; i++) {
//             if (i % 3 == 1) {
//                 int newPosition = i;
//                 if (newPosition + 3 > 83){
//                     return true;
//                 } else {
//                     return false;
//                 }
//             } else {
//                 return false;
//             }
//         }
//     } else {
//         for (int i = _player_position + 1; i < _BOARD_SIZE; i++){
//             if (i % 3 == 1) {
//                 return true;
//             } else {
//                 return false;
//             }
//         }
//     }
// }