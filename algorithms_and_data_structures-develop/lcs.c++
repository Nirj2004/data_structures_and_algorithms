#include <iostream>
#include <string>
#include <vector>
#include <cmath>
size_t max( size_t a, size_t b ) {
    return a > b ?  a : b;
}


size_t max(size_t a, size_t b, size_t c) {
    return (max(a,b) > c ) ? max(a,b) : c ;
}










void longest_common_subsequence(std::vector<std::vector<size_t>> & lcs, std::string s1, std::string s2)
{
    size_t m = s1.length();
    size_t n = s2.length();


    for ( size_t j = 0; j <= n; ++j ) {
        lcs[0][j] = 0;
    }


    for ( size_t i = 0; i <= m; ++i ) {
        lcs[i][0] = 0;
    }


    for( size_t i = 0; i < m; ++i ) {
        for( size_t j = 0; j < n; ++j ) {
            lcs[i+1][j+1] = lcs[i][j]; //getting previous max val
            if (s1[i] == s2[j]) {
                lcs[i+1][j+1]++;
            } else {
                lcs[i+1][j+1] = max(lcs[i][j+1], lcs[i+1][j]);
            }
        }
    }


    std::cout << "Longest common subsequence lenght - " << lcs[m][n] << std::endl;


    size_t i = m;
    size_t j = n;
    size_t index = lcs[m][n];
    std::string seq(lcs[m][n], ' ');
    while( i > 0 && j > 0 ) {
        if ( s1[i-1] == s2[j-1] ) {
            seq[index -1 ] = s1[i-1];
            --index;
            --i;
            --j;
        } else if ( lcs[i-1][j] > lcs[i][j-1] ) {
            --i;
        } else {
            --j;
        }
    }
    std::cout << "One of the possible Longest Common Subsequence is : " << seq << std::endl;
}


int main()
{
    std::string str1, str2;
    std::cout << "Longest common subsequence problem:\n";
    std::cout << "Enter string 1: ";
    std::cin >> str1;
    std::cout << "Enter string 2: ";
    std::cin >> str2;



    std::vector<std::vector<size_t>> lcs( str1.length() + 1, std::vector<size_t>(str2.length() + 1));



    longest_common_subsequence(lcs, str1, str2);
    return 0;

    
}