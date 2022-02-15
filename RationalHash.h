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
        std::vector<Cell> cells; //комірки для хешування у вторинній таблиці
    };
    std::vector<size_t> randomVec; //коефіцієнти згортки вектора в число (випадкові)
    size_t A, B, P, M; //параметри хешування у первинну таблицю
    std::vector<Secondary> secondaryTables;

    static size_t randN(const size_t& min, const size_t& max);
    static size_t randomVecNGen();
    static bool isPrime(const size_t& n);
    static size_t nearestPrime(const size_t& n);
    static std::pair<size_t, size_t> findRepeatingNumbers(const std::vector<size_t>& v);
    size_t vectorCompression(const std::vector<Rational>& v);
    std::vector<size_t> inputVectorsCompression(const std::vector<std::vector<Rational>>& v);
    void hashing(const std::vector<std::vector<Rational>>& inputV, const std::vector<size_t>& numbersV);
public:
    explicit RationalHash(const std::vector<std::vector<Rational>>& input);
    bool contains(const std::vector<Rational>& n);
};

#endif