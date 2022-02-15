#include <iostream>
#include "RationalHash.h"

#include <algorithm>


int main()
{
    RationalHash a({{{-1,2},{0,1}}, {Rational{-1},Rational{-6},{6,-7}}, {{-1,3},{22,-17}}, {{1, -1},{-6, 1},{-6,-7}}});
    return 0;
}