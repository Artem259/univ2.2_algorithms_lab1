#include <iostream>
#include "Rational.h"
#include <cmath>


bool isPrime(const size_t& n)
{
    size_t square = ceil(sqrt(n));
    for(size_t i=2; i<=square; i++)
    {
        if(n%i==0) return false;
    }
    return true;
}

size_t nearestPrime(const size_t& n)
{
    size_t res = n+1;
    while(!isPrime(res))
    {
        res++;
    }
    return res;
}

int main()
{
    size_t a = 2-3;
    std::cout<< a;
    return 0;
}