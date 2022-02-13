//
// Created by Artem on 10.02.2022.
//

#ifndef RATIONALHASH_H
#define RATIONALHASH_H

#include <vector>
#include <cmath>
#include "Rational.h"

class RationalHash
{
private:
    struct Cell
    {
        std::vector<Rational> data; //хешований у комірку вектор
    };
    struct Secondary
    {
        size_t a, b, m; //параметри хешування у вторинну таблицю
        Cell *cells; //комірки для хешування у вторинній таблиці
    };
    std::vector<size_t> vP; //коефіцієнти згортки вектора в число
    size_t A, B, P, M; //параметри хешування у первинну таблицю
    Secondary *secondaryTables;

    static bool isPrime(const size_t& n);
    static size_t nearestPrime(const size_t& n);
    size_t vectorsCompression(const std::vector<Rational>& v);
public:
    explicit RationalHash(const std::vector<std::vector<Rational>>& input);
    bool contains(const std::vector<Rational>& n);
};

#endif