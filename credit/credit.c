#include <cs50.h>
#include <stdio.h>

long length(long x);
string checksum(long x);

int main(void)
{
    long credit = get_long("Enter a Credit Card #: ");

    string s = checksum(credit);
    printf("%s\n", s);
}

long length(long x)
{
    long length = 0;
    while (x != 0)
    {
        x = x / 10;
        length += 1;
    }
    return length;
}

string checksum(long x)
{
    bool valid = true;
    long result = 0;
    long n = x;
    long k = x;
    long y;
    long len = length(x);

    for (int i = 0; i < len / 2; i++)
    {
        n = n / 10;
        y = (n % 10) * 2;
        n = n / 10;
        while (y != 0)
        {
            result += y % 10;
            y = y / 10;
        }
    }
    if (len % 2 != 0)
    {
        len += 1;
        for (int j = 0; j < len / 2; j++)
        {
            result += k % 10;
            k = k / 100;
        }
        len -= 1;
    }
    else
    {
        for (int j = 0; j < len / 2; j++)
        {
            result += k % 10;
            k = k / 100;
        }
    }

    printf("%ld\n", result);

    if (result % 10 != 0)
    {
        valid = false;
        return "INVALID";
    }

    for (int i = 0; i < len - 2; i++)
    {
        x = x / 10;
    }

    if (len == 15)
    {
        if (x == 34 || x == 37)
        {
            return "AMEX";
        }
    }

    if (len == 16)
    {
        if (x == 51 || x == 52 || x == 53 || x == 54 || x == 55)
        {
            return "MASTERCARD";
        }
    }

    if (len == 13 || len == 16)
    {
        if (x / 10 == 4)
        {
            return "VISA";
        }
    }

    return "INVALID";
}
