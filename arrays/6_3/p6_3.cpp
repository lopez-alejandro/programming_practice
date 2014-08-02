/*
 * Goal:
 * write a function that takes in two strings
 * representing integers and returns an integer
 * prepresenting their product
 */
#include <iostream>

using namespace std;

int multiply(string, string);
int strToInt(string);

int main(void){
    string firstNum, secondNum;
    cin >> firstNum;
    cin >> secondNum;
    cout << multiply(firstNum, secondNum) << endl;
    return 1;
}

int multiply(string a, string b){
    return strToInt(a) * strToInt(b);
}

// converts strings to intergers
int strToInt(string a){
    // we convert the strings into intergers by reading them in char by char
    int aSize = a.size();
    int intA = 0;
    int place = 1;      // refers to the digit, ones place, tens place, hundreds place etc


    for(int i = aSize - 1; i > 0; --i){
        intA += (a[i] - '0') * place;
        place *= 10; // increase the place value
    }

    // convert to a negative number if dash exists in the front
    if(a[0] == '-'){
        intA *= -1;
    }else{
        intA += (a[0] - '0') * place;
    }
    return intA;
}
