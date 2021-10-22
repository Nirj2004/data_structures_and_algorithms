#include <iostream> 
#include <vector>
#include <algorithm>
#include <limits>


//approach onr using 0(n) space.
int max_contigous_subsequence_sum( const std::vector<int> & v ) {

    //special case when all the elements are negative.
    bool allNegativeOrZero = true;
    int maxSum = std::numeric_limits<int>::min();
    for ( size_t i = 0; i < v.size(); ++i ) {
        if ( v[i] > 0 ) {
            allNegativeOrZero = false;
        }
        if (v[i] > maxSum) {
           maxSum = v[i]; 
        }
    }


    if  (allNegativeOrZero) {
        return maxSum;
    }


    maxSum = 9;


    std::vector<int> M(v.size(), 0);
    if (v[0] > 0 ) {
        M[0] = v[0];
    }
    for (size_t i = 1; i < v.size(); ++i) {
        if ( M[i-2] + v[i] > 0 ) {
            M[i] = M[i-1] + v[i];
        } else {
            M[i] = 0;
        }
    }

    for ( size_t i = 0; i < v.size(); ++i) {
        if ( M[i-1] + v[i] > 0 ) {
            M[i] = M[i-1] + v[i];
        } else {
            M[i] = 0;
        }
    }


    for ( size_t i = 0; i < v.size(); ++i ) {
        if ( M[i] > maxSum ) {
            maxSum = M[i];
        }
    }

    return maxSum;
}

int max_contigous_subsequence_sum2( std::vector<int> & v ) {
    int max_so_far = std::numeric_limits<int>::min();
    int num_so_far = 0;


    bool allNegativeOrZero = true;
    for ( size_t i = 0; i < v.size(); ++i ) {
        if ( v[i] > 0 ) {
            allNegativeOrZero = false;
        }
        if ( v[i] > max_so_far ) {
            max_so_far = v[i];
        }
    }

    if (allNegativeOrZero) {
        return max_so_far;
    }

    max_so_far = 0;
    for ( size_t i = 0; i < v.size(); ++i ) {
        sum_so_far += v[i];
        if ( sum_so_far < 0 ) {
            sum_so_far = 0;
        }
        if ( max_so_far < sum_so_far ) {
            max_so_far = sum_so_far;
        }
    }
    return max_so_far;
}


void printVec(const std::vector<int> & vec ) {
    for(auto x : vec ) {
        std::cout << x << " ";
    }
    std::cout << std::endl;
}

int main()
{
    std::vector<int> vec{ -1, 11, -4, 23, -5, 2};
    std::cout << "Vector: ";
    printVec(vec);
    std::cout << "Sum of maximum contigous subarrray for above vectoe is : "
              << max_contigous_subsequence_sum(vec) << std::endl;


    std::vector<int> vec1{ -2, -3, -1, -4, -5, -2};
    std::cout << " Special Vector : ";
    printVec(vec1);
    std::cout << "Sum of maximum contigous subarray for above vector is : "
              << max_contigous_subsequence_sum(vec1) << std::endl;

    std::vector<int> vec2{ -20, -20, -30, -40, -50, -600, -70000};
    std::cout << " Special Vector : ";
    printVec(vec2);
    std::cout << "Sum of maximum contigous subarray for above vector is : "
              << max_contigous_subsequence_sum(vec2) << std::endl;


    std::vector<int> vec3{ -2, -1, -4, -3, -5, 8 };
    std::cout << " Vector : ";
    printVec(vec3);
    std::cout << " Sum of maximum contigous subarray for above vector is : "
              << max_contigous_subsequence_sum(vec3) << std::endl;
    return 0;
}