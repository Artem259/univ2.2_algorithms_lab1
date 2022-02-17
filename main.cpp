#include <iostream>
#include "RationalHash.h"

#include <algorithm>


int main()
{
    RationalHash a({{{-1,2},{0,1}}, {{-1,3},{0,1}},{{-1,2},{1,1}}, {Rational{-1},Rational{-6},
            {6,-7}}, {{-1,3},{22,-17}}, {{1, -1},{-6, 1},{-6,-7}}, {{0,1}}, {{0,1}, {0,1}}, {{0,1},{0,1},{0,1}}});
    std::cout<<a.contains({{-1,2},{0,1}});
    std::cout<<a.contains({{-1,3},{0,1}});
    std::cout<<a.contains({{-1,2},{1,1}});
    std::cout<<a.contains({{Rational{-1},Rational{-6}, {6,-7}}});
    std::cout<<a.contains({{-1,3},{22,-17}});
    std::cout<<a.contains({{1, -1},{-6, 1},{-6,-7}});
    std::cout<<a.contains({{0,1}});
    std::cout<<a.contains({{0,1}, {0,1}});
    std::cout<<a.contains({{0,1},{0,1},{0,1}});


    std::cout<<a.contains({{0,1}, {-1,2}});
    std::cout<<a.contains({{1,1}, {0,1}});
    std::cout<<a.contains({{0,1}, {0,1}, Rational{-1},Rational{-6}, {6,-7}});
    std::cout<<a.contains({{0,1}, {-1,2},{1,1}});

    return 0;
}