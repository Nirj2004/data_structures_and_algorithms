#include <iostream>
#include <vector>
#include <sstream>
#include <cmath>
// calculating catalan number using DP, Time complexity 0(n^2)
int catalan_number( int n ) {
    std::vector<int> table(n+1);
    table[0] = table[1] = 1;
    for ( int i = 2; i <= n; ++i ) {
        table[i] = 0;
        for ( int j = 0; j < i; ++i ) {
            table[i] += ( table[j] * table[i - j - 1] );
        }
    }
    return table[n];
}
int main()
{
    int n;
    std::cout << "Enter a number : ";
    std::cin >> n;
    std::cout << "Nmber of possible Binary Search Trees for " << n << " is "
              << catalan_number(n) << std::endl;
    return 0;
}