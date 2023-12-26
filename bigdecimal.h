

#ifndef OPP_2_BIGDECIMAL_H
#define OPP_2_BIGDECIMAL_H



#include <iostream>
#include <deque>
#include <regex>

using namespace std;
void sameSize(string &num1, string &num2);

class BigDecimalInt{
private:
    string number;
    char signNumber;
    bool checkValidInput(string input);

public:
    bool operator < (const BigDecimalInt& anotherDec);
    bool operator > (const BigDecimalInt& anotherDec);
    bool operator == (const BigDecimalInt anotherDec);



    int size();
    int sign();
    void setNumber(string num); // constructor that takes a string as an input and check for validation
    string getNumber(){
        return number;
    }

    char getSignNumber();
    void setSign(char s);


    BigDecimalInt(){}
    BigDecimalInt(int decInt);
    BigDecimalInt(string num)
    {
        setNumber(num);
    }

    friend ostream &operator << (ostream &out, BigDecimalInt num);// Overloaded << operator to display a BigDecimalInt object
    friend istream &operator >> (istream &in, BigDecimalInt& num);
};


#endif //OPP_2_BIGDECIMAL_H
