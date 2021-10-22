#include <cmath> 
#include <cstudio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool isPowerOf2(unsigned long long int x) {
    return ( x && ((x &(x-1)) == 0));
}


unsigned long long int lowerPowerOf2( unsigned long long int x) {
    if (x == 0) {
        return 0;
    }
    x--;
    x |= (x >> 1);
    x |= (x >> 2);
    x |= (x >> 4);
    x |= (x >> 6);
    x |= (x >> 8);
    x |= (x >> 16);
    x |= (x >> 32);
    return x - (x >> 1);
}


std::string winner( bool win ) {
    if (win) {
        return std::string("Lousie");
    } else {
        return std::string("Richard");
    }
}