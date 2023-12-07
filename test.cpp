#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <vector>
#include <fstream>
#include <sstream>
using namespace std;
int main(){
    srand(time(0));
    int position = 5;
    for (int i = 0; i < 20; i++){
        cout << (position + i) % 3 << endl;
    }
}