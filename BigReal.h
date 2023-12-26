

#ifndef OPP_2_BIGREAL_H
#define OPP_2_BIGREAL_H

#include <bits/stdc++.h>
#include <iostream>
#include "bigdecimal.h"

using namespace std;

void setZeros(BigDecimalInt& f, BigDecimalInt& s);

class BigReal
{
private:
    BigDecimalInt integerPart;
    BigDecimalInt decimalPart;


public:
    BigReal();
    BigReal(double realNumber  ); // Default constructor
    BigReal(string realNumber);
    BigReal(BigDecimalInt bigInteger);
    BigReal(const BigReal &other);       // Copy constructor
    BigReal &operator=(BigReal &other);  // Assignment operator




    // Overloading operators
    bool operator<  (BigReal anotherReal);
    bool operator>  (BigReal anotherReal);
    bool operator== (BigReal anotherReal);

    int size();
    int sign();

    friend ostream& operator << (ostream& out, BigReal num);
    friend istream& operator >> (istream& in, BigReal& num);

};


#endif //OPP_2_BIGREAL_H
