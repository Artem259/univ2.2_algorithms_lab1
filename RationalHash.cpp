//
// Created by Artem on 12.02.2022.
//

#include "RationalHash.h"
#include <ctime>
#include <algorithm>
#include <cassert>

size_t RationalHash::randN(const size_t& min, const size_t& max)
{
    return min+(rand()%(max-min+1));
}
size_t RationalHash::randomVecNGen()
{
    return randN(1,1000);
}
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

size_t RationalHash::vectorCompression(const std::vector<Rational>& v)
{
    assert(v.size()<=randomVec.size());
    size_t res = 0;
    for(size_t i=0; i<v.size(); i++)
    {
        res += (v[i].denominator+v[i].numerator)*randomVec[i];
    }
    return res;
}
std::vector<size_t> RationalHash::inputVectorsCompression(const std::vector<std::vector<Rational>>& input)
{
    size_t max = 0;
    for(auto &v : input)
    {
        if(v.size()>max) max=v.size();
    }
    randomVec.resize(max);
    std::generate(randomVec.begin(), randomVec.end(), RationalHash::randomVecNGen);

    std::vector<size_t> res(input.size()), curr;
    bool allUnique;
    while(true)
    {
        for(size_t i=0; i<input.size(); i++)
        {
            res[i] = vectorCompression(input[i]);
        }
        curr = res;
        sort(curr.begin(), curr.end());
        allUnique = std::adjacent_find(curr.begin(), curr.end()) == curr.end();
        if(allUnique) break;
        randomVec[0] = randomVecNGen();
    }
    return res;
}
void RationalHash::hashing(const std::vector<std::vector<Rational>>& inputV, const std::vector<size_t>& numbersV)
{
    M = numbersV.size();
    P = nearestPrime(*max_element(numbersV.begin(), numbersV.end()));
    A = randN(1, P-1);
    B = randN(0, P-1);

    std::vector<std::vector<size_t>> preHash(M);
    size_t currIndex;
    for(auto i : numbersV)
    {
        currIndex = ((A*i+B)%P)%M;
        preHash[currIndex].push_back(i);
    }

    secondaryTables.resize(M);
    for(size_t i=0; i<preHash.size(); i++)
    {
        if(preHash[i].empty())
        {
            secondaryTables[i].m = 0;
            secondaryTables[i].a = 0;
            secondaryTables[i].b = 0;
            secondaryTables[i].cells = {};
        }
        else if(preHash[i].size()==1)
        {
            secondaryTables[i].m = 1;
            secondaryTables[i].a = 0;
            secondaryTables[i].b = 0;
            secondaryTables[i].cells = {Cell{inputV[i]}};
        }
        else
        {

        }
    }
}
RationalHash::RationalHash(const std::vector<std::vector<Rational>>& input)
{
    srand(time(nullptr));
    auto numbers = inputVectorsCompression(input); //randomVec
    hashing(input, numbers); //M,P,A,B
}
bool RationalHash::contains(const std::vector<Rational>& n)
{

}


