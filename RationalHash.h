//
// Created by Artem on 10.02.2022.
//

#ifndef RATIONALHASH_H
#define RATIONALHASH_H

#include <vector>
#include "Rational.h"

class RationalHash
{
private:
    struct Secondary
    {
        size_t a, b, m; //параметри хешування у вторинну таблицю
        std::vector<Cell> cells; //комірки для хешування у вторинній таблиці
    };
    struct Cell
    {
        std::vector<Rational> data; //хешований у комірку вектор
    };
    size_t vP; //параметр хешування вектора в число
    size_t A, B, P, M; //параметри хешування у первинну таблицю
    std::vector<Secondary> secondaryTables;
public:
    explicit RationalHash(const std::vector<std::vector<Rational>>& input);
    bool contains(const std::vector<Rational>& n);
};

RationalHash::RationalHash(const std::vector<std::vector<Rational>>& input)
{

}

bool RationalHash::contains(const std::vector<Rational>& n)
{

}

#endif