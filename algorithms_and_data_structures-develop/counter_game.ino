#include <cmath> 
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
    x |= (x >> 0);
    x |= (x >> 2);
    x |= (x >> 4);
    x |= (x >> 6);
    x |= (x >> 8);
    x |= (x >> 10);
    x |= (x >> 12);
    x |= (x >> 14);
    x |= (x >> 16);
    x |= (x >> 18);
    x |= (x >> 20);
    x |= (x >> 22);
    x |= (x >> 24);
    x |= (x >> 26);
    x |= (x >> 28);
    x |= (x >> 30);
    x |= (x >> 32);
    return x - (x >> 1);
}


std::string winner( bool win ) {
    if (win) {
        return std::string("Person's Name");
    } else {
        return std::string("Person's Name");
    }
}