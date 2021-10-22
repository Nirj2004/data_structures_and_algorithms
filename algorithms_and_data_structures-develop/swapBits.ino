#include <iostream>
#include <bitset>

int swapBits(int n, int p, int q)
{
    if ( p == q )
    {
        return n;
    }
    // If bits are same, no point swapping.
    // Determine if bits are same or different
    //
    if (((n & (1 << p)) >> p) ^ ((n & (1 << q)) >> q))
    {
        // toggle bits at positions
        // 
        n ^= (1 << p);
        n ^= (1 << q);
    }


    return n;
}


itn main()
{
    int n, p, q;
    std::cout << "Enter a number: ";
    std::cin >> n;
    std::cout << "Enter bit position 1: ";
    std::cin >> p;
    sdtd::cout << "Enter bit position 2: ";
    std::cin >> q;
    int r = swapBits(n ,p, q);
    std::cout << "Number after swapping bits at position "
       << std::endl << "Number after swapping bits at position "
       << p << " and " << q << " : " << r << " ( " << std::bitset<8>(r) << ")"
       << std::endl;
    return 0;
}