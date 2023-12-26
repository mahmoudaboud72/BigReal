#include "BigReal.h"
// Default constructor that initializes a BigReal object with integerPart and decimalPart set to "0"
BigReal::BigReal() : integerPart("0"), decimalPart("0") {}

// Default constructor
BigReal::BigReal(double realNumber)
{
    string realNumberStr = to_string(realNumber);// Convert the double to a string.
    int decimalPointIndex = realNumberStr.find('.');// Find the position of the decimal point in the string

    // Extract the integer and decimal parts of the number
    string integerPartStr = realNumberStr.substr(0, decimalPointIndex);
    string decimalPartStr = realNumberStr.substr(decimalPointIndex + 1);

    // Initialize the integerPart and decimalPart using the corresponding BigDecimalInt constructors
    integerPart = BigDecimalInt(integerPartStr);
    decimalPart = BigDecimalInt(decimalPartStr);
}

// Constructor that takes a string representation of a real number
BigReal::BigReal(string realNumber)
{
    int decimalPointIndex = realNumber.find('.');
    if (decimalPointIndex == -1)
    {
        // Initialize the integerPart and decimalPart using the corresponding BigDecimalInt constructors
        integerPart = BigDecimalInt(realNumber);
        decimalPart = BigDecimalInt("0");
    }
    else
    {
        // Extract the integer and decimal parts of the number
        string integerPartStr = realNumber.substr(0, decimalPointIndex);
        string decimalPartStr = realNumber.substr(decimalPointIndex + 1);

        // Initialize the integerPart and decimalPart using the corresponding BigDecimalInt constructors
        integerPart = BigDecimalInt(integerPartStr);
        decimalPart = BigDecimalInt(decimalPartStr);
    }
}

// Constructor that takes a BigDecimalInt for the integer part and initializes a BigReal object
BigReal::BigReal(BigDecimalInt bigInteger)
{
    integerPart = bigInteger;
    decimalPart = BigDecimalInt(0); // Set the decimalPart to "0"
}

// Copy constructor to create a BigReal object from another BigReal object
BigReal::BigReal(const BigReal &other)
{
    integerPart = other.integerPart;
    decimalPart = other.decimalPart;
}


// Assignment operator for copying a BigReal object
BigReal &BigReal::operator=(BigReal &other)
{
    // Copy the integer and decimal parts from the other BigReal object
    integerPart = other.integerPart;
    decimalPart = other.decimalPart;
    return *this; // return a reference to the current object
}



// Function to set the number of zeros for two BigDecimalInt objects.
void setZeros(BigDecimalInt &f, BigDecimalInt &s)
{
    string str1 = f.getNumber();
    string str2 = s.getNumber();
    int diff = abs(f.size() - s.size());

    if (str1.size() > str2.size())
    {
        for (int i = 0; i < diff; i++)
        {
            str2 += "0";
        }
    }
    else
    {
        for (int i = 0; i < diff; i++)
        {
            str1 += "0";
        }
    }
    f.setNumber(str1);
    s.setNumber(str2);
}

// Comparison operator to check if one BigReal is less than another
bool BigReal::operator<(BigReal anotherReal)
{
    int s1, s2;
    s1 = integerPart.sign();
    s1 = integerPart.sign();

    if (integerPart < anotherReal.integerPart)
    {
        return true;
    }
    if (decimalPart.size() != anotherReal.decimalPart.size())
    {
        setZeros(decimalPart, anotherReal.decimalPart);
    }

    if (integerPart == anotherReal.integerPart)
    {
        if (decimalPart < anotherReal.decimalPart && s1 == 1)
        {
            return true;
        }
        if (decimalPart < anotherReal.decimalPart && s1 == 0)
        {
            return false;
        }
        if (decimalPart > anotherReal.decimalPart && s1 == 1)
        {
            return false;
        }
        if (decimalPart > anotherReal.decimalPart && s1 == 0)
        {
            return true;
        }
    }
    return false;
}

bool BigReal::operator>(BigReal anotherReal)
{
    int s1, s2;
    s1 = integerPart.sign();
    s1 = integerPart.sign();

    if (integerPart > anotherReal.integerPart)
    {
        return true;
    }
    if (decimalPart.size() != anotherReal.decimalPart.size())
    {
        setZeros(decimalPart, anotherReal.decimalPart);
    }

    if (integerPart == anotherReal.integerPart)
    {
        if (decimalPart > anotherReal.decimalPart && s1 == 1)
        {
            return true;
        }
        if (decimalPart > anotherReal.decimalPart && s1 == 0)
        {
            return false;
        }
        if (decimalPart < anotherReal.decimalPart && s1 == 1)
        {
            return false;
        }
        if (decimalPart < anotherReal.decimalPart && s1 == 0)
        {
            return true;
        }
    }
    return false;
}

bool BigReal::operator==(BigReal anotherReal)
{
    if (integerPart == anotherReal.integerPart and decimalPart == anotherReal.decimalPart)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int BigReal::size()
{
    int total;
    total = integerPart.size() + decimalPart.size();
    return total;
}
int BigReal::sign()
{
    return integerPart.sign();
}

ostream &operator<<(ostream &out, BigReal num)
{
    out << num.integerPart << "." << num.decimalPart;
    return out;
}
istream &operator>>(istream &in, BigReal &num)
{
    string n;
    in >> n;

    // Create a new BigReal object from the input string and assign it to the provided BigReal object 'num'
    BigReal real(n);
    num = real;
    return in;
}
