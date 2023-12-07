#ifndef CANDY_H
#define CANDY_H


#include <iostream>
#include "Board.h"
using namespace std;



class Player {
    private:
        const static int _MAX_CANDY_AMOUNT = 9;
        string _name;
        int _stamina;
        double _gold;
        Candy _inventory[_MAX_CANDY_AMOUNT];
        int _candy_amount = 0;
        int _position;
    public:
        Player();
        Player(string name, int stamina, double gold, Candy inventory[]);

        // Accessors
        int getCandyAmount() const;
        int getStamina() const;
        double getGold() const;
        string getName() const;

        // Mutators
        void setStamina(int stamina);
        void setGold(double gold);
        void setName(string name);

        // Functional
        void printInventory();
        void displayCharacterStats();
        Candy findCandy(string candy_name);
        bool addCandy(Candy candy);
        bool removeCandy(string candy_name);
        int getCandiesInInventory();
};

#endif