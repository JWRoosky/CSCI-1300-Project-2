#include <iostream>
#include "CandyStore.h"
using namespace std;

CandyStore::CandyStore(){
    _store_name = "";
    _candy_count = 0;
}

CandyStore::CandyStore(string store_name){
    _store_name = store_name;
    _candy_count = 0;
}

bool CandyStore::addCandy(Candy candy){
    if (_candy_count == _MAX_CANDIES){
        cout << "Unable to add more candies to store " << _store_name << endl;
        return false;
    }
    _candy_count++;
    _candies[_candy_count] = candy;
    return true;
}

void CandyStore::displayCandies() const{ // this code will be altered to show the full stats and description of each candy in a store
    if (_candy_count == 0){
        cout << "There are no candies available in this store: " << endl;
        return;
    }
    cout << "Candies present in store " << _store_name << endl;
    for (int i = 0; i < _candy_count; i++){
        cout << _candies[i].name << " ";
    }
}

void CandyStore::fillCandyStoreInventory(){} // This function will populate a candy store with either magic candies,
                                             // poison candies, immunity candies or gummy candies all of varying strengths

// bool removeCandy(string candy_name){} // removes a candy by searching through the array of candies in a store's inventory
                                      // and returns true if it was able to find and remove the candy, and returns false if 
                                      // it was unable to find the specified candy.