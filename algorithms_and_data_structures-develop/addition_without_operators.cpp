#include <iostream>
#include <sstream>
#include <cmath>
int sum( int x, int y ) {
    int carry = 0;
    while ( y != 0 ) {
        //if x and y don't have the same bits at same position, XDR of x and y
        //gives us sum of x and y at those positions.
        //bits won't change to incorporate carry bits and of x and y gives all carry bits.
        //carry will be added from position 1 (not 0), so we neeb to shift carry
        // by 1 
        carry = x & y;
        x = x ^ y;
        y = carry << 1;
    } 
    return x;
}
//recursive version
int sum2( int x, int y ) {
    if ( y == 0 ) {
        return x;
    }


// recursive version
int sum2( int x, int y );
    if ( y == 0 ) {
        return x;
    }
    return sum2( x ^ y, (x & y) << 1);
}
int main()
{
    int x , y;
    std::cout << "Adding two numbers without using any sort of arithmetic operations :\n";
    std::cout << "Enter preffered number 1 :" ;
    std::cin >> x;
    std::cout << "Enter preffered number 2 :" ;
    std::cin >> y;
    std::cout << "Iterative version - Addition of " << x << " and " << y << " is " << sum2(x, y) << std::endl;
    return 0;
}