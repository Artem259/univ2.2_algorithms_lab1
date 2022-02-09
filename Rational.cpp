//
// Created by Pavel on 10/16/2021.
//

#include "Rational.h"
#include <random>

std::random_device rd;
std::mt19937 mersenne(rd());

long long gcd(long long x, long long y) // Euclidean algorithm
{
    if (y == 0) return x;
    return gcd(y, x % y);
}

long long lcm(long long x, long long y)
{
    return (x*y)/gcd(x, y);
}

void reduction(long long &x, long long &y)
{
    long long nod = gcd(x, y);
    if(!nod)
    {
        y = 1;
        return;
    }
    x /= nod;
    y /= nod;
    if(y < 0)
    {
        x *= -1;
        y *= -1;
    }
    if(y==0)
    {
        y = 1;
    }
}

Rational::Rational()
{
    numerator = 0;
    denominator = 1;
}

Rational::Rational(long long n, long long d)
{
    numerator = n;
    denominator = d;
    if(!d)
        denominator = 1;
    reduction(numerator, denominator);
}

Rational::Rational(long long n)
{
    numerator = n;
    denominator = 1;
}

Rational::Rational(const Rational &r)
{
    numerator = r.numerator;
    denominator = r.denominator;
}

void Rational::random(const long long &n)
{
    numerator = mersenne() % (std::abs(n)+1);
    denominator = mersenne() % (std::abs(n)+1);
    if (mersenne() % 2)
        numerator *= -1;
    if (mersenne() % 2)
        denominator *= -1;
    reduction(numerator, denominator);
}

std::ostream& operator<< (std::ostream &out, const Rational &r)
{
    out << r.numerator << '/' << r.denominator;
    return out;
}

Rational operator + (const Rational &r1,const Rational &r2)
{
    Rational r3;
    r3.denominator = lcm(r1.denominator, r2.denominator);
    r3.numerator = r1.numerator * (r3.denominator / r1.denominator) + r2.numerator * (r3.denominator / r2.denominator);
    reduction(r3.numerator, r3.denominator);
    return r3;
}

Rational operator - (const Rational &r1,const Rational &r2)
{
    Rational r3;
    r3.denominator = lcm(r1.denominator, r2.denominator);
    r3.numerator = r1.numerator * (r3.denominator / r1.denominator) - r2.numerator * (r3.denominator / r2.denominator);
    reduction(r3.numerator, r3.denominator);
    return r3;
}

Rational operator * (const Rational &r1,const Rational &r2)
{
    Rational r3(r1.numerator, r2.denominator);
    Rational r4(r2.numerator, r1.denominator);
    Rational r5;
    r5.denominator = r3.denominator * r4.denominator;
    r5.numerator = r3.numerator * r4.numerator;
    return r5;
}

Rational operator / (const Rational &r1, const Rational &r2)
{
    Rational r3(r1.numerator, r2.numerator);
    Rational r4(r2.denominator, r1.denominator);
    Rational r5;
    r5.denominator = r3.denominator * r4.denominator;
    r5.numerator = r3.numerator * r4.numerator;
    return r5;
}

bool operator ==(const Rational &r1, const Rational &r2)
{
    if (r1.numerator * r2.denominator == r2.numerator * r1.denominator)
        return true;
    return false;
}

bool operator !=(const Rational &r1, const Rational &r2)
{
    return !(r1==r2);
}