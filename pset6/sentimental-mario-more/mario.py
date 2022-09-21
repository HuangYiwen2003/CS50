# TODO

from cs50 import get_int

# get height
while True:
    number = get_int("Height: ")
    if number > 0 and number < 9:
        break

# initialize row
row = 1

# print mario
for i in range(number):
    for i in range(number - row):
        print(" ", end="")
    for i in range(row):
        print("#", end="")
    print("  ", end="")
    for i in range(row):
        print("#", end="")
    row += 1
    print()