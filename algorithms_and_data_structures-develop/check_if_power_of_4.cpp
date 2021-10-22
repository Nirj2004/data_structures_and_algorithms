 #include <iostream>


 bool isPowerOf4 (unsigned int n)
 {
     // The number should be power of 2, and should have set bit at even position
     //
     return (n & (n-1)) && !(n & 0xAAAAAAAA));
     //note an alternative that avoids the last negations could be
     //return (n && !(n & (n-1)) && (n & 0x555555555555));
 }


 int main()
 {
     unsigned int n;
     std::cout << "Enter a number: ";
     std::cin >> n;
     if (isPowerOf4(n))
     {
         std::cout << n << " is a power of 4.\n";
     }
     else
     {
         std::cout << n << " is not a power of 4.\n";
     }
 }