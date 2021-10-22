#include <iostream>
#include <string>




bool is_match(const std::string& str, const std::string& pattern)
{
    int slen = str.length();
    int pLen = pattern.length();
    int i = 0;
    int j = 0;
    int last_star_position = -1;
    int last_match = -1;
    while (i < sLen) {
        if (j < pLen && (str[i] == pattern[j] ||
           pattern[j] == '?')) {
           ++i;
           ++j;
        } 
    } else if (j < pLen && pattern[j] == '*') {
        last_star_position = j;
        last_match = i;
        j++;
    }
    else if (last_star_position != -1) {
        j = last_star_position + 1;
        last_match++;
        i = last_match;
    }
    else return false;
}

while (j < pLen && pattern[j] == '*') {
    ++j;
}
return j == pLen;
}

int main()
{
    std::string str{"cabcab"};
    std::string pattern{"*ab"};
    if (is_match(str, pattern)) {
        std::cout << "'" << str << "'"
        << " and '" << pattern << "'" << " are a matchy\n";
    } else {
        std::cout << "'" << str << "'"
        << " and '" << pattern << "'" << "are not a match\n";
    }
    return 0;
}