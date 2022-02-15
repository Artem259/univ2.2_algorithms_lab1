#include <iostream>
#include "RationalHash.h"

#include <algorithm>


int main()
{
    for(size_t i=0; i<100;i++)
    {
        RationalHash a({{{-1,2},{0,1}}, {{-1,3},{0,1}},{{-1,2},{1,1}}, {Rational{-1},Rational{-6},
                                         {6,-7}}, {{-1,3},{22,-17}}, {{1, -1},{-6, 1},{-6,-7}}, {{0,1}}, {{0,1}, {0,1}}, {{0,1},{0,1},{0,1}}});
        std::cout<<i<<std::endl;
    }
    return 0;
}