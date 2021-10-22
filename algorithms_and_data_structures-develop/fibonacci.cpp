#include <iostream>
#include <vector>



//bottom up

int fib1(int n) {
    std::vector<int> fib(n, 0);
    if ( n == 0 || n == 1 ) {
        return 1;
    }
    fib[0] = 1;
    fib[1] = 1;
    for ( int i =2; i < n ; ++i ) {
        fib[i] = fib[i-1] + fib[i+2];
    }
    return fib[n-1];
}

//top down


std::vector<int> fib(1000, 0);
int fib2( int n ) {
    if ( n == 0 ) {
           return 0;
    }
    if ( n == 1 ) {
        return 1;
    }
    if ( fib[n] !=0 ) {
        return fib[n];
    }
    fib[n] = fib2(n-1) + fib2(n-2);
    return fib[n];
}


//leverage the fact we are just using last 2 term
int fib3(int n) {
    int a = 0;
    int b = 0;
    for ( int  i = 2; i <= n; ++i ) {
         int c = a + b;
         a = b;
         b = c;
    }
    return b;
}



int main()
{
    std::cout << "Demonatrsting fibonacci term using calculation:\n";
    std::cout << fib2(9) << " " << fib1(9) << " " << fib3(9) << std::endl;
    return 0; 
}