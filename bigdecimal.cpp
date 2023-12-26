


#include "bigdecimal.h"

// regex function that checks the validation of the input.
bool BigDecimalInt :: checkValidInput(string input)
{
    regex validInput("[-+]?[0-9]+");
    return regex_match(input, validInput);
}




//samesize func
void sameSize(string &num1, string &num2){
    //initializing sz1 & 2 to store size in it
    int sz1= num1.size();
    int sz2= num2.size();

    int diff=abs(sz1-sz2); // getting the diffrance between num1 & 2

    //checking which num has the smaller size
    if(num1.size()<num2.size())
    {
        reverse(num1.begin(),num1.end()); //reverse the number to put zeros in the back
        for(int i=0; i<diff ;i++)
            num1+='0'; //applying zeros to the smaller one in size from the back
        reverse(num1.begin(),num1.end()); // return number in  the right way
    }
    else if(num1.size()>num2.size()){
        reverse(num2.begin(),num2.end());
        for(int i=0; i<diff; i++)
            num2+='0';
        reverse(num2.begin(),num2.end());
    }
}


// Constructor that takes an integer from the user and converts it to a string
BigDecimalInt::BigDecimalInt(int decInt) {
    setNumber(to_string(decInt));
}






// constructor that takes a string as an input.
void BigDecimalInt :: setNumber(string num)
{
    bool validNumber = checkValidInput(num); // Check if the input is a valid number
    if(validNumber)
    {
        number = num; //set number
        if(number[0] == '+')
        {
            number.erase(0,1);// Remove the plus sign and set the signNumber to '+'
            signNumber = '+';
        }
        else if (number[0] == '-')
        {
            number.erase(0,1);
            signNumber = '-';
        }
        else
        {
            signNumber = '+'; // if no sign detected set as plus
        }
    }
    else
    {
        cout << "Invalid" << "\n";
        exit(1);// Terminate the program
    }
}





// operator < overloading function.
bool BigDecimalInt :: operator < (const BigDecimalInt& anotherDec)
{
    string comp1 = "", comp2 = "";
    long long len1 = number.length(), len2 = anotherDec.number.length();

    // checks both numbers having the same size for comparison
    while (len1 < len2){
        comp1 += '0';
        len1++;
    }
    while (len2 < len1){
        comp2 += '0';
        len2++;
    }
    comp1 += number;
    comp2 += anotherDec.number;

    if(signNumber == '-' && anotherDec.signNumber == '+') // Compare the numbers, considering their signs
    {
        return true; // This number is less than the other
    }
    else if(signNumber == '+' && anotherDec.signNumber == '-')
    {
        return false; // This number is greater than the other
    }
    else if(signNumber == '+' && anotherDec.signNumber == '+')
    {
        return comp1 < comp2; // Compare the absolute values
    }
    else
    {
        return comp1 > comp2;
    }
}




// operator > overloading function.
bool BigDecimalInt :: operator > (const BigDecimalInt &anotherDec)
{
    string comp1 = "", comp2 = "";
    long long len1 = number.length(), len2 = anotherDec.number.length();

    while (len1 < len2){
        comp1 += '0';
        len1++;
    }
    while (len2 < len1){
        comp2 += '0';
        len2++;
    }
    comp1 += number;
    comp2 += anotherDec.number;

    if(signNumber == '-' & anotherDec.signNumber == '+')
    {
        return false;
    }
    else if(signNumber == '+' & anotherDec.signNumber == '-')
    {
        return true;
    }
    else if(signNumber == '+' & anotherDec.signNumber == '+')
    {
        return comp1 > comp2;
    }
    else
    {
        return comp1 < comp2;
    }
}




// operator == overloading function.
bool BigDecimalInt :: operator == (const BigDecimalInt anotherDec)
{   string n1=number;
    string n2=anotherDec.number;

    if(number.size()!=anotherDec.number.size()){
        sameSize(n1,n2); // calling func same size to adjust the size for comparing
    }
    if (signNumber == anotherDec.signNumber && n1 == n2)
    {
        return true; // both are equal

    }
    else
    {
        return false;
    }
}



// function to return the size of number.
int BigDecimalInt :: size()
{
    return number.size();//return size of the number
}

// function returns the sign.
int BigDecimalInt :: sign()
{
    if (signNumber == '+')
    {
        return 1; // Return 1 for positive sign
    }
    else
    {
        return 0; // Return 0 for negative sign
    }
}

char BigDecimalInt::getSignNumber(){return signNumber;} // Return the sign character of the number
void BigDecimalInt::setSign(char s){signNumber=s;}


// Overloaded << operator to display a BigDecimalInt object
ostream &operator << (ostream &out, BigDecimalInt num)
{
    if(num.signNumber == '+')
    {
        out << num.number ; // Display the number without the '+' sign
    }
    else
    {
        out << num.signNumber << num.number ; // Display the number with the '-' sign

    }
    return out;// Return the output stream
}

istream &operator >> (istream &in, BigDecimalInt& num){
    in>>num.number;
    return in;
}
