#include <stdio.h>
#include <cs50.h>

int main(void)
{
    long number = get_long("Number:");
    long copy = number;
    int size;
    for (size = 0; copy > 0; size++)
    {
        copy /= 10;
    }
    copy = number;
    for (int i = 0; i < size - 2; i++)
    {
        copy /= 10;
    }
    long copy2 = number / 10;
    int sum = 0;
    int s;
    for (int i = 0; i < size / 2; i++)
    {
        s = 2 * (copy2 % 10);
        if (s > 9)
        {
            sum = sum + 1 + s % 10;
        }
        else
        {
            sum = sum + s;
        }
        copy2 /= 100;
    }
    copy2 = number;
    for (int i = 0; i < size - size / 2; i++)
    {
        sum = sum + copy2 % 10;
        copy2 /= 100;
    }
    if (sum % 10 != 0)
    {
        printf("INVALID\n");
    }
    else if (copy > 50 && copy < 56 && size == 16)
    {
        printf("MASTERCARD\n");
    }
    else if (copy > 39 && copy < 50 && (size == 13 || size == 16))
    {
        printf("VISA\n");
    }
    else if ((copy == 34 || copy == 37) && size == 15)
    {
        printf("AMEX\n");
    }
    else
    {
        printf("INVALID\n");
    }
}