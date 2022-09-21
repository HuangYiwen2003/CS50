# TODO
from cs50 import get_int


def main():
    number = get_int("Number:")
    copy = number
    size = len(str(number))
    for i in range(size - 2):
        copy //= 10
    copy2 = number // 10
    sum = 0
    for i in range(size // 2):
        s = 2 * (copy2 % 10)
        if s > 9:
            sum = sum + 1 + s % 10
        else:
            sum = sum + s
        copy2 //= 100
    copy2 = number
    for i in range(size - size // 2):
        sum = sum + copy2 % 10
        copy2 //= 100
    if sum % 10 != 0:
        print("INVALID")
    elif copy > 50 and copy < 56 and size == 16:
        print("MASTERCARD")
    elif (copy > 39 and copy < 50 and (size == 13 or size == 16)):
        print("VISA")
    elif ((copy == 34 or copy == 37) and size == 15):
        print("AMEX")
    else:
        print("INVALID")


main()