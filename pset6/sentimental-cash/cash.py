# TODO
from cs50 import get_float


def main():
    cents = get_cents()

    quarters = calculate_quarters(cents)
    cents = cents - quarters * 25

    dimes = calculate_dimes(cents)
    cents = cents - dimes * 10

    nickels = calculate_nickels(cents)
    cents = cents - nickels * 5

    pennies = calculate_pennies(cents)
    cents = cents - pennies * 1

    coins = quarters + dimes + nickels + pennies

    print(f"total number:{coins}")


def get_cents():
    while True:
        cents0 = get_float("input: ")
        if cents0 > 0:
            break
    return cents0 * 100


def calculate_quarters(cents1):
    if cents1 >= 25:
        return cents1 // 25
    else:
        return 0


def calculate_dimes(cents2):
    if cents2 >= 10:
        return cents2 // 10
    else:
        return 0


def calculate_nickels(cents3):
    if cents3 >= 5:
        return cents3 // 5
    else:
        return 0


def calculate_pennies(cents3):
    return cents3


main()
