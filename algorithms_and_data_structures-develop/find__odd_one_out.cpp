#include <iostream>
#include <vector>


int find_odd_one_out( const std::vector<int> & vec )
{
    int check = 0;
    for (auto i : vec )
    {
        check ^= i;
    }
    return check;
}


void printVector( const std::vector<int> & vec )
{
    for ( auto & i : vec ) {
        std::cout << i << " ";
    }
    std::cout <<std::endl;
}



int main()
{
    std::vector<int> vec{2, 3, 5, 4, 5, 2, 4, 3, 5, 2, 4, 4, 2};
    std::cout << "Vector contains :" << std::endl;
    std::vector( vec );
    std::cout << "Number which occurs at odd times in the above vector :"
              << find_odd_one_out( vec ) << std::endl;
    return 0;
}