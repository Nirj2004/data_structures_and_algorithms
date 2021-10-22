#include <vector>
#include <iostream>
#include <sstream>


int min_guards_required(std::vector<int> & cities ) {
    int guardCount = 0;
    int unsafeRoads = 0;
    int n = cities.size();
    if ( n == 1 ) {
        std::cout << guardCount << std::endl;
        return 0;
    }
    int i = 0;
    while ( i < n - 1 ) {
        unsafeRoads = 0;
        if (cities[i] == 0 && cities[i+1] == 0 ) {
            while(i < n-1 && cities[i] == 0 && cities[i+1] == 0 ) {
                    ++unsafeRoads;
                    ++i;
            }
            if ( unsafeRoads <= 2 ) {
                guardCount += 1;
            } else {
                if ( unsafeRoads % 2 ) {
                    guardCount += (unsafeRoads/2) + 1;
                } else {
                    guardCount += unsafeRoads/2;
                }
            }
        }
        ++i;
    }
    return guardCount;
}



int main() {
    int n;
    std::cin >> n;
    std::vector<int> cities(n);
    for(int i = 0; i < n; ++i ) {
        std::cin >> cities[i];
    }
    std::cout << min_guards_required(cities) << std::endl;
    return 0;
}