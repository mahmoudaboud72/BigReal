/*
 FCAI - OOP Programming - 2023 - Assignment 2
zip file Name: A2_Task1 & 2_S24_ 20220320 .zip

 Mahmoud Mohamed Mahmoud 20220320
Teaching Assistant: Eng/ Mohamed Talaat Saad Farrag.
*/

#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#include "BigReal.h"
#include "bigdecimal.h"
int main()
{
    BigReal n1("0010.3");
    BigReal n2("10.9");

    BigDecimalInt a(20);

    cout<<"Test << operator "<<n1<<endl;

    n1 = n2;
    cout<<"Test assignment opreator "<<n1<<endl;

    BigReal n3 = BigReal(+-444);
    cout<<"Test bigDecimalInt constructor "<<n3<<endl;

    BigReal n4 = BigReal(100.085445);
    cout<<"Test double constructor "<<n4<<endl;

    BigReal n5 = BigReal(n4);
    cout<<"Test copy constructor "<<n5<<endl;

    BigReal n6("3.11");
    cout<<"Test > operator "<<(n5>n6)<<endl;

    cout<<"Test < operator "<<(n5<n6)<<endl;

    BigReal n7("01.22");
    BigReal n8("-1.22");
    cout<<"Test == operator "<<(n7==n8)<<endl;



    return 0;
}
