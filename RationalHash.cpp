//
// Created by Artem on 12.02.2022.
//

#include "RationalHash.h"

bool RationalHash::isPrime(const size_t& n)
{
    size_t square = ceil(sqrt(n));
    for(size_t i=2; i<=square; i++)
    {
        if(n%i==0) return false;
    }
    return true;
}

size_t RationalHash::nearestPrime(const size_t& n)
{
    size_t res = n+1;
    while(!isPrime(res))
    {
        res++;
    }
    return res;
}

size_t RationalHash::vectorsCompression(const std::vector<Rational> &v)
{
    size_t max = 0;

}

RationalHash::RationalHash(const std::vector<std::vector<Rational>>& input)
{
    size_t v;
    for(auto &i: input)
    {

    }
}

bool RationalHash::contains(const std::vector<Rational>& n)
{

}


