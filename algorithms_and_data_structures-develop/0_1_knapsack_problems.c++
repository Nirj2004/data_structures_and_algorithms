#include <iostream>
#include <vector>
#include <cmath>
#include <sstream>
#include <cctype>


int maximum_possible_loot_value(const std::vector<int>& weights,
    const std::vector<int>& values, const int capacity)
{
    int items_count = values.size();
    std::vector<std::vector<int>>loots(items_count + 1, std::vector<int>(capacity + 1));
    for (int i = 0; i <= items_count; ++i) {
        for (int w = 0; w <= capacity; ++w) {
            if ( i == 0 || w == 0 ) {
                loots[i][w] = 0;
            }
            else if (weights[i-1] <= w) {
                loots[i][w] = loots[i-1][w];
            }
        }
    }
    return loots[items_count][capacity];
}

void print_vector(const std::vector<int>& vec) {
    for (auto v : vec) {
        std::cout << v << " ";
    }
    std::cout << std::endl;
}


int main()
{
    std::vector<int> values{40, 10, 90};
    std::vector<int> weights{20, 40, 60};
    int capacity = 190;
    std::cout << "Weights of items: ";
    print_vector(values);
    std::cout << " Capacity :" << capacity << std::endl;
    std::cout << "Maximum possible loot value for capacity" << capacity
       << " : " << maximum_possible_loot_value(weights, values, capacity) << std::endl;
    return 0;
}