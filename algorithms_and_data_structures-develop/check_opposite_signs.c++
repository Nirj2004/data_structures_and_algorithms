#include <iostream>

  bool are_of_different_signs(int a, int b)
  {
      return ((a ^ b) < 0);
  }

  int main()
  {
      int a, b;
      std::cout << "Enter number 1: ";
      std::cin >> a;
      std::cout << "Enter number 2: ";
      std::cin >> b;
      if (are_of_different_signs(a, b))
      { 
          std::cout << a << " and " << b << " are of different signs " << std::endl;
      }
      else
      {
          std::cout << a << " and " << b << " are of same signs " << std::endl;
      }
      return 0;
  }