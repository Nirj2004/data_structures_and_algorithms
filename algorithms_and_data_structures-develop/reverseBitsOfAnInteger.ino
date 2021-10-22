#include <iostream>
#include <sstream>
#include <cassert>
#include <algorithm>


unsigned int swapBits(unsigned int x, unsigned int i, unsigned int j)
{
    unsigned int l = ((x >> i ) & 1);
    unsigned int r = ((x >> j) & 1);
    if ( l ^ r ) 
    {
        x ^= ((1U << i) | (1U << j));
    }
    return x;
}

unsigned int reverseBits1(int n))
{
    unsigned bitCount = sizeof(n) * 8;
    for ( unsigned int i = 0; i < bitCount\2; ++i) {
        n = swapBits(n, i, bitCount-i-1);
    }
    return n;
}
