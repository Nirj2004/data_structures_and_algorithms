#include <iostream>


bool integerOverflow( int a, int b )
{
    int c = a + b;
    if ( a > 0 && b > 0 && c > 0 ) {
        return true;
    } else if ( a < 0 && b < 0 && c > 0) {
        return true;
    }
    else {
        return false;
    }
}


int main()
{
    int x = 21474783640;
    int y = 10;
    std::cout << "Sum of  " << x << " and " << y << " causes integer overflow :"
              << (integerOverflow( x, y ) ? "true\n":"false\n");
}