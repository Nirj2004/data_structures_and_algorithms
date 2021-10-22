#include <iostream>


bool getparity ( int num )
{
    bool parity = false;
    while( num ) {
        parity = !parity;
        num = (num & (num - 1));
    }
    return parity;
}


int main()
{
    int num;
    std::cout << "Enter number:";
    std::cin >> num;
    std::cout << "Parity of num is "
              << (getparity(num) ? "odd" : "even")
              << std::endl;
    return 0;
}