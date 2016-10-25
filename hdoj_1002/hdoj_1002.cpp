//
// Created by Harlan1994 on 2016/10/25.
//

#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

using namespace std;

const int MAX_LENGTH = 1000;

struct BigNum
{
    int len;
    int s[MAX_LENGTH];

    BigNum()
    {
        len = 1;
        memset(s, 0, sizeof(s));
    }

    BigNum operator = (int num)
    {
        char temp[MAX_LENGTH];
        sprintf(temp, "%d", num);
        *this = temp;
        return *this;
    }

    BigNum operator = (const char* num)
    {
        len = strlen(num);
        for(int i = 0; i < len; i++)
        {
            s[i] = num[len - i - 1] - '0';
        }
        return *this;
    }

    BigNum(int num)
    {
        *this = num;
    }

    BigNum(const char* num)
    {
        *this = num;
    }

    string str() const
    {
        string result = "";
        for(int i = 0; i < len; i++)
        {
            result = (char)(s[i] + '0') + result;
        }
        if(result == "")result = "0";

        return result;
    }

    BigNum operator + (const BigNum& x) const
    {
        BigNum c;
        c.len = 0;
        for(int i = 0, j = 0; j || i < max(len, x.len); i++)
        {
            int t = j;
            if(i < len)t += s[i];
            if(i < x.len)t += x.s[i];
            c.s[c.len++] = t % 10;
            j = t / 10;
        }
        return c;
    }

    BigNum operator += (BigNum& x)
    {
        *this = *this + x;
        return *this;
    }

    bool operator < (const BigNum& b) const
    {
        if(len != b.len)return len < b.len;
        for(int i = len - 1; i >= 0; i--)
        {
            if(s[i] != b.s[i])return s[i] < b.s[i];
        }
        return false;
    }

    bool operator > (const BigNum& b) const
    {
        return b < *this;
    }

    bool operator <= (const BigNum& b) const
    {
        return !(*this > b);
    }

    bool operator >= (const BigNum& b) const
    {
        return !(*this < b);
    }

    bool operator != (const BigNum& b) const
    {
        return !(*this < b) || !(*this > b);
    }

    bool operator == (const BigNum& b) const
    {
        return !(*this < b) && !(*this > b);
    }
};

istream& operator >> (istream& in, BigNum& x)
{
    string s;
    in >> s;
    x = s.c_str();
    return in;
}

ostream& operator << (ostream& out, const BigNum& x)
{
    out << x.str();
    return out;
}

int main(){

}