#include <stdio.h>
#include <cs50.h>

int get_cents(void);
int calculate_quarters(int cents);
int calculate_dimes(int cents);
int calculate_nickels(int cents);
int calculate_pennies(int cents);

int main(void)
{
    int cents = get_cents();

    int quarters = calculate_quarters(cents);
    cents = cents - quarters * 25;

    int dimes = calculate_dimes(cents);
    cents = cents - dimes * 10;

    int nickels = calculate_nickels(cents);
    cents = cents - nickels * 5;

    int pennies = calculate_pennies(cents);
    cents = cents - pennies * 1;

    int coins = quarters + dimes + nickels + pennies;

    printf("total number:%i\n", coins);
}

int get_cents(void)
{
    int cents;
    do
    {
        cents = get_int("Change owed:");
    }
    while (cents < 0);
    return cents;
}

int calculate_quarters(int cents)
{
    if (cents >= 25)
    {
        return cents / 25;
    }
    else
    {
        return 0;
    }
}

int calculate_dimes(int cents)
{
    if (cents >= 10)
    {
        return cents / 10;
    }
    else
    {
        return 0;
    }
}

int calculate_nickels(int cents)
{
    if (cents >= 5)
    {
        return cents / 5;
    }
    else
    {
        return 0;
    }
}

int calculate_pennies(int cents)
{
    return cents;
}