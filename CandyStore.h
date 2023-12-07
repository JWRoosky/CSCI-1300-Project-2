#ifndef CANDYSTORE_H
#define CANDYSTORE_H
#include <iostream>
#include "Board.h"
using namespace std;

class CandyStore {
    private:
        string _store_name;
        const static int _MAX_CANDIES = 4;
        Candy _candies[_MAX_CANDIES];    
        int _candy_count = 0;
    public:
        CandyStore();
        CandyStore(string store_name);
        bool addCandy(Candy candy);
        bool removeCandy(string candy_name);
        void displayCandies() const;
        void fillCandyStoreInventory();
};

#endif