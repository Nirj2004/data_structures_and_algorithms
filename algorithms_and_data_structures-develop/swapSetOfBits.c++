#include <iostream>


int swapBits(unsigned int num, unsigned int p1,
             unsigned int p2, unsigned int n )
{
    unsigned int set1 = (num >> p1 ) & ((1U << n) - 1);
    unsigned int set2 = (num >> p2) & ((1U << n) - 1);
    unsigned int xorSets = set1 ^ set2;
    xorSets = (xorSets << p1) | (xorSets << p2);


    unsigned int finalVal = xorSets ^ num;
    return finalVal;
}


int main()
{
    std::cout << "Swapping bits in number 28, such that 2 bits starting from 0th bit and 2 bits "
                 "starting from 3rd bit are swapped, 28 becomes " << swapBits(28, 0, 3, 2)
                 << std::endl;


    std::cout << "Swapping bits in number 47, such that 3 bits starting from 1st bit(0 based counting) and 3 bits "
                "starting from 5th bit(0 based counting) are expected to be swapped, 47 becomes " << swapBits(47, 1, 5, 3)
                << std::endl;
}