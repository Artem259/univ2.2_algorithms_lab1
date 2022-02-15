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
std::pair<size_t, size_t> RationalHash::findRepeatingNumbers(const std::vector<size_t>& v)
{
    std::vector<size_t> tmp = v;
    sort(tmp.begin(), tmp.end());
    auto it = std::adjacent_find(tmp.begin(), tmp.end());
    if(it == tmp.end()) return {0,0};

    std::pair<size_t, size_t> res;
    bool first = true;
    for(size_t i=0; i<v.size(); i++)
    {
        if(v[i]==*it)
        {
            if(first)
            {
                res.first = i;
                first = false;
            }
            else
            {
                res.second = i;
                break;
            }
        }
    }
    return res;
}

size_t RationalHash::vectorCompression(const std::vector<Rational>& v)
{
    assert((!v.empty()) && v.size()<=randomVec.size());
    size_t res = 0;
    for(size_t i=0; i<v.size(); i++)
    {
        if(v[i].denominator+v[i].numerator!=0)
            res += (v[i].denominator+v[i].numerator)*randomVec[i];
        else
            res += (v[i].denominator*v[i].numerator)*randomVec[i];
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

    size_t square = M*M;
    std::vector<size_t> res(input.size());
    while(true)
    {
        for(size_t i=0; i<input.size(); i++)
        {
            res[i] = vectorCompression(input[i])%square + 1;
        }
        std::pair<size_t, size_t> repeating = findRepeatingNumbers(res);
        if(repeating == std::pair<size_t, size_t>{0,0}) break;
        assert(input[repeating.first] != input[repeating.second]);
        randomVec[0] = randomVecNGen();
    }
    return res;
}
void RationalHash::hashing(const std::vector<std::vector<Rational>>& inputV, const std::vector<size_t>& numbersV)
{
    P = nearestPrime(*max_element(numbersV.begin(), numbersV.end()));
    A = randN(1, P-1);
    B = randN(0, P-1);

    std::vector<std::vector<size_t>> preHash(M);
    size_t currIndex;
    for(size_t i=0; i<numbersV.size(); i++)
    {
        currIndex = ((A*numbersV[i]+B)%P)%M;
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
            secondaryTables[i].cells = {Cell{inputV[preHash[i][0]]}};
        }
        else
        {
            secondaryTables[i].m = preHash[i].size()*preHash[i].size(); //square
            secondaryTables[i].cells.resize(secondaryTables[i].m);
            bool flag = false;
            while(true)
            {
                secondaryTables[i].a = randN(1, P-1);
                secondaryTables[i].b = randN(0, P-1);
                for(size_t k=0; k<preHash[i].size(); k++)
                {
                    currIndex = ((secondaryTables[i].a*numbersV[preHash[i][k]]+secondaryTables[i].b)%P)%secondaryTables[i].m;
                    if(!secondaryTables[i].cells[currIndex].data.empty())
                    {
                        flag = true;
                        break;
                    }
                    secondaryTables[i].cells[currIndex] = {inputV[preHash[i][k]]};
                }
                if(flag)
                {
                    flag = false;
                    secondaryTables[i].cells.clear();
                    secondaryTables[i].cells.resize(secondaryTables[i].m);
                }
                else break;
            }
        }
    }
}
RationalHash::RationalHash(const std::vector<std::vector<Rational>>& input)
{
    srand(time(nullptr));
    M = input.size();

    auto numbers = inputVectorsCompression(input); //randomVec
    hashing(input, numbers); //P,A,B, secondaryTables
}
bool RationalHash::contains(const std::vector<Rational>& n)
{

}


