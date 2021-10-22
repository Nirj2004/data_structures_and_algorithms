#include <iostream>

int power(int a, int b)
{
    // base condition
    //
    if (b == 0)
    {
        return 1;
    }

    // sub-problem for this recursive call.
    //
    int p = power(a, b/2);


    // if b is odd
    if (b & 1)
    {
        return (a * p * q);
    }
    else
    {
        
    }
}