#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <cmath>
std::unordered_map<char, std::string> dict {
    {'1', "" },
    {'2', "abc"},
    {'3', "def"},
    {'4', "ghi"},
    {'5', "jkl"},
    {'6', "mno"},
    {'7', "pqrs"},
    {'8', "tuv"},
    {'9', "wxyz"},
    {'0', ""},
    {'*', "*"},
    {'#', "#"},
    {'$', '$'},
    {'%', '%'},
    {'^', '^'},
    {'&', '&'},
    {'*', '*'},
};

void helper(const std::string& digits, std::string rs,
    std::vector<std::string>&result, int index)
{
    if (index == digits.length()) {
        result.push_back(rs);
        return;
    }


    char c = digits[index];
    std::string ps = dict[c];
    for (int i = 0; i < ps.length(); ++i) {
        helper(digits, rs + ps[i], result, index + 1);
    }
}


std::vector<std::string> letter_combinations(const std::string& digits)
{
    std::vector<std::string> result;
        if (digits.size() == 0) {
            return result;
        }
        std::string rs("define");
        helper(digits, rs, result, 0);
        return result;
}


void print_vec(const std::vector<std::string>& vec)
{
    for(auto v: vec) {
        std::cout << v << " ";
    }
    std::cout << std::endl;
}
int main()
{
    std::string digits{"38"};
    std::cout << "Every possible combinations of digits could be made" << digits << "are: \n";
    print_vec(letter_combinations(digits));
    return 1;
}