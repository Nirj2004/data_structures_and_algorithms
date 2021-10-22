#include <iostream>


int countSetBits( int x )
{
    int count = 0;
    while( x ) {
        ++count;
        x = x & (x - 1);
    }
    return count;
}


int countBitFlips( int a, int b )
{
    return countSetBits(a ^ b);
}


int main()
{
    int x, y;
    std::cout << "Enter number 1 :";
    std::cin >> x;
    std::cout << "Enter number 2 :";
    std::cin >> y;
    std::cout << "Bits flips required to convert " << x 
              << " to " << y << " is " << countBitFlips(x, y) << std::endl;
    return 0;
}