#include <iostream>
#include <cmath>

using namespace std;

bool isValid(long long);
int sumOfDoubleEvenPlace(long long);
int getDigit(int);
int sumOfOddPlace(long long);
bool prefixMatched(int);
int getSize(long long);
long getPrefix(long long, int);

int main()
{
    long long number = 0;

    cout << "Enter a credit card number as a long integer: ";
    cin >> number;
    if(cin.fail())
    {
        cout << "Input error";
    }
    else
    {
        if(number > 0)
        {
            if(isValid(number) == true)
            {
                cout << number << " is valid" << endl;
            }
            else
            {
                cout << number << " is invalid" << endl;
            }
        }
        else
        {
            cout << "You cannot enter a negative number";
        }
    }

    return 0;
}

bool isValid(long long number)
{
    int sum_of_number = sumOfDoubleEvenPlace(number) + sumOfOddPlace(number);
    int prefix = 0;
    if (getPrefix(number, 2) == 37)
    {
        prefix = getPrefix(number, 2);
    }
    else
    {
        prefix = getPrefix(number, 1);
    } 
    
    if ((getSize(number) >= 13 && getSize(number) <= 16) && (sum_of_number % 10 == 0) && (prefixMatched(prefix) == true))
    {
        return true;
    }
    else
    {
        return false;
    }
}
int sumOfDoubleEvenPlace(long long number)
{
    int sum = 0;
    int digit = 0;
    int counter = 1;
    int double_digit = 0;
    int corrected_digit = 0;

    while (number != 0)
    {
        digit = number % 10;
        number /= 10;
        if(counter % 2 == 0)
        {
            double_digit = digit * 2;
            corrected_digit = getDigit(double_digit);
            sum+=corrected_digit;
        }
        counter++;
    }
    return sum;
}


int getDigit(int number)
{
    int corrected_digit = 0;
    int digit = 0;

    if(number > 9)
    {
        while(number != 0)
        {
            digit = number % 10;
            corrected_digit += digit;
            number /= 10;
        }
        return corrected_digit;
    }
    else
    {
        return number;
    }
}

int sumOfOddPlace(long long number)
{
    int sum = 0;
    int digit = 0;
    int counter = 1;

    while (number != 0)
    {
        digit = number % 10;
        number /= 10;
        if(counter % 2 != 0)
        {
            sum+=digit;
        }
        counter++;
    }
    return sum;
}


bool prefixMatched(int d)
{
    int visa = 4;
    int mastercard = 5;
    int american_express = 37;
    int discover = 6;

    if (d == visa || d == mastercard || d == american_express || d == discover)
    {
        return true;
    }
    else
    {
        return false;
    }
}


int getSize(long long d)
{
    int size = 1;
    if(d > 0)
    {
        for(size = 0; d > 0; size++)
        {
            d/=10;
        }
    }

    return size;
}

long getPrefix(long long number, int k)
{
    while(number >= pow(10, k))
    {
        number /= 10;
    }

    return number;
}
