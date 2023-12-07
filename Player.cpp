#include "Player.h"
#include <cstring>

Player::Player(){
    _name = "";
    _stamina = 0;
    _gold = 0;
    _candy_amount = 0;
    _position = 0;
    for (int i = 0; i < _MAX_CANDY_AMOUNT; i++){
        _inventory[i] = Candy{"", "", "", 0, "", 0.0};
    }
}

Player::Player(string name, int stamina, double gold, Candy candy_array[]){
    _name = name;
    _stamina = stamina;
    _gold = gold;   

    for (int i = 0; i < _MAX_CANDY_AMOUNT; i++){
        if (candy_array[i].name != ""){
            _inventory[i] = candy_array[i];
            _candy_amount ++;
        }
        else{
            _inventory[i] = Candy{"", "", "", 0, "", 0.0};
        }
    }
    _position = 0;
}

// Accessors
int Player::getCandyAmount() const{
    return _candy_amount;
}

int Player::getStamina() const{
    return _stamina;
}

double Player::getGold() const{
    return _gold;
}

string Player::getName() const{
    return _name;
}

// Mutators
void Player::setStamina(int stamina){
    _stamina = stamina;
}

void Player::setGold(double gold){
    _gold = gold;
}

void Player::setName(string name){
    _name = name;
}

// Functional
void Player::printInventory(){
    for (int i = 0; i < _MAX_CANDY_AMOUNT; i++){
        if (i == 3 || i == 6){
            cout << endl;
        }
        
        if (_inventory[i].name.length() == 0){
            cout << "[Emtpy]   ";
        } else {
            cout << "[" << _inventory[i].name << "]   ";
        }
    }
    cout << endl;
}

void Player::displayCharacterStats(){
    cout << "Name: " << _name << endl;
    cout << "Stamina: " << _stamina << endl;
    cout << "Gold: " << _gold << endl;
    cout << "Candies: " << endl;
    printInventory();
}

Candy Player::findCandy(string candy_name) {
    // Convert the search name to lowercase for case-insensitive comparison
    for (int i = 0; i < candy_name.length(); i++) {
        candy_name[i] = tolower(candy_name[i]);
    }

    for (int i = 0; i < _MAX_CANDY_AMOUNT; i++) {
        // Convert the inventory candy name to lowercase for case-insensitive comparison
        string inventoryCandyName = _inventory[i].name;
        for (int j = 0; j < inventoryCandyName.length(); j++) {
            inventoryCandyName[j] = tolower(inventoryCandyName[j]);
        }

        if (candy_name == inventoryCandyName) {
            return _inventory[i];
        }
    }
    Candy candy;
    return candy;
}

bool Player::addCandy(Candy candy){
    if (_candy_amount == _MAX_CANDY_AMOUNT){
        return false;
    }
    if (candy.name != "") {
        _inventory[_candy_amount] = candy;
        _candy_amount++;
    }
    return true;
}

int Player::getCandiesInInventory() {
    int count = 0; 
    for (int i = 0; i < _MAX_CANDY_AMOUNT; i++) {
        if (_inventory[i].name != "") {
            count++;
        }
    }
    return count;
}

bool Player::removeCandy(string candy_name){
    for (int i = 0; i < candy_name.length(); i++){
        candy_name[i] = tolower(candy_name[i]);
    }
    for (int i = 0; i < _MAX_CANDY_AMOUNT; i++){
        string temp = _inventory[i].name;
        for (int j = 0; j < temp.length(); j++){
            temp[j] = tolower(temp[j]); // Use 'j' as the index for temp, not 'i'
        }
        if (temp == candy_name){
            for (int j = i; j < _MAX_CANDY_AMOUNT - 1; j++){
                _inventory[j] = _inventory[j + 1];
            }
            _inventory[_MAX_CANDY_AMOUNT - 1] = Candy{"", "", "", 0, "", 0.0};
            _candy_amount--;
            return true;
        }
    }
    return false;
}


// bool Player::removeCandy(string candy_name){
//     for (int i = 0; i < candy_name.length(); i++){
//         candy_name[i] = tolower(candy_name[i]);
//     }
//     for (int i = 0; i < _MAX_CANDY_AMOUNT; i++){
//         string temp = _inventory[i].name;
//         for (int j = 0; j < temp.length(); j++){
//             temp[i] = tolower(temp[i]);
//         }
//         if (temp == candy_name){
//             for (int j = i; j < _MAX_CANDY_AMOUNT - 1; j++){
//                 _inventory[j] = _inventory[j + 1];
//             }
//             _inventory[_MAX_CANDY_AMOUNT - 1] = Candy{"", "", "", 0, "", 0.0};
//             _candy_amount --;
//             return true;
//         }
//     }
//     return false;
// }