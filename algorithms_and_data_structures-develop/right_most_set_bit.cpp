#include <iostream>
#include <cmath>

int position_of_first_set_bit( int num ) 
{
    return log2(num & -num) +1;
}

int main()
{
    int num;
    std::cout << "Enter a number :";
    std::cin >> num;


    std::cout << "Position of first set bit number in binary representation of"
              << num << " is " << position_of_first_set_bit( num )
              << std::endl;


    return 0;
}