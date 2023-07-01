lim = int(input())
speed = int(input())

x = speed - lim

if x <= 0:
    print("Congratulations, you are within the speed limit!")
elif x >= 31:
    print("You are speeding and your fine is $500.")
elif x >= 21:
    print("You are speeding and your fine is $270.")
elif x >= 1:
    print("You are speeding and your fine is $100.")