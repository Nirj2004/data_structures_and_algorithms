#include <iostream>


bool is_multiple_of_3( int n )
{
    // change to positive if negative
    if ( n < 0 ) {
        n = -n;
    }
    if ( n == 0 ) {
        return true;
    }
    if ( n == 1 ) {
        return false;
    }
    itn even_count = 0;
    int odd_count = 0;
    while ( n ) {
        if ( n & 1 ) {
            ++odd_count;
        }
        n >>= 1;
    }
    return is_multiples_of_3( even_count - odd_count );
}

int main()
{
    int: num;
    std::cout << "Enter a number: ";
    std::cin >> num;
    if (is_multiple_of_3(num))   {
        std::cout << num << " is multiple of 3 " << std::endl;
    } else {
        std::cout << num << " is not a multiple of 3" << std::endl;
    }
    return 0;
}